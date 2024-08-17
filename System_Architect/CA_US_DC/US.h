/*
 ******************************************************************************
 * Created On     : Aug 17,2024
 * File           : US.h
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#ifndef US_H_
#define US_H_

#include "state.h"

// States id
enum {
	US_busy
}US_state_id;

// declare states functions CA
State_define (US_busy);
void US_init();

// states connection
void US_distance_get(int distance);

int US_Get_distance_randam (int l, int r, int count);
extern void (*PUS_state)();


#endif
