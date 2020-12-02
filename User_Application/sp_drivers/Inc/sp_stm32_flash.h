/*
 * sp_stm32_flash.h
 *
 *  Created on: Nov 18, 2020
 *      Author: sijan
 */

#ifndef SP_STM32_FLASH_H_
#define SP_STM32_FLASH_H_

#include "stm32f4xx.h"
#include "stdio.h"


typedef enum {
    Data_Byte = 0x00,
    Data_HalfWord = 0x01,
    Data_Word = 0x02,
    Data_DoubleWord = 0x03

} FLASH_TypeDataTypeDef;


typedef enum {
    sector0 = 0x00,
    sector1 = 0x01,
    sector2 = 0x02,
    sector4 = 0x03,
    sector5 = 0x04,
    sector6 = 0x05,
    sector7 = 0x06
} FLASH_SectorTypeDef;


typedef enum {
    Level0 = 0x00,
    Level1 = 0x01,
    Level2 = 0x02,
    Level3 = 0x03
} FLASH_voltagelevelTypeDef;


typedef struct{
    FLASH_SectorTypeDef sector;
    uint32_t voltageLevel;
}FLASH_initEraseTypedef;

#define FLASH_SNB_POS 3
#define FLASH_SNB_SELECT   0x0F<<(FLASH_SNB_POS)

#define FLASH_SER_POS 1
#define FLASH_SER_SELECT   0x01<<(FLASH_SER_POS)

#define FLASH_PSIZE_POS 8
#define FLASH_PSIZE_SELECT  0x03<<(FLASH_PSIZE_POS)

#define FLASH_PG_POS 0
#define FLASH_PG_SELECT  0x01<<(FLASH_PG_POS)

#define FLASH_START_POS 16
#define FLASH_START_SELECT  0x01<<(FLASH_START_POS)

#define set_bit(REG, BIT)     ((REG) |= (BIT))
#define clear_bit(REG, BIT)   ((REG) &= ~(BIT))
#define read_bit(REG, BIT)    ((REG) & (BIT))
#define clear_reg(REG)        ((REG) = (0x0))
#define write_reg(REG, VAL)   ((REG) = (VAL))
#define read_reg(REG)         ((REG))


#define Activate_Programming() (FLASH->CR  |= 1<<(0))
#define Deactivate_Programming() (clear_bit(FLASH->CR,FLASH_PG_SELECT))

#define WaitBusy_Flash() while((FLASH->SR) & 1<<(16))

#define Flash_Unlock() do{FLASH->KEYR = 0x45670123; FLASH->KEYR = 0xCDEF89AB;}while(0)
#define Flash_UnlockOPTR() do{FLASH->OPTKEYR = 0x08192A3B; FLASH->OPTKEYR = 0x4C5D6E7F;}while(0)


#define Flash_LockKey() (FLASH->CR |= 1<<(31))


void Flash_Write(FLASH_TypeDataTypeDef Typedata, uint32_t Address, uint64_t Data);

void Flash_Write_Byte(uint32_t Address, uint64_t Data);
void Flash_Write_HalfWord(uint32_t Address, uint64_t Data);

void Flash_Erase(FLASH_initEraseTypedef *eraseinit);




#endif /* SP_STM32_FLASH_H_ */
