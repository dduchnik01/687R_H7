################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TouchGFX/target/generated/subdir.mk
-include TouchGFX/target/subdir.mk
-include TouchGFX/gui/src/model/subdir.mk
-include TouchGFX/gui/src/mainscreen_screen/subdir.mk
-include TouchGFX/gui/src/common/subdir.mk
-include TouchGFX/generated/texts/src/subdir.mk
-include TouchGFX/generated/images/src/subdir.mk
-include TouchGFX/generated/gui_generated/src/mainscreen_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/common/subdir.mk
-include TouchGFX/generated/fonts/src/subdir.mk
-include TouchGFX/App/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 687R_H7
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
687R_H7.elf \

MAP_FILES += \
687R_H7.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
687R_H7.list \


# All Target
all: main-build

# Main-build Target
main-build: 687R_H7.elf secondary-outputs

# Tool invocations
687R_H7.elf 687R_H7.map: $(OBJS) $(USER_OBJS) C:\Users\DDusznik\Desktop\Soft\687R_H7\STM32H743XIHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "687R_H7.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\DDusznik\Desktop\Soft\687R_H7\STM32H743XIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="687R_H7.map" -Wl,--gc-sections -static -L"C:\Users\DDusznik\Desktop\Soft\687R_H7\Middlewares\ST\touchgfx\lib\core\cortex_m7\gcc" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

687R_H7.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "687R_H7.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 687R_H7.elf 687R_H7.list 687R_H7.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
