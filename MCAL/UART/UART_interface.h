/*
 * UART_interface.h
 *
 *  Created on: Oct 21, 2024
 *      Author: Ahmed Ali
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "UART_private.h"
#include "UART_config.h"



void UART_Init(void);

void UART_Send(u8 data);

u8 UART_Receive(void);


#endif /* UART_INTERFACE_H_ */
