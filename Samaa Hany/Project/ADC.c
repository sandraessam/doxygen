/*
 * ADC.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include "ADC.h"

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


void ADC_INIT(void) {

	//Enable the Vref
	SET_BIT(ADMUX, CH6);
	CLR_BIT(ADMUX, CH7);

	// ADC Pre-scaler
	SET_BIT(ADCSRA, CH0);
	SET_BIT(ADCSRA, CH1);
	SET_BIT(ADCSRA, CH2);

	// Enable ADC
	SET_BIT(ADCSRA, CH7);

	// Enable ADC Interrupt
	SET_BIT(ADCSRA, CH3);

	// Enable Global Interrupt
	SET_BIT(SREG,CH7);
	ADMUX &= 0xf0;
}

/** @brief Initialization of ADC peripheral
 * Start Conversion by making bit6 in ADCSRA register=1
 *
 * @param void
 *
 * @return void
 *
 */

void ADC_StartConversion(void) {

	//Start Conversion
	SET_BIT(ADCSRA, CH6);
}

/** @brief Read data from ADC register
 *
 * @param void
 *
 * @return Stored value in ADC register
 *
 */
uint16 ADC_Read(void) {
	return ADC;
}
