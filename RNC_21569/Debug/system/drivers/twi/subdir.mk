################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.9.1/SHARC/lib/src/drivers/Source/twi/adi_twi.c 

SRC_OBJS += \
./system/drivers/twi/adi_twi.doj 

C_DEPS += \
./system/drivers/twi/adi_twi.d 


# Each subdirectory must supply rules for building sources it contributes
system/drivers/twi/adi_twi.doj: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.9.1/SHARC/lib/src/drivers/Source/twi/adi_twi.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "system/drivers/twi/adi_twi.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


