/**
 * @file CO_SCH.h
 * @author ahmed elsayed (elbanawiahmed@gmail.com)
 * @brief co-operatine schduler used to handle tasks
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CO_SCH_H
#define CO_SCH_H
#include "STD_TYPES.h"
#include "STD_MEMORY_MAP.h"
#include "TMR0.h"
/**
 * @brief this macro used to define number of tasks 
 * 
 */
#define CO_SCH_MAX_TASKS 1
/**
 * @brief this function used to inite timer,interrupt and the schduler
 * 
 */
void CO_SCH_Init(void);
/**
 * @brief this function used to dispatch tasks
 * 
 */
void CO_SCH_Dispatch_Tasks(void);
/**
 * @brief this function used add tasks to the schduler
 * 
 * @param PTASK pointer to the task
 * @param DELAY task's delay time
 * @param PERIOD task's period
 */
void CO_SCH_Add_Task(void (*const PTASK)(void),
                     const UINT8_t DELAY,
                     const UINT8_t PERIOD);
/**
 * @brief this function used to delete the required task
 * 
 * @param ID required task id
 */
void CO_SCH_Delete_Task(const UINT8_t ID);
/**
 * @brief this function used to start the schduler
 * 
 */
void CO_SCH_Start(void);
/**
 * @brief this function used to stop the schduler
 * 
 */
void CO_SCH_Stop(void);
#if 0
void CO_SCH_Sleep(void);
#endif
#endif
