/*
 * sp_stm32_sd.c
 *
 *  Created on: Nov 23, 2020
 *      Author: sijan
 */

#include <sp_stm32_sd.h>

uint8_t spi_rx_buffer[45];

/*
 * Initialise the SD-Card
 * Sending 10 dummy byte before sending any command
 */
void sd_init(void) {

    dummy_byte();

    uint8_t cmd[] = { 0x40 | 0x00 /* CMD0 */, 0x00, 0x00, 0x00,
            0x00 /* ARG = 0 */, 0x95 /* CRC7 + end bit */};
    sd_sendSPI(SPI1, cmd, sizeof(cmd));

    SPI_Receivedata(SPI1, spi_rx_buffer, 1);

    dummy_byte();

    uint8_t cmd8[] = { 0x40 | 0x08, 0x00, 0x00, 0x01, 0xAA, 0x87 };
    sd_sendSPI(SPI1, cmd8, sizeof(cmd8));

    SPI_Receivedata(SPI1, spi_rx_buffer, 5);

    do {
        dummy_byte();
        uint8_t cmd55[] = { 0x40 | 0x37 /* CMD55 */, 0x00, 0x00, 0x00,
                0x00 /* ARG */, (0x7F << 1) | 1 /* CRC7 + end bit */};
        sd_sendSPI(SPI1, cmd55, sizeof(cmd55));

        SPI_Receivedata(SPI1, spi_rx_buffer, 6);

        dummy_byte();

        uint8_t cmd41[] = { 0x40 | 0x29 /* ACMD41 */, 0x40, 0x00, 0x00,
                0x00 /* ARG */, (0x7F << 1) | 1 /* CRC7 + end bit */};
        sd_sendSPI(SPI1, cmd41, sizeof(cmd41));
        SPI_Receivedata(SPI1, spi_rx_buffer, 6);

    } while (*spi_rx_buffer != 0x00); //wait while response is 0x00 from Card

    dummy_byte();
    uint8_t cmd58[] = { 0x40 | 0x3A /* CMD58 */, 0x00, 0x00, 0x00,
            0x00 /* ARG */, (0x7F << 1) | 1 /* CRC7 + end bit */};
    sd_sendSPI(SPI1, cmd58, sizeof(cmd58));
    SPI_Receivedata(SPI1, spi_rx_buffer, 6);

}

/*
 * Write a single block/sector(512 Byte) in SD Card
 *
 */
void sd_writesingleblock(uint32_t blockNum, uint8_t *buffer) {

    dummy_byte();

    uint8_t cmd16[] = { 0x40 | 0x10, 0x00, 0x00, 0x02, 0x00, 0xFF };
    sd_sendSPI(SPI1, cmd16, sizeof(cmd16));
    SPI_Receivedata(SPI1, spi_rx_buffer, 6);

    dummy_byte();
    uint8_t cmd24[] = { 0x40 | 0x18 /* CMD24 */, (blockNum >> 24) & 0xFF, /* ARG */
    (blockNum >> 16) & 0xFF, (blockNum >> 8) & 0xFF, blockNum & 0xFF,
            (0x7F << 1) | 1 };

    sd_sendSPI(SPI1, cmd24, sizeof(cmd24));
    SPI_Receivedata(SPI1, spi_rx_buffer, 6);

    dummy_byte();
    uint8_t dataToken = 0xFE;
    uint8_t crc[2] = { 0xFF, 0xFF };

    sd_sendSPI(SPI1, &dataToken, sizeof(dataToken));
    sd_sendSPI(SPI1, buffer, 15);
    sd_sendSPI(SPI1, crc, sizeof(crc));

    SPI_Receivedata(SPI1, spi_rx_buffer, 6);    //receive without transmit
    delay1();
    delay1();

}

/*
 * Read a block from SD-Card from given physical address
 *
 */
void sd_readsingleblock(uint32_t blockNum, uint8_t *buffer) {

    dummy_byte();

    uint8_t cmd16[] = { 0x40 | 0x10, 0x00, 0x00, 0x02, 0x00, 0xFF };
    sd_sendSPI(SPI1, cmd16, sizeof(cmd16));
    SPI_Receivedata(SPI1, spi_rx_buffer, 6);

    dummy_byte();

    uint8_t cmd17[] = { 0x40 | 0x11, (blockNum >> 24) & 0xFF, /* ARG */
    (blockNum >> 16) & 0xFF, (blockNum >> 8) & 0xFF, blockNum & 0xFF,
            (0x7F << 1) | 1 };

    sd_sendSPI(SPI1, cmd17, sizeof(cmd17));
    SPI_Receivedata(SPI1, spi_rx_buffer, 5);

    uint8_t dataToken = 0xFE;
    wait_fortoken(dataToken);

    SPI_Receivedataall(SPI1, buffer, 512);

    delay1();

}

/*
 * Send SPI Commands
 *
 */
void sd_sendSPI(SPI_TypeDef *SPIx, uint8_t *pdata, uint16_t len) {

    for (uint16_t i = 0; i < len; i++) {
        SPI_Sendchar(SPI1, *(pdata));
        pdata++;
    }
}

void wait_fortoken(uint8_t Token) {
    do {
        SPI_Receivedataall(SPI1, spi_rx_buffer, 1);
    } while (*spi_rx_buffer != 0xFE);
}

void dummy_byte(void) {
    CS_PIN_HIGH();
    uint8_t high = 0xFF;
    for (int i = 0; i < 10; i++) {
        SPI_Sendchar(SPI1, high);
    }
    CS_PIN_LOW();
}
