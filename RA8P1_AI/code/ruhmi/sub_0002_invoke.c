#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "common_data.h"

#include "sub_0002_tensors.h"
#include "sub_0002_command_stream.h"
#include "sub_0002_model_data.h"

#include "sub_0002_invoke.h"

// Include Ethos-U driver headers (Assumed to be available)
#include "ethosu_driver.h"

// Define arenas with allocation and 16-byte alignment
__attribute__((aligned(32), section(".sdram_noinit"))) uint8_t sub_0002_arena[17088];
// Fast scratch arena not used for Ethos-U55
//  We will not create it for now and reuse the address of the other arena
// __attribute__((aligned(16))) static uint8_t sub_0002_fast_scratch[17088];
uint8_t* sub_0002_fast_scratch = sub_0002_arena;

int sub_0002_invoke(bool clean_outputs) {
  // Initialize base addresses and sizes
  uint64_t base_addrs[21] = {0};
  size_t base_addrs_size[21] = {0};
  int num_base_addrs = 21;

  // Variables for command stream
  uint8_t* cms_data = NULL;
  int cms_size = 0;

  // Prepare base_addrs and base_addrs_size arrays
  // Buffer sub_0002_model with size 2672 and address: 4294967295
  base_addrs[0] = (uint64_t)(uintptr_t)sub_0002_model_data;
  base_addrs_size[0] = sub_0002_model_data_size;
  // Buffer sub_0002_arena with size 17088 and address: 0
  base_addrs[1] = (uint64_t)(uintptr_t) (sub_0002_arena+0);
  base_addrs_size[1] = 17088;

  // Buffer sub_0002_fast_scratch with size 17088 and address: 0
  base_addrs[2] = (uint64_t)(uintptr_t) (sub_0002_arena+0);
  base_addrs_size[2] = 17088;

  // Buffer input_tensor_0 with size 3456 and address: 13632
  base_addrs[3] = (uint64_t)(uintptr_t) (sub_0002_arena+13632);
  base_addrs_size[3] = 3456;

  // Buffer input_tensor_1 with size 216 and address: 0
  base_addrs[4] = (uint64_t)(uintptr_t) (sub_0002_arena+0);
  base_addrs_size[4] = 216;

  // Buffer input_tensor_2 with size 216 and address: 13408
  base_addrs[5] = (uint64_t)(uintptr_t) (sub_0002_arena+13408);
  base_addrs_size[5] = 216;

  // Buffer input_tensor_3 with size 864 and address: 224
  base_addrs[6] = (uint64_t)(uintptr_t) (sub_0002_arena+224);
  base_addrs_size[6] = 864;

  // Buffer input_tensor_4 with size 864 and address: 8000
  base_addrs[7] = (uint64_t)(uintptr_t) (sub_0002_arena+8000);
  base_addrs_size[7] = 864;

  // Buffer input_tensor_5 with size 3456 and address: 4320
  base_addrs[8] = (uint64_t)(uintptr_t) (sub_0002_arena+4320);
  base_addrs_size[8] = 3456;

  // Buffer input_tensor_6 with size 216 and address: 7776
  base_addrs[9] = (uint64_t)(uintptr_t) (sub_0002_arena+7776);
  base_addrs_size[9] = 216;

  // Buffer input_tensor_7 with size 864 and address: 3456
  base_addrs[10] = (uint64_t)(uintptr_t) (sub_0002_arena+3456);
  base_addrs_size[10] = 864;

  // Buffer input_tensor_8 with size 3456 and address: 9088
  base_addrs[11] = (uint64_t)(uintptr_t) (sub_0002_arena+9088);
  base_addrs_size[11] = 3456;

  // Buffer output_tensor_0 with size 3456 and address: 13632
  if (clean_outputs) {
    memset(sub_0002_arena + 13632, 0, 3456);
  }
  base_addrs[12] = (uint64_t)(uintptr_t) (sub_0002_arena+13632);
  base_addrs_size[12] = 3456;

  // Buffer output_tensor_1 with size 216 and address: 8864
  if (clean_outputs) {
    memset(sub_0002_arena + 8864, 0, 216);
  }
  base_addrs[13] = (uint64_t)(uintptr_t) (sub_0002_arena+8864);
  base_addrs_size[13] = 216;

  // Buffer output_tensor_2 with size 216 and address: 13408
  if (clean_outputs) {
    memset(sub_0002_arena + 13408, 0, 216);
  }
  base_addrs[14] = (uint64_t)(uintptr_t) (sub_0002_arena+13408);
  base_addrs_size[14] = 216;

  // Buffer output_tensor_3 with size 864 and address: 12544
  if (clean_outputs) {
    memset(sub_0002_arena + 12544, 0, 864);
  }
  base_addrs[15] = (uint64_t)(uintptr_t) (sub_0002_arena+12544);
  base_addrs_size[15] = 864;

  // Buffer output_tensor_4 with size 864 and address: 8000
  if (clean_outputs) {
    memset(sub_0002_arena + 8000, 0, 864);
  }
  base_addrs[16] = (uint64_t)(uintptr_t) (sub_0002_arena+8000);
  base_addrs_size[16] = 864;

  // Buffer output_tensor_5 with size 3456 and address: 0
  if (clean_outputs) {
    memset(sub_0002_arena + 0, 0, 3456);
  }
  base_addrs[17] = (uint64_t)(uintptr_t) (sub_0002_arena+0);
  base_addrs_size[17] = 3456;

  // Buffer output_tensor_6 with size 216 and address: 6912
  if (clean_outputs) {
    memset(sub_0002_arena + 6912, 0, 216);
  }
  base_addrs[18] = (uint64_t)(uintptr_t) (sub_0002_arena+6912);
  base_addrs_size[18] = 216;

  // Buffer output_tensor_7 with size 864 and address: 7136
  if (clean_outputs) {
    memset(sub_0002_arena + 7136, 0, 864);
  }
  base_addrs[19] = (uint64_t)(uintptr_t) (sub_0002_arena+7136);
  base_addrs_size[19] = 864;

  // Buffer output_tensor_8 with size 3456 and address: 3456
  if (clean_outputs) {
    memset(sub_0002_arena + 3456, 0, 3456);
  }
  base_addrs[20] = (uint64_t)(uintptr_t) (sub_0002_arena+3456);
  base_addrs_size[20] = 3456;

  // Command stream data
  cms_data = (uint8_t*)sub_0002_command_stream;
  cms_size = (int) sub_0002_command_stream_size;

  // Invoke the Ethos-U driver
  if (num_base_addrs > 8) {
    num_base_addrs = 8;
  }
  int result = ethosu_invoke_v3(&g_ethosu0, cms_data, cms_size, base_addrs, base_addrs_size, num_base_addrs, NULL);

  if (result == -1) {
    // Ethos-U invocation failed
    return -1;
  }

  return 0;
}
