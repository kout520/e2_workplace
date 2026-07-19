################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/add.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/conv.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/maximum_minimum.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/mul.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/pooling.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/softmax.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/svdf.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.cc \
../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.cc 

CREF += \
VAI0.cref 

CC_DEPS += \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/add.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/conv.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/maximum_minimum.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/mul.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/pooling.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/softmax.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/svdf.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.d \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.d 

OBJS += \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/add.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/conv.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/maximum_minimum.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/mul.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/pooling.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/softmax.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/svdf.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.o \
./ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.o 

MAP += \
VAI0.map 


# Each subdirectory must supply rules for building sources it contributes
ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/%.o: ../ra/npu/tflite-micro/tensorflow/lite/micro/kernels/cmsis_nn/%.cc
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m85 -mthumb -mlittle-endian -mfloat-abi=hard -Os -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c++17 -flax-vector-conversions -fshort-enums -fno-unroll-loops -fno-rtti -fno-exceptions -w -I"D:\\e2_workplace\\VAI0\\src" -I"." -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\inc" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\inc\\api" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\inc\\instances" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\src\\rm_freertos_port" -I"D:\\e2_workplace\\VAI0\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"D:\\e2_workplace\\VAI0\\ra_gen" -I"D:\\e2_workplace\\VAI0\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\e2_workplace\\VAI0\\ra_cfg\\fsp_cfg" -I"D:\\e2_workplace\\VAI0\\ra_cfg\\aws" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\src\\rm_ethosu" -I"D:\\e2_workplace\\VAI0\\ra\\tes\\dave2d\\inc" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS-NN\\Include" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS-NN" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\flatbuffers\\include" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS-DSP\\PrivateInclude" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS-DSP\\Include" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\ethos-u-core-driver\\include" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\ruy" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\gemmlowp" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\tflite-micro" -I"D:\\e2_workplace\\VAI0\\src\\ai_application" -I"D:\\e2_workplace\\VAI0\\src\\ai_application\\common" -I"D:\\e2_workplace\\VAI0\\src\\ai_application\\face_detection" -I"D:\\e2_workplace\\VAI0\\src\\camera_layer" -I"D:\\e2_workplace\\VAI0\\src\\display_layer" -I"D:\\e2_workplace\\VAI0\\src\\time_counter" -I"D:\\e2_workplace\\VAI0\\src\\external_memory" -I"D:\\e2_workplace\\VAI0\\src\\console" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\src\\r_drw" -D_RENESAS_RA_ -D_MEM_USAGE=0 -D_RA_CORE=CPU0 -DTF_LITE_STATIC_MEMORY -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c++ "$<" -c -o "$@")
	@clang++ --target=arm-none-eabi @"$@.in"

