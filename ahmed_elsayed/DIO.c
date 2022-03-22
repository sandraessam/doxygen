/**
 * @file DIO.c
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief this is digital input output module
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DIO_H
#include "STD_MEMORY_MAP.h"
#include "DIO.h"
/**
 * @brief this function used to inite mcu pins as input or output
 * 
 */
void DIO_INIT(void){
	DIO_PIN_ID_t Pin_Id;
	DIO_PORT_ID_t Port_Id;
	volatile UINT8_t* const Reg[DIO_MAX_PORTS] = { DDRA_ADD, DDRB_ADD, DDRC_ADD, DDRD_ADD };
	for (Pin_Id = DIO_PINA0; Pin_Id < DIO_MAX_PINS; Pin_Id++) {
		Port_Id = Pin_Id / 8;
		switch (Pin_Direction[Pin_Id]) {
		case DIO_PIN_DIRECTION_OUTPUT:
			SET_BIT(*Reg[Port_Id], Pin_Id % 8);
			break;
		case DIO_PIN_DIRECTION_INPUT_PULL_UP:
			CLEAR_BIT(*Reg[Port_Id], Pin_Id % 8);
			DIO_WRITE_PIN_VALUE(Pin_Id, DIO_PIN_STATE_HIGH);
			break;
		case DIO_PIN_DIRECTION_INPUT_FLOAT:
			CLEAR_BIT(*Reg[Port_Id], Pin_Id % 8);
			DIO_WRITE_PIN_VALUE(Pin_Id, DIO_PIN_STATE_LOW);
		break;
		default:
			break;
		}
	}
}
/**
 * @brief this function used to specify state of mcu pin  
 * 
 * @param PIN_ID this value can be:
 *                     DIO_PINA0 to DIO_PINA7
 *                     DIO_PINB0 to DIO_PINB7
 *                     DIO_PINC0 to DIO_PINC7
 *                     DIO_PIND0 to DIO_PIND7
 * @param PIN_STATE this value can be:
 *                      DIO_PIN_STATE_LOW
 *                      DIO_PIN_STATE_HIGH
 */
void DIO_WRITE_PIN_VALUE(const DIO_PIN_ID_t PIN_ID, const DIO_PIN_STATE_t PIN_STATE){
	volatile UINT8_t* const Reg[DIO_MAX_PORTS] = { PORTA_ADD, PORTB_ADD, PORTC_ADD, PORTD_ADD };
	DIO_PORT_ID_t Port_Id = PIN_ID / 8;
	switch (PIN_STATE) {
	case DIO_PIN_STATE_HIGH:
		SET_BIT(*Reg[Port_Id], PIN_ID % 8);
		break;
	case DIO_PIN_STATE_LOW:
		CLEAR_BIT(*Reg[Port_Id], PIN_ID % 8);
		break;
	default:
		break;
	}
}
/**
 * @brief this function used to read mcu pin state
 * 
 * @param PIN_ID this value can be:
 *                  DIO_PINA0 to DIO_PINA7
 *                  DIO_PINB0 to DIO_PINB7
 *                  DIO_PINC0 to DIO_PINC7
 *                  DIO_PIND0 to DIO_PIND7
 * 
 * @return DIO_PIN_STATE_t this value can be:
 *                              DIO_PIN_STATE_LOW
 *                              DIO_PIN_STATE_HIGH
 */
DIO_PIN_STATE_t DIO_READ_PIN_VALUE(const DIO_PIN_ID_t PIN_ID){
	volatile UINT8_t* const Reg[DIO_MAX_PORTS] = { PINA_ADD, PINB_ADD, PINC_ADD, PIND_ADD };
	DIO_PORT_ID_t Port_Id = PIN_ID / 8;
	DIO_PIN_STATE_t State = DIO_PIN_STATE_LOW;
	if(DIO_PIN_STATE_HIGH == GET_BIT(*Reg[Port_Id], PIN_ID % 8)){
		State = DIO_PIN_STATE_HIGH;
	}
	return State;
}
/**
 * @brief this function used to write value to mcu port
 * 
 * @param PORT_ID this value can be:
 *                      DIO_PORTA
 *                      DIO_PORTB
 *                      DIO_PORTC
 *                      DIO_PORTD
 * @param VALUE 
 */
void DIO_WRITE_PORT(const DIO_PORT_ID_t PORT_ID, const UINT8_t VALUE){
	volatile UINT8_t* const Reg[DIO_MAX_PORTS] = { PORTA_ADD, PORTB_ADD, PORTC_ADD, PORTD_ADD };
	*Reg[PORT_ID] = VALUE;
}
/**
 * @brief this function used to read value of mcu port
 * 
 * @param PORT_ID this value can be:
 *                      DIO_PORTA
 *                      DIO_PORTB
 *                      DIO_PORTC
 *                      DIO_PORTD
 * @return UINT8_t this value from 0 to 255
 */
UINT8_t DIO_Read_PORT(const DIO_PORT_ID_t PORT_ID){
	volatile UINT8_t* const Reg[DIO_MAX_PORTS] = { PINA_ADD, PINB_ADD, PINC_ADD, PIND_ADD };
	return *Reg[PORT_ID];
}
#endif
