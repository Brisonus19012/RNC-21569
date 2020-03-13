################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/sru/sru_config.c 

SRC_OBJS += \
./system/sru/sru_config.doj 

C_DEPS += \
./system/sru/sru_config.d 


# Each subdirectory must supply rules for building sources it contributes
system/sru/sru_config.doj: ../system/sru/sru_config.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "system/sru/sru_config.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


