/*
 ******************************************************************************
 * Created On     : Sep 26,2024
 * File           : HAL_LCD.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#ifndef INC_HAL_LCD_H_
#define INC_HAL_LCD_H_

//====================================
//Includes
//====================================

#include "stdint.h"


//=======================================
//Macros Configuration References
//=======================================

/*@LCD_define_Port: 				GPIOA
*				  					GPIOB
*				  					GPIOC
*				  					GPIOD
*				  					GPIOE
*/

#define LCD_DATA_PORT					DIOA
#define LCD_CONTROL_PORT				DIOC


//@LCD_define_PIN:					GPIO_PIN_0 -> GPIO_PIN_15

#define LCD_RS_PIN						DIO_PIN_0
#define LCD_RW_PIN						DIO_PIN_1
#define LCD_E_PIN						DIO_PIN_2


/*@LCD_Mode:		LCD_MODE_8_BIT
 * 					LCD_MODE_4_BIT
 */

#define LCD_MODE_8_BIT						1
#define LCD_MODE_4_BIT						2

#define  LCD_Mode                       LCD_MODE_8_BIT




/*
* ===============================================
* APIs Supported by "HAL LCD DRIVER"
* ===============================================
*/

void HAL_LCD_Init(void);
void HAL_LCD_Send_Cmnd(uint8_t Copy_Cmnd);
void HAL_LCD_Send_Char (uint8_t Copy_Char);
void HAL_LCD_Send_String (char* Copy_String);
void HAL_LCD_GOTO_XY (uint8_t Copy_LineNumber , uint8_t Copy_Position);
void HAL_LCD_Send_Number(uint32_t Copy_Number);
void HAL_LCD_Clean_Screen(void);
void HAL_LCD_Special_Character(uint8_t Copy_CharNum, uint8_t* Copy_Pattern, uint8_t Copy_LineNumber, uint8_t Copy_Position);

#endif /* INC_HAL_LCD_H_ */
