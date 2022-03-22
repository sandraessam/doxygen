/*
 * Fire_Alarm.c
 *
 *  Created on: Jan 10, 2022
 *      Author: Samaa Seif
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_Confg.h"
#include "DIO.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "ADC.h"
#include "Fire_Alarm.h"
#include "util/delay.h"

volatile uint32 Global_ADC;
/** @brief Main function of the Fire alarm project
 * By using ADC peripheral and after calculating the input signal code take the decision
 * In case the temperature between 0 and 50 degree, Yellow LED will be on
 * In case the temperature between 50 and 100 degree, Blue LED and buzzer will be on
 * In case the temperature between 100 and 150 degree, Red LED and buzzer will be on
 * @param void
 *
 * @return void
 *
 */

void Fire_MainFunction(void) {
	volatile uint32 Analog = ((uint32) (1000 * (Global_ADC * Vref))) / 1024;
	uint32 Degree = (Analog / 10);
	if (Degree >= 0 && Degree <= Level1) {
		DIO_Write_Channel(LED1, HIGH);
		DIO_Write_Channel(LED2, LOW);
		DIO_Write_Channel(LED3, LOW);
		DIO_Write_Channel(FIRE_Buz, LOW);
	} else if (Degree > Level1 && Degree <= Level2) {
		DIO_Write_Channel(LED1, LOW);
		DIO_Write_Channel(LED2, HIGH);
		DIO_Write_Channel(LED3, LOW);
		DIO_Write_Channel(FIRE_Buz, HIGH);
		_delay_ms(500);
		DIO_Write_Channel(FIRE_Buz, LOW);
	} else if (Degree > Level2 && Degree <= Level3) {
		DIO_Write_Channel(LED1, LOW);
		DIO_Write_Channel(LED2, LOW);
		DIO_Write_Channel(LED3, HIGH);
		DIO_Write_Channel(FIRE_Buz, HIGH);
		_delay_ms(500);
		DIO_Write_Channel(FIRE_Buz, LOW);

	}
}
