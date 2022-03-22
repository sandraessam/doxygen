/**
 * @file SSD.c
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief this is 7seg module
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SSD_H
#include "DIO.h"
#include "SSD.h"
/**
 * @brief this function used to write value on mcu pins
 * 
 * @param VALUE this value from 0 to 9
 */
static void SSD_Write(const UINT8_t VALUE);
/**
 * @brief this function used to inite 7seg
 * 
 */
void SSD_Init(void){
	/*todo*/
}
/**
 * @brief this function used to display value on 7seg
 * 
 * @param VALUE this value from 0 to 9
 */
void SSD_Display(const UINT8_t VALUE) {
#if SSD_TYPE == COMM_CATHOD
	switch (VALUE) {
	case 0:
		SSD_Write(0X3F);
		break;
	case 1:
		SSD_Write(0X06);
		break;
	case 2:
		SSD_Write(0X5B);
		break;
	case 3:
		SSD_Write(0X4F);
		break;
	case 4:
		SSD_Write(0X66);
		break;
	case 5:
		SSD_Write(0X6D);
		break;
	case 6:
		SSD_Write(0X7C);
		break;
	case 7:
		SSD_Write(0X07);
		break;
	case 8:
		SSD_Write(0X7F);
		break;
	case 9:
		SSD_Write(0X6F);
		break;
	default:
		/* Error */
		break;
	}
#elif SSD_TYPE == COMM_ANOD
	switch (VALUE) {
	case 0:
		SSD_Write(~0X3F);
		break;
	case 1:
		SSD_Write(~0X06);
		break;
	case 2:
		SSD_Write(~0X5B);
		break;
	case 3:
		SSD_Write(~0X4F);
		break;
	case 4:
		SSD_Write(~0X66);
		break;
	case 5:
		SSD_Write(~0X6D);
		break;
	case 6:
		SSD_Write(~0X7C);
		break;
	case 7:
		SSD_Write(~0X07);
		break;
	case 8:
		SSD_Write(~0X7F);
		break;
	case 9:
		SSD_Write(~0X6F);
		break;
	default:
		/* Error */
		break;
	}
#endif
}
/**
 * @brief this function used to write value on mcu pins
 * 
 * @param VALUE this value from 0 to 9
 */
static void SSD_Write(const UINT8_t VALUE){
	DIO_WRITE_PIN_VALUE(SSD_PIN_A, GET_BIT(VALUE, 0));
	DIO_WRITE_PIN_VALUE(SSD_PIN_B, GET_BIT(VALUE, 1));
	DIO_WRITE_PIN_VALUE(SSD_PIN_C, GET_BIT(VALUE, 2));
	DIO_WRITE_PIN_VALUE(SSD_PIN_D, GET_BIT(VALUE, 3));
	DIO_WRITE_PIN_VALUE(SSD_PIN_E, GET_BIT(VALUE, 4));
	DIO_WRITE_PIN_VALUE(SSD_PIN_F, GET_BIT(VALUE, 5));
	DIO_WRITE_PIN_VALUE(SSD_PIN_G, GET_BIT(VALUE, 6));
}
/**
 * @brief this function used to switch on specific 7seg
 * 
 * @param SSD_ID this value can be:
 * 					SSD_UNITS
 * 					SSD_TENS
 */
void SSD_On(const SSD_ID_t SSD_ID){
	switch(SSD_ID){
#if SSD_MAX_NUMBERS == 1
	case SSD_UNITS:
			DIO_WRITE_PIN_VALUE(SSD_UNITS_PIN, SSD_STATE_ON);
			break;
#elif SSD_MAX_NUMBERS == 2
	case SSD_UNITS:
		DIO_WRITE_PIN_VALUE(SSD_UNITS_PIN, SSD_STATE_ON);
		break;
	case SSD_TENS:
			DIO_WRITE_PIN_VALUE(SSD_TENS_PIN, SSD_STATE_ON);
			break;
#endif
	default:
		/* Error: undefined SSD_ID */
		break;
	}
}
/**
 * @brief this function used to switch off specific 7seg
 * 
 * @param SSD_ID this value can be:
 * 					SSD_UNITS
 * 					SSD_TENS
 */
void SSD_Off(const SSD_ID_t SSD_ID){
	switch(SSD_ID){
#if SSD_MAX_NUMBERS == 1
	case SSD_UNITS:
			DIO_WRITE_PIN_VALUE(SSD_UNITS_PIN, SSD_STATE_OFF);
			break;
#elif SSD_MAX_NUMBERS == 2
	case SSD_UNITS:
		DIO_WRITE_PIN_VALUE(SSD_UNITS_PIN, SSD_STATE_OFF);
		break;
	case SSD_TENS:
			DIO_WRITE_PIN_VALUE(SSD_TENS_PIN, SSD_STATE_OFF);
			break;
#endif
	default:
		/* Error: undefined SSD_ID */
		break;
	}
}
/**
 * @brief this function used to update the displayed value called from the schduler
 * 
 */
void SSD_Update(void){
	static UINT8_t Flag = 1, Counter = 200, Time = 0;
	--Counter;
	if(0 == Counter){
		Counter = 200;
		Time++;
		if(Time > 59){
			Time = 0;
		}
	}
	if(Flag){
		SSD_Off(SSD_TENS);
		SSD_On(SSD_UNITS);
		SSD_Display(Time % 10);
		Flag = 0;
	}else{
		SSD_Off(SSD_UNITS);
		SSD_On(SSD_TENS);
		SSD_Display(Time / 10);
		Flag = 1;
	}
}
#endif
