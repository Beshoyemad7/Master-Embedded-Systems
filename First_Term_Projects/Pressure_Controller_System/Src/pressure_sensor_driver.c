/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : pressure_sensor_driver.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#include "pressure_sensor_driver.h"
#include "driver.h"

#define PS_Time  100000   // read duration sensor = 100 second
uint32_t PS_pval = 0;     // read value from sensor

void (*PS_state)();


/************************************Function Description***********************************/
/*void PS_init: This function performs initialization for pressure sensor driver.          */
/*******************************************************************************************/
void PS_init()
{

}



/************************************Function Description***********************************/
/*void ST_PS_reading():This function takes the pressure value from the sensor and then sending the value to the algorithm model*/
/*******************************************************************************************/
State_define(PS_reading)
{
	PS_state_id = PS_reading;
	PS_pval = getPressureVal();

	setPressureVal(PS_pval);

	PS_state = State(PS_waiting);
}



/************************************Function Description***********************************/
/*void ST_PS_waiting(): This function waits for 100 seconds then takes new value from sensor. */
/*******************************************************************************************/
State_define(PS_waiting)
{
	PS_state_id = PS_waiting;
	
	Delay(PS_Time);
	
	PS_state = State(PS_reading);
}


