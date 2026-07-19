/**
 * RA8P1_AI — best-int8 实时目标检测
 * OV5640 → CEU → 128×128 int8 → Ethos-U55 → 串口输出
 */
#include "hal_data.h"
#include "headfile.h"
#include <stdio.h>
#include <string.h>
#include "model.h"
#include "model_io_data.h"
#include "pmu_ethosu.h"

static FILE __stdout_f; FILE *const stdout = &__stdout_f;
volatile bool g_uart9_tx_done = true;
void user_uart9_callback(uart_callback_args_t *p) {
    if (p && UART_EVENT_TX_COMPLETE == p->event) g_uart9_tx_done = true;
}
void timer_1ms_callback(timer_callback_args_t *p) { (void)p; }

static void uart_str(const char *s) {
    uint32_t n = strlen(s);
    g_uart9_tx_done = false;
    g_uart9.p_api->write(g_uart9.p_ctrl, (uint8_t*)s, n);
    while (!g_uart9_tx_done) {}
}
#define LOG(fmt, ...) do { char _b[128]; snprintf(_b, sizeof(_b), fmt, ##__VA_ARGS__); uart_str(_b); } while(0)

#define CAM_W  320
#define CAM_H  240
#define MDL_W  192
#define MDL_H  192
static uint16_t g_frame[CAM_W * CAM_H]
    BSP_ALIGN_VARIABLE(32) BSP_PLACE_IN_SECTION(".sdram_noinit");
static uint16_t g_disp[CAM_W * CAM_H]
    BSP_ALIGN_VARIABLE(32) BSP_PLACE_IN_SECTION(".sdram_noinit");

/* 预处理: CEU原始RGB565 → 192×192 uint8 NHWC (R↔B交换) */
static void preprocess(const uint16_t *src, uint8_t *dst) {
    int cx = (CAM_W - MDL_W) / 2, cy = (CAM_H - MDL_H) / 2;
    for (int y = 0; y < MDL_H; y++) {
        for (int x = 0; x < MDL_W; x++) {
            int sx = cx + x * CAM_W / MDL_W;
            int sy = cy + y * CAM_H / MDL_H;
            uint16_t p = src[sy * CAM_W + sx];
            // CEU word = 正确RGB565, 做R↔B交换
            int r5 = (p >> 11) & 0x1F, g6 = (p >> 5) & 0x3F, b5 = p & 0x1F;
            // R↔B swap
            int base = (y * MDL_W + x) * 3;
            dst[base + 0] = (uint8_t)(b5 << 3);  // R位置放B
            dst[base + 1] = (uint8_t)(g6 << 2);  // G不动
            dst[base + 2] = (uint8_t)(r5 << 3);  // B位置放R
        }
    }
}

/* 扫描所有位置找 A2 A5 00, 取最高分 */
typedef struct { int score; int count; } DetInfo;

static void detect(const uint8_t *out, int len, DetInfo *r) {
    r->score = -999; r->count = 0;
    for (int i = 0; i < len - 5; i++) {
        if (out[i] == 0xA2 && out[i+1] == 0xA5 && out[i+2] == 0x00) {
            int s = (int8_t)out[i+3];  // score 在 A2 A5 00 后面1字节
            if (s > r->score) r->score = s;
            r->count++;
        }
    }
}

void hal_entry(void)
{
    fsp_err_t err;
    g_uart9.p_api->open(g_uart9.p_ctrl, g_uart9.p_cfg);
    uart_str("=== AI Camera ===\r\n");

    LOG("[1/5] OV5640...\r\n");
    err = ov5640_init();
    if (FSP_SUCCESS != err) { LOG("FAIL\r\n"); while(1); }
    ov5640_set_resolution(OV5640_RES_QVGA);
    // 不切 RGB565！保持 YUV 输出, 匹配 CEU YCbCr422 处理
    LOG("OK\r\n");

    LOG("[2/5] CEU...\r\n");
    err = g_ceu0.p_api->open(g_ceu0.p_ctrl, g_ceu0.p_cfg);
    if (FSP_SUCCESS != err && FSP_ERR_ALREADY_OPEN != err) { LOG("FAIL\r\n"); while(1); }
    LOG("OK\r\n");

    LOG("[3/6] OSPI...\r\n");
    err = g_ospi0.p_api->open(g_ospi0.p_ctrl, g_ospi0.p_cfg);
    if (FSP_SUCCESS != err) { LOG("FAIL\r\n"); while(1); }
    LOG("OK\r\n");

    LOG("[4/6] LCD...\r\n");
    LCD_Init(); LCD_Clear(BLACK);
    LCD_ShowString(10, 10, 300, 24, 16, WHITE, (u8*)"AI Camera Ready");
    LOG("OK\r\n");

    LOG("[5/6] NPU...\r\n");
    err = RM_ETHOSU_Open(&g_rm_ethosu0_ctrl, &g_rm_ethosu0_cfg);
    if (FSP_SUCCESS != err) { LOG("FAIL\r\n"); while(1); }
    ETHOSU_PMU_Enable(&g_ethosu0);
    LOG("OK\r\n");

    LOG("[6/6] === Detection loop ===\r\n");

    /* === 一次性诊断: RUHMI测试图片 vs 摄像头 === */
    {
        extern uint8_t model_serving_default_keras_tensor_121_0[110592];
        uint8_t *inp = GetModelInputPtr_serving_default_keras_tensor_121_0();

        /* Test A: RUHMI内置测试图片 */
        memcpy(inp, model_serving_default_keras_tensor_121_0, 110592);
        extern uint8_t sub_0000_arena[884736], sub_0004_arena[49904];
        SCB_CleanDCache_by_Addr(sub_0000_arena, 112640);
        RunModel(false);
        SCB_InvalidateDCache_by_Addr(sub_0004_arena, 49904);
        const uint8_t *out = GetModelOutputPtr_StatefulPartitionedCall_1_0_70408();
        int bestA = -999;
        for (int d=0; d<200; d++)
            if (out[d*12+8] == 0x78 && out[d*12+9] == 0x5C)
            { int s=(int8_t)out[d*12+10]; if(s>bestA)bestA=s; }
        LOG("  DIAG: RUHMI test image  best=%d\r\n", bestA);

        /* Test B: 摄像头首帧 */
        g_capture_complete = false;
        g_ceu0.p_api->captureStart(g_ceu0.p_ctrl, (uint8_t*)g_frame);
        uint32_t to = 2000;
        while (!g_capture_complete && to) { R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS); to--; }
        if (g_capture_complete) {
            SCB_InvalidateDCache_by_Addr(g_frame, sizeof(g_frame));
            preprocess(g_frame, inp);
            SCB_CleanDCache_by_Addr(sub_0000_arena, 112640);
            RunModel(false);
            SCB_InvalidateDCache_by_Addr(sub_0004_arena, 49904);
            int bestB = -999;
            for (int d=0; d<200; d++)
                if (out[d*12+8] == 0x78 && out[d*12+9] == 0x5C)
                { int s=(int8_t)out[d*12+10]; if(s>bestB)bestB=s; }
            LOG("  DIAG: camera frame       best=%d\r\n", bestB);
        }
        LOG("  === Entering main loop ===\r\n");
    }

    uint32_t fc = 0;
    while (1) {
        /* 捕获 */
        g_capture_complete = false;
        g_ceu0.p_api->captureStart(g_ceu0.p_ctrl, (uint8_t*)g_frame);
        uint32_t to = 2000;
        while (!g_capture_complete && to) { R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS); to--; }
        if (!g_capture_complete) continue;
        fc++;
        SCB_InvalidateDCache_by_Addr(g_frame, sizeof(g_frame));

        /* 显示缓冲 */
        for (uint32_t i = 0; i < CAM_W * CAM_H; i++) {
            uint16_t p = g_frame[i];
            int r5 = (p >> 11) & 0x1F, g6 = (p >> 5) & 0x3F, b5 = p & 0x1F;
            g_disp[i] = ((uint16_t)b5 << 11) | (g6 << 5) | r5;
        }

        /* 预处理 */
        uint8_t *inp = GetModelInputPtr_serving_default_keras_tensor_121_0();
        preprocess(g_frame, inp);

        /* Clean: 只clean输入区域(arena0前112KB) */
        extern uint8_t sub_0000_arena[884736];
        SCB_CleanDCache_by_Addr(sub_0000_arena, 112640);

        /* 推理 */
        RunModel(false);

        /* Invalidate: 只刷输出 arena(arena4, 50KB) */
        extern uint8_t sub_0004_arena[49904];
        SCB_InvalidateDCache_by_Addr(sub_0004_arena, 49904);

        /* 解析: 只扫前400检测(速度快3x, 覆盖足够) */
        const uint8_t *out = GetModelOutputPtr_StatefulPartitionedCall_1_0_70408();
        int best_sc = -999, best_d = -1;
        int scan = 400; // 只扫描前400个检测
        for (int d = 0; d < scan; d++) {
            int s_off = d * 12 + 6;
            if (out[s_off+2] == 0x78 && out[s_off+3] == 0x5C) {
                int sc = (int8_t)out[s_off + 4];
                if (sc > best_sc) { best_sc = sc; best_d = d; }
            }
        }

        /* 提取最佳检测框并画到 LCD */
        int bx = 0, by = 0, bw = 0, bh = 0;
        if (best_d >= 0) {
            int b_off = best_d * 12;
            // box bytes: [b0,b1,E2,A5,b4,b5] → b0/b1=ymin/xmin? b4/b5=ymax/xmax?
            int b0 = (int8_t)out[b_off+0], b1 = (int8_t)out[b_off+1];
            int b4 = (int8_t)out[b_off+4], b5 = (int8_t)out[b_off+5];
            // 映射: int8[-128,127]→模型输入[0,192]→LCD坐标
            int cx_m = (CAM_W - MDL_W) / 2, cy_m = (CAM_H - MDL_H) / 2;
            bx = cx_m + (b1 + 128) * MDL_W / 256;
            by = cy_m + (b0 + 128) * MDL_H / 256;
            bw = ((b5 + 128) * MDL_W / 256) - bx + cx_m;
            bh = ((b4 + 128) * MDL_H / 256) - by + cy_m;
            if (bw < 4) bw = 4; if (bh < 4) bh = 4;
        }

        // 时间滤波 (阈值110, 适应YCbCr→RGB转换后的分数分布)
        static int streak = 0;
        if (best_sc >= 90) streak++; else if (best_sc < 80) streak = 0;

        /* LCD: 隔帧更新减少SPI传输 */
        if (fc & 1) {  // 奇数帧更新LCD
            LCD_ShowImage(0, 0, CAM_W, CAM_H, g_disp);
            if (streak >= 3 && best_d >= 0) {
                LCD_DrawRectangle(bx, by, bx+bw, by+bh, RED);
            }
        }

        // 叠加文字
        char overlay[32];
        if (streak >= 5) {
            snprintf(overlay, sizeof(overlay), "DIGIT! %d", best_sc);
            LCD_ShowString(10, 210, 300, 30, 24, RED, (u8*)overlay);
        } else if (streak > 0) {
            snprintf(overlay, sizeof(overlay), "wait:%d", streak);
            LCD_ShowString(10, 210, 300, 24, 12, YELLOW, (u8*)overlay);
        }

        if (streak >= 4) {
            LOG(">> DIGIT!  score=%d  box=%d,%d %dx%d\r\n",
                best_sc, bx, by, bw, bh);
            streak = 0;
        } else if (fc % 20 == 0) {
            LOG("F:%u score=%d  s=%d\r\n",
                (unsigned)fc, best_sc, streak);
        }
    }
}
