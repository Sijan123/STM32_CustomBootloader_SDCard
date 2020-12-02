/*
 * sp_stm32_bootloader.c
 *
 *  Created on: Nov 19, 2020
 *      Author: sijan
 */

#include "sp_stm32_bootloader.h"

uint8_t bootloader_rx_buffer[10] = { 0 };
uint8_t sd_data[512] = { 0 };

/*
 * Jump to user application
 * Retrive the MSP value and Reset Handler Address
 * Call the Reset Handler using Function Pointer
 *
 */
void jumpto_app() {

    void (*app_reset_handler)(void);

    uint32_t msp_value = *(volatile uint32_t*) FLASH_SECTOR2_ADDRESS;
    __set_MSP(msp_value);
    uint32_t resethandler_address = *(volatile uint32_t*) (FLASH_SECTOR2_ADDRESS
            + 4);
    app_reset_handler = (void*) resethandler_address;
    app_reset_handler();

}

/*
 * Bootloader Mode commands via UART
 * Erase main memory sector
 * Load binary image from SD-Card
 *
 */
void bootloader_uartread() {

    while (1) {
        uint8_t blcommand;

        printmsg(USART2, "*************************\n");
        printmsg(USART2, "Welcome to Bootloader\n");
        printmsg(USART2, "Erase Sector = 0x00\n");
        printmsg(USART2, "Load Software = 0x01\n");

        USART_Receive(USART2, bootloader_rx_buffer, 1);
        blcommand = *(bootloader_rx_buffer);

        switch (blcommand) {

        case 0x00:
            bootloader_flasherase_cmd();
            break;
        case 0x01:
            bootloader_memwrite_cmd();
            break;
        }
    }
}


/*
 *Erase main memory sector received UART
 *
 */
void bootloader_flasherase_cmd() {

    printmsg(USART2, "Enter Sector number (0-7)\n");
    USART_Receive(USART2, bootloader_rx_buffer, 1);
    uint8_t sector = *(bootloader_rx_buffer);

    FLASH_initEraseTypedef ftype;
    ftype.voltageLevel = 0;
    ftype.sector = sector;

    Flash_Erase(&ftype);

    printmsg(USART2, "Sector %d erased \n", sector);

}

/*
 * Read image from SD-Card and place to buffer sd_data[512]
 * 512 byte of data is copied in one block
 */

void bootloader_memwrite_cmd() {

    printmsg(USART2, "Enter Memory Addess \n");
    USART_Receive(USART2, bootloader_rx_buffer, 4);
    uint32_t mem_address = *(uint32_t*) (bootloader_rx_buffer);

    sd_init();
    uint32_t sd_address = 0x006028;

    for (uint8_t l = 0; l < 3; l++) {
        sd_readsingleblock(sd_address + l, sd_data);
        execute_memorywrite(sd_data, mem_address + (512 * l), 512);
    }

    printmsg(USART2, "Program Loaded\n");

}

/*
 * Place data from Buffer to Sector-2
 */
void execute_memorywrite(uint8_t *pbuffer, uint32_t mem_address,
        uint16_t payload_len) {

    for (uint32_t i = 0; i < payload_len; i++) {
        Flash_Write(Data_Byte, mem_address + (i), pbuffer[i]);
    }
}


void bootloader_sendUART(USART_TypeDef *USARTx, uint8_t *pdata, uint8_t len) {

    for (uint8_t i = 0; i < len; i++) {
        USART_SendChar(USART2, *(pdata));
        pdata++;
    }
}
