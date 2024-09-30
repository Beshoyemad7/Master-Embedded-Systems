/*
 ******************************************************************************
 * Created On     : Sep 26,2024
 * File           : HAL_LCD.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

//=================================
//Includes
//=================================

#include "MCAL_DIO.h"
#include "HAL_LCD.h"
#include "HAL_LCD_Private.h"


void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}



/**================================================================
* @Fn			- GPIO_LCD_init
* @brief 		- Configuration Data pins and control pins -> (Pin Number - Pin Mode - Output Speed)
* @param [in] 	- none
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void GPIO_LCD_init(void)
{
	DIO_PinConfig_t pinConfig;

	// Control pins
	pinConfig.DIO_PinNumber = LCD_RS_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_CONTROL_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = LCD_RW_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_CONTROL_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = LCD_E_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_CONTROL_PORT, &pinConfig);

	// Data	pins
	pinConfig.DIO_PinNumber = DIO_PIN_0;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = DIO_PIN_1;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = DIO_PIN_2;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = DIO_PIN_3;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = DIO_PIN_4;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = DIO_PIN_5;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = DIO_PIN_6;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.DIO_PinNumber = DIO_PIN_7;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(LCD_DATA_PORT, &pinConfig);

}




/**================================================================
* @Fn			- HAL_LCD_Init
* @brief 		- The function initializes the LCD by configuring it for 8-bit mode or , 4-bit mode
* 				  enabling the display, and clearing the screen
* 				  It also sets the entry mode and cursor behavior.
* @param [in] 	- none
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void HAL_LCD_Init(void)
{
	delay_ms(40);
	GPIO_LCD_init();

#if LCD_Mode == LCD_MODE_8_BIT

	/*Function Set*/
	HAL_LCD_Send_Cmnd(LCD_8_BIT_2_LINE_DOT_5_7);
	delay_ms(5);

#elif LCD_Mode == LCD_MODE_4_BIT

	HAL_LCD_Send_Cmnd(0x03);
    delay_ms(5);
    HAL_LCD_Send_Cmnd(0x02);
    delay_ms(5);

	HAL_LCD_Send_Cmnd(LCD_4_BIT_2_LINE_DOT_5_7);
	delay_ms(2);


#endif

	HAL_LCD_Send_Cmnd(Display_ON_Cursor_BLINKING);
	delay_ms(2);
	HAL_LCD_Send_Cmnd(Clear_Display);
	delay_ms(2);
	HAL_LCD_Send_Cmnd(Entry_Mode);

}




/**================================================================
* @Fn			- HAL_LCD_Send_Cmnd
* @brief 		- The function sends a command to the LCD by setting the control pins
* @param [in] 	- Copy_Cmnd: Passed Data commend
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void HAL_LCD_Send_Cmnd(uint8_t Copy_Cmnd)
{

#if LCD_Mode == LCD_MODE_8_BIT

	/*Send Commend*/
	MCAL_DIO_WritePort(LCD_DATA_PORT, Copy_Cmnd);

	/*RS = 0 -> Instruction set*/
	MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_RESET);

	/*RW = 0 -> Write operation*/
	MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_RESET);

	/*E = 1*/
	MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN,DIO_PIN_SET);
	delay_ms(1);
	/*E = 0*/
	MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN,DIO_PIN_RESET);

#elif LCD_Mode == LCD_MODE_4_BIT

    /*Send the higher nibble (D7-D4) */
    MCAL_DIO_WritePort(LCD_DATA_PORT, (Copy_Cmnd & 0xF0));

    /*RS = 0 -> Instruction set */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_RESET);

    /*RW = 0 -> Write operation */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_RESET);

    /*E = 1 */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN, DIO_PIN_SET);
    delay_ms(1);

    /*E = 0 */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN, DIO_PIN_RESET);
    delay_ms(1);

    /*Send the lower nibble (D3-D0) */
    MCAL_DIO_WritePort(LCD_DATA_PORT, ((Copy_Cmnd << 4) & 0xF0));

    /*RS = 0 -> Instruction set */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_RESET);

    /*RW = 0 -> Write operation */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_RESET);

    /*E = 1 */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN, DIO_PIN_SET);
    delay_ms(1);

    /*E = 0 */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN, DIO_PIN_RESET);

#endif

}




/**================================================================
* @Fn			- HAL_LCD_Send_Char
* @brief 		- The function sends a char to the LCD by setting the control pins
* @param [in] 	- Copy_Char: Passed Char
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void HAL_LCD_Send_Char (uint8_t Copy_Char)
{

#if LCD_Mode == LCD_MODE_8_BIT

	/*Write Commend*/
	MCAL_DIO_WritePort(LCD_DATA_PORT, Copy_Char);

	/*RS = 1 -> Data set*/
	MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_SET);

	/*RW = 0 -> Write operation*/
	MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_RESET);

	/*E = 1*/
	MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN,DIO_PIN_SET);
	delay_ms(1);
	/*E = 0*/
	MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN,DIO_PIN_RESET);

#elif LCD_Mode == LCD_MODE_4_BIT

    /* Send the higher nibble (D7-D4) */
    MCAL_DIO_WritePort(LCD_DATA_PORT, (Copy_Char & 0xF0));

    /* RS = 1 -> Data set */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_SET);

    /* RW = 0 -> Write operation */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_RESET);

    /* E = 1  */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN, DIO_PIN_SET);
    delay_ms(1);

    /* E = 0 */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN, DIO_PIN_RESET);
    delay_ms(1);

    /* Send the lower nibble (D3-D0) */
    MCAL_DIO_WritePort(LCD_DATA_PORT, ((Copy_Char << 4) & 0xF0));

    /* RS = 1 -> Data set  */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_SET);

    /* RW = 0 -> Write operation */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_RESET);

    /* E = 1 */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN, DIO_PIN_SET);
    delay_ms(1);

    /* E = 0 */
    MCAL_DIO_WritePin(LCD_CONTROL_PORT, LCD_E_PIN, DIO_PIN_RESET);

#endif

}




/**================================================================
* @Fn			- HAL_LCD_Send_String
* @brief 		- The function sends a String to the LCD char by char
* @param [in] 	- Copy_String: Passed string
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void HAL_LCD_Send_String (char* Copy_String)
{
	uint8_t string_counter =0;

	while( (Copy_String[string_counter]) != '\0' )
	{
		if(string_counter == 16 )
		{
			HAL_LCD_GOTO_XY(2,0);
		}

		HAL_LCD_Send_Char(Copy_String[string_counter]);
		delay_ms(15);

		string_counter++;

	}
}




/**================================================================
* @Fn			- HAL_LCD_GOTO_XY
* @brief 		- The function GO to specific (line,position)
* @param [in] 	- Copy_LineNumber: Line number 1 or 2
* @param [in] 	- Copy_Position: Position from 0 to 15 for each line
* @retval 		- none
* Note			- none
*
*/

void HAL_LCD_GOTO_XY (uint8_t Copy_LineNumber , uint8_t Copy_Position)
{
	if(Copy_Position < 16 && Copy_Position>=0)
	{
		switch(Copy_LineNumber)
		{
			case 1:	HAL_LCD_Send_Cmnd(LCD_BEGIN_AT_Line_1 + Copy_Position); 	break;
			case 2:	HAL_LCD_Send_Cmnd(LCD_BEGIN_AT_Line_2 + Copy_Position); 	break;
			default: 	break;
		}
	}
	else
		return;

}




/**================================================================
* @Fn			- HAL_LCD_Clean_Screen
* @brief 		- Clear_Display
* @param [in] 	- none
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void HAL_LCD_Clean_Screen(void)
{
	HAL_LCD_Send_Cmnd(Clear_Display);
	delay_ms(20);
}




/**================================================================
* @Fn			- HAL_LCD_Send_Number
* @brief 		- The function sends Number to the LCD
* @param [in] 	- Copy_Number: Passed Number
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void HAL_LCD_Send_Number(uint32_t Copy_Number)
{
	uint8_t Digits_Arr[32];
	uint8_t	Digits_counter =0;

	if(Copy_Number > 0)
	{
		while(Copy_Number != 0)
		{
			Digits_Arr[Digits_counter] = Copy_Number % 10;
			Copy_Number = Copy_Number/10;
			Digits_counter++;
		}

		for(int8_t i=Digits_counter-1; i>=0; i--)
		{
			HAL_LCD_Send_Char(Digits_Arr[i] + '0');
		}

	}
	else
	{
		HAL_LCD_Send_Char('0');
	}
}




/**================================================================
* @Fn			- HAL_LCD_Special_Character
* @brief 		- The function sends Special Character to the LCD
* @param [in] 	- Copy_CharNum: Passed char Number for CGRAM
* @param [in] 	- Copy_Pattern: Passed Array of Pattern
* @param [in] 	- Copy_LineNumber: Passed Line Number
* @param [in] 	- Copy_Position: Passed Position
* @retval 		- none
* Note			- none
*
*/

void HAL_LCD_Special_Character(uint8_t Copy_CharNum, uint8_t* Copy_Pattern, uint8_t Copy_LineNumber, uint8_t Copy_Position)
{
	uint8_t CGRAM_Address = Copy_CharNum *8 ;   // to take address for CharNum -> Max custom characters,
												// typically up to 8 (0-7)

	HAL_LCD_Send_Cmnd(CGRAM_Address + 64 );

	for(uint8_t Local_u8Counter=0 ; Local_u8Counter <8 ; Local_u8Counter++  )
	{

		HAL_LCD_Send_Char(Copy_Pattern[Local_u8Counter]);

	}

	HAL_LCD_GOTO_XY( Copy_LineNumber ,  Copy_Position);
	HAL_LCD_Send_Char(CGRAM_Address);
}






