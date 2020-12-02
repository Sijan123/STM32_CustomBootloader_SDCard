#include "main.h"
#include "stdio.h"

//delay
void delay1(void);

/*
 * Initialise GPIO CLocks
 * Input Mode for User-Button
 */
void gpioinit(void) {

    RCC_AHB1_CLKEN(RCC_AHB1Peri_GPIOA);
    RCC_AHB1_CLKEN(RCC_AHB1Peri_GPIOB);
    RCC_AHB1_CLKEN(RCC_AHB1Peri_GPIOC);

    GPIO_Config(GPIOC, 13, Input_Mode, No, No_AF);
}

/*
 * Initialise UART1-Interface
 * TX_PIN : PA2
 * RX_PIN : PA3
 */
void uartinit(void) {

    RCC_APB1_CLKEN(RCC_APB1Peri_USART2);
    GPIO_Config(GPIOA, 3, Alternate_Mode, No, AF_SPI_USART);
    GPIO_Config(GPIOA, 2, Alternate_Mode, No, AF_SPI_USART);

    USART_ConfigTypedef huart;

    huart.Mode = USART_TX_RX_ENABLE;
    huart.Oversampling_Mode = Oversampling_16;
    huart.Parity_Control = Parity_Disable;
    huart.Parity_Selection = Parity_Odd;
    huart.Baudrate = 0x683;  //1200 0x3415 //0x683--9600

    USART_Config(USART2, huart);
    USART_Enable(USART2);
}

/*
 * Initialise SPI1-Interface
 * SCK_PIN : PA5 (SPI clock)
 * MOSI_PIN : PA7 (SPI dataout)
 * MISO_PIN : PA6 (SPI datain)
 * CS_PIN : PB5
 */
void spiinit(void) {

    RCC_APB2_CLKEN(RCC_APB2Peri_SPI1);

    GPIO_Config(GPIOA, SCK_PIN, Alternate_Mode, No, AF_SPI);
    GPIO_Config(GPIOA, MOSI_PIN, Alternate_Mode, No, AF_SPI);
    GPIO_Config(GPIOA, MISO_PIN, Alternate_Mode, No, AF_SPI);
    GPIO_Config(GPIOB, CS_PIN, Output_Mode, Pull_Down, No_AF);

    SPI_Config(SPI1, SPI_BaudRate_sysclkby16, SPI_BIDIMode_2Line, SPI_First_MSB,
            SPI_DataFrame_8Bit, SPI_Master, SPI_Receive);
    SPI_Enable(SPI1);

}

/*
 * SPI Disable before jumping to user app
 */
void spideinit(void) {
    GPIO_Deinit(GPIOA, 5);
    GPIO_Deinit(GPIOA, 6);
    GPIO_Deinit(GPIOA, 7);
    RCC_APB2_CLKDIS(RCC_APB2Peri_SPI1);
}

/*
 * main function for Bootloader
 */
int main(void) {

    gpioinit();
    uartinit();

    //If button is not pressed, jump to user application
    if (GPIO_Read(GPIOC, 13)) {
        spideinit();
        jumpto_app();

    //else load the commands for bootloader
    } else {
        spiinit();
        bootloader_uartread();
    }

    while (1) {

        delay1();
        delay1();

    }

    return 0;
}

void delay1(void) {
    unsigned static volatile long i = 0;
    unsigned static volatile long j = 0;
    for (i = 0; i < 2000; i++) {
        for (j = 0; j < 400;) {
            j++;
        }
    }
}

