################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7A8 --code_state=32 -me --include_path="C:/Users/sulavs/hogwarts/phoenix" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/Users/sulavs/Downloads/ti_starterware/include" --include_path="C:/Users/sulavs/Downloads/ti_starterware/include/hw" --include_path="C:/Users/sulavs/Downloads/ti_starterware/include/armv7a" --include_path="C:/Users/sulavs/Downloads/ti_starterware/include/armv7a/am335x" --include_path="C:/Users/sulavs/Downloads/ti_starterware/third_party/lwip-1.4.0" --include_path="C:/Users/sulavs/Downloads/ti_starterware/third_party/lwip-1.4.0/src/include" --include_path="C:/Users/sulavs/Downloads/ti_starterware/third_party/lwip-1.4.0/src/include/ipv4" --include_path="C:/Users/sulavs/Downloads/ti_starterware/third_party/lwip-1.4.0/src/include/lwip" --include_path="C:/Users/sulavs/Downloads/ti_starterware/third_party/lwip-1.4.0/ports/cpsw" --include_path="C:/Users/sulavs/Downloads/ti_starterware/third_party/lwip-1.4.0/ports/cpsw/include" --include_path="C:/Users/sulavs/Downloads/ti_starterware/third_party/lwip-1.4.0/apps/httpserver_raw" --include_path="C:/Users/sulavs/Downloads/ti_starterware/examples/beaglebone/enet_lwip" --define=am3359 --define=am335x --define=beaglebone -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


