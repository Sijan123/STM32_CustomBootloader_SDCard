/*
 * sp_stm32_bootloader.h
 *
 *  Created on: Nov 19, 2020
 *      Author: sijan
 */

#ifndef SP_STM32_BOOTLOADER_H_
#define SP_STM32_BOOTLOADER_H_

#include <sp_stm32_gpio.h>
#include "stm32f4xx.h"
#include "stdio.h"
#include "main.h"
#include <sp_stm32_uart.h>
#include <sp_stm32_flash.h>

#define FLASH_SECTOR2_ADDRESS 0x08008000

#define CRC_FAIL 1
#define CRC_SUCESS 0

#define ACK 0xA5
#define NACK  0X7F

typedef enum {
    BL_GET_VER = 0x51,
    BL_GET_HELP = 0x52,
    BL_FLASH_ERASE = 0x56,
    BL_MEM_WRITE = 0x57
} Bootloader_CommandTypeDef;

void bootloader_uartread();
void jumpto_app();


void bootloader_flasherase_cmd();
void bootloader_memwrite_cmd();

void execute_memorywrite(uint8_t *pdata, uint32_t mem_address, uint16_t payload_len);
void bootloader_sendUART(USART_TypeDef *USARTx,uint8_t *pdata,uint8_t len);


#endif /* SP_STM32_BOOTLOADER_H_ */
