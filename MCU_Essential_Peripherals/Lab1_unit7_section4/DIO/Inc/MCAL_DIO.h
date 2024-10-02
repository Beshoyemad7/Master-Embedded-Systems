/*
 ******************************************************************************
 * Created On     : Sep 28,2024
 * File           : MCAL_DIO.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#ifndef INC_MCAL_DIO_H_
#define INC_MCAL_DIO_H_


//======================================
//Includes
//======================================

#include "ATmega32.h"


//===============================
//Configuration structures
//===============================

typedef struct {

	uint8_t DIO_PinNumber; 		 // Specifies the DIO pins to be configured
								 // This parameter set based on  @ref DIO_PIN_define

	uint8_t DIO_PinMode;		// Specifies the operating mode for the selected pins
								// This parameter can be a value of @ref DIO_MODE_define

} DIO_PinConfig_t;



//@DIO_PIN_define
#define DIO_PIN_0		((uint8_t)0x01) // 1<<0
#define DIO_PIN_1		((uint8_t)0x02) // 1<<1
#define DIO_PIN_2		((uint8_t)0x04) // 1<<2
#define DIO_PIN_3		((uint8_t)0x08) // 1<<3
#define DIO_PIN_4		((uint8_t)0x10) // 1<<4
#define DIO_PIN_5		((uint8_t)0x20) // 1<<5
#define DIO_PIN_6		((uint8_t)0x40) // 1<<6
#define DIO_PIN_7		((uint8_t)0x80) // 1<<7
#define DIO_PINAll		((uint8_t)0xFF)



//@ref GPIO_MODE_define -> DDRx
#define DIO_MODE_INPUT_FLO					 0x0
#define DIO_MODE_INPUT_PU				     0x1 		//Input
#define DIO_MODE_OUTPUT        				 0x2		//Output


//@ref DIO -> DIOA...DIOD
#define DIOA								0
#define DIOB 								1
#define DIOC								2
#define DIOD								3

//@ref DIO_PIN_Value
#define DIO_PIN_SET							0x1
#define DIO_PIN_RESET						0x0





/*
* ===============================================
* APIs Supported by "MCAL DIO DRIVER"
* ===============================================
*/

void MCAL_DIO_Init(uint8_t DIOx, DIO_PinConfig_t *PinConfig);
void MCAL_DIO_WritePin(uint8_t DIOx, uint8_t PinNum, uint8_t Value);
void MCAL_DIO_WritePort(uint8_t DIOx, uint8_t Value);
uint8_t MCAL_DIO_ReadPin(uint8_t DIOx , uint8_t PinNum);
uint8_t MCAL_DIO_ReadPort(uint8_t DIOx);
void MCAL_DIO_TogglePin(uint8_t DIOx , uint8_t PinNum);



#endif /* INC_MCAL_DIO_H_ */
