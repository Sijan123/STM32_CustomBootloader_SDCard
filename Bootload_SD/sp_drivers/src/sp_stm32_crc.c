/*
 * sp_stm32_crc.c
 *
 *  Created on: 21 Nov 2020
 *      Author: sijan
 */

#include "sp_stm32_crc.h"

int CRC_Verify(uint8_t *receiveddata, uint32_t length, uint32_t host_crc) {

    uint32_t calcCRC = 0xFF;
    uint32_t tempdata;

    RESET_CRC_DR();

    for (uint32_t i = 0; i < length; i++) {
        tempdata = (uint32_t) receiveddata[i];
        CRC->DR = tempdata;
        //CRC->DR = receiveddata[i];
    }
    calcCRC = CRC->DR;

    RESET_CRC_DR();

    if (host_crc == calcCRC) {
        return 0;
    } else {
        return 1;
    }
}
