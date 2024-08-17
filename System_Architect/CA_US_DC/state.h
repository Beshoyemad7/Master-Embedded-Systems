/*
 * state.h
 *
 *  Created on: Aug 17, 2024
 *      Author: Beshoy Emad
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdlib.h>

#define State_define(_state_fun_) void ST_##_state_fun_()
#define State(_state_fun_) ST_##_state_fun_



#endif /* STATE_H_ */
