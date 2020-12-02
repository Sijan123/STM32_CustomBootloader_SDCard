/*
 * stm32_uart.c
 *
 *  Created on: 7 Oct 2020
 *      Author: sijan pahari
 */

#include <sp_stm32_uart.h>

void USART_Config(USART_TypeDef *USARTx, USART_ConfigTypedef huartx) {

    USARTx->CR1 |= (uint32_t) huartx.Mode | huartx.Oversampling_Mode
            | huartx.Parity_Control | huartx.Parity_Selection;
    USARTx->BRR = huartx.Baudrate;
}

void USART_Enable(USART_TypeDef *USARTx) {
    USARTx->CR1 |= 1 << (13);
}

void USART_SendChar(USART_TypeDef *USARTx, char data) {
    while (!(USARTx->SR & 1 << (6)))
        ;
    USARTx->DR = data;
}

void USART_SendString(USART_TypeDef *USARTx, char *string) {

    while (*string) {
        USART_SendChar(USARTx, *string);
        string++;
    }
}


void USART_Receive(USART_TypeDef *USARTx, uint8_t *string, uint8_t len) {

    for (uint8_t i = 0; i < len; i++) {
        WAIT_DATA_RECEIVE(USART2);
        *string = Receive_UART(USART2);
        string++;
    }
}

/* prints formatted string to console over UART */
void printmsg(USART_TypeDef *USARTx, char *format, ...) {
    char str[80];

    /*Extract the the argument list using VA apis */
    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);
    USART_SendString(USARTx, str);
    va_end(args);

}

