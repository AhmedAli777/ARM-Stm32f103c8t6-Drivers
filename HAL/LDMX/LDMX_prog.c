/*
 * LDMAX_private.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Ahmed Ali
 */

#include "LDMX_interface.h"


void LDMX_voidInit()
{
	GPIO_voidSetHalfPortDirection( LDMX_ROW_PORT ,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetHalfPortDirection( LDMX_COL_PORT ,OUTPUT_SPEED_2MHZ_PP);

}

void LDMX_voidDisplay( u8 *copy_u8Data)
{
	for(u8 i = 0; i<8; i++)
	{

		GPIO_voidSetHalfPortValue(LDMX_COL_PORT,0xff);
		GPIO_voidSetHalfPortValue(LDMX_ROW_PORT, copy_u8Data[i]);
		GPIO_voidSetHalfPortValue(LDMX_COL_PORT,~(1<<i));

        STK_delay(1,MS_UNIT);
	}	
}


