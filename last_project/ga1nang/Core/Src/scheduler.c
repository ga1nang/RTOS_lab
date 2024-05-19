/*
 * software_timer.c
 *
 *  Created on: May 19, 2024
 *      Author: Hi There
 */

#include "scheduler.h"
#include <stdio.h>
#define MAX_TICKS 10

sTasks *head;
uint32_t number_of_Tasks;
uint32_t taskID;

void SCH_Init(void) {
    head = NULL;
    number_of_Tasks = 0;
    taskID = 0;
}

sTasks *createTask(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
    sTasks *res = (sTasks *)malloc(sizeof(sTasks));
    if (res != NULL) {
        res->pTask = pFunction;
        res->Delay_after_task = DELAY / MAX_TICKS;
        res->Period = PERIOD / MAX_TICKS;
        res->RunMe = 0;
        res->previous = NULL;
        res->next = NULL;
        res->TaskID = taskID++;
    }
    return res;
}

void SCH_Arrange_Task(sTasks *newTask, uint8_t condition) {
    sTasks *temp = head;
    sTasks *prev = NULL;
    uint32_t running_Delay = 0;

    if (condition == 1) {
        newTask->Delay_after_task = newTask->Period;
    }

    while (temp != NULL && running_Delay + temp->Delay_after_task < newTask->Delay_after_task) {
        running_Delay += temp->Delay_after_task;
        prev = temp;
        temp = temp->next;
    }

    newTask->next = temp;
    if (prev != NULL) {
        prev->next = newTask;
        newTask->previous = prev;
    } else {
        head = newTask;
    }

    newTask->Delay_after_task -= running_Delay;

    if (temp != NULL) {
        temp->previous = newTask;
        temp->Delay_after_task -= newTask->Delay_after_task;
    }
}

void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
    if (number_of_Tasks < SCH_MAX_TASKS) {
        sTasks *newTask = createTask(pFunction, DELAY, PERIOD);
        if (newTask == NULL) {
            return;
        }

        if (head == NULL) {
            head = newTask;
        } else {
            SCH_Arrange_Task(newTask, 0);
        }
        number_of_Tasks++;
    }
}

void SCH_Readd_Task(sTasks *task) {
    if (task == NULL) {
        return;
    }

    // Remove the task from the list
    if (task->previous != NULL) {
        task->previous->next = task->next;
    } else {
        head = task->next;
    }
    if (task->next != NULL) {
        task->next->previous = task->previous;
    }

    // Reset the task's delay
    task->Delay_after_task = task->Period;

    // Re-add the task to the scheduler
    SCH_Arrange_Task(task, 1);
}

void SCH_Update(void) {
    if (head != NULL) {
        if (head->Delay_after_task > 0) {
            head->Delay_after_task--;
        }
        while (head != NULL && head->Delay_after_task == 0) {
            head->RunMe++;
            SCH_Readd_Task(head);
        }
    }
}

void SCH_Dispatch_Tasks(void) {
    sTasks *temp = head;
    while (temp != NULL) {
        if (temp->RunMe > 0) {
            temp->RunMe--;
            (*temp->pTask)();
        }
        temp = temp->next;
    }
}
