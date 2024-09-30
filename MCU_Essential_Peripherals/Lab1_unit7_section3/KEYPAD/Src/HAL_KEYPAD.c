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
#include "MCAL_GPIO.h"

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
	GPIO_PinConfig_t pinConfig;

	// Rows pins
	pinConfig.GPIO_PinNumber = KPD_R1_PIN;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KPD_Port, &pinConfig);

	pinConfig.GPIO_PinNumber = KPD_R2_PIN;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KPD_Port, &pinConfig);

	pinConfig.GPIO_PinNumber = KPD_R3_PIN;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KPD_Port, &pinConfig);

	pinConfig.GPIO_PinNumber = KPD_R4_PIN;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KPD_Port, &pinConfig);

	// Columns pins
	pinConfig.GPIO_PinNumber = KPD_C1_PIN;
	pinConfig.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(KPD_Port, &pinConfig);

	pinConfig.GPIO_PinNumber = KPD_C2_PIN;
	pinConfig.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(KPD_Port, &pinConfig);

	pinConfig.GPIO_PinNumber = KPD_C3_PIN;
	pinConfig.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(KPD_Port, &pinConfig);

	pinConfig.GPIO_PinNumber = KPD_C4_PIN;
	pinConfig.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(KPD_Port, &pinConfig);

	MCAL_GPIO_WritePin(KPD_Port, KPD_R1_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(KPD_Port, KPD_R2_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(KPD_Port, KPD_R3_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(KPD_Port, KPD_R4_PIN, GPIO_PIN_RESET);

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
		MCAL_GPIO_WritePin(KPD_Port, KPD_RowsPins[Rows_counter], GPIO_PIN_SET);

		for(Column_counter=0; Column_counter<4; Column_counter++)
		{
			Return_value = MCAL_GPIO_ReadPin(KPD_Port, KPD_ColumnsPins[Column_counter]);

			if(Return_value == GPIO_PIN_SET)
			{
				Return_value = MCAL_GPIO_ReadPin(KPD_Port, KPD_ColumnsPins[Column_counter]);

				while(Return_value == GPIO_PIN_SET)
				{
					Return_value = MCAL_GPIO_ReadPin(KPD_Port, KPD_ColumnsPins[Column_counter]);
				}

				return KPD_Keys[Rows_counter][Column_counter];
			}
		}

		MCAL_GPIO_WritePin(KPD_Port, KPD_RowsPins[Rows_counter], GPIO_PIN_RESET);
	}

	return 'A';
}

