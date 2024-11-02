/*
 * LDMAX_private.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Ahmed Ali
 */

#include "SS_interface.h"



u8 SS_grid[10]={
	0b00111111,  //0
	0b00000110,  //1
	0b01011011,  //2
	0b01001111,  //3
	0b01100110,  //4
	0b01101101,  //5
	0b01111101,  //6
	0b00000111,  //7
	0b01111111,  //8
	0b01101111   //9
};

void SS_voidSSInit(u8 PORT, u8 POS)
{
	GPIO_voidSetHalfPortDirection(PORT, POS, OUTPUT_SPEED_2MHZ_PP);
}



void SS_voidDisplayNum(u8 PORT, u8 POS, u8 num)
{
#if SS_TYPE == CATHODE
		GPIO_voidSetHalfPortValue(PORT, POS,SS_grid[num]);
#elif SS_TYPE == ANODE
		GPIO_voidSetHalfPortValue(PORT, POS,~(SS_grid[num]));
#endif
}

void SS_voidCountUp(u8 PORT, u8 POS)// 0 -> 9
{
	for (u8 i =0 ; i<10 ; i++)
	{
		SS_voidDisplayNum(PORT, POS,i);
		STK_delay(DELAYTIME);
	}
}
void SS_voidCountDown(u8 PORT, u8 POS) // 9 -> 0
{
	{
		for (s8 i =9 ; i>=0 ; i--)
		{
			SS_voidDisplayNum(PORT, POS,i);
			STK_delay(DELAYTIME);
		}
	}
}
void SS_voidTurnOFF(u8 PORT, u8 POS)
{
	GPIO_voidSetHalfPortValue(PORT, POS, 0X00);
}

void SS_voidCheckAll(u8 PORT, u8 POS)
{
	GPIO_voidSetHalfPortValue(PORT, POS, 0XFF);
}


void SS_voidDisplay2Digits(u8 PORT1, u8 POS1, u8 PORT2, u8 POS2, u8 num)
{
	u8 digt1= num /10;
	u8 digt2 =num %10;

	SS_voidDisplayNum(PORT1, POS1,digt1);
	SS_voidDisplayNum(PORT2, POS2,digt2);

}
