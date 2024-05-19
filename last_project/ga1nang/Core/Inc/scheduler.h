/*
 * software_timer.c
 *
 *  Created on: May 19, 2024
 *      Author: Hi There
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct sTasks {
    void (*pTask)(void);
    uint32_t Delay_after_task;
    uint32_t Period;
    uint8_t RunMe;
    uint32_t TaskID;
    struct sTasks *previous;
    struct sTasks *next;
} sTasks;

#define SCH_MAX_TASKS 40

void SCH_Init(void);
sTasks *createTask(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
void SCH_Arrange_Task(sTasks *newTask, uint8_t condition);
void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
void SCH_Readd_Task(sTasks *task);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);

#endif /* INC_SCHEDULER_H_ */


