################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include sp_drivers/src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Bootloader_SD.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Bootloader_SD.list \


# All Target
all: Bootloader_SD.elf secondary-outputs

# Tool invocations
Bootloader_SD.elf: $(OBJS) $(USER_OBJS) E:\study\german\ language\7th\ sem\Project_Update\Bootloader_SDCard\Bootload_SD\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "Bootloader_SD.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\study\german language\7th sem\Project_Update\Bootloader_SDCard\Bootload_SD\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Bootloader_SD.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Bootloader_SD.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Bootloader_SD.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
