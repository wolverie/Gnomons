################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
SRC_SRCS += \
..\src/lowlvl.src 

C_SRCS += \
..\src/Basic.c \
..\src/SampleCUnit.c \
..\src/dbsct.c \
..\src/interrupt_handlers.c \
..\src/lowsrc.c \
..\src/reset_program.c \
..\src/sbrk.c \
..\src/source.c \
..\src/testsource.c \
..\src/vector_table.c 

C_DEPS += \
./src/Basic.d \
./src/SampleCUnit.d \
./src/dbsct.d \
./src/interrupt_handlers.d \
./src/lowsrc.d \
./src/reset_program.d \
./src/sbrk.d \
./src/source.d \
./src/testsource.d \
./src/vector_table.d 

SRC_DEPS += \
./src/lowlvl.d 

OBJS += \
./src/Basic.obj \
./src/SampleCUnit.obj \
./src/dbsct.obj \
./src/interrupt_handlers.obj \
./src/lowlvl.obj \
./src/lowsrc.obj \
./src/reset_program.obj \
./src/sbrk.obj \
./src/source.obj \
./src/testsource.obj \
./src/vector_table.obj 


# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=c   -include="C:\PROGRA~2\Renesas\RX\2_5_0/include","C:\workspace\SampleCUnit\src\Headers"  -debug -nomessage -isa=rxv2 -fpu -nologo  -define=__RX=1   "$<"
	ccrx -lang=c -output=obj="$(@:%.d=%.obj)"  -include="C:\PROGRA~2\Renesas\RX\2_5_0/include","C:\workspace\SampleCUnit\src\Headers"  -debug -nomessage -isa=rxv2 -fpu -nologo  -define=__RX=1   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

src/%.obj: ../src/%.src
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Assembler'
	asrx  -MM -MP -MF="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)"  -nolistfile -isa=rxv2 -debug -fpu -nologo   "$<"
	asrx -output="$(@:%.d=%.obj)" -nolistfile -isa=rxv2 -debug -fpu -nologo   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

