/*
 ******************************************************************************
 * Created On     : Oct 3,2024
 * File           : MCAL_EXTI.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#ifndef INC_MCAL_EXTI_H_
#define INC_MCAL_EXTI_H_

//======================================
//Includes
//======================================

#include "MCAL_DIO.h"



//========================================
//Configuration structures
//========================================

typedef struct{

	uint8_t 		 EXTI_INT_Line;
	uint8_t	 		 DIO_Port;
	uint8_t			 DIO_PIN;

}EXTI_DIO_Mapping_t;


typedef struct{

	EXTI_DIO_Mapping_t			EXTI_PIN;   	        //@ref EXTI_define

	uint8_t						Trigger_Case;           /* Both INT0 , INT1 Options :
																			  INT_Trigger_Low_Level
	 	 	 	 	 	 	 	 	 	 	 	 	 	 * 					  INT_Trigger_RisingAndFalling
	 	 	 	 	 	 	 	 	 	 	 	 	 	 *					  INT_Trigger_FALLING
	 	 	 	 	 	 	 	 	 	 	 	 	 	 *					  INT_Trigger_RISING
	 	 	 	 	 	 	 	 	 	 	 	 	 	 *
	 	 	 	 	 	 	 	 	 	 	 	 	 	 *	INT2 Options	  :
	 	 	 	 	 	 	 	 	 	 	 	 	 	 *					  INT_Trigger_RISING
	 	 	 	 	 	 	 	 	 	 	 	 	 	 *					  INT_Trigger_FALLING
	 	 	 	 	 	 	 	 	 	 	 	 	 	 *					  @ref EXTI_Trigger_define*/

	uint8_t						INT_EN;   		        //@ref EXTI_ISR_define

	uint8_t						Global_INT_EN;   		//@ref EXTI_ISR_define

	void (* P_ISR_CallBack)(void);

}EXTI_PinConfig_t;




/***************************************************************************
 * Configuration Macros
 **************************************************************************/

#define EXTI0											0
#define EXTI1											1
#define EXTI2											2


//@ref EXTI_Trigger_define

#define EXTI_Trigger_Low_Level						    0b00
#define EXTI_Trigger_RisingAndFalling				    0b01
#define EXTI_Trigger_FALLING							0b10
#define EXTI_Trigger_RISING							    0b11


//@ref EXTI_ISR_define
#define EXTI_ISR_Enable		     				         1
#define EXTI_ISR_Disable								 0



//@ref EXTI_define
#define INT0D2							(EXTI_DIO_Mapping_t){EXTI0, DIOD, DIO_PIN_2}
#define INT1D3							(EXTI_DIO_Mapping_t){EXTI1, DIOD, DIO_PIN_3}
#define INT2B2							(EXTI_DIO_Mapping_t){EXTI2, DIOB, DIO_PIN_2}



/*
* ===============================================
* APIs Supported by "MCAL EXTI DRIVER"
* ===============================================
*/

void MCAL_EXTI_DIO_Init(EXTI_PinConfig_t* EXTI_Config);
void MCAL_EXTI_DIO_DeInit(void);
void MCAL_EXTI_DIO_Update(EXTI_PinConfig_t* EXTI_Config);




#endif /* INC_MCAL_EXTI_H_ */
