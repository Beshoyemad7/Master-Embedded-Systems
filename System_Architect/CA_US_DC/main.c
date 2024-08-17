/*
 * main.c
/*
 ******************************************************************************
 * Created On     : Aug 17,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include "CA.h"
#include "US.h"
#include "DC.h"

#include <stdio.h>

void setup ()
{
	// init block
	US_init();
	DC_init();

	// set states pointer for each block
	PCA_state = State(CA_waiting);
	PUS_state = State(US_busy);
	PDC_state = State(DC_idel);
}

void main ()
{
	setup ();

	while(1)
	{
		// Call states
		PUS_state();
		PCA_state();
		PDC_state();

		for(volatile int i=0; i<1000; i++);
	}
}
