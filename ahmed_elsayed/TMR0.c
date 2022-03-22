/**
 * @file TMR0.c
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief this is timer0 module
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TMR0_H
#include "TMR0.h"
/**
 * @brief this function used to define timer0 prescaler
 * 
 * @param PRESCALER this value can be:
 * 						 TMR0_NO_CLK
 * 						 TMR0_DF1
 * 						 TMR0_DF8
 * 						 TMR0_DF64
 * 						 TMR0_DF256
 * 						 TMR0_DF1024
 * 						 TMR0_EXT_CLK_FALLING_EDGE
 * 						 TMR0_EXT_CLK_RISING_EDGE
 */
void TMR0_Set_Prescaler(const TMR0_PRESCALER_t PRESCALER){
	TCCR0 &= 0XF8;
	TCCR0 |= PRESCALER;
}
/**
 * @brief this function used to define timer0 modes
 * 
 * @param MODE this value can be:
 * 					TMR0_NORMAL
 * 					TMR0_PWM
 * 					TMR0_CTC
 * 					TMR0_FAST_PWM
 */
void TMR0_Mode(const TMR0_MODE_t MODE){
	switch (MODE) {
	case TMR0_NORMAL:
		CLEAR_BIT(TCCR0, 3);
		CLEAR_BIT(TCCR0, 6);
		break;
	case TMR0_PWM:
		SET_BIT(TCCR0, 6);
		CLEAR_BIT(TCCR0, 3);
		break;
	case TMR0_CTC:
		SET_BIT(TCCR0, 3);
		CLEAR_BIT(TCCR0, 6);
		break;
	case TMR0_FAST_PWM:
		SET_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);
		break;
	}
}
/**
 * @brief this function used to inite timer0 and inite both OCR0 and TCNT0
 * 
 */
void TMR0_Init(void){
	TMR0_Set_Buffer(TMR0_TCNTR, 0);
	TMR0_Set_Buffer(TMR0_OCR, 0);
}
/**
 * @brief this function used to enable or disable timer0 interrupt
 * 
 * @param INT this value can be:
 * 					TMR0_OV_INT_ENABLE
 * 					TMR0_OV_INT_DISABLE
 * 					TMR0_OC_INT_ENABLE
 * 					TMR0_OC_INT_DISABLE
 */
void TMR0_INT(const TMR0_INT_t INT){
	switch(INT){
	case TMR0_OV_INT_ENABLE:
		SET_BIT(TIMSK, 0);
		break;
	case TMR0_OV_INT_DISABLE:
		CLEAR_BIT(TIMSK, 0);
		break;
	case TMR0_OC_INT_ENABLE:
		SET_BIT(TIMSK, 1);
		break;
	case TMR0_OC_INT_DISABLE:
		CLEAR_BIT(TIMSK, 1);
		break;
	}
}
/**
 * @brief this function used to define output compare match modes
 * 
 * @param STATE this value can be:
 * 					OC0_DISABLE
 * 					OC0_TOGGLE
 * 					OC0_CLEAR
 * 					OC0_SET
 */
void TMR0_OC0(const TMR0_OC0_t STATE){
	CLEAR_BIT(TCCR0, 4);
	CLEAR_BIT(TCCR0, 5);
	TCCR0 |= (STATE << 4);
}
/**
 * @brief this function used to init timer0 buffers
 * 
 * @param BUFFER this value can be:
 *  						TMR0_TCNTR
 * 							TMR0_OCR
 * @param VALUE this value from 0 to 255
 */
void TMR0_Set_Buffer(const TMR0_BFF_t BUFFER, const UINT8_t VALUE){
	switch (BUFFER) {
	case TMR0_TCNTR:
		TCNT0 = VALUE;
		break;
	case TMR0_OCR:
		OCR0 = VALUE;
		break;
	default:
		break;

	}
}
/**
 * @brief this function used to read timer0 buffers
 * 
 * @param BUFFER this value can be:
 * 					TMR0_TCNTR
 * 					TMR0_OCR
 * @return UINT8_t this value from 0 to 255
 */
UINT8_t TMR0_Read_Buffer(const TMR0_BFF_t BUFFER){
	UINT8_t Buffer = 0;
	switch (BUFFER) {
		case TMR0_TCNTR:
			Buffer = TCNT0;
			break;
		case TMR0_OCR:
			Buffer = OCR0;
			break;
		default:
			break;
		}
	return Buffer;
}
#endif
