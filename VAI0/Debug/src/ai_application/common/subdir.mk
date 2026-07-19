################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/ai_application/common/ImageUtils.cc \
../src/ai_application/common/Main.cc \
../src/ai_application/common/Model.cc \
../src/ai_application/common/PlatformMath.cc \
../src/ai_application/common/TensorFlowLiteMicro.cc \
../src/ai_application/common/UseCaseCommonUtils.cc 

CREF += \
VAI0.cref 

CC_DEPS += \
./src/ai_application/common/ImageUtils.d \
./src/ai_application/common/Main.d \
./src/ai_application/common/Model.d \
./src/ai_application/common/PlatformMath.d \
./src/ai_application/common/TensorFlowLiteMicro.d \
./src/ai_application/common/UseCaseCommonUtils.d 

OBJS += \
./src/ai_application/common/ImageUtils.o \
./src/ai_application/common/Main.o \
./src/ai_application/common/Model.o \
./src/ai_application/common/PlatformMath.o \
./src/ai_application/common/TensorFlowLiteMicro.o \
./src/ai_application/common/UseCaseCommonUtils.o 

MAP += \
VAI0.map 


# Each subdirectory must supply rules for building sources it contributes
src/ai_application/common/%.o: ../src/ai_application/common/%.cc
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m85 -mthumb -mlittle-endian -mfloat-abi=hard -Os -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c++17 -flax-vector-conversions -fshort-enums -fno-unroll-loops -fno-rtti -fno-exceptions -I"D:\\e2_workplace\\VAI0\\src" -I"." -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\inc" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\inc\\api" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\inc\\instances" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\src\\rm_freertos_port" -I"D:\\e2_workplace\\VAI0\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"D:\\e2_workplace\\VAI0\\ra_gen" -I"D:\\e2_workplace\\VAI0\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\e2_workplace\\VAI0\\ra_cfg\\fsp_cfg" -I"D:\\e2_workplace\\VAI0\\ra_cfg\\aws" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\src\\rm_ethosu" -I"D:\\e2_workplace\\VAI0\\ra\\tes\\dave2d\\inc" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS-NN\\Include" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS-NN" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\flatbuffers\\include" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS-DSP\\PrivateInclude" -I"D:\\e2_workplace\\VAI0\\ra\\arm\\CMSIS-DSP\\Include" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\ethos-u-core-driver\\include" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\ruy" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\gemmlowp" -I"D:\\e2_workplace\\VAI0\\ra\\npu\\tflite-micro" -I"D:\\e2_workplace\\VAI0\\src\\ai_application" -I"D:\\e2_workplace\\VAI0\\src\\ai_application\\common" -I"D:\\e2_workplace\\VAI0\\src\\ai_application\\face_detection" -I"D:\\e2_workplace\\VAI0\\src\\camera_layer" -I"D:\\e2_workplace\\VAI0\\src\\display_layer" -I"D:\\e2_workplace\\VAI0\\src\\time_counter" -I"D:\\e2_workplace\\VAI0\\src\\external_memory" -I"D:\\e2_workplace\\VAI0\\src\\console" -I"D:\\e2_workplace\\VAI0\\ra\\fsp\\src\\r_drw" -D_RENESAS_RA_ -D_MEM_USAGE=0 -D_RA_CORE=CPU0 -DTF_LITE_STATIC_MEMORY -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c++ "$<" -c -o "$@")
	@clang++ --target=arm-none-eabi @"$@.in"

