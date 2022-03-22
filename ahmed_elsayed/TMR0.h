/**
 * @file TMR0.h
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief this is timer0 module
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TMR0_H
#define TMR0_H
#include "STD_MEMORY_MAP.h"
/**
 * @brief create new data type to express the timer prescaler and type of source clock
 * 
 */
typedef enum{
	TMR0_NO_CLK = 0,
	TMR0_DF1,
	TMR0_DF8,
	TMR0_DF64,
	TMR0_DF256,
	TMR0_DF1024,
	TMR0_EXT_CLK_FALLING_EDGE,
	TMR0_EXT_CLK_RISING_EDGE
}TMR0_PRESCALER_t;
/**
 * @brief create new data type to express timer operation modes
 * 
 */
typedef enum{
	TMR0_NORMAL = 0,
	TMR0_PWM,
	TMR0_CTC,
	TMR0_FAST_PWM
}TMR0_MODE_t;
/**
 * @brief create new data type to express enable or disable timer interrupt 
 * 
 */
typedef enum{
	TMR0_OV_INT_ENABLE = 0,
	TMR0_OV_INT_DISABLE,
	TMR0_OC_INT_ENABLE,
	TMR0_OC_INT_DISABLE
}TMR0_INT_t;
/**
 * @brief create new data type to express output compare match modes 
 * 
 */
typedef enum{
	OC0_DISABLE = 0,
	OC0_TOGGLE, /* Only in Normal Mode, else is Reserved */
	OC0_CLEAR,
	OC0_SET
}TMR0_OC0_t;
/**
 * @brief create new data type to express timers buffer 
 * 
 */
typedef enum{
	TMR0_TCNTR = 0,
	TMR0_OCR
}TMR0_BFF_t;
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
void TMR0_Set_Prescaler(const TMR0_PRESCALER_t PRESCALER);
/**
 * @brief this function used to define timer0 modes
 * 
 * @param MODE this value can be:
 * 					TMR0_NORMAL
 * 					TMR0_PWM
 * 					TMR0_CTC
 * 					TMR0_FAST_PWM
 */
void TMR0_Mode(const TMR0_MODE_t MODE);
/**
 * @brief this function used to inite timer0 and inite both OCR0 and TCNT0
 * 
 */
void TMR0_Init(void);
/**
 * @brief this function used to enable or disable timer0 interrupt
 * 
 * @param INT this value can be:
 * 					TMR0_OV_INT_ENABLE
 * 					TMR0_OV_INT_DISABLE
 * 					TMR0_OC_INT_ENABLE
 * 					TMR0_OC_INT_DISABLE
 */
void TMR0_INT(const TMR0_INT_t INT);
/**
 * @brief this function used to define output compare match modes
 * 
 * @param STATE this value can be:
 * 					OC0_DISABLE
 * 					OC0_TOGGLE
 * 					OC0_CLEAR
 * 					OC0_SET
 */
void TMR0_OC0(const TMR0_OC0_t STATE);
/**
 * @brief this function used to init timer0 buffers
 * 
 * @param BUFFER this value can be:
 *  						TMR0_TCNTR
 * 							TMR0_OCR
 * @param VALUE this value from 0 to 255
 */
void TMR0_Set_Buffer(const TMR0_BFF_t BUFFER, const UINT8_t VALUE);
/**
 * @brief this function used to read timer0 buffers
 * 
 * @param BUFFER this value can be:
 * 					TMR0_TCNTR
 * 					TMR0_OCR
 * @return UINT8_t this value from 0 to 255
 */
UINT8_t TMR0_Read_Buffer(const TMR0_BFF_t BUFFER);
#endif
