/** @file LCD_CONFIG.h
 *
 *	some macros for LCD to make code more readable.
 *	
 *  Created on: 14/01/2022
 *     @author AsmaaSamir
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* -- MACROS -- */

/* define the port used in AVR32 microcontroller */
#define LCD_PORT   PORT_A


/*
 * these values used in LCD to make spacific commands 
 */
#define LCD_CLEAR 			0x01
#define LCD_RETURN_HOME 	0x02
#define LCD_ENTRY_MODE 		0x06
#define LCD_DISPLAY_ON		0x0E
#define LCD_DISPLAY_OFF		0x08
#define LCD_FUNCTION_SET 	0x38
#define LCD_FUNCTION_RESET	0x30
#define LCD_SET_CURSOR 		0x14


/*
 * define all LCD pins which connected to DIO pins in AVR32 microcontroller
 */
#define D0 PinA0
#define D1 PinA1
#define D2 PinA2
#define D3 PinA3
#define D4 PinA4
#define D5 PinA5
#define D6 PinA6
#define D7 PinA7

#define RS PinB0
#define RW PinB1
#define E  PinB2

#endif /* LCD_CONFIG_H_ */
