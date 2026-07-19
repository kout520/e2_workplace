/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_capture_api.h"
#include "r_ceu.h"
FSP_HEADER
/* CEU on CAPTURE instance */
extern const capture_instance_t g_ceu_qvga;
/* Access the CEU instance using these structures when calling API functions directly (::p_api is not used). */
extern ceu_instance_ctrl_t g_ceu_qvga_ctrl;
extern const capture_cfg_t g_ceu_qvga_cfg;
#ifndef g_ceu_callback
void g_ceu_callback(capture_callback_args_t *p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
