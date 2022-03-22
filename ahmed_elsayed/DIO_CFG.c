/**
 * @file DIO_CFG.c
 * @author your name (elbanawiahmed@gmail.com)
 * @brief this digital input output module configuration used to configure mcu pins as input or output
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DIO_CFG_H
#include "STD_TYPES.h"
#include "DIO_CFG.h"
/**
 * @brief this array used to inite mcu pins dirctions
 * 
 */
DIO_PIN_DIRECTION_t Pin_Direction[DIO_MAX_PINS] = {

		DIO_PIN_DIRECTION_OUTPUT, 			/* PINA0 */
		DIO_PIN_DIRECTION_OUTPUT, 			/* PINA1 */
		DIO_PIN_DIRECTION_OUTPUT, 			/* PINA2 */
		DIO_PIN_DIRECTION_OUTPUT, 			/* PINA3 */

		DIO_PIN_DIRECTION_OUTPUT, 			/* PINA4 */
		DIO_PIN_DIRECTION_OUTPUT, 			/* PINA5 */
		DIO_PIN_DIRECTION_OUTPUT, 			/* PINA6 */
		DIO_PIN_DIRECTION_OUTPUT, 			/* PINA7 */

		DIO_PIN_DIRECTION_OUTPUT, 			/* PINB0 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINB1 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINB2 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINB3 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINB4 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINB5 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINB6 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINB7 */

		DIO_PIN_DIRECTION_OUTPUT, 			/* PINC0 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINC1 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINC2 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINC3 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINC4 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINC5 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINC6 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PINC7 */

		DIO_PIN_DIRECTION_OUTPUT, 			/* PIND0 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PIND1 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PIND2 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PIND3 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PIND4 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PIND5 */
		DIO_PIN_DIRECTION_OUTPUT,			/* PIND6 */
		DIO_PIN_DIRECTION_OUTPUT			/* PIND7 */
};
#endif
