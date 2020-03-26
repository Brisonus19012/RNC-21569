################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2b_peri_config.c \
../a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_plugin.c \
../a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_verinfo.c 

SRC_OBJS += \
./a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2b_peri_config.doj \
./a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_plugin.doj \
./a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_verinfo.doj 

C_DEPS += \
./a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2b_peri_config.d \
./a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_plugin.d \
./a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_verinfo.d 


# Each subdirectory must supply rules for building sources it contributes
a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2b_peri_config.doj: ../a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2b_peri_config.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2b_peri_config.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_plugin.doj: ../a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_plugin.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_plugin.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_verinfo.doj: ../a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_verinfo.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-slave/src/a2bslave_verinfo.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


