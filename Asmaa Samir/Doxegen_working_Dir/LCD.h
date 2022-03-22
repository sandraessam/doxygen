/** @file LCD.h
 *
 *	functions that are being used in code for LCD
 *	
 *  Created on: 14/01/2022
 *      @author AsmaaSamir
 */

#include "LCD_CONFIG.h"

#ifndef LCD_H_
#define LCD_H_


/* @brief LCD initialition 
 * 
 * function to initial the LCD to be active
 * by specific steps as in data sheet
 * 
 * @param No parameter need
 * @return Should not return
 */
extern void LCD_vidInit(void);


/* @brief Send command 
 * 
 * function to send command to the lcd to do
 * by specific steps as in data sheet
 * 
 * @param command the command to exectute
 * @return Should not return
 */
extern void LCD_vidSendCommand(uint8 command);


/** @brief print one character
 * 
 * function to send character to the lcd to show it
 * by specific steps as in data sheet
 * 
 * @param data the character to print
 * @return Should not return
 */
extern void LCD_vidSendChar(uint16 data);


/** @brief move cursor
 * 
 * function to go to specific row and column in lcd
 * 
 * @param x the number of row wanted to go
 * @param y the number of column wanted to go
 * @return Should not return
 */
extern void LCD_vidGotoXY(uint8 x,uint8 y);


/** @brief print string of character
 * 
 * function to send string to show it to lcd
 * by using LCD_vidSendChar function and string as  array of char
 * 
 * @param string the array wanted to prin
 * @param index the length of characters must be print from array
 * @return Should not return
 */
extern void LCD_vidSendString(uint8* string,uint8 index);


/** @brief print one character
 * 
 * function to save and show extra string to show it to lcd
 * by using LCD_vidSendChar function and Extra_char array
 * 
 * @param x the number of row wanted to print in
 * @param y the number of column wanted to print in
 * @return Should not return
 */
extern void LCD_vidSindExtraChar(uint8 X,uint8 Y);

#endif /* LCDH_ */
