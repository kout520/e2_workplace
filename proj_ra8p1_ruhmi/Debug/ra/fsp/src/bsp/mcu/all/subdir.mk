################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/bsp/mcu/all/bsp_clocks.c \
../ra/fsp/src/bsp/mcu/all/bsp_common.c \
../ra/fsp/src/bsp/mcu/all/bsp_delay.c \
../ra/fsp/src/bsp/mcu/all/bsp_group_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_guard.c \
../ra/fsp/src/bsp/mcu/all/bsp_io.c \
../ra/fsp/src/bsp/mcu/all/bsp_ipc.c \
../ra/fsp/src/bsp/mcu/all/bsp_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_macl.c \
../ra/fsp/src/bsp/mcu/all/bsp_ospi_b.c \
../ra/fsp/src/bsp/mcu/all/bsp_register_protection.c \
../ra/fsp/src/bsp/mcu/all/bsp_sbrk.c \
../ra/fsp/src/bsp/mcu/all/bsp_sdram.c \
../ra/fsp/src/bsp/mcu/all/bsp_security.c 

C_DEPS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.d \
./ra/fsp/src/bsp/mcu/all/bsp_common.d \
./ra/fsp/src/bsp/mcu/all/bsp_delay.d \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_guard.d \
./ra/fsp/src/bsp/mcu/all/bsp_io.d \
./ra/fsp/src/bsp/mcu/all/bsp_ipc.d \
./ra/fsp/src/bsp/mcu/all/bsp_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_macl.d \
./ra/fsp/src/bsp/mcu/all/bsp_ospi_b.d \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.d \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.d \
./ra/fsp/src/bsp/mcu/all/bsp_sdram.d \
./ra/fsp/src/bsp/mcu/all/bsp_security.d 

CREF += \
proj_ra8p1_ruhmi.cref 

OBJS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.o \
./ra/fsp/src/bsp/mcu/all/bsp_common.o \
./ra/fsp/src/bsp/mcu/all/bsp_delay.o \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_guard.o \
./ra/fsp/src/bsp/mcu/all/bsp_io.o \
./ra/fsp/src/bsp/mcu/all/bsp_ipc.o \
./ra/fsp/src/bsp/mcu/all/bsp_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_macl.o \
./ra/fsp/src/bsp/mcu/all/bsp_ospi_b.o \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.o \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.o \
./ra/fsp/src/bsp/mcu/all/bsp_sdram.o \
./ra/fsp/src/bsp/mcu/all/bsp_security.o 

MAP += \
proj_ra8p1_ruhmi.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/bsp/mcu/all/%.o: ../ra/fsp/src/bsp/mcu/all/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m3 -mthumb -O0 -ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra_gen" -I"." -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra_cfg\\fsp_cfg" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\src" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\fsp\\inc" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\fsp\\inc\\api" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\fsp\\inc\\instances" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\fsp\\src\\rm_ethosu" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\flatbuffers\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-NN\\Include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-NN" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\layer_by_layer_profiler\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\ethosu_monitor\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\ethosu_profiler\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-driver\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-DSP\\PrivateInclude" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-DSP\\Include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ruy" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\gemmlowp" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\tflite-micro" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\crc\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\npu\\ethos-u-core-software\\lib\\arm_profiler\\include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-View\\EventRecorder\\Include" -I"D:\\e2_workplace\\proj_ra8p1_ruhmi\\ra\\arm\\CMSIS-View\\EventRecorder\\Config" -I"D:/e2_workplace/proj_ra8p1_ruhmi/generate" -I"D:/e2_workplace/proj_ra8p1_ruhmi/generate" -I"D:/e2_workplace/proj_ra8p1_ruhmi/generate" -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

