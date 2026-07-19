################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal_entry.c \
../src/hal_warmstart.c \
../src/model.c \
../src/model_io_data.c \
../src/sub_0000_command_stream.c \
../src/sub_0000_invoke.c \
../src/sub_0000_io_data.c \
../src/sub_0000_model_data.c \
../src/sub_0000_tensors.c 

C_DEPS += \
./src/hal_entry.d \
./src/hal_warmstart.d \
./src/model.d \
./src/model_io_data.d \
./src/sub_0000_command_stream.d \
./src/sub_0000_invoke.d \
./src/sub_0000_io_data.d \
./src/sub_0000_model_data.d \
./src/sub_0000_tensors.d 

OBJS += \
./src/hal_entry.o \
./src/hal_warmstart.o \
./src/model.o \
./src/model_io_data.o \
./src/sub_0000_command_stream.o \
./src/sub_0000_invoke.o \
./src/sub_0000_io_data.o \
./src/sub_0000_model_data.o \
./src/sub_0000_tensors.o 

SREC += \
RA8P1_TEST11.srec 

MAP += \
RA8P1_TEST11.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mthumb -mfloat-abi=hard -mcpu=cortex-m85+nopacbti -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -I"D:/e2_workplace/RA8P1_TEST11/ra_gen" -I"D:/e2_workplace/RA8P1_TEST11/code" -I"." -I"D:/e2_workplace/RA8P1_TEST11/ra_cfg/fsp_cfg/bsp" -I"D:/e2_workplace/RA8P1_TEST11/ra_cfg/fsp_cfg" -I"D:/e2_workplace/RA8P1_TEST11/src" -I"D:/e2_workplace/RA8P1_TEST11/ra/fsp/inc" -I"D:/e2_workplace/RA8P1_TEST11/ra/fsp/inc/api" -I"D:/e2_workplace/RA8P1_TEST11/ra/fsp/inc/instances" -I"D:/e2_workplace/RA8P1_TEST11/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"D:/e2_workplace/RA8P1_TEST11/ra/fsp/src/rm_ethosu" -I"D:/e2_workplace/RA8P1_TEST11/ra/npu/ethos-u-core-driver/include" -std=c99 -Wno-stringop-overflow -Wno-format-truncation -flax-vector-conversions --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

