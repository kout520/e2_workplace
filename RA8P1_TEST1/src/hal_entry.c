#include "hal_data.h"
#include "headfile.h"
// #include "ov5640.h"
// #include "tjc_usart_hmi.h"
// #include "AS608pro.h"
// #include "pn532.h"

/* ===== 1ms 定时器回调 ===== */
void timer_1ms_callback(timer_callback_args_t *p_args)
{
    if (TIMER_EVENT_CYCLE_END == p_args->event)
    {
        g_system_tick();
    }
}

#if (1 == BSP_MULTICORE_PROJECT) && BSP_TZ_SECURE_BUILD
bsp_ipc_semaphore_handle_t g_core_start_semaphore = { .semaphore_num = 0 };
#endif

volatile bool g_uart9_tx_done = true;
volatile int  motor_flag = 0;

void user_uart9_callback(uart_callback_args_t * p_args)
{
    if (NULL == p_args) { return; }
    if (UART_EVENT_TX_COMPLETE == p_args->event)
        g_uart9_tx_done = true;
}

int _write(int fd, char * pBuffer, int size)
{
    FSP_PARAMETER_NOT_USED(fd);
    if ((size <= 0) || (NULL == pBuffer)) { return 0; }
    g_uart9_tx_done = false;
    g_uart9.p_api->write(g_uart9.p_ctrl, (uint8_t *)pBuffer, (uint32_t)size);
    while (!g_uart9_tx_done) { ; }
    return size;
}

/* ==================================================================
 *              录音导出功能
 * ================================================================== */
#define RECORD_SAMPLE_RATE   16000   /* 实际采样率取决于 GPT1 配置 */
#define RECORD_SECS          4
#define RECORD_SAMPLES       (RECORD_SAMPLE_RATE * RECORD_SECS)  /* 64000 */
#define RECORD_BUF_SIZE      (RECORD_SAMPLES * 2)               /* 128000 bytes */

/* 录音缓冲区: 放在 SDRAM (够大) */
static int16_t g_record_buf[RECORD_SAMPLES]
    BSP_ALIGN_VARIABLE(32) BSP_PLACE_IN_SECTION(".sdram_noinit");

static volatile bool g_record_trigger = false;

/** 检查串口是否有录音指令 'r' */
static void check_serial_trigger(void)
{
    uint8_t ch;
    fsp_err_t err = g_uart9.p_api->read(g_uart9.p_ctrl, &ch, 1);
    if (FSP_SUCCESS == err && ch == 'r') {
        g_record_trigger = true;
    }
}

/** 录音: 采集 RECORD_SAMPLES 个采样点 */
static void record_start(void)
{
    uint32_t collected = 0;
    int      debug_printed = 0;
    printf("REC START (%d samples, %d secs)...\r\n", RECORD_SAMPLES, RECORD_SECS);

    /* 在开始录音前清掉旧缓冲 */
    while (inmp441_get_buffer() != NULL) { ; }

    while (collected < RECORD_SAMPLES)
    {
        int16_t *buf = inmp441_get_buffer();  /* 512 samples */
        if (buf != NULL)
        {
            /* 首次数据: 打印前8个采样值验证 */
            if (debug_printed < 2) {
                printf("DEBUG samples: %d %d %d %d %d %d %d %d\r\n",
                       buf[0], buf[1], buf[2], buf[3],
                       buf[4], buf[5], buf[6], buf[7]);
                debug_printed++;
            }

            uint32_t remain = RECORD_SAMPLES - collected;
            uint32_t copy = (remain > INMP441_SAMPLES_PER_BUF)
                          ? INMP441_SAMPLES_PER_BUF : remain;
            memcpy(&g_record_buf[collected], buf, copy * sizeof(int16_t));
            collected += copy;

            /* 进度 */
            if (0 == (collected % (RECORD_SAMPLE_RATE / 4)))  /* 每 0.25s */
                printf("  %lu / %lu\r\n", collected, (uint32_t)RECORD_SAMPLES);
        }
    }

    printf("REC DONE (%lu samples)\r\n", collected);
}

/** 导出: 将录音数据通过串口发出 (二进制协议) */
static void record_export(void)
{
    uint32_t total_bytes = RECORD_SAMPLES * sizeof(int16_t);  /* 64000 */

    /* 同步字: 0xAA55AA55 (文本中不会出现) */
    uint32_t sync  = 0xAA55AA55;
    uint32_t count = RECORD_SAMPLES;

    printf("EXPORT %lu samples...\r\n", count);

    /* 1. 发同步字 */
    g_uart9_tx_done = false;
    g_uart9.p_api->write(g_uart9.p_ctrl, (uint8_t *)&sync, 4);
    while (!g_uart9_tx_done) { ; }

    /* 2. 发采样数 (4 字节 LE) */
    g_uart9_tx_done = false;
    g_uart9.p_api->write(g_uart9.p_ctrl, (uint8_t *)&count, 4);
    while (!g_uart9_tx_done) { ; }

    /* 3. 发 PCM 数据 */
    #define CHUNK_SIZE  512
    uint8_t *p = (uint8_t *)g_record_buf;
    uint32_t sent = 0;

    while (sent < total_bytes)
    {
        uint32_t chunk = total_bytes - sent;
        if (chunk > CHUNK_SIZE) chunk = CHUNK_SIZE;

        g_uart9_tx_done = false;
        g_uart9.p_api->write(g_uart9.p_ctrl, p + sent, chunk);
        while (!g_uart9_tx_done) { ; }

        sent += chunk;
    }

    printf("DONE\r\n");
}

void hal_entry(void)
{
    fsp_err_t err;

    /* --- 0. 调试串口 --- */
    g_uart9.p_api->open(g_uart9.p_ctrl, g_uart9.p_cfg);

    /* --- 1ms 定时器 --- */
    g_timer_1ms.p_api->open(g_timer_1ms.p_ctrl, g_timer_1ms.p_cfg);
    g_timer_1ms.p_api->start(g_timer_1ms.p_ctrl);

    /* --- INMP441 麦克风 --- */
    err = inmp441_init();
    if (FSP_SUCCESS != err) {
        printf("INMP441 init fail: %d\r\n", err);
        while(1);
    }

    printf("\r\n========================================\r\n");
    printf("  INMP441 录音导出工具\r\n");
    printf("========================================\r\n");
    printf("  发送任意字符 → 开始录 %d 秒\r\n", RECORD_SECS);
    printf("  录音完成 → 自动通过串口导出\r\n");
    printf("========================================\r\n\r\n");

    /* ================================================================
     *                        主 循 环
     * ================================================================ */
    while (1)
    {
        /* 持续取走音频缓冲 (维持 DMA 循环) */
        if (inmp441_get_buffer() != NULL) {
            /* 正常循环中丢弃音频数据, 只有录音时才收集 */
        }

        /* 检查串口触发 */
        check_serial_trigger();

        /* 触发录音 (串口收到任意字符) */
        if (g_record_trigger)
        {
            g_record_trigger = false;

            /* 录音 */
            record_start();

            /* 导出 */
            record_export();

            printf("\r\n发送任意字符开始下一次录音...\r\n");
        }

        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);
    }
}

#if (0 == _RA_CORE) && (1 == BSP_MULTICORE_PROJECT) && !BSP_TZ_NONSECURE_BUILD
#if BSP_TZ_SECURE_BUILD
    R_BSP_IpcSemaphoreTake(&g_core_start_semaphore);
#endif
    R_BSP_SecondaryCoreStart();
#if BSP_TZ_SECURE_BUILD
    while(FSP_ERR_IN_USE == R_BSP_IpcSemaphoreTake(&g_core_start_semaphore)) { ; }
#endif
#endif

#if (1 == _RA_CORE) && (1 == BSP_MULTICORE_PROJECT) && BSP_TZ_SECURE_BUILD
    R_BSP_IpcSemaphoreGive(&g_core_start_semaphore);
#endif

#if BSP_TZ_SECURE_BUILD
    R_BSP_NonSecureEnter();
#endif

#if BSP_TZ_SECURE_BUILD
FSP_CPP_HEADER
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable () { }
FSP_CPP_FOOTER
#endif
