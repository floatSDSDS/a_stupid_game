################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
TOUCHinit/TOUCH_TSC2046.obj: ../TOUCHinit/TOUCH_TSC2046.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"c:/ti/ccsv6/tools/compiler/arm_5.1.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/mywork/Hello2016/TOUCHinit" --include_path="C:/ti/TivaWare_C_Series-2.1.0.12573" --include_path="C:/ti/mywork/Hello2016/User" --include_path="c:/ti/ccsv6/tools/compiler/arm_5.1.6/include" --include_path="C:/ti/mywork/Hello2016" --include_path="C:/ti/mywork/Hello2016/EPIinit" --include_path="C:/ti/mywork/Hello2016/TFTinit" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="TOUCHinit/TOUCH_TSC2046.pp" --obj_directory="TOUCHinit" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


