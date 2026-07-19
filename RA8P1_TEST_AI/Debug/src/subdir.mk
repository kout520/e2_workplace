################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/font.c \
../src/hal_entry.c \
../src/hal_warmstart.c \
../src/lcd.c \
../src/model.c \
../src/model_io_data.c \
../src/ov5640.c \
../src/sub_0000_command_stream.c \
../src/sub_0000_invoke.c \
../src/sub_0000_io_data.c \
../src/sub_0000_model_data.c \
../src/sub_0000_tensors.c \
../src/text.c \
../src/time_counter.c 

C_DEPS += \
./src/font.d \
./src/hal_entry.d \
./src/hal_warmstart.d \
./src/lcd.d \
./src/model.d \
./src/model_io_data.d \
./src/ov5640.d \
./src/sub_0000_command_stream.d \
./src/sub_0000_invoke.d \
./src/sub_0000_io_data.d \
./src/sub_0000_model_data.d \
./src/sub_0000_tensors.d \
./src/text.d \
./src/time_counter.d 

OBJS += \
./src/font.o \
./src/hal_entry.o \
./src/hal_warmstart.o \
./src/lcd.o \
./src/model.o \
./src/model_io_data.o \
./src/ov5640.o \
./src/sub_0000_command_stream.o \
./src/sub_0000_invoke.o \
./src/sub_0000_io_data.o \
./src/sub_0000_model_data.o \
./src/sub_0000_tensors.o \
./src/text.o \
./src/time_counter.o 

SREC += \
RA8P1_TEST_AI.srec 

MAP += \
RA8P1_TEST_AI.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mthumb -mfloat-abi=hard -mcpu=cortex-m85+nopacbti -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -I"D:/e2_workplace/RA8P1_TEST_AI/ra_gen" -I"." -I"D:/e2_workplace/RA8P1_TEST_AI/ra_cfg/fsp_cfg/bsp" -I"D:/e2_workplace/RA8P1_TEST_AI/ra_cfg/fsp_cfg" -I"D:/e2_workplace/RA8P1_TEST_AI/src" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/fsp/inc" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/fsp/inc/api" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/fsp/inc/instances" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/arm/CMSIS-View/EventRecorder/Include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/arm/CMSIS-View/EventRecorder/Config" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/flatbuffers/include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/arm/CMSIS-DSP/PrivateInclude" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/arm/CMSIS-DSP/Include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/fsp/src/rm_ethosu" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/tflite-micro" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/ruy" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/gemmlowp" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/ethos-u-core-driver/include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/ethos-u-core-software/lib/layer_by_layer_profiler/include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/ethos-u-core-software/lib/ethosu_monitor/include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/ethos-u-core-software/lib/ethosu_profiler/include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/ethos-u-core-software/lib/crc/include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/npu/ethos-u-core-software/lib/arm_profiler/include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/arm/CMSIS-NN/Include" -I"D:/e2_workplace/RA8P1_TEST_AI/ra/arm/CMSIS-NN" -std=c99 -Wno-stringop-overflow -Wno-format-truncation -flax-vector-conversions --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

