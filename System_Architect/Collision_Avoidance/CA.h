/*
 ******************************************************************************
 * Created On     : Aug 16,2024
 * File           : CA.h
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#ifndef CA_H_
#define CA_H_

#include <stdio.h>
#include <stdlib.h>

#define State_define(_state_fun_) void ST_##_state_fun_()
#define State(_state_fun_) ST_##_state_fun_

// States id
enum {
	CA_waiting,
	CA_driving
}CA_state_id;

// declare states functions CA
State_define (CA_waiting);    // void ST_CA_waiting()
State_define (CA_driving);	  // void ST_CA_driving()

int US_Get_distance_randam (int l, int r, int count);

extern void (*PCA_state)();

#endif
