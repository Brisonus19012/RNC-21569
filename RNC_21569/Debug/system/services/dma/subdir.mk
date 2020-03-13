################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.9.1/SHARC/lib/src/services/Source/dma/adi_dma.c 

SRC_OBJS += \
./system/services/dma/adi_dma.doj 

C_DEPS += \
./system/services/dma/adi_dma.d 


# Each subdirectory must supply rules for building sources it contributes
system/services/dma/adi_dma.doj: C:/Analog\ Devices/CrossCore\ Embedded\ Studio\ 2.9.1/SHARC/lib/src/services/Source/dma/adi_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "system/services/dma/adi_dma.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


