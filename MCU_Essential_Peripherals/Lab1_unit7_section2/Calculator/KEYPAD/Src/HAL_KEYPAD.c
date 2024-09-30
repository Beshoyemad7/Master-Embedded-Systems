/*
 ******************************************************************************
 * Created On     : Sep 27,2024
 * File           : HAL_KEYPAD.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/


//=================================
//Includes
//=================================

#include "HAL_KEYPAD.h"
#include "MCAL_DIO.h"

uint16_t KPD_Keys[4][4]	     = 	  KPD_KEYS;
uint16_t KPD_RowsPins[4]     = 	  {KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN, KPD_R4_PIN};
uint16_t KPD_ColumnsPins[4]  =    {KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN, KPD_C4_PIN};




/**================================================================
* @Fn			- GPIO_KPD_init
* @brief 		- Configuration Rows and Columns Pins
* @param [in] 	- none
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void GPIO_KPD_init (void)
{
	DIO_PinConfig_t pinConfig;

	// Rows pins
	pinConfig.DIO_PinNumber = KPD_R1_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(KPD_Port, &pinConfig);

	pinConfig.DIO_PinNumber = KPD_R2_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(KPD_Port, &pinConfig);

	pinConfig.DIO_PinNumber = KPD_R3_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(KPD_Port, &pinConfig);

	pinConfig.DIO_PinNumber = KPD_R4_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_OUTPUT;
	MCAL_DIO_Init(KPD_Port, &pinConfig);

	// Columns pins
	pinConfig.DIO_PinNumber = KPD_C1_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_INPUT_PU;
	MCAL_DIO_Init(KPD_Port, &pinConfig);

	pinConfig.DIO_PinNumber = KPD_C2_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_INPUT_PU;
	MCAL_DIO_Init(KPD_Port, &pinConfig);

	pinConfig.DIO_PinNumber = KPD_C3_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_INPUT_PU;
	MCAL_DIO_Init(KPD_Port, &pinConfig);

	pinConfig.DIO_PinNumber = KPD_C4_PIN;
	pinConfig.DIO_PinMode = DIO_MODE_INPUT_PU;
	MCAL_DIO_Init(KPD_Port, &pinConfig);

	MCAL_DIO_WritePin(KPD_Port, KPD_R1_PIN, DIO_PIN_SET);
	MCAL_DIO_WritePin(KPD_Port, KPD_R2_PIN, DIO_PIN_SET);
	MCAL_DIO_WritePin(KPD_Port, KPD_R3_PIN, DIO_PIN_SET);
	MCAL_DIO_WritePin(KPD_Port, KPD_R4_PIN, DIO_PIN_SET);

}




/**================================================================
* @Fn			- KPD_GetKeyState
* @brief 		- This function checks each column for a key press,
* 				  Denounces, and returns the corresponding key value or 'A' if no key is pressed.
* @param [in] 	- none
* @param [out] 	- return key value
* @retval 		- none
* Note			- none
*
*/

uint8_t KPD_GetKeyState(void)
{
	uint8_t Column_counter= 0;
	uint8_t Rows_counter= 0;
	uint8_t Return_value;

	GPIO_KPD_init();

	for(Rows_counter=0; Rows_counter<4; Rows_counter++)
	{
		MCAL_DIO_WritePin(KPD_Port, KPD_RowsPins[Rows_counter], DIO_PIN_RESET);

		for(Column_counter=0; Column_counter<4; Column_counter++)
		{
			Return_value = MCAL_DIO_ReadPin(KPD_Port, KPD_ColumnsPins[Column_counter]);

			if(Return_value == DIO_PIN_RESET)
			{
				Return_value = MCAL_DIO_ReadPin(KPD_Port, KPD_ColumnsPins[Column_counter]);

				while(Return_value == DIO_PIN_RESET)
				{
					Return_value = MCAL_DIO_ReadPin(KPD_Port, KPD_ColumnsPins[Column_counter]);
				}

				return KPD_Keys[Rows_counter][Column_counter];
			}
		}

		MCAL_DIO_WritePin(KPD_Port, KPD_RowsPins[Rows_counter], DIO_PIN_SET);
	}

	return 'A';
}

