################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sp_drivers/src/sp_stm32_adc.c \
../sp_drivers/src/sp_stm32_bootloader.c \
../sp_drivers/src/sp_stm32_clock.c \
../sp_drivers/src/sp_stm32_crc.c \
../sp_drivers/src/sp_stm32_flash.c \
../sp_drivers/src/sp_stm32_gpio.c \
../sp_drivers/src/sp_stm32_sd.c \
../sp_drivers/src/sp_stm32_spi.c \
../sp_drivers/src/sp_stm32_timer.c \
../sp_drivers/src/sp_stm32_uart.c 

OBJS += \
./sp_drivers/src/sp_stm32_adc.o \
./sp_drivers/src/sp_stm32_bootloader.o \
./sp_drivers/src/sp_stm32_clock.o \
./sp_drivers/src/sp_stm32_crc.o \
./sp_drivers/src/sp_stm32_flash.o \
./sp_drivers/src/sp_stm32_gpio.o \
./sp_drivers/src/sp_stm32_sd.o \
./sp_drivers/src/sp_stm32_spi.o \
./sp_drivers/src/sp_stm32_timer.o \
./sp_drivers/src/sp_stm32_uart.o 

C_DEPS += \
./sp_drivers/src/sp_stm32_adc.d \
./sp_drivers/src/sp_stm32_bootloader.d \
./sp_drivers/src/sp_stm32_clock.d \
./sp_drivers/src/sp_stm32_crc.d \
./sp_drivers/src/sp_stm32_flash.d \
./sp_drivers/src/sp_stm32_gpio.d \
./sp_drivers/src/sp_stm32_sd.d \
./sp_drivers/src/sp_stm32_spi.d \
./sp_drivers/src/sp_stm32_timer.d \
./sp_drivers/src/sp_stm32_uart.d 


# Each subdirectory must supply rules for building sources it contributes
sp_drivers/src/sp_stm32_adc.o: ../sp_drivers/src/sp_stm32_adc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_adc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_bootloader.o: ../sp_drivers/src/sp_stm32_bootloader.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_bootloader.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_clock.o: ../sp_drivers/src/sp_stm32_clock.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_clock.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_crc.o: ../sp_drivers/src/sp_stm32_crc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_crc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_flash.o: ../sp_drivers/src/sp_stm32_flash.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_flash.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_gpio.o: ../sp_drivers/src/sp_stm32_gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_sd.o: ../sp_drivers/src/sp_stm32_sd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_sd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_spi.o: ../sp_drivers/src/sp_stm32_spi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_timer.o: ../sp_drivers/src/sp_stm32_timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
sp_drivers/src/sp_stm32_uart.o: ../sp_drivers/src/sp_stm32_uart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"E:/study/german language/7th sem/Project_Update/Bootloader_SDCard/Bootload_SD/sp_drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"sp_drivers/src/sp_stm32_uart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

