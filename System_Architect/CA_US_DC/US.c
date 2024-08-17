/*
 ******************************************************************************
 * Created On     : Aug 16,2024
 * File           : US.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/
/*
 ******************************************************************************
 * Created On     : Aug 17,2024
 * File           : US.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/
#include "US.h"

// variables
int US_distance = 0;

// state pointer to function
void (*PUS_state)();

void US_init()
{
	// init driver US
	printf("US_init \n");
}

State_define (US_busy)
{
	// state name
	US_state_id = US_busy ;

	// distance random
	US_distance= US_Get_distance_randam(45, 55, 1);
	printf("US_busy state: distance =%d \n",US_distance);

	US_distance_get(US_distance);
	PUS_state= State(US_busy);
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

