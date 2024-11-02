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

#include "SS_config.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "../../MCAL/STK/STK_interface.h"


#define zero  0
#define one   1
#define two   2
#define three 3
#define four  4
#define five  5
#define six   6
#define seven 7
#define eight 8
#define nine  9

void SS_voidSSInit(u8 PORT, u8 POS); //SS_1 - SS_2 ,,



void SS_voidDisplayNum(u8 PORT, u8 POS, u8 num);
void SS_voidCountUp(u8 PORT, u8 POS);   // 0 -> 9
void SS_voidCountDown(u8 PORT, u8 POS); // 9 -> 0
void SS_voidTurnOFF(u8 PORT, u8 POS);
void SS_voidCheckAll(u8 PORT, u8 POS);
void SS_voidDisplay2Digits(u8 PORT1, u8 POS1, u8 PORT2, u8 POS2, u8 num);

#endif /* LDMX_INT_H_ */
