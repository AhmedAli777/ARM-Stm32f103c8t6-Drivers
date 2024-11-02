/*
 * UART_private.h
 *
 *  Created on: Oct 21, 2024
 *      Author: Ahmed Ali
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

typedef struct {
    volatile u32 SR;   // Status register
    volatile u32 DR;   // Data register
    volatile u32 BRR;  // Baud rate register
    volatile u32 CR1;  // Control register 1
    volatile u32 CR2;  // Control register 2
    volatile u32 CR3;  // Control register 3
    volatile u32 GTPR; // Guard time and prescaler register
} UART_TypeDef;

#define UART1_BASE (0x40013800UL)
#define UART1 ((UART_TypeDef *) UART1_BASE)


#define UART_CR1_UE   13  // UART Enable
#define UART_CR1_TE   3   // Transmitter Enable
#define UART_CR1_RE   2   // Receiver Enable
#define UART_SR_TXE   7   // Transmit data register empty
#define UART_SR_RXNE  5   // Read data register not empty

#define TX_PIN   GPIOA,PIN9
#define RX_PIN   GPIOA,PIN10


#endif /* UART_PRIVATE_H_ */
