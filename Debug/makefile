################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./dmtimerCounter.obj" \
"./httpd.obj" \
"./lwiplib.obj" \
"./main.obj" \
"../phoenix.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/Users/sulavs/Downloads/ti_starterware/binary/armv7a/cgt_ccs/am335x/drivers/Debug/drivers.lib" \
-l"C:/Users/sulavs/Downloads/ti_starterware/binary/armv7a/cgt_ccs/am335x/system_config/Debug/system.lib" \
-l"C:/Users/sulavs/Downloads/ti_starterware/binary/armv7a/cgt_ccs/am335x/beaglebone/platform/Debug/platform.lib" \
-l"C:/Users/sulavs/Downloads/ti_starterware/binary/armv7a/cgt_ccs/utils/Debug/utils.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
phoenix.out \

EXE_OUTPUTS__QUOTED += \
"phoenix.out" \

BIN_OUTPUTS += \
C:/Users/sulavs/hogwarts/phoenix/Debug/phoenix.bin \

BIN_OUTPUTS__QUOTED += \
"C:\Users\sulavs\hogwarts\phoenix\Debug\phoenix.bin" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "phoenix.out"

# Tool invocations
phoenix.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7A8 --code_state=32 -me --define=am3359 --define=am335x --define=beaglebone -g --diag_warning=225 --diag_wrap=off --display_error_number -z -m"phoenix.map" --heap_size=0x800 --stack_size=0x800 -i"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/lib" -i"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --reread_libs --define=A8_CORE=1 --diag_wrap=off --display_error_number --warn_sections --xml_link_info="phoenix_linkInfo.xml" --ram_model -o "phoenix.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

C:/Users/sulavs/hogwarts/phoenix/Debug/phoenix.bin: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: Arm Hex Utility'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armhex" --diag_wrap=off -o "C:/Users/sulavs/hogwarts/phoenix/Debug/phoenix.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "dmtimerCounter.obj" "httpd.obj" "lwiplib.obj" "main.obj" 
	-$(RM) "dmtimerCounter.d" "httpd.d" "lwiplib.d" "main.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-"C:/ti/ccs1200/ccs/utils/tiobj2bin/tiobj2bin.bat"  "C:\Users\sulavs\hogwarts\phoenix\Debug\phoenix.out"  "C:\Users\sulavs\hogwarts\phoenix\Debug\phoenix.bin"  "C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armofd.exe"  "C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armhex.exe"  "C:/ti/ccs1200/ccs/utils/tiobj2bin/mkhex4bin.exe" & "../../../../../../../tools/ti_image/tiimage.exe" "0x80000000" "NONE" "C:\Users\sulavs\hogwarts\phoenix\Debug\phoenix.bin" "C:\Users\sulavs\hogwarts\phoenix\Debug\phoenix_ti.bin"
	-copy "C:\Users\sulavs\hogwarts\phoenix\Debug\phoenix.bin" "C:\Users\sulavs\Downloads\bbb_tftp\firmware.bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

