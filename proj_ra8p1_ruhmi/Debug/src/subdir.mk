################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/compute_sub_0000.c \
../src/hal_entry.c \
../src/hal_warmstart.c \
../src/kernel_library_int.c \
../src/kernel_library_utils.c \
../src/model_io_data.c \
../src/time_counter.c 

C_DEPS += \
./src/compute_sub_0000.d \
./src/hal_entry.d \
./src/hal_warmstart.d \
./src/kernel_library_int.d \
./src/kernel_library_utils.d \
./src/model_io_data.d \
./src/time_counter.d 

CREF += \
proj_ra8p1_ruhmi.cref 

OBJS += \
./src/compute_sub_0000.o \
./src/hal_entry.o \
./src/hal_warmstart.o \
./src/kernel_library_int.o \
./src/kernel_library_utils.o \
./src/model_io_data.o \
./src/time_counter.o 

MAP += \
proj_ra8p1_ruhmi.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m3 -mthumb -O0 -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra_gen" -I"." -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra_cfg\\fsp_cfg" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\src" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\fsp\\inc" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\fsp\\inc\\api" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\fsp\\inc\\instances" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\fsp\\src\\rm_ethosu" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\flatbuffers\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-NN\\Include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-NN" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\layer_by_layer_profiler\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\ethosu_monitor\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\ethosu_profiler\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-driver\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-DSP\\PrivateInclude" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-DSP\\Include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ruy" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\gemmlowp" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\tflite-micro" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\crc\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\arm_profiler\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-View\\EventRecorder\\Include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-View\\EventRecorder\\Config" -I"D:/e2_workplace/proj_ra8p1_ruhmi/generate" -I"D:/e2_workplace/proj_ra8p1_ruhmi/generate" -I"D:/e2_workplace/proj_ra8p1_ruhmi/generate" -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

