/** @file LCD.c
 *
 *	implementation of functions that are being used in code for LCD
 *	
 *  Created on: 14/01/2022
 *  @author AsmaaSamir
 */

/* -- Includes -- */

/* -- variable types -- */
#include "STD_TYPES.h"   /* for using standard variable types */

/* -- input / output -- */
#include "DIO.h"		 /* for using DIO function */

/* -- display -- */
#include "LCD.h"		 /* for controlling LCD display  */

/* -- time -- */
#include <util/delay.h>  /* for time */

/*
 * array to save the characters of word "enta 7ramy" in arabic.
 */
uint8 Extra_char[64]={0x00,0x00,0x13,0x12,0x12,0x1E,0x00,0x00,		//y
					  0x00,0x06,0x19,0x09,0x06,0x00,0x00,0x00,		//m
					  0x04,0x04,0x04,0x04,0x04,0x00,0x03,0x00,	    //a
					  0x00,0x00,0x00,0x00,0x03,0x04,0x18,0x00,		//r
					  0x00,0x00,0x0E,0x01,0x1F,0x00,0x00,0x00,		//ha
					  0x0A,0x00,0x11,0x11,0x1F,0x00,0x00,0x00,		//t
					  0x02,0x00,0x02,0x02,0x1E,0x00,0x00,0x00,		//n
					  0x07,0x1C,0x00,0x04,0x04,0x04,0x00,0x00		//A
};



void 
LCD_vidSendCommand(uint8 command)
{
	DIO_WriteChannel(RS,LOW);

	DIO_WriteChannel(RW,LOW);

	DIO_WriteChannel(E,HIGH);

	DIO_WritePort(LCD_PORT,command);

	DIO_WriteChannel(E,LOW);
	_delay_ms(5);
	DIO_WriteChannel(E,HIGH);
	_delay_ms(10);

}

void 
LCD_vidInit(void)
{
	_delay_ms(50);
	LCD_vidSendCommand(LCD_RETURN_HOME);
	_delay_ms(1);
	LCD_vidSendCommand(LCD_FUNCTION_SET);
	_delay_ms(1);
	LCD_vidSendCommand(LCD_DISPLAY_ON);
	_delay_ms(1);
	LCD_vidSendCommand(LCD_CLEAR);
	_delay_ms(2);
	LCD_vidSendCommand(LCD_ENTRY_MODE);
	_delay_ms(2);
}


void 
LCD_vidSendChar(uint16 data)
{
	DIO_WriteChannel(RS,HIGH);

	DIO_WriteChannel(RW,LOW);

	DIO_WriteChannel(E,HIGH);

	DIO_WritePort(LCD_PORT,data);

	DIO_WriteChannel(E,LOW);
	_delay_ms(5);

	DIO_WriteChannel(E,HIGH);
	_delay_ms(10);
}



void 
LCD_vidGotoXY(uint8 x,uint8 y)
{
	if(y>0 && x<=16)
	{
		switch(y)
		{
		case 1:
			LCD_vidSendCommand(x+127);
			break;
		case 2:
			LCD_vidSendCommand(x+191);
			break;
		}
	}
}



void 
LCD_vidSendString(uint8* string,uint8 index)
{
	uint8 i=0;
	for(i=0;i<index;i++)
	{
		LCD_vidSendChar(string[i]);
		_delay_ms(2);
	}

}


void 
LCD_vidSindExtraChar(uint8 X,uint8 Y)
{
	uint8 i=0,j=0;
	if((X>0 && X<16)&&(Y==1 || Y==2))
	{
		LCD_vidSendCommand(64);
		for(i=0;i<64;i++)
		{
			LCD_vidSendChar(Extra_char[i]);
		}
		LCD_vidSendCommand(128);
		LCD_vidGotoXY(X,Y);
		for(j=0;j<8;j++)
		{
			LCD_vidSendChar(j);
			_delay_ms(10);
			if(j==4){LCD_vidSendChar(0x20);_delay_ms(10);}
		}
	}
}






