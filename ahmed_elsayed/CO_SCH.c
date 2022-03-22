/**
 * @file CO_SCH.c
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief co-operatine schduler used to handle tasks
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CO_SCH_H
#include "CO_SCH.h"
#define ENDED 0
/**
 *
 * @brief this macro used to mapping tick time:
 * example: 39 == mapped to tick= 5m
 */
#define TMR_INT_CYCLE 39
/**
 * @brief creating a new data type to express task characterstics
 * 
 */
typedef struct{
        void (*pTask)(void);
        UINT8_t Period, Delay, Id, Run;
}TASK_t;
/**
 * @brief this function used to update all tasks
 * 
 */
static void CO_SCH_Update_Tasks(void);
/**
 * @brief array to hold all tasks characterstics
 * 
 */
static TASK_t CO_SCH_Task[CO_SCH_MAX_TASKS];
/**
 * @brief this variable is updated using isr every tick time
 * 
 */
static volatile BOOL_t CO_SCH_Update = FALSE;
/**
 * @brief this function used to delete the required task
 * 
 * @param ID required task id
 */
void CO_SCH_Delete_Task(const UINT8_t ID){
     if(ID < CO_SCH_MAX_TASKS && CO_SCH_Task[ID].pTask != NULL_PTR){
        CO_SCH_Task[ID].pTask = NULL_PTR;
        CO_SCH_Task[ID].Run = 0;
        CO_SCH_Task[ID].Delay = 0;
        CO_SCH_Task[ID].Period = 0;
     }
     else{
        /* Error: Undefined Task */
     }
}
/**
 * @brief this function used to inite timer,interrupt and the schduler
 * 
 */
void CO_SCH_Init(void){
	 UINT8_t Id;
	 /* ToDo: Disable Global Interrupt */
	 GIC;
     for(Id = 0; Id < CO_SCH_MAX_TASKS; Id++){
         CO_SCH_Delete_Task(Id);
     }
     /* To Do: Init Timer Here */
     TMR0_Init();
     TMR0_Mode(TMR0_CTC);
     TMR0_Set_Prescaler(TMR0_NO_CLK);
     TMR0_Set_Buffer(TMR0_OCR, TMR_INT_CYCLE); 		/* 5 ms */
     TMR0_INT(TMR0_OC_INT_ENABLE);
}
/**
 * @brief this function used add tasks to the schduler
 * 
 * @param PTASK pointer to the task
 * @param DELAY task's delay time
 * @param PERIOD task's period
 */
void CO_SCH_Add_Task(void (*const PTASK)(void),
                     const UINT8_t DELAY,
                     const UINT8_t PERIOD){

     static UINT8_t Id = 0;
     if(Id < CO_SCH_MAX_TASKS){
        CO_SCH_Task[Id].pTask = PTASK;
        CO_SCH_Task[Id].Delay = 1 + DELAY;
        CO_SCH_Task[Id].Period = PERIOD;
        CO_SCH_Task[Id].Run = 0;
        CO_SCH_Task[Id].Id = Id;
        Id++;
     }
     else{
        /* Error: Scheduler is Full */
     }
}
/**
 * @brief this function used to dispatch tasks
 * 
 */
void CO_SCH_Dispatch_Tasks(void){
	UINT8_t Id;
     if(TRUE == CO_SCH_Update){
        CO_SCH_Update_Tasks();
        for(Id = 0; Id < CO_SCH_MAX_TASKS; Id++){
            if(CO_SCH_Task[Id].Run > 0){
               CO_SCH_Task[Id].pTask();
               CO_SCH_Task[Id].Run--;
               if(ENDED == CO_SCH_Task[Id].Period){
                  CO_SCH_Delete_Task(Id);
               }
            }
            else{
               /* Task is not Ready */
            }
        }
        CO_SCH_Update = FALSE;
     }
}
/**
 * @brief this function used to update all tasks
 * 
 */
static void CO_SCH_Update_Tasks(void){
	UINT8_t Id;
       for(Id = 0; Id < CO_SCH_MAX_TASKS; Id++){
           if(CO_SCH_Task[Id].pTask != NULL_PTR){
              CO_SCH_Task[Id].Delay--;
              if(ENDED == CO_SCH_Task[Id].Delay){
                 CO_SCH_Task[Id].Run++;
                 CO_SCH_Task[Id].Delay = CO_SCH_Task[Id].Period;
              }
              else{
                 /* Task is not Ready */
              }
           }
           else{
              /* Error: Undefined Task */
           }
       }
}
/**
 * @brief this function used to start the schduler
 * 
 */
void CO_SCH_Start(void){
     /* To Do: Enable Interrupt Here */
	TMR0_Set_Prescaler(TMR0_DF1024);				/* Tick = 128 us */
	TMR0_Set_Buffer(TMR0_OCR, TMR_INT_CYCLE); 		/* 5 ms */
	GIE;
}
/**
 * @brief this function used to stop the schduler
 * 
 */
void CO_SCH_Stop(void){
	GIC;
	TMR0_Set_Prescaler(TMR0_NO_CLK);
}
#if 0
void CO_SCH_Sleep(void){
     /* To Do: */
}
#endif
/**
 * @brief Construct a new ISR object to enable updating the tasks
 * 
 */
ISR(TIMER0_COMP_VECT){
     CO_SCH_Update = TRUE;
}
#endif
