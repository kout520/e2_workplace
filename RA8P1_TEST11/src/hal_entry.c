#include "hal_data.h"
#include "headfile.h"
#include "ov5640.h"
#include "model.h"
#include "model_io_data.h"
#include "pmu_ethosu.h"

#define CAM_W   320
#define CAM_H   240
#define MOD_SZ  128

/* 图像缓冲区 */
__attribute__((section(".sdram"), aligned(32)))
static uint8_t g_cam[CAM_W * CAM_H * 2];

/* ---- printf 重定向 (UART9) ---- */
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

/* ---- YCbCr422 → 128x128 RGB (定点, 最近邻) ---- */
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
            int U = row[sx_even*2+0], Y0 = row[sx_even*2+1],
                V = row[sx_even*2+2], Y1 = row[sx_even*2+3];
            int Y = (sx & 1) ? Y1 : Y0;
            int dU = U - 128, dV = V - 128;
            int R = Y + ((1436*dV)>>10);
            int G = Y - ((352*dU)>>10) - ((731*dV)>>10);
            int B = Y + ((1814*dU)>>10);
            if(R<0)R=0;if(R>255)R=255;
            if(G<0)G=0;if(G>255)G=255;
            if(B<0)B=0;if(B>255)B=255;
            int idx = (oy*MOD_SZ + ox)*3;
            dst[idx+0]=(uint8_t)R; dst[idx+1]=(uint8_t)G; dst[idx+2]=(uint8_t)B;
        }
    }
}

void hal_entry(void)
{
    printf("=== AI START ===\r\n");

    /* NPU */
    int s = RM_ETHOSU_Open(&g_rm_ethosu0_ctrl, &g_rm_ethosu0_cfg);
    if(s) printf("NPU fail:%d\r\n", s);
    else  printf("NPU OK\r\n");

    /* 摄像头 */
    s = ov5640_init();
    if(s){ printf("Cam fail:%d\r\n", s); return; }
    uint16_t cid; ov5640_check_chip_id(&cid);
    printf("Cam:0x%04X\r\n", cid);
    ov5640_set_resolution(OV5640_RES_QVGA);
    ov5640_set_output_format(OV5640_FORMAT_YUV422);
    ov5640_stream_on();

    uint8_t *in  = GetModelInputPtr_serving_default_input_0();
    uint8_t *out = GetModelOutputPtr_StatefulPartitionedCall_1_0_70031();
    printf("READY in=%d out=%d\r\n",
           model_serving_default_input_0_SIZE,
           model_StatefulPartitionedCall_1_0_SIZE);

    /* 主循环 */
    while(1){
        s = ov5640_capture_start(g_cam, sizeof(g_cam));
        if(s){ R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS); continue; }
        s = ov5640_capture_wait(500);
        if(s) continue;

        ycbcr_to_rgb128(g_cam, in);
        RunModel(false);

        float cx=out[0]*0.00390625f, cy=out[1]*0.00390625f,
              w =out[2]*0.00390625f, h =out[3]*0.00390625f,
              cf=out[4]*0.00390625f;

        if(cf > 0.5f)
            printf("DETECT cx=%d cy=%d w=%d h=%d cf=%.2f\r\n",
                   (int)(cx*CAM_W),(int)(cy*CAM_H),
                   (int)(w*CAM_W),(int)(h*CAM_H), (double)cf);
        else
            printf("NO cf=%.2f\r\n", (double)cf);
    }
}
