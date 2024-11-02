/*
 * IR_prog.c
 *
 *  Created on: Oct 20, 2024
 *      Author: Ahmed Ali
 */

#include "IR_interface.h"

volatile u8   StartFlag      = 0;
volatile u32  FrameData[50]  = {0};
volatile u8   EdgeCounter    = 0;
volatile u8   IR_Data        = 0;

void IR_PeriodicEXTI();
void ReadFrameArray();

void IR_Init()
{

	EXTI_voidConfigure(IR_PIN, EXTI_FALLING_EDGE, IR_PeriodicEXTI);
}

void IR_PeriodicEXTI() {

    if (StartFlag == 0) {
    	STK_voidRunFunOnceAfter(1000000, US_UNIT, ReadFrameArray); 
    	StartFlag = 1;

    } else if (EdgeCounter <50)  {

        FrameData[EdgeCounter] = STK_u32GetElapsedTime(US_UNIT);

        STK_voidRunFunOnceAfter(1000000, US_UNIT, ReadFrameArray);

        EdgeCounter++;
    }
}

void ReadFrameArray()
{
	u8 i;


	if ( (FrameData[0] >= 9000) && (FrameData[0] <= 15000) ) //START BIT
	{


		for (i=0;i<8;i++)
		{
			if (  (FrameData[17+i] >= 2000) && (FrameData[17+i] <=2300) )
			{
				SET_BIT(IR_Data,i);
			}
			else
			{
				CLR_BIT(IR_Data,i);
			}
		}
	}
	StartFlag     = 0;
	FrameData[0] = 0;
	EdgeCounter   = 0;
}

u8 IR_GetData()
{
	return IR_Data;
}
