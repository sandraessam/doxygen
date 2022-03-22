/**
 * @file main.c
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief this is counter project counts from 0 to 99 every one second 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CO_SCH.h"
#include "SSD.h"
/**
 * @brief this funtion used to inite and run the system
 * 
 * @return int this value is 0 if system succeeded 
 */
int main(void)
{
	DIO_INIT();
	CO_SCH_Init();
	CO_SCH_Add_Task(SSD_Update, 0, 1); /* tick=5ms so period=tick*1=5ms */
	CO_SCH_Start();
	while(1){
		CO_SCH_Dispatch_Tasks();
	}
	return 0;
}
