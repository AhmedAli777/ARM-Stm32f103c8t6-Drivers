/*
 * CFile1.c
 *
 * Created: 14/08/2024 10:38:08 ص
 *  Author: Ahmed Ali
 */ 

#include "LCD_interface.h"

void LCD_voidSendCMD(u8 u8CMD)//Send Instruction to LCD
{

	GPIO_voidSetPinValue(LCD_RS, GPIO_LOW);
	GPIO_voidSetPinValue(LCD_RW, GPIO_LOW);
	GPIO_voidSetHalfPortValue(LCD_PORT,u8CMD);
		
	GPIO_voidSetPinValue(LCD_E, GPIO_HIGH);
	GPIO_voidSetPinValue(LCD_E, GPIO_LOW);
	STK_delay(5,MS_UNIT);
}


void LCD_voidWriteChar(u8 u8CHAR) //Send data to LCD
{
		GPIO_voidSetPinValue(LCD_RS, GPIO_HIGH);
		GPIO_voidSetPinValue(LCD_RW, GPIO_LOW);
		GPIO_voidSetHalfPortValue(LCD_PORT,u8CHAR);
		
		GPIO_voidSetPinValue(LCD_E, GPIO_HIGH);
		GPIO_voidSetPinValue(LCD_E, GPIO_LOW);
		STK_delay(5,MS_UNIT);
}

void LCD_voidLCDInit(){
	
	GPIO_voidSetPinDirection(LCD_RS,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LCD_RW,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LCD_E,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetHalfPortDirection(LCD_PORT, OUTPUT_SPEED_2MHZ_PP);
	
	STK_delay(31,MS_UNIT);
	LCD_voidSendCMD(LCD_FUNSET_8BIT);
	STK_delay(40,US_UNIT);
	LCD_voidSendCMD(LCD_DISPON_CUROFF);
	STK_delay(40,US_UNIT);
	LCD_voidSendCMD(LCD_CLR);
	STK_delay(1.54,MS_UNIT);
	LCD_voidSendCMD(LCD_ENTRY_MODE);
	STK_delay(2,MS_UNIT);

}

void LCD_voidGoTo(u8 X, u8 Y)
{
	if (X>0 && X<=16)
	{
		switch(Y)
		{
			case 1: LCD_voidSendCMD(127+X);break;
			case 2: LCD_voidSendCMD(191+X);break;
			default:break;	
		}	
	}
}

void LCD_ClrLCD()
{
	LCD_voidSendCMD(LCD_CLR);
	STK_delay(2,MS_UNIT);
	
}
void LCD_voidWriteStrig(u8 *ptrStr)
{
	u8 counter=0;
	
	while(ptrStr[counter]!='\0')
	{
		LCD_voidWriteChar(ptrStr[counter]);
		counter++;
	}
	
}

void LCD_voidWriteNum(s32 s32NUM)
{
	u32 temp= 1;
	if(s32NUM==0){
		LCD_voidWriteChar('0');
	}

	if(s32NUM<0){
		LCD_voidWriteChar('-');
		s32NUM*=-1;
	}
	while(s32NUM!=0)
	{
		temp= (temp*10)+s32NUM%10;
		s32NUM/=10;
	}
	while(temp !=1)
	{
		LCD_voidWriteChar((temp%10)+48);
		temp/=10;
	}
}

void LCD_voidSaveCustomChar(u8 CGRAMIndex, u8 CustomChar[])
{
	
	LCD_voidSendCMD(LCD_CGRAM_ADDRESS+CGRAMIndex*8);
	
	for(u8 i = 0 ; i<8; i++)
	{
		
		LCD_voidWriteChar(CustomChar[i]);
	}
	
	LCD_voidSendCMD(LCD_DDRAM_SETCURS);
}

void LCD_voidWriteCustomChar(u8 CGRAMIndex)
{
	if(CGRAMIndex<8)
	{
		LCD_voidWriteChar(CGRAMIndex);
		
	}
}
