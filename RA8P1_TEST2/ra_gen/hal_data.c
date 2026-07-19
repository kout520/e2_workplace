/* generated HAL source file - do not edit */
#include "hal_data.h"
ceu_instance_ctrl_t g_ceu_qvga_ctrl;
const ceu_extended_cfg_t g_ceu_qvga_extended_cfg =
{ .capture_format = CEU_CAPTURE_FORMAT_DATA_SYNCHRONOUS,
  .input_order = CEU_INPUT_ORDER_CB0Y0CR0Y1,
  .output_format = CEU_OUTPUT_FORMAT_YCBCR422,
  .data_bus_width = CEU_DATA_BUS_SIZE_8_BIT,
  .edge_info.dsel = 0,
  .edge_info.hdsel = 0,
  .edge_info.vdsel = 0,
  .hsync_polarity = CEU_HSYNC_POLARITY_HIGH,
  .vsync_polarity = CEU_VSYNC_POLARITY_HIGH,
  .byte_swapping =
  { .swap_8bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x00 & 0x01, .swap_16bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x01
          & 0x01,
    .swap_32bit_units = (0x1 | 0x2 | 0x4 | 0x0) >> 0x02 & 0x01, },
  .burst_mode = CEU_BURST_TRANSFER_MODE_X8,
  .scale_down_factor = 0x0U,
  .h_output_size = 0,
  .v_output_size = 0,
  .image_area_size = 320 * 240 * 2,
  .interrupts_enabled = 0 | R_CEU_CEIER_CPEIE_Msk | 0 | R_CEU_CEIER_VDIE_Msk | R_CEU_CEIER_CDTOFIE_Msk | 0 | 0
          | R_CEU_CEIER_VBPIE_Msk | R_CEU_CEIER_NHDIE_Msk | R_CEU_CEIER_NVDIE_Msk,
  .ceu_ipl = (12),
  .ceu_irq = VECTOR_NUMBER_CEU_CEUI, };

const capture_cfg_t g_ceu_qvga_cfg =
{ .x_capture_pixels = 320,
  .y_capture_pixels = 240,
  .x_capture_start_pixel = 0,
  .y_capture_start_pixel = 0,
  .bytes_per_pixel = 2,
  .p_callback = g_ceu_callback,
  .p_context = (void*) NULL,
  .p_extend = &g_ceu_qvga_extended_cfg, };

const capture_instance_t g_ceu_qvga =
{ .p_ctrl = &g_ceu_qvga_ctrl, .p_cfg = &g_ceu_qvga_cfg, .p_api = &g_ceu_on_capture, };
void g_hal_init(void)
{
    g_common_init ();
}
