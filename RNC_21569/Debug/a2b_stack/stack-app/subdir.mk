################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../a2b_stack/stack-app/adi_a2b_audioroutingtable.c \
../a2b_stack/stack-app/adi_a2b_busconfig.c \
../a2b_stack/stack-app/app.c 

SRC_OBJS += \
./a2b_stack/stack-app/adi_a2b_audioroutingtable.doj \
./a2b_stack/stack-app/adi_a2b_busconfig.doj \
./a2b_stack/stack-app/app.doj 

C_DEPS += \
./a2b_stack/stack-app/adi_a2b_audioroutingtable.d \
./a2b_stack/stack-app/adi_a2b_busconfig.d \
./a2b_stack/stack-app/app.d 


# Each subdirectory must supply rules for building sources it contributes
a2b_stack/stack-app/adi_a2b_audioroutingtable.doj: ../a2b_stack/stack-app/adi_a2b_audioroutingtable.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/stack-app/adi_a2b_audioroutingtable.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/stack-app/adi_a2b_busconfig.doj: ../a2b_stack/stack-app/adi_a2b_busconfig.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/stack-app/adi_a2b_busconfig.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/stack-app/app.doj: ../a2b_stack/stack-app/app.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/stack-app/app.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


