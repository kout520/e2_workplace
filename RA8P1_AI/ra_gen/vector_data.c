/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_NUM_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = rm_ethosu_isr, /* NPU IRQ (NPU IRQ) */
            [1] = gpt_counter_overflow_isr, /* GPT0 COUNTER OVERFLOW (Overflow) */
            [2] = iic_master_rxi_isr, /* IIC0 RXI (Receive data full) */
            [3] = iic_master_txi_isr, /* IIC0 TXI (Transmit data empty) */
            [4] = iic_master_tei_isr, /* IIC0 TEI (Transmit end) */
            [5] = iic_master_eri_isr, /* IIC0 ERI (Transfer error) */
            [6] = ceu_isr, /* CEU CEUI (CEU interrupt) */
            [7] = sci_b_uart_rxi_isr, /* SCI9 RXI (Receive data full) */
            [8] = sci_b_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [9] = sci_b_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [10] = sci_b_uart_eri_isr, /* SCI9 ERI (Receive error) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_NUM_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_NPU_IRQ,GROUP0), /* NPU IRQ (NPU IRQ) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_GPT0_COUNTER_OVERFLOW,GROUP1), /* GPT0 COUNTER OVERFLOW (Overflow) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_IIC0_RXI,GROUP2), /* IIC0 RXI (Receive data full) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_IIC0_TXI,GROUP3), /* IIC0 TXI (Transmit data empty) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_IIC0_TEI,GROUP4), /* IIC0 TEI (Transmit end) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_IIC0_ERI,GROUP5), /* IIC0 ERI (Transfer error) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_CEU_CEUI,GROUP6), /* CEU CEUI (CEU interrupt) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_SCI9_RXI,GROUP7), /* SCI9 RXI (Receive data full) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TXI,GROUP0), /* SCI9 TXI (Transmit data empty) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TEI,GROUP1), /* SCI9 TEI (Transmit end) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_SCI9_ERI,GROUP2), /* SCI9 ERI (Receive error) */
        };
        #endif
        #endif
