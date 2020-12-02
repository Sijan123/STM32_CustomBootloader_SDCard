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
User_Application.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
User_Application.list \

OBJCOPY_BIN += \
User_Application.bin \


# All Target
all: User_Application.elf secondary-outputs

# Tool invocations
User_Application.elf: $(OBJS) $(USER_OBJS) E:\study\german\ language\7th\ sem\Project_Update\Custom_Bootloader\User_Application\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "User_Application.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\study\german language\7th sem\Project_Update\Custom_Bootloader\User_Application\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="User_Application.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

User_Application.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "User_Application.list"
	@echo 'Finished building: $@'
	@echo ' '

User_Application.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "User_Application.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
