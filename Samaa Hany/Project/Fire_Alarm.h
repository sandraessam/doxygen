/*
 * Fire_Alarm.h
 *
 *  Created on: Jan 10, 2022
 *      Author: Samaa Seif
 */

#ifndef FIRE_ALARM_H_
#define FIRE_ALARM_H_

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
void Fire_MainFunction(void);

/*LEDs for the alarm: 1- LED1: Yellow for normal temperature
 * 					  2- LED2: Blue for higher temperature
 * 					  3- LED3: Red for extremely high temperature
 * */
#define LED1  PORT_B0
#define LED2  PORT_B1
#define LED3  PORT_B2

/*Levels of temperature: 1- Level1: Normal temperature
 * 					  	 2- Level2: Higher temperature
 * 					     3- Level3: Extremely high temperature
 * */
#define Level1 50
#define Level2 100
#define Level3 150

#define FIRE_Buz  PORT_B3
volatile uint32 Global_ADC;

#endif /* FIRE_ALARM_H_ */
