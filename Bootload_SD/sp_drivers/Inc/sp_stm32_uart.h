/*
 * stm32_uart.h
 *
 *  Created on: 7 Oct 2020
 *      Author: sijan
 */

#ifndef INC_SP_STM32_UART_H_
#define INC_SP_STM32_UART_H_

#include "stm32f4xx.h"
#include "stdio.h"
#include <stdarg.h>
#include <string.h>
#include <stdint.h>

#define USART_TX_ENABLE 1<<(3)
#define USART_RX_ENABLE 1<<(2)
#define USART_TX_RX_ENABLE 1<<(2) | 1<<(3)

#define Parity_Disable 0x00
#define Parity_Enable  1<<(10)

#define Parity_Even 0x00
#define Parity_Odd  1<<(9)

#define Oversampling_16 0x00
#define Oversampling_8  1<<(15)

typedef struct {
    uint32_t Mode;
    uint32_t Parity_Control;
    uint32_t Parity_Selection;
    uint32_t Oversampling_Mode;
    uint32_t Baudrate;
    uint32_t Int_EN;

} USART_ConfigTypedef;

#define No_Value 0x000
#define UART_RX_INTEN 1<<(5)
#define UART_TX_INTEN 1<<(7)


#define RXNE_POS 5
#define USART_SR_RXNE_SELECT 1<<(RXNE_POS)
#define WAIT_DATA_RECEIVE(HANDLE) while(!((HANDLE->SR)&USART_SR_RXNE_SELECT))

#define UART_IT_EN(HAND, INT) (HAND->CR1 |= INT)

#define UART_RXIT_FLAG 1<<(5)         //uart receive interrupt flag

#define CHECK_UART_ITFLAG(HAND, FLAG) (HAND->SR & FLAG)

#define CHECK_UART_ITFLAG(HAND, FLAG) (HAND->SR & FLAG)

#define Receive_UART(HAND) (HAND->DR)

void USART_Config(USART_TypeDef *USARTx, USART_ConfigTypedef huartx);
void USART_Enable(USART_TypeDef *USARTx);
void USART_SendChar(USART_TypeDef *USARTx, char data);
void USART_SendString(USART_TypeDef *USARTx, char *string);
void USART_Receive(USART_TypeDef *USARTx,uint8_t *string,uint8_t len);
void printmsg(USART_TypeDef *USARTx, char *format,...);

#endif /* INC_SP_STM32_UART_H_ */
