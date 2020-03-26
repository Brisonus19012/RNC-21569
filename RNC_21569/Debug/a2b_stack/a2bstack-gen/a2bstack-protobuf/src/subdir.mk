################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../a2b_stack/a2bstack-gen/a2bstack-protobuf/src/a2b_bdd_helper.c \
../a2b_stack/a2bstack-gen/a2bstack-protobuf/src/bdd_pb2.pb.c \
../a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_common.c \
../a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_decode.c 

SRC_OBJS += \
./a2b_stack/a2bstack-gen/a2bstack-protobuf/src/a2b_bdd_helper.doj \
./a2b_stack/a2bstack-gen/a2bstack-protobuf/src/bdd_pb2.pb.doj \
./a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_common.doj \
./a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_decode.doj 

C_DEPS += \
./a2b_stack/a2bstack-gen/a2bstack-protobuf/src/a2b_bdd_helper.d \
./a2b_stack/a2bstack-gen/a2bstack-protobuf/src/bdd_pb2.pb.d \
./a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_common.d \
./a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_decode.d 


# Each subdirectory must supply rules for building sources it contributes
a2b_stack/a2bstack-gen/a2bstack-protobuf/src/a2b_bdd_helper.doj: ../a2b_stack/a2bstack-gen/a2bstack-protobuf/src/a2b_bdd_helper.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack-protobuf/src/a2b_bdd_helper.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack-protobuf/src/bdd_pb2.pb.doj: ../a2b_stack/a2bstack-gen/a2bstack-protobuf/src/bdd_pb2.pb.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack-protobuf/src/bdd_pb2.pb.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_common.doj: ../a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_common.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_common.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_decode.doj: ../a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_decode.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="RNC_21569" -proc ADSP-21569 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG -DADI_DEBUG @includes-dc3f4b3fa9e2a6e9c52a36d2c8e12f5c.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -char-size-8 -swc -gnu-style-dependencies -MD -Mo "a2b_stack/a2bstack-gen/a2bstack-protobuf/src/pb_decode.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


