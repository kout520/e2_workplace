/*
 * This file is developed by EdgeCortix Inc. to be used with certain Renesas Electronics Hardware only.
 *
 * Copyright © 2025 EdgeCortix Inc. Licensed to Renesas Electronics Corporation with the
 * right to sublicense under the Apache License, Version 2.0.
 *
 * This file also includes source code originally developed by the Renesas Electronics Corporation.
 * The Renesas disclaimer below applies to any Renesas-originated portions for usage of the code.
 *
 * The Renesas Electronics Corporation
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED 'AS IS' AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
 * SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Changed from original python code to C source code.
 * Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
 *
 * This file also includes source codes originally developed by the TensorFlow Authors which were distributed under the following conditions.
 *
 * The TensorFlow Authors
 * Copyright 2023 The Apache Software Foundation
 *
 * This product includes software developed at
 * The Apache Software Foundation (http://www.apache.org/).
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "model.h"

// CPU compute declarations
#include "sub_0000_invoke.h"
#include "compute_sub_0001.h"
#include "sub_0002_invoke.h"
#include "compute_sub_0003.h"
#include "sub_0004_invoke.h"

// Buffers for CPU units
uint8_t buf_serving_default_keras_tensor_121_0[110592];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_11_70373[864];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_13_70379[864];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_14_70384[864];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_19_70355[216];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_21_70361[216];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_22_70366[216];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_3_70391[3456];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_5_70397[3456];
int8_t buf_functional_15_1_tf_detect_1_strided_slice_6_70402[3456];
int8_t buf_functional_15_1_tf_detect_1_Reshape_1_70406[10368];
int8_t buf_functional_15_1_tf_detect_1_Reshape_3_70388[2592];
int8_t buf_functional_15_1_tf_detect_1_Reshape_5_70370[648];

// Arenas for CPU units
uint8_t compute_arena_sub_0001[kBufferSize_sub_0001];
uint8_t compute_arena_sub_0003[kBufferSize_sub_0003];

  // Model input pointers
uint8_t* GetModelInputPtr_serving_default_keras_tensor_121_0() {
  return (uint8_t*) (sub_0000_arena + sub_0000_address_serving_default_keras_tensor_121_0);
}


  // Model output pointers
uint8_t* GetModelOutputPtr_StatefulPartitionedCall_1_0_70408() {
  return (uint8_t*) (sub_0004_arena + sub_0004_address_StatefulPartitionedCall_1_0_70408);
}


void RunModel(bool clean_outputs) {
  // Buffers for NPU units
  int8_t* buf_functional_15_1_tf_detect_1_Reshape_2_70372 = (int8_t*) (sub_0000_arena + sub_0000_address_functional_15_1_tf_detect_1_Reshape_2_70372);
  int8_t* buf_functional_15_1_tf_detect_1_Reshape_4_70354 = (int8_t*) (sub_0000_arena + sub_0000_address_functional_15_1_tf_detect_1_Reshape_4_70354);
  int8_t* buf_functional_15_1_tf_detect_1_Reshape_70390 = (int8_t*) (sub_0000_arena + sub_0000_address_functional_15_1_tf_detect_1_Reshape_70390);
  int8_t* buf_functional_15_1_tf_detect_1_Sigmoid_21_70404 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_Sigmoid_21_70404);
  int8_t* buf_functional_15_1_tf_detect_1_Sigmoid_51_70386 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_Sigmoid_51_70386);
  int8_t* buf_functional_15_1_tf_detect_1_Sigmoid_81_70368 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_Sigmoid_81_70368);
  int8_t* buf_functional_15_1_tf_detect_1_truediv_1_70401 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_truediv_1_70401);
  int8_t* buf_functional_15_1_tf_detect_1_truediv_2_70378 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_truediv_2_70378);
  int8_t* buf_functional_15_1_tf_detect_1_truediv_3_70383 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_truediv_3_70383);
  int8_t* buf_functional_15_1_tf_detect_1_truediv_4_70360 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_truediv_4_70360);
  int8_t* buf_functional_15_1_tf_detect_1_truediv_5_70365 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_truediv_5_70365);
  int8_t* buf_functional_15_1_tf_detect_1_truediv_70396 = (int8_t*) (sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_truediv_70396);
  uint8_t* buf_StatefulPartitionedCall_1_0_70408 = (uint8_t*) (sub_0004_arena + sub_0004_address_StatefulPartitionedCall_1_0_70408);

  // NPU Unit
  sub_0000_invoke(clean_outputs);

  // CPU Unit
  compute_sub_0001(compute_arena_sub_0001, buf_functional_15_1_tf_detect_1_Reshape_2_70372, buf_functional_15_1_tf_detect_1_Reshape_4_70354, buf_functional_15_1_tf_detect_1_Reshape_70390, buf_functional_15_1_tf_detect_1_strided_slice_11_70373, buf_functional_15_1_tf_detect_1_strided_slice_13_70379, buf_functional_15_1_tf_detect_1_strided_slice_14_70384, buf_functional_15_1_tf_detect_1_strided_slice_19_70355, buf_functional_15_1_tf_detect_1_strided_slice_21_70361, buf_functional_15_1_tf_detect_1_strided_slice_22_70366, buf_functional_15_1_tf_detect_1_strided_slice_3_70391, buf_functional_15_1_tf_detect_1_strided_slice_5_70397, buf_functional_15_1_tf_detect_1_strided_slice_6_70402  );

  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_11_70373), buf_functional_15_1_tf_detect_1_strided_slice_11_70373, 864);
  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_13_70379), buf_functional_15_1_tf_detect_1_strided_slice_13_70379, 864);
  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_14_70384), buf_functional_15_1_tf_detect_1_strided_slice_14_70384, 864);
  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_19_70355), buf_functional_15_1_tf_detect_1_strided_slice_19_70355, 216);
  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_21_70361), buf_functional_15_1_tf_detect_1_strided_slice_21_70361, 216);
  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_22_70366), buf_functional_15_1_tf_detect_1_strided_slice_22_70366, 216);
  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_3_70391), buf_functional_15_1_tf_detect_1_strided_slice_3_70391, 3456);
  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_5_70397), buf_functional_15_1_tf_detect_1_strided_slice_5_70397, 3456);
  memcpy((sub_0002_arena + sub_0002_address_functional_15_1_tf_detect_1_strided_slice_6_70402), buf_functional_15_1_tf_detect_1_strided_slice_6_70402, 3456);
  // NPU Unit
  sub_0002_invoke(clean_outputs);

  // CPU Unit
  compute_sub_0003(compute_arena_sub_0003, buf_functional_15_1_tf_detect_1_Sigmoid_21_70404, buf_functional_15_1_tf_detect_1_Sigmoid_51_70386, buf_functional_15_1_tf_detect_1_Sigmoid_81_70368, buf_functional_15_1_tf_detect_1_truediv_1_70401, buf_functional_15_1_tf_detect_1_truediv_2_70378, buf_functional_15_1_tf_detect_1_truediv_3_70383, buf_functional_15_1_tf_detect_1_truediv_4_70360, buf_functional_15_1_tf_detect_1_truediv_5_70365, buf_functional_15_1_tf_detect_1_truediv_70396, buf_functional_15_1_tf_detect_1_Reshape_1_70406, buf_functional_15_1_tf_detect_1_Reshape_3_70388, buf_functional_15_1_tf_detect_1_Reshape_5_70370  );

  memcpy((sub_0004_arena + sub_0004_address_functional_15_1_tf_detect_1_Reshape_1_70406), buf_functional_15_1_tf_detect_1_Reshape_1_70406, 10368);
  memcpy((sub_0004_arena + sub_0004_address_functional_15_1_tf_detect_1_Reshape_3_70388), buf_functional_15_1_tf_detect_1_Reshape_3_70388, 2592);
  memcpy((sub_0004_arena + sub_0004_address_functional_15_1_tf_detect_1_Reshape_5_70370), buf_functional_15_1_tf_detect_1_Reshape_5_70370, 648);
  // NPU Unit
  sub_0004_invoke(clean_outputs);

}
