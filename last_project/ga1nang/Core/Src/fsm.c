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
		status = VALVE_1;
		setTimer(0, 5000);
		break;
	case VALVE_1:
		//TODO
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = VALVE_2;
			setTimer(0, 5000);
		}
		break;
	case VALVE_2:
		//TODO
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = VALVE_3;
			setTimer(0, 5000);
		}
		break;
	case VALVE_3:
		//TODO
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = PUMP_1;
			setTimer(0, 10000);
		}
		break;
	case PUMP_1:
		//TODO
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = PUMP_2;
			setTimer(0, 30000);
		}
		break;
	case PUMP_2:
		//TODO
		execution_task(status);
		if (isTimerExpired(0) == 1) {
			status = IDLE;
			setTimer(0, 60000);
		}
		break;
	case IDLE:
		//TODO
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

void execution_task(int status){
	switch(status){
		case VALVE_1:
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			break;
		case VALVE_2:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			break;
		case VALVE_3:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			break;
		case PUMP_1:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			break;
		case PUMP_2:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
			break;
		case IDLE:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
		}

}


