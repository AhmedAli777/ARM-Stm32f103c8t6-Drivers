/*
 * KPD_interface.h
 *
 * Created: 13/08/2024 02:05:55 م
 *  Author: Ahmed Ali
 */ 


#ifndef KPD_INT_H_
#define KPD_INT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "KPD_config.h"
#include "KPD_private.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"


void KPD_voidKPDInit();
u8   KPD_u8GetKey();


#endif /* KPD_INT_H_ */
