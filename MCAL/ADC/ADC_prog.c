/*
 * ADC_prog.c
 *
 *  Created on: Oct 18, 2024
 *      Author: Ahmed Ali
 */



#include "ADC_interface.h"


void ADC_voidInit(void) {
    //Enable ADC
	SET_BIT(ADC1->CR2, ADC_CR2_ADON);

    // SAMPLE TIME

    ADC1->SMPR2 |= (ADC_SAMPLE_TIME << (ADC_CHANNEL * 3));

#if (ADC_MODE == ADC_CONTINUOUS_CONVERSION)
        SET_BIT(ADC1->CR2, ADC_CR2_CONT);
#elif (ADC_MODE == ADC_SINGLE_CONVERSION)
        CLR_BIT(ADC1->CR2, ADC_CR2_CONT);
#endif

        RCC_CFGR &= ~(0b11 << 14);
        RCC_CFGR |= (ADC_PRESCALER << 14);

#if INTERNAL_TEMP_SENSOR == T_ENABLE
	SET_BIT(ADC1->CR2, ADC_CR2_TSVREFE);
#endif

	SET_BIT(ADC1->CR2, ADC_CR2_CAL);
    while (GET_BIT(ADC1->CR2, ADC_CR2_CAL) == 1);
}

u16 ADC_u16ReadChannel(u8 channel) {

	ADC1->SQR3 = channel;

    SET_BIT(ADC1->CR2, ADC_CR2_SWSTART );

    while (GET_BIT(ADC1->SR, ADC_SR_EOC) == 0);

    return ADC1->DR;
}
