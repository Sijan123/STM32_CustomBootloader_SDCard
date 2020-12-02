/*
 * sp_stm32_crc.h
 *
 *  Created on: 21 Nov 2020
 *      Author: sijan
 */

#ifndef SP_STM32_CRC_H_
#define SP_STM32_CRC_H_

#include "stm32f4xx.h"
#include "stdio.h"
#include "main.h"


#define RESET_POS 0
#define RESET_SELECT 1<<(RESET_POS)



#define RESET_CRC_DR() (set_bit(CRC->CR, RESET_SELECT));



int CRC_Verify(uint8_t *receiveddata, uint32_t length, uint32_t host_crc);
#endif /* SP_STM32_CRC_H_ */
