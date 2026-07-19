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
 */

#include <stdint.h>

#include "compute_sub_0003.h"

#include "arm_nn_types.h"
#include "arm_nnfunctions.h"
#include "kernel_library_utils.h"

#include "kernel_library_int.h" 

 

void compute_sub_0003(
  // buffer for intermediate results
  uint8_t* main_storage, // should provide at least 13621 bytes of storage

  // inputs
  
  const int8_t functional_15_1_tf_detect_1_Sigmoid_21_70404[3456], // 1,576,3,2
  
  const int8_t functional_15_1_tf_detect_1_Sigmoid_51_70386[864], // 1,144,3,2
  
  const int8_t functional_15_1_tf_detect_1_Sigmoid_81_70368[216], // 1,36,3,2
  
  const int8_t functional_15_1_tf_detect_1_truediv_1_70401[3456], // 1,576,3,2
  
  const int8_t functional_15_1_tf_detect_1_truediv_2_70378[864], // 1,144,3,2
  
  const int8_t functional_15_1_tf_detect_1_truediv_3_70383[864], // 1,144,3,2
  
  const int8_t functional_15_1_tf_detect_1_truediv_4_70360[216], // 1,36,3,2
  
  const int8_t functional_15_1_tf_detect_1_truediv_5_70365[216], // 1,36,3,2
  
  const int8_t functional_15_1_tf_detect_1_truediv_70396[3456], // 1,576,3,2
  

  // outputs
  
  int8_t functional_15_1_tf_detect_1_Reshape_1_70406[10368] , // 1,1728,6
  
  int8_t functional_15_1_tf_detect_1_Reshape_3_70388[2592] , // 1,432,6
  
  int8_t functional_15_1_tf_detect_1_Reshape_5_70370[648]  // 1,108,6
  
) {
  // Buffers allocated on the main storage (note: depends on the execution order)
    
  
  int8_t* functional_15_1_tf_detect_1_concat_1_70387 = (int8_t *) &main_storage[11024]; // 1,144,3,6 == 2592
  
  int8_t* functional_15_1_tf_detect_1_concat_2_70369 = (int8_t *) &main_storage[10368]; // 1,36,3,6 == 648
  
  int8_t* functional_15_1_tf_detect_1_concat_70405 = (int8_t *) &main_storage[0]; // 1,576,3,6 == 10368
  
  

  // Parameters
  







//
// CMSIS-NN concat
//

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_truediv_70396
    , 2
    , 3
    , 576
    , 1
    , functional_15_1_tf_detect_1_concat_70405 

    , 6 

    , 0 
);

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_truediv_1_70401
    , 2
    , 3
    , 576
    , 1
    , functional_15_1_tf_detect_1_concat_70405 

    , 6 

    , 2 
);

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_Sigmoid_21_70404
    , 2
    , 3
    , 576
    , 1
    , functional_15_1_tf_detect_1_concat_70405 

    , 6 

    , 4 
);


//
// Identity - bypassing functional_15_1_tf_detect_1_Reshape_1_70406 operation
//
// Input functional_15_1_tf_detect_1_concat_70405: int8_t - 1,576,3,6
// Output functional_15_1_tf_detect_1_Reshape_1_70406: int8_t - 1,1728,6


memcpy(functional_15_1_tf_detect_1_Reshape_1_70406, functional_15_1_tf_detect_1_concat_70405, 10368 * sizeof(int8_t));





//
// CMSIS-NN concat
//

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_truediv_4_70360
    , 2
    , 3
    , 36
    , 1
    , functional_15_1_tf_detect_1_concat_2_70369 

    , 6 

    , 0 
);

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_truediv_5_70365
    , 2
    , 3
    , 36
    , 1
    , functional_15_1_tf_detect_1_concat_2_70369 

    , 6 

    , 2 
);

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_Sigmoid_81_70368
    , 2
    , 3
    , 36
    , 1
    , functional_15_1_tf_detect_1_concat_2_70369 

    , 6 

    , 4 
);


//
// Identity - bypassing functional_15_1_tf_detect_1_Reshape_5_70370 operation
//
// Input functional_15_1_tf_detect_1_concat_2_70369: int8_t - 1,36,3,6
// Output functional_15_1_tf_detect_1_Reshape_5_70370: int8_t - 1,108,6


memcpy(functional_15_1_tf_detect_1_Reshape_5_70370, functional_15_1_tf_detect_1_concat_2_70369, 648 * sizeof(int8_t));





//
// CMSIS-NN concat
//

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_truediv_2_70378
    , 2
    , 3
    , 144
    , 1
    , functional_15_1_tf_detect_1_concat_1_70387 

    , 6 

    , 0 
);

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_truediv_3_70383
    , 2
    , 3
    , 144
    , 1
    , functional_15_1_tf_detect_1_concat_1_70387 

    , 6 

    , 2 
);

arm_concatenation_s8_x	(
      functional_15_1_tf_detect_1_Sigmoid_51_70386
    , 2
    , 3
    , 144
    , 1
    , functional_15_1_tf_detect_1_concat_1_70387 

    , 6 

    , 4 
);


//
// Identity - bypassing functional_15_1_tf_detect_1_Reshape_3_70388 operation
//
// Input functional_15_1_tf_detect_1_concat_1_70387: int8_t - 1,144,3,6
// Output functional_15_1_tf_detect_1_Reshape_3_70388: int8_t - 1,432,6


memcpy(functional_15_1_tf_detect_1_Reshape_3_70388, functional_15_1_tf_detect_1_concat_1_70387, 2592 * sizeof(int8_t));





}
