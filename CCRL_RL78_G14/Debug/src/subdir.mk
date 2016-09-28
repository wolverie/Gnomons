################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
..\src/cstart.asm \
..\src/stkinit.asm 

C_SRCS += \
..\src/r_cg_cgc.c \
..\src/r_cg_cgc_user.c \
..\src/r_cg_intc.c \
..\src/r_cg_intc_user.c \
..\src/r_cg_port.c \
..\src/r_cg_port_user.c \
..\src/r_cg_wdt.c \
..\src/r_cg_wdt_user.c \
..\src/r_main.c \
..\src/r_systeminit.c 

C_DEPS += \
./src/r_cg_cgc.d \
./src/r_cg_cgc_user.d \
./src/r_cg_intc.d \
./src/r_cg_intc_user.d \
./src/r_cg_port.d \
./src/r_cg_port_user.d \
./src/r_cg_wdt.d \
./src/r_cg_wdt_user.d \
./src/r_main.d \
./src/r_systeminit.d 

OBJS += \
./src/cstart.obj \
./src/r_cg_cgc.obj \
./src/r_cg_cgc_user.obj \
./src/r_cg_intc.obj \
./src/r_cg_intc_user.obj \
./src/r_cg_port.obj \
./src/r_cg_port_user.obj \
./src/r_cg_wdt.obj \
./src/r_cg_wdt_user.obj \
./src/r_main.obj \
./src/r_systeminit.obj \
./src/stkinit.obj 

ASM_DEPS += \
./src/cstart.d \
./src/stkinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.asm src/asm.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Assembler'
	scandep1 -MM -MP -MF"$(@:%.obj=%.d)" -MT"$(@:%.obj=%.obj)" -MT"$(@:%.obj=%.d)"   -D__RL78_S3__  -D__UCHAR -D__UBIT  -D__RENESAS__=1 -D__RENESAS_VERSION__=0x -D__RL78__ -D__CCRL__ -D__CCRL -U__STDC_HOSTED__ -U__STDC_VERSION__ -U_WIN32 -UWIN32 -U__WIN32__ -U__GNUC__ -U__GNUC_MINOR__ -U__GNUC_PATCHLEVEL__   -E -quiet -I. -C "$<"
	ccrl -o "$(@:%.d=%.obj)" -cpu=S3 -c -dev="C:/Renesas/e2_studio/DebugComp/RL78\Common\DR5F104PJ.DVF" -g   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

src/%.obj: ../src/%.c src/c.sub
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrl  -MM -MP -o "$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)"  -cpu=S3 -dev="C:/Renesas/e2_studio/DebugComp/RL78\Common\DR5F104PJ.DVF" -I "C:\PROGRA~2\Renesas\RL78\1_2_0/inc" -g   "$<"
	ccrl -o "$(@:%.d=%.obj)" -cpu=S3 -c -dev="C:/Renesas/e2_studio/DebugComp/RL78\Common\DR5F104PJ.DVF" -I "C:\PROGRA~2\Renesas\RL78\1_2_0/inc" -g   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

