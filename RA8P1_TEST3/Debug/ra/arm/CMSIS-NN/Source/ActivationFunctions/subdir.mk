################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_nn_activation_s16.c \
../ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu6_s8.c \
../ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu_q15.c \
../ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu_q7.c 

C_DEPS += \
./ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_nn_activation_s16.d \
./ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu6_s8.d \
./ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu_q15.d \
./ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu_q7.d 

OBJS += \
./ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_nn_activation_s16.o \
./ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu6_s8.o \
./ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu_q15.o \
./ra/arm/CMSIS-NN/Source/ActivationFunctions/arm_relu_q7.o 

SREC += \
RA8P1_TEST3.srec 

MAP += \
RA8P1_TEST3.map 


# Each subdirectory must supply rules for building sources it contributes
ra/arm/CMSIS-NN/Source/ActivationFunctions/%.o: ../ra/arm/CMSIS-NN/Source/ActivationFunctions/%.c
	$(file > $@.in,-mthumb -mfloat-abi=hard -mcpu=cortex-m85+nopacbti -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -I"D:/e2_workplace/RA8P1_TEST3/ra_gen" -I"D:/e2_workplace/RA8P1_TEST3/code" -I"." -I"D:/e2_workplace/RA8P1_TEST3/ra_cfg/fsp_cfg/bsp" -I"D:/e2_workplace/RA8P1_TEST3/ra_cfg/fsp_cfg" -I"D:/e2_workplace/RA8P1_TEST3/src" -I"D:/e2_workplace/RA8P1_TEST3/ra/fsp/inc" -I"D:/e2_workplace/RA8P1_TEST3/ra/fsp/inc/api" -I"D:/e2_workplace/RA8P1_TEST3/ra/fsp/inc/instances" -I"D:/e2_workplace/RA8P1_TEST3/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"D:/e2_workplace/RA8P1_TEST3/ra/arm/CMSIS-View/EventRecorder/Include" -I"D:/e2_workplace/RA8P1_TEST3/ra/arm/CMSIS-View/EventRecorder/Config" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/flatbuffers/include" -I"D:/e2_workplace/RA8P1_TEST3/ra/arm/CMSIS-DSP/PrivateInclude" -I"D:/e2_workplace/RA8P1_TEST3/ra/arm/CMSIS-DSP/Include" -I"D:/e2_workplace/RA8P1_TEST3/ra/fsp/src/rm_ethosu" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/tflite-micro" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/ruy" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/gemmlowp" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/ethos-u-core-driver/include" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/ethos-u-core-software/lib/layer_by_layer_profiler/include" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/ethos-u-core-software/lib/ethosu_monitor/include" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/ethos-u-core-software/lib/ethosu_profiler/include" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/ethos-u-core-software/lib/crc/include" -I"D:/e2_workplace/RA8P1_TEST3/ra/npu/ethos-u-core-software/lib/arm_profiler/include" -I"D:/e2_workplace/RA8P1_TEST3/ra/arm/CMSIS-NN/Include" -I"D:/e2_workplace/RA8P1_TEST3/ra/arm/CMSIS-NN" -std=c99 -Wno-stringop-overflow -Wno-format-truncation -w -flax-vector-conversions --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

