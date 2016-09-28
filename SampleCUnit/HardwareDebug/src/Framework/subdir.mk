################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/Framework/CUError.c \
..\src/Framework/MyMem.c \
..\src/Framework/TestDB.c \
..\src/Framework/TestRun.c \
..\src/Framework/Util.c 

C_DEPS += \
./src/Framework/CUError.d \
./src/Framework/MyMem.d \
./src/Framework/TestDB.d \
./src/Framework/TestRun.d \
./src/Framework/Util.d 

OBJS += \
./src/Framework/CUError.obj \
./src/Framework/MyMem.obj \
./src/Framework/TestDB.obj \
./src/Framework/TestRun.obj \
./src/Framework/Util.obj 


# Each subdirectory must supply rules for building sources it contributes
src/Framework/%.obj: ../src/Framework/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=c   -include="C:\PROGRA~2\Renesas\RX\2_5_0/include","C:\workspace\SampleCUnit\src\Headers"  -debug -nomessage -isa=rxv2 -fpu -nologo  -define=__RX=1   "$<"
	ccrx -lang=c -output=obj="$(@:%.d=%.obj)"  -include="C:\PROGRA~2\Renesas\RX\2_5_0/include","C:\workspace\SampleCUnit\src\Headers"  -debug -nomessage -isa=rxv2 -fpu -nologo  -define=__RX=1   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

