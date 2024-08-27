/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : alarm_monitor_driver.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#include "alarm_monitor_driver.h"
#include "driver.h"

void (*ALDR_state)();


/************************************Function Description***********************************/
/*void ALDR_init(): This function performs initialization for alarm monitor driver.        */
/*******************************************************************************************/
void ALDR_init()
{

}



/************************************Function Description***********************************/
/*void AlarmON(): IN signal receive start on alarm.                                        */
/*******************************************************************************************/
void AlarmON()
{
	
	ALDR_state = State(ALDR_AlarmON);

}



/************************************Function Description***********************************/
/*void AlarmOFF(): IN signal receive start off alarm.                                     */
/*******************************************************************************************/
void AlarmOFF()
{
	
	ALDR_state = State(ALDR_AlarmOFF);
}



/************************************Function Description***********************************/
/*void ST_ALDR_waiting(): this function waits another signal.                              */
/*******************************************************************************************/
State_define(ALDR_waiting)
{
	ALDR_state_id= ALDR_waiting;
	ALDR_state = State(ALDR_waiting);
	
}



/************************************Function Description***********************************/
/*void ST_ALDR_AlarmON(): this function sending GPIO logic low (Active low)               */
/*******************************************************************************************/
State_define(ALDR_AlarmON)
{
	ALDR_state_id= ALDR_AlarmON;
	Set_Alarm_actuator(0);
	
	ALDR_state = State(ALDR_waiting);
}



/************************************Function Description***********************************/
/*void ST_ALDR_AlarmOFF(): this function sending GPIO logic high (Active low)               */
/*******************************************************************************************/
State_define(ALDR_AlarmOFF)
{
	ALDR_state_id= ALDR_AlarmOFF;
	Set_Alarm_actuator(1);
	
	ALDR_state = State(ALDR_waiting);
}
