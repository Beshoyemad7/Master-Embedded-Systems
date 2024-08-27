/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : algorithm.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "state.h"
#include "Platform_Types.h"

// states algorithm id
enum {
	Alg_HighPressureDetect
}Alg_state_id;

// declare states functions algorithm
State_define(Alg_HighPressureDetect);

// OUT signal from algorithm to alarm monitor
void alg_HighPressureDetect();

// pointer to function for algorithm
extern void (*Alg_state)();

#endif /* ALGORITHM_H_ */
