/*
 * ADC_interface.h
 *
 *  Created on: Oct 18, 2024
 *      Author: Ahmed Ali
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_private.h"
#include "ADC_config.h"



#define ADC_CHANNEL_0    0
#define ADC_CHANNEL_1    1
#define ADC_CHANNEL_2    2
#define ADC_CHANNEL_3    3
#define ADC_CHANNEL_4    4
#define ADC_CHANNEL_5    5
#define ADC_CHANNEL_6    6
#define ADC_CHANNEL_7    7
#define ADC_CHANNEL_8    8
#define ADC_CHANNEL_9    9
#define ADC_CHANNEL_10   10
#define ADC_CHANNEL_11   11
#define ADC_CHANNEL_12   12
#define ADC_CHANNEL_13   13
#define ADC_CHANNEL_14   14
#define ADC_CHANNEL_15   15

#define ADC_SAMPLE_1_5_CYCLES     0b000
#define ADC_SAMPLE_7_5_CYCLES     0b001
#define ADC_SAMPLE_13_5_CYCLES    0b010
#define ADC_SAMPLE_28_5_CYCLES    0b011
#define ADC_SAMPLE_41_5_CYCLES    0b100
#define ADC_SAMPLE_55_5_CYCLES    0b101
#define ADC_SAMPLE_71_5_CYCLES    0b110
#define ADC_SAMPLE_239_5_CYCLES   0b111

#define ADC_SINGLE_CONVERSION     0
#define ADC_CONTINUOUS_CONVERSION 1

#define T_ENABLE                  1
#define T_DISABLE                 0


#define ADC_PRESCALER_DIV2        0b00
#define ADC_PRESCALER_DIV4        0b01
#define ADC_PRESCALER_DIV6        0b10
#define ADC_PRESCALER_DIV8        0b11


void ADC_voidInit(void);
u16 ADC_u16ReadChannel(u8 channel);


#endif /* ADC_INTERFACE_H_ */
