/*
 ******************************************************************************
 * Created On     : Sep 27,2024
 * File           : HAL_KEYPAD.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#ifndef INC_HAL_KEYPAD_H_
#define INC_HAL_KEYPAD_H_

//====================================
//Includes
//====================================

#include "stdint.h"


//=======================================
//Macros Configuration References
//=======================================



/*@KPD_Port: 						GPIOA
*				  					GPIOB
*				  					GPIOC
*				  					GPIOD
*				  					GPIOE
*/

#define  KPD_Port				    GPIOB




//@KPD_define_PIN:				GPIO_PIN_0 -> GPIO_PIN_15

#define KPD_R1_PIN				GPIO_PIN_0
#define KPD_R2_PIN				GPIO_PIN_1
#define KPD_R3_PIN				GPIO_PIN_3
#define KPD_R4_PIN				GPIO_PIN_4

#define KPD_C1_PIN				GPIO_PIN_5
#define KPD_C2_PIN				GPIO_PIN_6
#define KPD_C3_PIN				GPIO_PIN_7
#define KPD_C4_PIN				GPIO_PIN_8




//@KPD_KEYS:
#define KPD_KEYS				{{'7','8','9','/'}, \
								{'4','5','6','*'},  \
								{'1','2','3','-'},  \
								{'?','0','=','+'}};



uint8_t KPD_GetKeyState(void);


#endif /* INC_HAL_KEYPAD_H_ */
