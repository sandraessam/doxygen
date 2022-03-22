/** @file MEMMAB.h
 *
 * define the addresses of all registers related to DIO .
 *
 *  Created on: 14/01/2022
 *      @author AsmaaSamir
 */


#ifndef MEMMAB_H_
#define MEMMAB_H_

/*
 *  macros are return the value of inside the registers in AVR32 microcontroller
 */
/* port A*/
#define PORTA_Register *((volatile uint8*)0x3B)
#define DDRA_Register *((volatile uint8*)0x3A)
#define PINA_Register *((volatile uint8*)0x39)

/* port B */
#define PORTB_Register *((volatile uint8*)0x38)
#define DDRB_Register *((volatile uint8*)0x37)
#define PINB_Register *((volatile uint8*)0x36)

/* port C */
#define PORTC_Register *((volatile uint8*)0x35)
#define DDRC_Register *((volatile uint8*)0x34)
#define PINC_Register *((volatile uint8*)0x33)

/* port D */
#define PORTD_Register *((volatile uint8*)0x32)
#define DDRD_Register *((volatile uint8*)0x31)
#define PIND_Register *((volatile uint8*)0x30)


/*
 * macros are return the addresses of registers in AVR32 microcontroller
 */
/* port A */
#define PORTA_Address (volatile uint8*)0x3B
#define DDRA_Address (volatile uint8*)0x3A
#define PINA_Address (volatile uint8*)0x39

/* port B */
#define PORTB_Address (volatile uint8*)0x38
#define DDRB_Address (volatile uint8*)0x37
#define PINB_Address (volatile uint8*)0x36

/* port C */
#define PORTC_Address (volatile uint8*)0x35
#define DDRC_Address (volatile uint8*)0x34
#define PINC_Address (volatile uint8*)0x33

/* port D */
#define PORTD_Address (volatile uint8*)0x32
#define DDRD_Address (volatile uint8*)0x31
#define PIND_Address (volatile uint8*)0x30

#endif /* MEMMAB_H_ */
