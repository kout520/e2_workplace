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

#include "sub_0000_io_data.h"

// Input tensor: serving_default_input_1_0
// Data Type: UINT8
// Shape: [1, 28, 28, 1]
// Number of elements: 784
// Size in bytes: 784
uint8_t sub_0000_serving_default_input_1_0[] = {
  140, 151, 183, 216, 154, 219, 139, 216, 108, 159,
  165, 98, 112, 76, 228, 14, 246, 69, 98, 122,
  202, 207, 135, 122, 145, 100, 236, 214, 18, 86,
  22, 165, 5, 94, 213, 245, 199, 35, 222, 222,
  250, 121, 204, 205, 118, 133, 199, 173, 30, 184,
  163, 148, 36, 137, 241, 194, 133, 27, 106, 121,
  67, 47, 198, 188, 116, 55, 145, 34, 4, 82,
  158, 38, 156, 56, 157, 98, 241, 231, 174, 115,
  92, 156, 111, 231, 178, 25, 15, 248, 170, 167,
  171, 43, 53, 91, 33, 192, 80, 155, 93, 83,
  145, 9, 112, 162, 253, 245, 26, 167, 53, 162,
  41, 254, 167, 148, 64, 106, 119, 121, 62, 159,
  40, 86, 28, 172, 168, 81, 35, 199, 50, 243,
  94, 169, 210, 3, 24, 159, 214, 172, 24, 248,
  249, 224, 119, 130, 250, 14, 154, 115, 189, 5,
  10, 113, 72, 250, 30, 92, 75, 123, 30, 176,
  81, 225, 106, 235, 16, 55, 177, 144, 145, 221,
  67, 130, 133, 234, 24, 235, 147, 21, 237, 71,
  81, 2, 170, 215, 33, 165, 183, 215, 74, 67,
  46, 101, 150, 141, 5, 42, 212, 94, 1, 37,
  173, 145, 69, 180, 188, 73, 246, 110, 63, 193,
  147, 101, 151, 229, 146, 163, 57, 228, 243, 174,
  114, 114, 216, 250, 179, 29, 76, 196, 208, 105,
  101, 172, 225, 63, 148, 80, 225, 247, 177, 150,
  185, 168, 128, 136, 244, 59, 164, 101, 108, 158,
  155, 121, 4, 120, 77, 183, 169, 73, 74, 98,
  158, 191, 109, 224, 34, 26, 76, 23, 145, 90,
  151, 141, 147, 8, 167, 248, 166, 82, 110, 56,
  229, 36, 94, 24, 111, 251, 228, 66, 206, 137,
  180, 114, 25, 25, 235, 90, 182, 120, 255, 215,
  38, 231, 222, 9, 41, 130, 157, 42, 31, 199,
  217, 221, 206, 105, 145, 35, 104, 8, 17, 251,
  178, 95, 116, 107, 184, 12, 221, 93, 249, 4,
  219, 59, 2, 195, 92, 241, 186, 191, 43, 86,
  133, 125, 13, 86, 51, 45, 4, 43, 203, 118,
  57, 223, 88, 241, 237, 155, 180, 152, 8, 200,
  42, 128, 159, 12, 147, 178, 60, 254, 239, 68,
  157, 173, 137, 221, 151, 192, 186, 246, 79, 141,
  101, 54, 53, 56, 47, 55, 241, 145, 189, 115,
  125, 248, 58, 174, 65, 21, 14, 14, 111, 124,
  79, 225, 178, 249, 96, 158, 45, 138, 6, 218,
  17, 190, 173, 122, 116, 173, 137, 155, 229, 182,
  253, 120, 55, 116, 169, 232, 67, 35, 5, 58,
  194, 225, 81, 231, 98, 165, 150, 83, 212, 133,
  161, 0, 223, 79, 70, 108, 204, 226, 47, 174,
  243, 116, 175, 123, 55, 201, 242, 58, 187, 225,
  65, 80, 54, 245, 132, 120, 6, 182, 53, 39,
  108, 186, 95, 165, 118, 55, 71, 47, 150, 206,
  221, 191, 30, 172, 132, 70, 33, 44, 183, 180,
  101, 118, 144, 215, 46, 52, 37, 42, 124, 31,
  91, 184, 240, 7, 195, 191, 191, 23, 231, 55,
  21, 191, 141, 187, 149, 11, 246, 53, 74, 73,
  61, 173, 25, 16, 4, 142, 237, 2, 171, 213,
  200, 251, 72, 180, 150, 46, 16, 131, 124, 148,
  250, 201, 224, 155, 86, 55, 246, 116, 59, 224,
  243, 126, 240, 183, 204, 124, 161, 181, 223, 127,
  75, 216, 217, 49, 158, 197, 3, 249, 88, 220,
  37, 199, 251, 252, 122, 192, 127, 1, 163, 68,
  94, 105, 35, 109, 210, 76, 48, 102, 130, 30,
  57, 251, 25, 103, 220, 145, 249, 87, 245, 201,
  232, 105, 198, 91, 85, 102, 20, 77, 104, 198,
  59, 237, 33, 83, 13, 243, 185, 3, 2, 136,
  197, 77, 37, 226, 20, 64, 22, 173, 172, 207,
  62, 110, 107, 192, 142, 212, 220, 97, 186, 24,
  69, 65, 33, 151, 14, 121, 77, 124, 67, 117,
  116, 134, 174, 113, 178, 218, 72, 110, 97, 211,
  46, 130, 201, 22, 14, 168, 178, 52, 199, 216,
  199, 174, 66, 45, 95, 17, 150, 2, 69, 228,
  94, 34, 50, 199, 117, 236, 11, 183, 204, 125,
  19, 120, 132, 225, 78, 125, 147, 106, 245, 44,
  165, 121, 9, 200, 110, 142, 130, 40, 137, 36,
  174, 166, 71, 138, 32, 83, 100, 37, 244, 40,
  47, 33, 231, 148, 139, 23, 116, 233, 225, 21,
  117, 204, 185, 224, 102, 23, 231, 109, 176, 121,
  179, 148, 83, 183, 193, 6, 162, 187, 61, 196,
  41, 2, 203, 78, 245, 59, 117, 128, 151, 244,
  219, 142, 117, 24, 243, 159, 147, 220, 210, 40,
  232, 254, 208, 21, 40, 24, 160, 162, 101, 243,
  16, 239, 108, 114,
};

// Output tensor: StatefulPartitionedCall_0_70018
// Data Type: UINT8
// Shape: [1, 10]
// Number of elements: 10
// Size in bytes: 10
uint8_t sub_0000_StatefulPartitionedCall_0_70018[] = {
  0, 0, 21, 229, 0, 0, 0, 0, 6, 0,
};

