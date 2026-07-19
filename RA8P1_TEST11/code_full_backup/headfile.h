/*
 * headfile.h
 *
 *  Created on: 2026年5月16日
 *      Author: kout
 */

#ifndef HEADFILE_H_
#define HEADFILE_H_

#include <stdint.h>
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
#include "hal_data.h"



#include "tjc_usart_hmi.h"
#include "key.h"
#include "lcd.h"
#include "AS608pro.h"
#include "pn532.h"

/* ===== 跨模块共享变量声明 ===== */
extern volatile int motor_flag;                             // 开锁标志

/* ===== 跨模块函数声明 ===== */
void uart2_send_value(int val);                             // USART2 发送(ESP32)
void uart8_send_value(int val);                             // USART8 发送(舵机/摄像头)
void uart9_send_value(int val);                             // USART9 发送(调试)
void dakai_clock_display(void);                             // 时钟页面显示


#endif /* HEADFILE_H_ */
