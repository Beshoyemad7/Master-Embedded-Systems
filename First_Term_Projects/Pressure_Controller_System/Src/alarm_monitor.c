/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : alarm_monitor.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#include "alarm_monitor.h"
#include "driver.h"

uint32_t Timer_period = 600000; // alarm duration = 60 second

void (*AL_state)();


/************************************Function Description***********************************/
/*void alg_HighPressureDetect(): IN signal This function receive that there are high pressure   */
/*******************************************************************************************/
void alg_HighPressureDetect()
{
	AL_state = State(AL_AlarmON);
}



/************************************Function Description***********************************/
/*void ST_AL_AlarmOFF(): This function sending signal to alarm monitor driver for start off alarm*/
/*******************************************************************************************/
State_define(AL_AlarmOFF)
{
	AL_state_id = AL_AlarmOFF;
	AlarmOFF();

	AL_state = State(AL_AlarmOFF); 

}



/************************************Function Description***********************************/
/*void ST_AL_AlarmON(): This function sending signal to alarm monitor driver for start on alarm*/
/*******************************************************************************************/
State_define(AL_AlarmON)
{
	AL_state_id = AL_AlarmON;
	AlarmON();

	AL_state = State(AL_waiting);
}



/************************************Function Description***********************************/
/*void ST_AL_waiting(): This function waits for alarm duration = 60 second*/
/*******************************************************************************************/
State_define(AL_waiting)
{
	AL_state_id = AL_waiting;

	Delay(Timer_period);

	AlarmOFF();

	AL_state = State(AL_AlarmOFF);
}


