################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf *.sni *.dbg *.lst *.lis *.lpp *.map *.x *.h *.lbk *.abs *.fsy

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OBJ_DEPS)),)
-include $(OBJ_DEPS)
endif
ifneq ($(strip $(ABS_DEPS)),)
-include $(ABS_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(O_DEPS)),)
-include $(O_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

ifneq ($(strip $(SRC_UPPER_SRCS)),)
ALL_ASMS += $(SRC_UPPER_SRCS) 
endif
ifneq ($(strip $(SRC_SRCS)),)
ALL_ASMS += $(SRC_SRCS) 
endif
ifneq ($(strip $(S_UPPER_SRCS)),)
ALL_ASMS += $(S_UPPER_SRCS) 
endif
ifneq ($(strip $(S_SRCS)),)
ALL_ASMS += $(S_SRCS) 
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LINKER_OUTPUT_OUTPUTS += \
CCRL_RL78_G14.abs \

# All Target
all: CCRL_RL78_G14.abs
	@echo 'Build complete.'

# Tool invocations
CCRL_RL78_G14.abs: $(OBJS) $(ALL_ASMS) 
	@echo 'Invoking: Linker'
	@echo 'Building target:'
	rlink  -subcommand="LinkerSubCommand.tmp"  -library="C:\PROGRA~2\Renesas\RL78\1_2_0\lib\rl78em4s.lib" -library="C:\PROGRA~2\Renesas\RL78\1_2_0\lib\rl78em4r.lib" -list="CCRL_RL78_G14.map" -nooptimize -entry=_start -auto_section_layout -security_id=00000000000000000000 -ocdbg=84 -debug_monitor=1fe00-1ffff -user_opt_byte=fffff8 -output="CCRL_RL78_G14.abs" -debug -nocompress -memory=high -vectn=2=ffff -rom=.data=.dataR,.sdata=.sdataR -device="C:/Renesas/e2_studio/DebugComp/RL78\Common\DR5F104PJ.DVF" -nomessage -nologo
	@echo 'Finished building target:'
	@echo.
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) 
	-rm -rf "src"/*.obj "src"/*.d "src"/*.src "src"/*.p "src"/*.pp "src"/*.mrc "src"/*.prn
	@echo.
	@echo 'Clean complete.'

post-build:
	@echo.
	-C:\Renesas\E2_STU~1\DEBUGC~1\RENESA~1.EXE CCRL_RL78_G14.abs CCRL_RL78_G14.x
	@echo.

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
