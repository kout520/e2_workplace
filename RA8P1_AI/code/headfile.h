/*
 * headfile.h — RA8P1_AI 公共头文件
 *   Ethos-U55 + TFLM 推理工程
 */

#ifndef HEADFILE_H_
#define HEADFILE_H_

#include <stdint.h>
#include "hal_data.h"
#include "bsp_api.h"
#include "common_data.h"
#include "r_gpt.h"
#include "r_timer_api.h"
#include "r_iic_master.h"
#include "r_i2c_master_api.h"
#include "r_capture_api.h"
#include "r_ceu.h"
#include "r_sci_b_uart.h"
#include "r_uart_api.h"

/* ===== 驱动模块 ===== */
#include "lcd.h"
#include "ov5640.h"

/* ===== TFLM + Ethos-U55 ===== */
#include "rm_ethosu_api.h"
#include "rm_ethosu.h"
#include "ethosu_driver.h"
#include "arm_math.h"
#include "arm_nnfunctions.h"

/* ===== 跨模块变量 ===== */
extern volatile int motor_flag;

/* ===== 辅助函数 ===== */
void uart9_send_value(int val);

#endif /* HEADFILE_H_ */
