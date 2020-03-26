################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/RNC_21569.c 

SRC_OBJS += \
./src/RNC_21569.doj 

C_DEPS += \
./src/RNC_21569.d 


# Each subdirectory must supply rules for building sources it contributes
src/RNC_21569.doj: ../src/RNC_21569.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "src/RNC_21569.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


