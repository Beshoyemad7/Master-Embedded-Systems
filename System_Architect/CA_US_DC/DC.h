/*
 ******************************************************************************
 * Created On     : Aug 17,2024
 * File           : DC.h
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#ifndef DC_H_
#define DC_H_

#include "state.h"

// States id
enum {
	DC_idel,
	DC_busy
}DC_state_id;

// declare states functions CA
State_define (DC_idel);
State_define (DC_busy);
void DC_init();

// states connection
void DC_motor_set(int speed);

extern void (*PDC_state)();

#endif
