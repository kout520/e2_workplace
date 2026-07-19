/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_NUM_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_b_uart_rxi_isr, /* SCI9 RXI (Receive data full) */
            [1] = sci_b_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [2] = sci_b_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [3] = sci_b_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [4] = gpt_counter_overflow_isr, /* GPT0 COUNTER OVERFLOW (Overflow) */
            [5] = r_icu_isr, /* ICU IRQ13 (External pin interrupt 13) */
            [6] = r_icu_isr, /* ICU IRQ12 (External pin interrupt 12) */
            [7] = rm_ethosu_isr, /* NPU IRQ (NPU IRQ) */
            [8] = ceu_isr, /* CEU CEUI (CEU interrupt) */
            [9] = iic_master_rxi_isr, /* IIC0 RXI (Receive data full) */
            [10] = iic_master_txi_isr, /* IIC0 TXI (Transmit data empty) */
            [11] = iic_master_tei_isr, /* IIC0 TEI (Transmit end) */
            [12] = iic_master_eri_isr, /* IIC0 ERI (Transfer error) */
            [13] = drw_int_isr, /* DRW INT (DRW interrupt) */
            [14] = glcdc_line_detect_isr, /* GLCDC LINE DETECT (Specified line) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_NUM_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_SCI9_RXI,GROUP0), /* SCI9 RXI (Receive data full) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TXI,GROUP1), /* SCI9 TXI (Transmit data empty) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TEI,GROUP2), /* SCI9 TEI (Transmit end) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_SCI9_ERI,GROUP3), /* SCI9 ERI (Receive error) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_GPT0_COUNTER_OVERFLOW,GROUP4), /* GPT0 COUNTER OVERFLOW (Overflow) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ13,GROUP5), /* ICU IRQ13 (External pin interrupt 13) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ12,GROUP6), /* ICU IRQ12 (External pin interrupt 12) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_NPU_IRQ,GROUP7), /* NPU IRQ (NPU IRQ) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_CEU_CEUI,GROUP0), /* CEU CEUI (CEU interrupt) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_IIC0_RXI,GROUP1), /* IIC0 RXI (Receive data full) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_IIC0_TXI,GROUP2), /* IIC0 TXI (Transmit data empty) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_IIC0_TEI,GROUP3), /* IIC0 TEI (Transmit end) */
            [12] = BSP_PRV_VECT_ENUM(EVENT_IIC0_ERI,GROUP4), /* IIC0 ERI (Transfer error) */
            [13] = BSP_PRV_VECT_ENUM(EVENT_DRW_INT,GROUP5), /* DRW INT (DRW interrupt) */
            [14] = BSP_PRV_VECT_ENUM(EVENT_GLCDC_LINE_DETECT,GROUP6), /* GLCDC LINE DETECT (Specified line) */
        };
        #endif
        #endif
