/*
 * DAC_interface.h
 *
 *  Created on: Oct 23, 2024
 *      Author: Ahmed Ali
 */

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DAC_private.h"
#include "DAC_config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"



void DAC_Init();
void DAC_GenerateWave(const u8 *row_file);


#endif /* DAC_INTERFACE_H_ */
