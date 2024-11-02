/*
 * UART_prog.c
 *
 *  Created on: Oct 21, 2024
 *      Author: Ahmed Ali
 */



#include "UART_interface.h"




void UART_Init(void) {


	GPIO_voidSetPinDirection(TX_PIN ,OUTPUT_SPEED_10MHZ_AFPP);
	GPIO_voidSetPinDirection(RX_PIN ,INPUT_FLOUTING);



    // Baud Rate

    f32 uartdiv= SYSTEM_FREQ / UART_BAUD_RATE;
    u16 mantissa = (u16) uartdiv;
    u16 fraction = (u16)((uartdiv -mantissa) *16);
    UART1->BRR = (mantissa<<4) | fraction;

    UART1->CR1 |= (1 << UART_CR1_TE);  // Sending enable
    UART1->CR1 |= (1 << UART_CR1_RE);  // Receiving enable
    UART1->CR1 |= (1 << UART_CR1_UE);  // UART enable
}

void UART_Send(u8 data) {

	while (!(UART1->SR & (1 << UART_SR_TXE)));
    UART1->DR = data;
}

u8 UART_Receive(void) {
    while (!(UART1->SR & (1 << UART_SR_RXNE)));
    return UART1->DR;
}
