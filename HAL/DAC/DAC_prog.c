/*
 * DAC_prog.c
 *
 *  Created on: Oct 23, 2024
 *      Author: Ahmed Ali
 */

#include "DAC_interface.h"




void DAC_Init()
{
	GPIO_voidSetHalfPortDirection(DAC_PORT,OUTPUT_SPEED_10MHZ_PP );
}



void DAC_GenerateWave(const u8 *row_file)
{
	u32 i;
	for (i=0 ; i< ROW_LENGTH; i++)
	{
		GPIO_voidSetHalfPortValue(DAC_PORT, row_file[i]);
		STK_delay(100,US_UNIT);

	}
}


