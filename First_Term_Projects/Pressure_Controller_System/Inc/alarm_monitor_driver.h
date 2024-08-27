/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : alarm_monitor_driver.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#ifndef ALARM_MONITOR_DRIVER_H_
#define ALARM_MONITOR_DRIVER_H_

#include "state.h"

// states alarm monitor driver id
enum {
	ALDR_waiting,
	ALDR_AlarmON,
	ALDR_AlarmOFF
}ALDR_state_id;

// declare states functions alarm monitor driver
State_define(ALDR_waiting);
State_define(ALDR_AlarmON);
State_define(ALDR_AlarmOFF);
void ALDR_init();

// pointer to function for alarm monitor driver
extern void (*ALDR_state)();

#endif /* ALARM_MONITOR_DRIVER_H_ */
