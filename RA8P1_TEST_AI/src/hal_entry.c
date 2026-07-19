/*
 * hal_entry.c - Digit "4" Detector (128x128x3 → 5 outputs)
 * Camera: OV5640 YCbCr422 QVGA → NPU Ethos-U55 → UART9 printf
 */
#include "hal_data.h"
#include "pmu_ethosu.h"
#include "stdio.h"
#include "model.h"
#include "model_io_data.h"
#include "ov5640.h"
#include "lcd.h"
#include "font.h"
#include <string.h>

#define CAM_W   320
#define CAM_H   240
#define MOD_SZ  128

/* SDRAM buffers */
__attribute__((section(".sdram"), aligned(32)))
static uint8_t g_cam[CAM_W * CAM_H * 2];    /* YCbCr422 raw */

/* ---- UART9 printf ---- */
static volatile bool g_uart_done = true;
void user_uart9_callback(uart_callback_args_t *p){
    if(p && p->event == UART_EVENT_TX_COMPLETE) g_uart_done = true;
}
int _write(int fd, char *b, int s){
    (void)fd; if(s<=0||!b)return 0;
    g_uart_done = false;
    g_uart9.p_api->write(g_uart9.p_ctrl, (uint8_t*)b, (uint32_t)s);
    while(!g_uart_done);
    return s;
}
int _close(int fd){(void)fd;return -1;}
int _lseek(int fd,int p,int o){(void)fd;(void)p;(void)o;return 0;}
int _read(int fd,char*b,int s){(void)fd;(void)b;(void)s;return -1;}
int _fstat(int fd,void*b){(void)fd;(void)b;return 0;}
int _isatty(int fd){(void)fd;return 1;}

/* ---- NPU clock cycle counter ---- */
static uint32_t GetCurrentTimeTicks(void){
    static bool init = false;
    if(!init){
        ARM_PMU_Enable();
        DCB->DEMCR |= DCB_DEMCR_TRCENA_Msk;
        ARM_PMU_CYCCNT_Reset();
        ARM_PMU_CNTR_Enable(PMU_CNTENSET_CCNTR_ENABLE_Msk);
        init = true;
    }
    return ARM_PMU_Get_CCNTR();
}

/* ---- YCbCr422 → 128x128 RGB (定点, nearest-neighbor) ---- */
static void ycbcr_to_rgb128(const uint8_t *src, uint8_t *dst)
{
    for(int oy = 0; oy < MOD_SZ; oy++){
        int sy = (oy * CAM_H) / MOD_SZ;
        if(sy >= CAM_H) sy = CAM_H - 1;
        const uint8_t *row = src + sy * CAM_W * 2;

        for(int ox = 0; ox < MOD_SZ; ox++){
            int sx = (ox * CAM_W) / MOD_SZ;
            if(sx >= CAM_W) sx = CAM_W - 1;
            int sx_even = sx & ~1;

            int U  = row[sx_even * 2 + 0];
            int Y0 = row[sx_even * 2 + 1];
            int V  = row[sx_even * 2 + 2];
            int Y1 = row[sx_even * 2 + 3];
            int Y  = (sx & 1) ? Y1 : Y0;

            int dU = U - 128, dV = V - 128;
            int R = Y + ((1436 * dV) >> 10);
            int G = Y - (( 352 * dU) >> 10) - ((731 * dV) >> 10);
            int B = Y + ((1814 * dU) >> 10);
            if(R < 0) R = 0; if(R > 255) R = 255;
            if(G < 0) G = 0; if(G > 255) G = 255;
            if(B < 0) B = 0; if(B > 255) B = 255;

            int idx = (oy * MOD_SZ + ox) * 3;
            dst[idx + 0] = (uint8_t)R;
            dst[idx + 1] = (uint8_t)G;
            dst[idx + 2] = (uint8_t)B;
        }
    }
}

void hal_entry(void)
{
    fsp_err_t st;

    /* 诊断：这行一定会在新固件中打印 */
    printf("=== RA8P1_TEST_AI v2 ===\r\n");

    /* ---- NPU Init ---- */
    st = RM_ETHOSU_Open(&g_rm_ethosu0_ctrl, &g_rm_ethosu0_cfg);
    if(st){ printf("NPU fail: %d\r\n", st); }
    else   { printf("NPU ready\r\n"); }

    /* ---- LCD Init ---- */
    LCD_Init();
    LCD_Display_Dir(LCD_DIR_Mode);
    LCD_Clear(BLACK);
    POINT_COLOR = WHITE; BACK_COLOR = BLACK;
    LCD_ShowString(0, 0, lcddev.width, 16, 16, GREEN,
                   (uint8_t*)"Digit-4 v2");

    /* ---- Camera Init ---- */
    st = ov5640_init();
    if(st){ printf("Cam fail: %d\r\n", st); return; }
    uint16_t cid; ov5640_check_chip_id(&cid);
    printf("OV5640: 0x%04X\r\n", cid);
    ov5640_set_resolution(OV5640_RES_QVGA);
    ov5640_set_output_format(OV5640_FORMAT_YUV422);
    ov5640_stream_on();

    /* ---- Model input / output pointers ---- */
    uint8_t *model_in  = GetModelInputPtr_serving_default_input_0();
    uint8_t *model_out = GetModelOutputPtr_StatefulPartitionedCall_1_0_70031();

    printf("Model: in=%d out=%d npu_arena=%d\r\n",
           model_serving_default_input_0_SIZE,
           model_StatefulPartitionedCall_1_0_SIZE,
           kArenaSize_sub_0000);
    printf("READY\r\n");

    /* ============================================================
     *                     MAIN LOOP
     * ============================================================ */
    char buf[64];
    int frame = 0;
    while(1)
    {
        /* 1. Capture frame */
        st = ov5640_capture_start(g_cam, sizeof(g_cam));
        if(st){ R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS); continue; }
        st = ov5640_capture_wait(500);
        if(st) continue;

        /* 2. Preprocess: YCbCr422 → 128x128 RGB */
        ycbcr_to_rgb128(g_cam, model_in);

        /* 3. NPU inference */
        uint32_t t0 = GetCurrentTimeTicks();
        RunModel(false);
        uint32_t cycles = GetCurrentTimeTicks() - t0;

        /* 4. Decode output: float = uint8 * (1/256) */
        float cx   = model_out[0] * 0.00390625f;
        float cy   = model_out[1] * 0.00390625f;
        float w    = model_out[2] * 0.00390625f;
        float h    = model_out[3] * 0.00390625f;
        float conf = model_out[4] * 0.00390625f;

        int px = (int)(cx * CAM_W);
        int py = (int)(cy * CAM_H);
        int pw = (int)(w  * CAM_W);
        int ph = (int)(h  * CAM_H);

        /* 5. Serial output */
        if(conf > 0.5f)
            printf("DETECT: cx=%d cy=%d w=%d h=%d conf=%.2f\r\n",
                   px, py, pw, ph, (double)conf);
        else
            printf("NO_DETECT conf=%.2f\r\n", (double)conf);

        /* 6. LCD: bounding box + info */
        snprintf(buf, sizeof(buf), "F:%d cyc:%lu", frame, (unsigned long)cycles);
        LCD_Fill(0, 40, lcddev.width, 55, BLACK);
        LCD_ShowString(0, 40, lcddev.width, 14, 12, WHITE, (uint8_t*)buf);

        if(conf > 0.5f){
            int x1 = (int)((cx - w/2) * lcddev.width);
            int y1 = (int)((cy - h/2) * lcddev.height);
            int x2 = (int)((cx + w/2) * lcddev.width);
            int y2 = (int)((cy + h/2) * lcddev.height);
            if(x1<0)x1=0; if(y1<0)y1=0;
            if(x2>=(int)lcddev.width) x2=lcddev.width-1;
            if(y2>=(int)lcddev.height)y2=lcddev.height-1;
            LCD_DrawLine(x1,y1,x2,y1,RED);
            LCD_DrawLine(x2,y1,x2,y2,RED);
            LCD_DrawLine(x2,y2,x1,y2,RED);
            LCD_DrawLine(x1,y2,x1,y1,RED);
            snprintf(buf, sizeof(buf), "4:%.2f", (double)conf);
            LCD_ShowString(x1, (y1>10)?y1-10:0, 60, 12, 12, RED, (uint8_t*)buf);
        }

        frame++;
    }

    RM_ETHOSU_Close(&g_rm_ethosu0_ctrl);
}
