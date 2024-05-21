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

//change the structure of the sTasks to turn it into a doubly linked list
typedef struct sTasks {
    void (*pTask)(void);
    uint32_t Delay_after_task;
    uint32_t Period;
    uint8_t RunMe;
    uint32_t TaskID;
    //previous task of this task
    struct sTasks *previous;
    //next task of this task
    struct sTasks *next;
} sTasks;

#define SCH_MAX_TASKS 40

//init the scheduler.
void SCH_Init(void);
//createTask function use to create the task and it will return a pointer point to a task.
sTasks *createTask(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
//SCH_Arrange_Task use to arrange the position of the task when adding new task or readding a task.
void SCH_Arrange_Task(sTasks *newTask, uint8_t condition);
//change SCH_Add_Task to make it can arrange the new added task.
void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
//SCH_Readd_Task is called when a task finish it process and we want to add the task to the list again.
void SCH_Readd_Task(sTasks *task);
//change the SCH_Update function to make it has complexity O(1).
void SCH_Update(void);
//change nothing
void SCH_Dispatch_Tasks(void);

#endif /* INC_SCHEDULER_H_ */


