/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : main.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#include "driver.h"
#include "pressure_sensor_driver.h"
#include "algorithm.h"
#include "alarm_monitor.h"
#include "alarm_monitor_driver.h"

void setup()
{
	// init block
	PS_init();
	ALDR_init();

	// set states pointer for each block
	PS_state = State(PS_reading);
	Alg_state = setPressureVal;
	AL_state = State(AL_AlarmOFF);
	ALDR_state = State(ALDR_waiting);
}
int main()
{
	GPIO_INITIALIZATION();
	setup();

	while (1)
	{
		//Implement your Design
		PS_state();
		Alg_state();
		AL_state();
		ALDR_state();
	}

  return 0;
}
