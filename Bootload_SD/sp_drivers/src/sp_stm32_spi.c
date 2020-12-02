#include <sp_stm32_spi.h>

void SPI_Config(SPI_TypeDef *spix, SPI_BaudRateTypeDef baudratepslcr,
        SPI_BIDIModeTypeDef bidimode, SPI_FirstTypeDef firstmsblsb,
        SPI_DataFrameTypeDef dataframe, SPI_MasterTypeDef masterslave,
        SPI_BIDIOETypeDef receivetransmit) {

    spix->CR1 |= baudratepslcr << (3) | firstmsblsb << (7) | dataframe << (11)
            | bidimode << (15) | masterslave << (2) | receivetransmit << (14)
            | 1 << (8) | 1 << (9);
}

void SPI_Enable(SPI_TypeDef *spix) {
    spix->CR1 |= 1 << (6);

}

void SPI_TxBufferEmpty(SPI_TypeDef *spix) {
    while (!(SPI1->SR & 1 << (1)))
        ;

}

void SPI_NotBusy(SPI_TypeDef *spix) {
    while ((SPI1->SR & 1 << (7)))
        ;

}

/*
 * In order to receive the response of command in SPI bus,
 * dummy data (0xFF) is sent twice after command.
 */
void SPI_Receivedata(SPI_TypeDef *spix, uint8_t *data, uint16_t len) {

    SPI_TxBufferEmpty(SPI1);
    spix->DR = 0xFF;
    WAIT_SPI_DATA_RECEIVE(SPI1);
    *(data) = spix->DR;

    for (uint16_t c = 0; c < len; c++) {
        SPI_TxBufferEmpty(SPI1);
        spix->DR = 0xFF;
        SPI_TxBufferEmpty(SPI1);
        WAIT_SPI_DATA_RECEIVE(SPI1);
        *(data) = spix->DR;
        data++;
    }

}

/*
 *Receive data direct after command
 *In order to receive data, must send dummy data for clock
 */
void SPI_Receivedataall(SPI_TypeDef *spix, uint8_t *data, uint16_t len) {
    for (uint16_t c = 0; c < len; c++) {
        SPI_TxBufferEmpty(SPI1);
        spix->DR = 0xFF;
        SPI_TxBufferEmpty(SPI1);
        WAIT_SPI_DATA_RECEIVE(SPI1);
        *(data) = spix->DR;
        data++;
    }
}

void SPI_Senddata(SPI_TypeDef *spix, uint8_t *data) {

    while (*data) {
        SPI_Sendchar(SPI1, *(data));
        data++;
    }
}

/*
 *While sending SPI-data, the receive buffer register must be
 *read to prevent the overflow. Sending and Receiving is simultaneous.
 */
void SPI_Sendchar(SPI_TypeDef *spix, uint8_t data) {

    uint8_t demo;
    SPI_TxBufferEmpty(SPI1);
    spix->DR = data;
    WAIT_SPI_DATA_RECEIVE(SPI1);
    demo = spix->DR;
}

