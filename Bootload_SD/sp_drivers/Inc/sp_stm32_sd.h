/*
 * sp_stm32_sd.h
 *
 *  Created on: Nov 23, 2020
 *      Author: sijan
 */

#ifndef SP_STM32_SD_H_
#define SP_STM32_SD_H_

#include "main.h"
#include "sp_stm32_gpio.h"


#define CS_PIN_LOW() clear_bit(GPIOB->ODR, 1<<(CS_PIN))
#define CS_PIN_HIGH() set_bit(GPIOB->ODR, 1<<(CS_PIN))

#define DATA_TOKEN_CMD24 0xFE


void sd_init(void);
void sd_sendSPI(SPI_TypeDef *SPIx, uint8_t *pdata, uint16_t len);
void sd_readsingleblock(uint32_t blockNum, uint8_t *buffer);
void sd_writesingleblock(uint32_t blockNum, uint8_t *buffer);

void wait_fortoken(uint8_t Token);


#endif /* SP_STM32_SD_H_ */
