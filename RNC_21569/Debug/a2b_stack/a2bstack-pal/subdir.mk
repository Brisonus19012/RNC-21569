################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../a2b_stack/a2bstack-pal/adi_a2b_codecInit.c \
../a2b_stack/a2bstack-pal/adi_a2b_init.c \
../a2b_stack/a2bstack-pal/adi_a2b_pal.c \
../a2b_stack/a2bstack-pal/adi_a2b_sportdriver.c \
../a2b_stack/a2bstack-pal/adi_a2b_sys.c \
../a2b_stack/a2bstack-pal/adi_a2b_timer.c \
../a2b_stack/a2bstack-pal/adi_a2b_twidriver.c 

SRC_OBJS += \
./a2b_stack/a2bstack-pal/adi_a2b_codecInit.doj \
./a2b_stack/a2bstack-pal/adi_a2b_init.doj \
./a2b_stack/a2bstack-pal/adi_a2b_pal.doj \
./a2b_stack/a2bstack-pal/adi_a2b_sportdriver.doj \
./a2b_stack/a2bstack-pal/adi_a2b_sys.doj \
./a2b_stack/a2bstack-pal/adi_a2b_timer.doj \
./a2b_stack/a2bstack-pal/adi_a2b_twidriver.doj 

C_DEPS += \
./a2b_stack/a2bstack-pal/adi_a2b_codecInit.d \
./a2b_stack/a2bstack-pal/adi_a2b_init.d \
./a2b_stack/a2bstack-pal/adi_a2b_pal.d \
./a2b_stack/a2bstack-pal/adi_a2b_sportdriver.d \
./a2b_stack/a2bstack-pal/adi_a2b_sys.d \
./a2b_stack/a2bstack-pal/adi_a2b_timer.d \
./a2b_stack/a2bstack-pal/adi_a2b_twidriver.d 


# Each subdirectory must supply rules for building sources it contributes
a2b_stack/a2bstack-pal/adi_a2b_codecInit.doj: ../a2b_stack/a2bstack-pal/adi_a2b_codecInit.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-pal/adi_a2b_codecInit.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-pal/adi_a2b_init.doj: ../a2b_stack/a2bstack-pal/adi_a2b_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-pal/adi_a2b_init.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-pal/adi_a2b_pal.doj: ../a2b_stack/a2bstack-pal/adi_a2b_pal.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-pal/adi_a2b_pal.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-pal/adi_a2b_sportdriver.doj: ../a2b_stack/a2bstack-pal/adi_a2b_sportdriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-pal/adi_a2b_sportdriver.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-pal/adi_a2b_sys.doj: ../a2b_stack/a2bstack-pal/adi_a2b_sys.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-pal/adi_a2b_sys.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-pal/adi_a2b_timer.doj: ../a2b_stack/a2bstack-pal/adi_a2b_timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-pal/adi_a2b_timer.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-pal/adi_a2b_twidriver.doj: ../a2b_stack/a2bstack-pal/adi_a2b_twidriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-pal/adi_a2b_twidriver.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


