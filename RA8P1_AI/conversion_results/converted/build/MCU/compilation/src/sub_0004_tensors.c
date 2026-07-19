#include "sub_0004_tensors.h"

const TensorInfo sub_0004_tensors[] = {
  { "_split_1_command_stream", 1, 488, "COMMAND_STREAM", 0xffffffff },
  { "_split_1_flash", 2, 0, "MODEL", 0xffffffff },
  { "_split_1_scratch", 3, 49904, "ARENA", 0x0 },
  { "_split_1_scratch_fast", 4, 49904, "FAST_SCRATCH", 0x0 },
  { "functional_15_1_tf_detect_1_Reshape_1_70406", 5, 10368, "INPUT_TENSOR", 0x9a70 },
  { "functional_15_1_tf_detect_1_Reshape_3_70388", 6, 2592, "INPUT_TENSOR", 0x9050 },
  { "functional_15_1_tf_detect_1_Reshape_5_70370", 7, 648, "INPUT_TENSOR", 0x8dc0 },
  { "StatefulPartitionedCall_1_0_70408", 0, 13608, "OUTPUT_TENSOR", 0x8dc0 },
};

const size_t sub_0004_tensors_count = sizeof(sub_0004_tensors) / sizeof(sub_0004_tensors[0]);

// Addresses for each input and output buffer inside of the arena
const uint32_t sub_0004_address_functional_15_1_tf_detect_1_Reshape_1_70406 = 0x9a70;
const uint32_t sub_0004_address_functional_15_1_tf_detect_1_Reshape_3_70388 = 0x9050;
const uint32_t sub_0004_address_functional_15_1_tf_detect_1_Reshape_5_70370 = 0x8dc0;
const uint32_t sub_0004_address_StatefulPartitionedCall_1_0_70408 = 0x8dc0;

