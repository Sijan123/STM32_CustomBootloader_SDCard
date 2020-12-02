/*
 * sp_stm32_flash.c
 *
 *  Created on: Nov 18, 2020
 *      Author: sijan
 */

#include <sp_stm32_flash.h>

/*
 * Write a byte to Flash/Main memory in given Address
 */
void Flash_Write(FLASH_TypeDataTypeDef Typedata, uint32_t Address, uint8_t Data) {

    Flash_Unlock();
    WaitBusy_Flash();
    FLASH->CR |= Typedata << (8);
    Activate_Programming();
    *(__IO uint8_t*) Address = (uint8_t) Data;
    WaitBusy_Flash();
    Deactivate_Programming();
    Flash_LockKey();
}

/*
 * Erase a Sector in main memory
 */
void Flash_Erase(FLASH_initEraseTypedef *eraseinit) {

    uint32_t tmp_psize = 0U;

    switch (eraseinit->voltageLevel) {
    case Level0:
        tmp_psize = Data_Byte;
        break;
    case Level1:
        tmp_psize = Data_HalfWord;
        break;
    case Level2:
        tmp_psize = Data_Word;
        break;
    case Level3:
        tmp_psize = Data_DoubleWord;
        break;

    }

    Flash_Unlock();
    clear_bit(FLASH->CR, FLASH_PSIZE_SELECT);
    FLASH->CR |= tmp_psize << (8);
    clear_bit(FLASH->CR, FLASH_SNB_SELECT);
    FLASH->CR |= (eraseinit->sector << (FLASH_SNB_POS));
    set_bit(FLASH->CR, (FLASH_SER_SELECT | FLASH_START_SELECT));
    WaitBusy_Flash();
    clear_bit(FLASH->CR,
            (FLASH_SER_SELECT | FLASH_SNB_SELECT | FLASH_START_SELECT));
    Flash_LockKey();

}

