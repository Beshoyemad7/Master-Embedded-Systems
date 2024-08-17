/*
 ******************************************************************************
 * Created On     : Aug 17,2024
 * File           : CA.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include "CA.h"

// variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

// state pointer to function
void (*PCA_state)();

void US_distance_get(int distance)
{
	CA_distance = distance;

	// event check
	if (CA_distance <= CA_threshold)
		PCA_state = State(CA_waiting);
	else
		PCA_state = State(CA_driving);

	printf("US------------ distance= %d-------->CA \n",CA_distance);

}

State_define (CA_waiting)
{
	// state name
	CA_state_id = CA_waiting ;

	printf("CA_waiting state: distance =%d , speed =%d \n",CA_distance,CA_speed);

	// state action
	CA_speed =0;
	DC_motor_set(CA_speed);
}

State_define (CA_driving)
{
	CA_state_id = CA_driving ;

	printf("CA_driving state: distance =%d , speed =%d \n",CA_distance,CA_speed);

	CA_speed =30;
	DC_motor_set(CA_speed);
}

