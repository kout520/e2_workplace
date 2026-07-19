#include "sub_0000_tensors.h"

const TensorInfo sub_0000_tensors[] = {
  { "_split_1_command_stream", 1, 2904, "COMMAND_STREAM", 0xffffffff },
  { "_split_1_flash", 2, 356016, "MODEL", 0xffffffff },
  { "_split_1_scratch", 3, 37632, "ARENA", 0x0 },
  { "_split_1_scratch_fast", 4, 37632, "FAST_SCRATCH", 0x0 },
  { "serving_default_input_1_0", 5, 784, "INPUT_TENSOR", 0x3100 },
  { "StatefulPartitionedCall_0_70018", 0, 10, "OUTPUT_TENSOR", 0x10 },
};

const size_t sub_0000_tensors_count = sizeof(sub_0000_tensors) / sizeof(sub_0000_tensors[0]);

// Addresses for each input and output buffer inside of the arena
const uint32_t sub_0000_address_serving_default_input_1_0 = 0x3100;
const uint32_t sub_0000_address_StatefulPartitionedCall_0_70018 = 0x10;

