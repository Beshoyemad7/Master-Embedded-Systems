/*
 ******************************************************************************
 * Created On     : Aug 16,2024
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

State_define (CA_waiting)
{
	// state name
	CA_state_id = CA_waiting ;

	// state action
	CA_speed =0;

	// distance random
	CA_distance= US_Get_distance_randam(45, 55, 1);

	// event check
	if (CA_distance <= CA_threshold)
		PCA_state = State(CA_waiting);
	else
		PCA_state = State(CA_driving);

	printf("CA_waiting state: distance =%d , speed =%d \n",CA_distance,CA_speed);
}

State_define (CA_driving)
{
	CA_state_id = CA_driving ;

	CA_speed =30;

	CA_distance= US_Get_distance_randam(45, 55, 1);

	if (CA_distance <= CA_threshold)
		PCA_state = State(CA_waiting);
	else
		PCA_state = State(CA_driving);

	printf("CA_driving state: distance =%d , speed =%d \n",CA_distance,CA_speed);
}

int US_Get_distance_randam (int l, int r, int count)
{
	int i;
	for(i=0; i<count; i++)
	{
		int rand_num = (rand() % (r - l + 1)) +l;
		return rand_num;
	}
}
