/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hal_data.h"

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

#if BSP_CFG_OSPI_B_STARTUP_ENABLED
/* OSPI B startup function - opens OSPI HAL driver for XIP mode */
static fsp_err_t ospi_b_startup_fn(void){
    extern const spi_flash_instance_t g_ospi0;
    return g_ospi0.p_api->open(g_ospi0.p_ctrl, g_ospi0.p_cfg);
}
#endif

void R_BSP_WarmStart (bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0
        R_FACI_LP->DFLCTL = 1U;
#endif
    }

#if BSP_CFG_OSPI_B_STARTUP_ENABLED
    if (BSP_WARM_START_POST_CLOCK == event)
    {
        R_BSP_OspiBInit(ospi_b_startup_fn, true);
    }
#endif

    if (BSP_WARM_START_POST_C == event)
    {
        R_IOPORT_Open(&IOPORT_CFG_CTRL, &IOPORT_CFG_NAME);
#if BSP_CFG_SDRAM_ENABLED
        R_BSP_SdramInit(true);
#endif
    }
}
