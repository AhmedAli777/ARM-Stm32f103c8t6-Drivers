/*
 * KPD_prog.c
 *
 * Created: 13/08/2024 02:06:56 م
 *  Author: Ahmed Ali
 */ 



#include "KPD_interface.h"

#if ASCII == ENABLE
u8 KPD_GRID[4][4]={
	{'7'  ,'8' , '9' ,'/'}, //R 0
	{'4'  ,'5' , '6' ,'*'}, //R 1
	{'1'  ,'2' , '3' ,'-'}, //R 2
	{'C'  ,'0' , '=' ,'+'}  //R 3

//   C0    C1   C2    C3
};
#elif ASCII == DISABLE
u8 KPD_GRID[4][4]={
	{7    ,8   , 9   ,'/'}, //R 0
	{4    ,5   , 6   ,'*'}, //R 1
	{1    ,2   , 3   ,'-'}, //R 2
	{'C'  ,'0' , '=' ,'+'}  //R 3

//   C0    C1   C2    C3
};
#endif

u8 COLS_arr[4]={KPD_COL0,KPD_COL1,KPD_COL2,KPD_COL3};
u8 ROWS_arr[4]={KPD_ROW0,KPD_ROW1,KPD_ROW2,KPD_ROW3};

void KPD_voidKPDInit()
{

//set directions
	for( u8 col =0 ; col <COLSNUM; col++)
		{
		GPIO_voidSetPinDirection(KPD_PORT,COLS_arr[col],OUTPUT_SPEED_2MHZ_PP);
		}

	for( u8 row =0 ; row <ROWSNUM; row++)
		{
		GPIO_voidSetPinDirection(KPD_PORT,ROWS_arr[row],INPUT_PULL_UP_DOWEN);
		}

	for( u8 col =0 ; col <COLSNUM; col++)
		{
		GPIO_voidSetPinValue(KPD_PORT,COLS_arr[col],GPIO_HIGH);
		}


	for( u8 row =0 ; row <ROWSNUM; row++)
		{
		GPIO_voidSetPinValue(KPD_PORT,ROWS_arr[row],GPIO_HIGH);
		}

}


u8   KPD_u8GetKey()
{
	u8 key=255;
	
	for( u8 col =0 ; col <COLSNUM; col++)
	{
		
		GPIO_voidSetPinValue(KPD_PORT,COLS_arr[col], GPIO_LOW);
		
		for ( u8 row = 0 ; row < ROWSNUM; row++ )
		{
			
			if ( GPIO_u8GetPinValue(KPD_PORT,ROWS_arr[row] ) == GPIO_LOW)
			{
				key = KPD_GRID [row][col];
			}
			
			while(GPIO_u8GetPinValue(KPD_PORT,ROWS_arr[row] ) == GPIO_LOW);
			STK_delay(10,MS_UNIT);
		}
			
		GPIO_voidSetPinValue(KPD_PORT,COLS_arr[col], GPIO_HIGH);
	}
	return key;
}
