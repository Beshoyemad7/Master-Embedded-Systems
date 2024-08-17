/*
 ******************************************************************************
 * Created On     : Aug 17,2024
 * File           : DC.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include "DC.h"

// variables
int DC_speed = 0;

// state pointer to function
void (*PDC_state)();

void DC_init()
{
	// init driver DC
	printf("DC_init \n");
}

void DC_motor_set(int speed)
{
	DC_speed = speed;
	PDC_state = State(DC_busy);

	printf("CA------------ speed= %d-------->DC \n",DC_speed);
}

State_define (DC_idel)
{
	// state name
	DC_state_id = DC_idel ;

	PDC_state = State(DC_idel);

	printf("DC_idel state: speed =%d \n",DC_speed);
}

State_define (DC_busy)
{
	// state name
	DC_state_id = DC_busy ;

	PDC_state = State(DC_idel);

	printf("DC_busy state: speed =%d \n",DC_speed);
}

