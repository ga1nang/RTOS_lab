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

//init the scheduler.
void SCH_Init(void) {
    head = NULL;
    number_of_Tasks = 0;
    taskID = 0;
}

//createTask function use to create the task and it will return a pointer point to a task.
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

//SCH_Arrange_Task use to arrange the position of the task when adding new task or readding a task.
void SCH_Arrange_Task(sTasks *newTask, uint8_t condition) {
    sTasks *temp = head;
    sTasks *prev = NULL;
    uint32_t running_Delay = 0;
    
    //this condition is for readding the task not for adding new task.
    if (condition == 1) {
        newTask->Delay_after_task = newTask->Period;
    }

    //find a position for the new task.
    while (temp != NULL && running_Delay + temp->Delay_after_task < newTask->Delay_after_task) {
        running_Delay += temp->Delay_after_task;
        prev = temp;
        temp = temp->next;
    }

    //adding the task to the doubly linked list.
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

//change SCH_Add_Task to make it can arrange the new added task.
void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
    if (number_of_Tasks < SCH_MAX_TASKS) {
        sTasks *newTask = createTask(pFunction, DELAY, PERIOD);

        //this condition is used to debug
        if (newTask == NULL) {
            return;
        }

        //if there is no task it will be added without arrange the task.
        if (head == NULL) {
            head = newTask;
        } else {
            SCH_Arrange_Task(newTask, 0);
        }
        number_of_Tasks++;
    }
}

//SCH_Readd_Task is called when a task finish it process and we want to add the task to the list again.
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

    // Readd the task to the scheduler
    SCH_Arrange_Task(task, 1);
}

//change the SCH_Update function to make it has complexity O(1).
void SCH_Update(void) {
    if (head != NULL) {
        if (head->Delay_after_task > 0) {
            head->Delay_after_task--;
        }
        //this while is used to check how many task we need to run at that time and execute them. 
        //For example, if there are 1 task need to execute it will just run 1 time, 
        //and if there are 2 tasks need to execute it will run 2 times,
        //therefore it complexity is O(1). Because we just need to check the first task.
        while (head != NULL && head->Delay_after_task == 0) {
            head->RunMe++;
            SCH_Readd_Task(head);
        }
    }
}

//change nothing
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
