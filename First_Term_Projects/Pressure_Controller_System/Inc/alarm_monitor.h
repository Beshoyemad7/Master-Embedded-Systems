/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : alarm_monitor.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"
#include "Platform_Types.h"

// states alarm monitor id
enum {
	AL_AlarmOFF,
	AL_AlarmON,
	AL_waiting
}AL_state_id;

// declare states functions alarm monitor
State_define(AL_AlarmOFF);
State_define(AL_AlarmON);
State_define(AL_waiting);

// OUT signal from alarm monitor to alarm monitor driver
void AlarmON();
void AlarmOFF();

// pointer to function for alarm monitor
extern void (*AL_state)();

#endif /* ALARM_MONITOR_H_ */
