/*
 * ADC.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Samaa Seif
 */

#ifndef ADC_H_
#define ADC_H_

/** @brief Initialization of ADC peripheral
 * Enable the Vref by making bit6=1 & bit7=0 in ADMUX register,
 * choose the suitable ADC Pre-scaler by making bit0,bit1 & bit2 in ADCSRA register=1,
 * Enable ADC peripheral by making bit7=0 in ADCSRA register,
 * Enable ADC Interrupt by making bit3=0 in ADCSRA register,
 * and Enable Global Interrupt
 *
 * @param void
 *
 * @return void
 *
 */
void ADC_INIT(void);

/** @brief Initialization of ADC peripheral
 * Start Conversion by making bit6 in ADCSRA register=1
 *
 * @param void
 *
 * @return void
 *
 */
void ADC_StartConversion(void);

/** @brief Read data from ADC register
 *
 * @param void
 *
 * @return Stored value in ADC register
 *
 */
uint16 ADC_Read(void);

#define CH0   0
#define CH1   1
#define CH2   2
#define CH3   3
#define CH4   4
#define CH5   5
#define CH6   6
#define CH7   7


#define Vref  5
#define V  5
#define R  1000

#endif /* ADC_H_ */
