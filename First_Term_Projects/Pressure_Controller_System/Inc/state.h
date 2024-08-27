/*
 ******************************************************************************
 * Created On     : Aug 25,2024
 * File           : state.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#ifndef STATE_H_
#define STATE_H_

#include <stdlib.h>

#define State_define(_state_fun_) void ST_##_state_fun_()
#define State(_state_fun_) ST_##_state_fun_



#endif /* STATE_H_ */
