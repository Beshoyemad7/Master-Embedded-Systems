/*
 ******************************************************************************
 * Created On     : Sep 25,2024
 * File           : MCAL_GPIO.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#ifndef GPIO_INC_MCAL_GPIO_H_
#define GPIO_INC_MCAL_GPIO_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"


//===============================
//Configuration structures
//===============================


typedef struct{

	uint16_t GPIO_PinNumber; 		 // Specifies the GPIO pins to be configured
						     	    // This parameter set based on  @ref GPIO_PIN_define

	uint8_t  GPIO_PinMode;		   // Specifies the operating mode for the selected pins
						  	  	  // This parameter can be a value of @ref GPIO_MODE_define

	uint8_t  GPIO_Output_Speed;  // Specifies the speed mode for the selected pins
	  	 	 	 	 	 	 	 // This parameter can be a value of @ref GPIO_SPEED_define


}GPIO_PinConfig_t;


// @GPIO_PIN_Value
#define GPIO_PIN_SET				1
#define GPIO_PIN_RESET				0

// @GPIO_RETURN_LOCK_State
#define GPIO_RETURN_LOCK_OK			1
#define GPIO_RETURN_LOCK_ERROR		0


//===============================
//Macros Configuration References
//===============================

//@ref GPIO_PIN_define
#define GPIO_PIN_0		((uint16_t)0x0001) // 1<<0
#define GPIO_PIN_1		((uint16_t)0x0002) // 1<<1
#define GPIO_PIN_2		((uint16_t)0x0004) // 1<<2
#define GPIO_PIN_3		((uint16_t)0x0008) // 1<<3
#define GPIO_PIN_4		((uint16_t)0x0010) // 1<<4
#define GPIO_PIN_5		((uint16_t)0x0020) // 1<<5
#define GPIO_PIN_6		((uint16_t)0x0040) // 1<<6
#define GPIO_PIN_7		((uint16_t)0x0080) // 1<<7
#define GPIO_PIN_8		((uint16_t)0x0100) // 1<<8
#define GPIO_PIN_9		((uint16_t)0x0200) // 1<<9
#define GPIO_PIN_10		((uint16_t)0x0400) // 1<<10
#define GPIO_PIN_11		((uint16_t)0x0800) // 1<<11
#define GPIO_PIN_12		((uint16_t)0x1000) // 1<<12
#define GPIO_PIN_13		((uint16_t)0x2000) // 1<<13
#define GPIO_PIN_14		((uint16_t)0x4000) // 1<<14
#define GPIO_PIN_15		((uint16_t)0x8000) // 1<<15
#define GPIO_PINAll		((uint16_t)0xFFFF)



//@ref GPIO_MODE_define
#define GPIO_MODE_Analog         				0x00000000u 	//Analog mode
#define GPIO_MODE_INPUT_FLO         			0x00000001u 	//Floating input (reset state)
#define GPIO_MODE_INPUT_PU         				0x00000002u		//Input pull-up
#define GPIO_MODE_INPUT_PD         				0x00000003u		//Input pull-down
#define GPIO_MODE_OUTPUT_PP         			0x00000004u		//General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD         			0x00000005u		//General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP         			0x00000006u		//Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD         			0x00000007u		//Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT         				0x00000008u		//Input Alternate function


// @ref GPIO_SPEED_define
#define GPIO_SPEED_10M							0x00000001u
#define GPIO_SPEED_2M							0x00000002u
#define GPIO_SPEED_50M							0x00000003u



/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/



void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNum);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx , uint16_t PinNum, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx , uint16_t PinNum);
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx , uint16_t PinNum);


#endif /* GPIO_INC_MCAL_GPIO_H_ */
