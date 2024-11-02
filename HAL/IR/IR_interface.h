/*
 * IR_interface.h
 *
 *  Created on: Oct 20, 2024
 *      Author: Ahmed Ali
 */

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "IR_config.h"

#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"





void IR_Init();
u8 IR_GetData();


#endif /* IR_INTERFACE_H_ */
