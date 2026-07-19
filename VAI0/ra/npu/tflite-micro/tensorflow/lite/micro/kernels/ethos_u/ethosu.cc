/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/micro_common.h"
#include "tensorflow/lite/micro/kernels/ethosu.h"

#include "ethosu_driver.h"

// External reference to the Ethos-U driver instance
extern struct ethosu_driver g_ethosu0;

namespace tflite {

void* EthosuInit(TfLiteContext* context, const char* buffer, size_t length) {
    return nullptr;
}

TfLiteStatus EthosuPrepare(TfLiteContext* context, TfLiteNode* node) {
    return kTfLiteOk;
}

TfLiteStatus EthosuInvoke(TfLiteContext* context, TfLiteNode* node) {
    // Get the compiled command stream from the node's custom initial data
    const uint8_t* cms_data =
        static_cast<const uint8_t*>(node->custom_initial_data);
    int cms_size = node->custom_initial_data_size;

    if (cms_data == nullptr || cms_size == 0) {
        // No command stream provided
        return kTfLiteOk;
    }

    // Collect base addresses from all tensors
    constexpr int kMaxBaseAddr = 4;
    uint64_t base_addr[kMaxBaseAddr] = {};
    size_t base_addr_size[kMaxBaseAddr] = {};
    int num_base_addr = 0;

    for (int i = 0; i < context->tensors_size && num_base_addr < kMaxBaseAddr;
         i++) {
        TfLiteTensor* tensor = context->tensors + i;
        if (tensor->data.data != nullptr && tensor->bytes > 0) {
            bool duplicate = false;
            for (int j = 0; j < num_base_addr; j++) {
                if (base_addr[j] ==
                    reinterpret_cast<uint64_t>(tensor->data.data)) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                base_addr[num_base_addr] =
                    reinterpret_cast<uint64_t>(tensor->data.data);
                base_addr_size[num_base_addr] = tensor->bytes;
                num_base_addr++;
            }
        }
    }

    // Invoke the Ethos-U NPU
    int result = ethosu_invoke(&g_ethosu0, cms_data, cms_size, base_addr,
                               base_addr_size, num_base_addr);

    return (result == 0) ? kTfLiteOk : kTfLiteError;
}

TFLMRegistration* Register_ETHOSU() {
    static TFLMRegistration r = {};
    r.init = EthosuInit;
    r.prepare = EthosuPrepare;
    r.invoke = EthosuInvoke;
    r.custom_name = "ethos-u";
    return &r;
}

const char* GetString_ETHOSU() {
    return "ethos-u";
}

}  // namespace tflite
