/**
 * @file DIO.h
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief this is digital input output module
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DIO_H
#define DIO_H
#include "STD_TYPES.h"
#include "STD_BITS.h"
#include "DIO_CFG.h"
/**
 * @brief this function used to inite mcu pins as input or output
 * 
 */
extern void DIO_INIT(void);
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
extern void DIO_WRITE_PIN_VALUE(const DIO_PIN_ID_t PIN_ID, const DIO_PIN_STATE_t PIN_STATE);
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
extern DIO_PIN_STATE_t DIO_READ_PIN_VALUE(const DIO_PIN_ID_t PIN_ID);
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
extern void DIO_WRITE_PORT(const DIO_PORT_ID_t PORT_ID, const UINT8_t VALUE);
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
extern UINT8_t DIO_Read_PORT(const DIO_PORT_ID_t PORT_ID);
#endif
