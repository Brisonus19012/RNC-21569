################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../a2b_stack/a2bstack-gen/a2bstack/src/audio.c \
../a2b_stack/a2bstack-gen/a2bstack/src/diag.c \
../a2b_stack/a2bstack-gen/a2bstack/src/gpio.c \
../a2b_stack/a2bstack-gen/a2bstack/src/i2c.c \
../a2b_stack/a2bstack-gen/a2bstack/src/interrupt.c \
../a2b_stack/a2bstack-gen/a2bstack/src/jobexec.c \
../a2b_stack/a2bstack-gen/a2bstack/src/memmgr.c \
../a2b_stack/a2bstack-gen/a2bstack/src/msg.c \
../a2b_stack/a2bstack-gen/a2bstack/src/msgrtr.c \
../a2b_stack/a2bstack-gen/a2bstack/src/pool.c \
../a2b_stack/a2bstack-gen/a2bstack/src/seqchart.c \
../a2b_stack/a2bstack-gen/a2bstack/src/stack.c \
../a2b_stack/a2bstack-gen/a2bstack/src/stackctx.c \
../a2b_stack/a2bstack-gen/a2bstack/src/stackctxmailbox.c \
../a2b_stack/a2bstack-gen/a2bstack/src/stackinfo.c \
../a2b_stack/a2bstack-gen/a2bstack/src/stringbuffer.c \
../a2b_stack/a2bstack-gen/a2bstack/src/system.c \
../a2b_stack/a2bstack-gen/a2bstack/src/timer.c \
../a2b_stack/a2bstack-gen/a2bstack/src/trace.c \
../a2b_stack/a2bstack-gen/a2bstack/src/util.c 

SRC_OBJS += \
./a2b_stack/a2bstack-gen/a2bstack/src/audio.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/diag.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/gpio.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/i2c.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/interrupt.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/jobexec.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/memmgr.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/msg.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/msgrtr.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/pool.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/seqchart.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/stack.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/stackctx.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/stackctxmailbox.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/stackinfo.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/stringbuffer.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/system.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/timer.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/trace.doj \
./a2b_stack/a2bstack-gen/a2bstack/src/util.doj 

C_DEPS += \
./a2b_stack/a2bstack-gen/a2bstack/src/audio.d \
./a2b_stack/a2bstack-gen/a2bstack/src/diag.d \
./a2b_stack/a2bstack-gen/a2bstack/src/gpio.d \
./a2b_stack/a2bstack-gen/a2bstack/src/i2c.d \
./a2b_stack/a2bstack-gen/a2bstack/src/interrupt.d \
./a2b_stack/a2bstack-gen/a2bstack/src/jobexec.d \
./a2b_stack/a2bstack-gen/a2bstack/src/memmgr.d \
./a2b_stack/a2bstack-gen/a2bstack/src/msg.d \
./a2b_stack/a2bstack-gen/a2bstack/src/msgrtr.d \
./a2b_stack/a2bstack-gen/a2bstack/src/pool.d \
./a2b_stack/a2bstack-gen/a2bstack/src/seqchart.d \
./a2b_stack/a2bstack-gen/a2bstack/src/stack.d \
./a2b_stack/a2bstack-gen/a2bstack/src/stackctx.d \
./a2b_stack/a2bstack-gen/a2bstack/src/stackctxmailbox.d \
./a2b_stack/a2bstack-gen/a2bstack/src/stackinfo.d \
./a2b_stack/a2bstack-gen/a2bstack/src/stringbuffer.d \
./a2b_stack/a2bstack-gen/a2bstack/src/system.d \
./a2b_stack/a2bstack-gen/a2bstack/src/timer.d \
./a2b_stack/a2bstack-gen/a2bstack/src/trace.d \
./a2b_stack/a2bstack-gen/a2bstack/src/util.d 


# Each subdirectory must supply rules for building sources it contributes
a2b_stack/a2bstack-gen/a2bstack/src/audio.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/audio.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/audio.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/diag.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/diag.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/diag.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/gpio.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/gpio.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/i2c.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/i2c.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/interrupt.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/interrupt.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/interrupt.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/jobexec.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/jobexec.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/jobexec.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/memmgr.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/memmgr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/memmgr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/msg.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/msg.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/msg.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/msgrtr.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/msgrtr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/msgrtr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/pool.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/pool.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/pool.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/seqchart.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/seqchart.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/seqchart.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/stack.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/stack.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/stack.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/stackctx.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/stackctx.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/stackctx.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/stackctxmailbox.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/stackctxmailbox.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/stackctxmailbox.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/stackinfo.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/stackinfo.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/stackinfo.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/stringbuffer.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/stringbuffer.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/stringbuffer.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/system.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/system.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/system.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/timer.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/timer.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/trace.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/trace.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/trace.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack/src/util.doj: ../a2b_stack/a2bstack-gen/a2bstack/src/util.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-3915bc24782d34f6e0419ae0cad69e4e.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack/src/util.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


