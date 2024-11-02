/*
 * ADC_private.h
 *
 *  Created on: Oct 18, 2024
 *      Author: Ahmed Ali
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

typedef struct {
    volatile u32 SR;      // Status Register
    volatile u32 CR1;     // Control Register 1
    volatile u32 CR2;     // Control Register 2
    volatile u32 SMPR1;   // Sample Time Register 1
    volatile u32 SMPR2;   // Sample Time Register 2
    volatile u32 JOFR[4]; // Injected Channel Data Offset Registers
    volatile u32 HTR;     // Higher Threshold Register
    volatile u32 LTR;     // Lower Threshold Register
    volatile u32 SQR1;    // Regular Sequence Register 1
    volatile u32 SQR2;    // Regular Sequence Register 2
    volatile u32 SQR3;    // Regular Sequence Register 3
    volatile u32 JSQR;    // Injected Sequence Register
    volatile u32 JDR[4];  // Injected Data Registers
    volatile u32 DR;      // Data Register
} ADC_TypeDef;

#define ADC1 ((ADC_TypeDef*) 0x40012400)

#define RCC_CFGR   *((volatile u32*)0x40021004)


#define ADC_CR2_ADON       0
#define ADC_CR2_CONT       1
#define ADC_CR2_CAL        3
#define ADC_CR2_SWSTART    22
#define ADC_CR2_TSVREFE    23
#define ADC_SR_EOC         1


#define RCC_CFGR_ADCPRE     14





#endif /* ADC_PRIVATE_H_ */
