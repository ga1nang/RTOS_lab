/*
 * software_timer.h
 *
 *  Created on: May 19, 2024
 *      Author: Hi There
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

void setTimer(int index, int value);
int isTimerExpired(int index);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
