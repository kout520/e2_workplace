################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/ruhmi/compute_sub_0001.c \
../code/ruhmi/compute_sub_0003.c \
../code/ruhmi/kernel_library_int.c \
../code/ruhmi/kernel_library_utils.c \
../code/ruhmi/model.c \
../code/ruhmi/model_io_data.c \
../code/ruhmi/sub_0000_command_stream.c \
../code/ruhmi/sub_0000_invoke.c \
../code/ruhmi/sub_0000_io_data.c \
../code/ruhmi/sub_0000_model_data.c \
../code/ruhmi/sub_0000_tensors.c \
../code/ruhmi/sub_0002_command_stream.c \
../code/ruhmi/sub_0002_invoke.c \
../code/ruhmi/sub_0002_io_data.c \
../code/ruhmi/sub_0002_model_data.c \
../code/ruhmi/sub_0002_tensors.c \
../code/ruhmi/sub_0004_command_stream.c \
../code/ruhmi/sub_0004_invoke.c \
../code/ruhmi/sub_0004_io_data.c \
../code/ruhmi/sub_0004_model_data.c \
../code/ruhmi/sub_0004_tensors.c 

C_DEPS += \
./code/ruhmi/compute_sub_0001.d \
./code/ruhmi/compute_sub_0003.d \
./code/ruhmi/kernel_library_int.d \
./code/ruhmi/kernel_library_utils.d \
./code/ruhmi/model.d \
./code/ruhmi/model_io_data.d \
./code/ruhmi/sub_0000_command_stream.d \
./code/ruhmi/sub_0000_invoke.d \
./code/ruhmi/sub_0000_io_data.d \
./code/ruhmi/sub_0000_model_data.d \
./code/ruhmi/sub_0000_tensors.d \
./code/ruhmi/sub_0002_command_stream.d \
./code/ruhmi/sub_0002_invoke.d \
./code/ruhmi/sub_0002_io_data.d \
./code/ruhmi/sub_0002_model_data.d \
./code/ruhmi/sub_0002_tensors.d \
./code/ruhmi/sub_0004_command_stream.d \
./code/ruhmi/sub_0004_invoke.d \
./code/ruhmi/sub_0004_io_data.d \
./code/ruhmi/sub_0004_model_data.d \
./code/ruhmi/sub_0004_tensors.d 

CREF += \
RA8P1_AI.cref 

OBJS += \
./code/ruhmi/compute_sub_0001.o \
./code/ruhmi/compute_sub_0003.o \
./code/ruhmi/kernel_library_int.o \
./code/ruhmi/kernel_library_utils.o \
./code/ruhmi/model.o \
./code/ruhmi/model_io_data.o \
./code/ruhmi/sub_0000_command_stream.o \
./code/ruhmi/sub_0000_invoke.o \
./code/ruhmi/sub_0000_io_data.o \
./code/ruhmi/sub_0000_model_data.o \
./code/ruhmi/sub_0000_tensors.o \
./code/ruhmi/sub_0002_command_stream.o \
./code/ruhmi/sub_0002_invoke.o \
./code/ruhmi/sub_0002_io_data.o \
./code/ruhmi/sub_0002_model_data.o \
./code/ruhmi/sub_0002_tensors.o \
./code/ruhmi/sub_0004_command_stream.o \
./code/ruhmi/sub_0004_invoke.o \
./code/ruhmi/sub_0004_io_data.o \
./code/ruhmi/sub_0004_model_data.o \
./code/ruhmi/sub_0004_tensors.o 

MAP += \
RA8P1_AI.map 


# Each subdirectory must supply rules for building sources it contributes
code/ruhmi/%.o: ../code/ruhmi/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m85 -mthumb -mlittle-endian -mfloat-abi=hard -Os -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -flax-vector-conversions -fshort-enums -fno-unroll-loops -I"D:\\e2_workplace\\RA8P1_AI\\code\\ruhmi" -I"D:\\e2_workplace\\RA8P1_AI\\code" -I"D:\\e2_workplace\\RA8P1_AI\\ra_gen" -I"." -I"D:\\e2_workplace\\RA8P1_AI\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\e2_workplace\\RA8P1_AI\\ra_cfg\\fsp_cfg" -I"D:\\e2_workplace\\RA8P1_AI\\src" -I"D:\\e2_workplace\\RA8P1_AI\\code" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\fsp\\inc" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\fsp\\inc\\api" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\fsp\\inc\\instances" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\arm\\CMSIS-View\\EventRecorder\\Include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\arm\\CMSIS-View\\EventRecorder\\Config" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\flatbuffers\\include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\arm\\CMSIS-DSP\\PrivateInclude" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\arm\\CMSIS-DSP\\Include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\fsp\\src\\rm_ethosu" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\tflite-micro" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\ruy" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\gemmlowp" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\ethos-u-core-driver\\include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\ethos-u-core-software\\lib\\layer_by_layer_profiler\\include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\ethos-u-core-software\\lib\\ethosu_monitor\\include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\ethos-u-core-software\\lib\\ethosu_profiler\\include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\ethos-u-core-software\\lib\\crc\\include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\npu\\ethos-u-core-software\\lib\\arm_profiler\\include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\arm\\CMSIS-NN\\Include" -I"D:\\e2_workplace\\RA8P1_AI\\ra\\arm\\CMSIS-NN" -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

