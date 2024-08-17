/*
 ******************************************************************************
 * Created On     : Aug 17,2024
 * File           : CA.h
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#ifndef CA_H_
#define CA_H_

#include "state.h"
// States id
enum {
	CA_waiting,
	CA_driving
}CA_state_id;


// declare states functions CA
State_define (CA_waiting);    // void ST_CA_waiting()
State_define (CA_driving);	  // void ST_CA_driving()


extern void (*PCA_state)();

#endif
