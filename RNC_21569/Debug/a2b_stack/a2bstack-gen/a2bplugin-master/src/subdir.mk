################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../a2b_stack/a2bstack-gen/a2bplugin-master/src/a2b_bert.c \
../a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_plugin.c \
../a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_verinfo.c \
../a2b_stack/a2bstack-gen/a2bplugin-master/src/discovery.c \
../a2b_stack/a2bstack-gen/a2bplugin-master/src/override.c \
../a2b_stack/a2bstack-gen/a2bplugin-master/src/periphcfg.c \
../a2b_stack/a2bstack-gen/a2bplugin-master/src/periphutil.c \
../a2b_stack/a2bstack-gen/a2bplugin-master/src/pwrdiag.c 

SRC_OBJS += \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/a2b_bert.doj \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_plugin.doj \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_verinfo.doj \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/discovery.doj \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/override.doj \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/periphcfg.doj \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/periphutil.doj \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/pwrdiag.doj 

C_DEPS += \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/a2b_bert.d \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_plugin.d \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_verinfo.d \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/discovery.d \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/override.d \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/periphcfg.d \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/periphutil.d \
./a2b_stack/a2bstack-gen/a2bplugin-master/src/pwrdiag.d 


# Each subdirectory must supply rules for building sources it contributes
a2b_stack/a2bstack-gen/a2bplugin-master/src/a2b_bert.doj: ../a2b_stack/a2bstack-gen/a2bplugin-master/src/a2b_bert.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-master/src/a2b_bert.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_plugin.doj: ../a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_plugin.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_plugin.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_verinfo.doj: ../a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_verinfo.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-master/src/a2bmaster_verinfo.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-master/src/discovery.doj: ../a2b_stack/a2bstack-gen/a2bplugin-master/src/discovery.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-master/src/discovery.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-master/src/override.doj: ../a2b_stack/a2bstack-gen/a2bplugin-master/src/override.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-master/src/override.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-master/src/periphcfg.doj: ../a2b_stack/a2bstack-gen/a2bplugin-master/src/periphcfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-master/src/periphcfg.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-master/src/periphutil.doj: ../a2b_stack/a2bstack-gen/a2bplugin-master/src/periphutil.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-master/src/periphutil.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bplugin-master/src/pwrdiag.doj: ../a2b_stack/a2bstack-gen/a2bplugin-master/src/pwrdiag.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bplugin-master/src/pwrdiag.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


