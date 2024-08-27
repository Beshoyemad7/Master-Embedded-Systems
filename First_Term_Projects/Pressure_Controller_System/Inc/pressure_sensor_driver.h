/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : pressure_sensor_driver.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

#include "state.h"
#include "Platform_Types.h"

// states pressure sensor id
enum {
	PS_reading,
	PS_waiting
}PS_state_id;

// declare states functions pressure sensor
State_define(PS_reading);
State_define(PS_waiting);
void PS_init();

// OUT signal from pressure sensor driver to algorithm
void setPressureVal( uint32_t pval);

// pointer to function for pressure sensor driver
extern void (*PS_state)();


#endif /* PRESSURE_SENSOR_DRIVER_H_ */
