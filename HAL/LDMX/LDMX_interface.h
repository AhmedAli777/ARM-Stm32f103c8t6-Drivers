/*
 * LDMAX_private.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Ahmed Ali
 */


#ifndef LDMX_INT_H_
#define LDMX_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "LDMX_config.h"
#include "LDMX_private.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"

void LDMX_voidInit();
void LDMX_voidDisplay( u8 *copy_u8Data);

#endif /* LDMX_INT_H_ */
