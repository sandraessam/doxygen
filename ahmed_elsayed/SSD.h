/**
 * @file SSD.h
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief this is 7seg module
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SSD_H
#define SSD_H
#include "DIO.h"
/**
 * @brief this macro used to specify maximum number of 7seg to connected with mcu
 * 
 */
#define SSD_MAX_NUMBERS 2
/**
 * @brief this macro used to enable or diable common cathod mode 
 * 
 */
#define COMM_CATHOD 0
/**
 * @brief this macro used to enable or diable common anode mode
 * 
 */
#define COMM_ANOD 1
/**
 * @brief this macro used to define 7seg mode(common anode or cathod)
 * 
 */
#define SSD_TYPE COMM_CATHOD
/**
 * @brief mapping 7seg pins to mcu pins
 * 
 */
typedef enum{
	SSD_PIN_A = DIO_PIND0,
	SSD_PIN_B = DIO_PIND1,
	SSD_PIN_C = DIO_PIND2,
	SSD_PIN_D = DIO_PIND3,
	SSD_PIN_E = DIO_PIND4,
	SSD_PIN_F = DIO_PIND5,
	SSD_PIN_G = DIO_PIND6,
#if SSD_MAX_NUMBERS == 1
	SSD_UNITS_PIN = DIO_PIND7
#elif SSD_MAX_NUMBERS == 2
	SSD_UNITS_PIN = DIO_PIND7,
	SSD_TENS_PIN = DIO_PINC0
#endif
}SSD_PIN_ID_t;
/**
 * @brief mapping 7seg to mcu port
 * 
 */
typedef enum{
	SSD_PORT_A = DIO_PORTD,
	SSD_PORT_B = DIO_PORTD,
	SSD_PORT_C = DIO_PORTD,
	SSD_PORT_D = DIO_PORTD,
	SSD_PORT_E = DIO_PORTD,
	SSD_PORT_F = DIO_PORTD,
	SSD_PORT_G = DIO_PORTD,
#if SSD_MAX_NUMBERS == 1
	SSD_UNITS_PORT = DIO_PORTD
#elif SSD_MAX_NUMBERS == 2
	SSD_UNITS_PORT = DIO_PORTD,
	SSD_TENS_PORT = DIO_PORTC
#endif
}SSD_PORT_ID_t;
typedef enum{
#if SSD_MAX_NUMBERS == 1
	SSD_UNITS = 0
#elif SSD_MAX_NUMBERS == 2
	SSD_UNITS = 0,
	SSD_TENS
#endif
}SSD_ID_t;
typedef enum{
#if SSD_TYPE == COMM_CATHOD
	SSD_STATE_ON = 0,
	SSD_STATE_OFF
#elif SSD_TYPE == COMM_ANOD
	SSD_STATE_OFF = 0,
	SSD_STATE_ON
#endif
}SSD_STATE_t;
/**
 * @brief this function used to inite 7seg
 * 
 */
extern void SSD_Init(void);
/**
 * @brief this function used to display value on 7seg
 * 
 * @param VALUE this value from 0 to 9
 */
extern void SSD_Display(const UINT8_t VALUE);
/**
 * @brief this function used to switch on specific 7seg
 * 
 * @param SSD_ID this value can be:
 * 					SSD_UNITS
 * 					SSD_TENS
 */
extern void SSD_On(const SSD_ID_t SSD_ID);
/**
 * @brief this function used to switch off specific 7seg
 * 
 * @param SSD_ID this value can be:
 * 					SSD_UNITS
 * 					SSD_TENS
 */
extern void SSD_Off(const SSD_ID_t SSD_ID);
/**
 * @brief this function used to update the displayed value called from the schduler
 * 
 */
void SSD_Update(void);
#endif
