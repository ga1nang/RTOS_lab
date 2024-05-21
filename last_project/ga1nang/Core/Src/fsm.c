/*
 * fsm.c
 *
 *  Created on: May 19, 2024
 *      Author: Hi There
 */
#include "fsm.h"

void fsm_run(){
	switch(status){
	case INIT:
	//TODO for INIT state.
		status = VALVE_1;
		setTimer(0, 5000);
		break;
	case VALVE_1:
		//TODO for VALVE_1 state.
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = VALVE_2;
			setTimer(0, 5000);
		}
		break;
	case VALVE_2:
		//TODO for VALVE_2 state.
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = VALVE_3;
			setTimer(0, 5000);
		}
		break;
	case VALVE_3:
		//TODO for VALVE_3 state.
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = PUMP_1;
			setTimer(0, 10000);
		}
		break;
	case PUMP_1:
		//TODO for PUMP_1 state.
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = PUMP_2;
			setTimer(0, 30000);
		}
		break;
	case PUMP_2:
		//TODO for PUMP_2 state.
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = IDLE;
			setTimer(0, 60000);
		}
		break;
	case IDLE:
		//TODO for IDLE state.
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = VALVE_1;
			setTimer(0, 5000);
		}
		break;
	default:
		break;
	}
}

//this function is used to execute the task of every state in the
//state machine.
void execution_task(int status){
	switch(status){
		case VALVE_1:
			//turn on the pin PB0.
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			break;
		case VALVE_2:
			//turn on the pin PB1.
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			break;
		case VALVE_3:
			//turn on the pin PB2.
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			break;
		case PUMP_1:
			//turn on the pin PB3.
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			break;
		case PUMP_2:
			//turn on the pin PB4.
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
			break;
		case IDLE:
			//turn on the pin PB5.
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
		}

}


