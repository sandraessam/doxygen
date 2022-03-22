/** @file main.c
 *
 *  Created on: 14/01/2022
 *      @author AsmaaSamir
 */


/* -- Includes -- */

/* -- variable types -- */
#include "STD_TYPES.h"   /* for using standard variable types */

/* -- display -- */
#include "LCD.h"		 /* for controlling LCD display  */

/* -- time -- */
#include <util/delay.h>  /* for time */



/** @brief LCD project entrypoint.
 *  
 *  This is the entrypoint for project.
 *  main function to test the LCD display function
 *
 * @return Should not return
 */
void main()
{
	/*
	 * array to save my name "asmaa samir" to display it on LCD 
	 * for test display using ascii codes
	 */
	uint8 name[15]={0x41,0x53,0x4D,0x41,0x41,0x20,0x53,0x41,0x4D,0x49,0x52};
	
	/*
	 * call DIO_INIT for set all input/output bits state
	 */
	DIO_INIT();
	
	/*
	 * call LCD_INIT for making all setup commands to power display on
	 */
	LCD_vidInit();
	
	/*
	 * while loop to loop on test functions
	 */
	 while(1)
	 {
		 /*
		  * test display one character
		  */
		 LCD_vidSendChar('G');
		 _delay_ms(1000);
		 LCD_vidSendCommand(LCD_CLEAR);
		 
		 /*
		  * test display array with defferent length input
		  */
		 LCD_vidSendString(&name[0],5);
		 _delay_ms(1000);
		 LCD_vidSendCommand(LCD_CLEAR);

		 LCD_vidSendString(&name[0],12);
		 _delay_ms(1000);
		 LCD_vidSendCommand(LCD_CLEAR);
		 
		 /*
		  * test display "anta 7ramy" word
		  */
		 LCD_vidSindExtraChar(1,1);
		 _delay_ms(1000);
		 LCD_vidSendCommand(LCD_CLEAR);
	 }


}
