/*
 ******************************************************************************
 * Created On     : Aug 16,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include "CA.h"

void setup ()
{
	PCA_state = State(CA_waiting);
}

void main ()
{
	setup ();

	while(1)
	{
		PCA_state();
		for(int i=0; i<1000;i++);
	}
}
