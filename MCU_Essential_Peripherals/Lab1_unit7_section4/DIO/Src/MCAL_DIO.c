/*
 ******************************************************************************
 * Created On     : Sep 28,2024
 * File           : MCAL_DIO.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/


//======================================
//Includes
//======================================

#include "MCAL_DIO.h"


DIO_TypeDef *DIO_x = DIO;




/**================================================================
* @Fn			- MCAL_DIO_Init
* @brief 		- initialization the DIOx PINy according to your pinConfig
* @param [in] 	- DIOx: Select DIO PORT (A, B, C, D)
* @param [in] 	- PinConfig: pointer to the GPIO_PinConfig_t structure that contains the configuration
* 				  information for the GPIO pin
* @retval 		- none
* Note			- none
*
*/

void MCAL_DIO_Init(uint8_t DIOx, DIO_PinConfig_t *PinConfig) {


	if (DIOx == DIOA) {
		if (PinConfig->DIO_PinMode == DIO_MODE_OUTPUT) {
			DIO_x->DDRA |= PinConfig->DIO_PinNumber;
		} else if ((PinConfig->DIO_PinMode == DIO_MODE_INPUT_FLO) || (PinConfig->DIO_PinMode == DIO_MODE_INPUT_PU)) {
			DIO_x->DDRA &= ~(PinConfig->DIO_PinNumber);

			if (PinConfig->DIO_PinMode == DIO_MODE_INPUT_PU) {
				DIO_x->PORTA |= PinConfig->DIO_PinNumber;
			} else {
				DIO_x->PORTA &= ~(PinConfig->DIO_PinNumber);
			}

		}
	}


	else if (DIOx == DIOB) {
		if (PinConfig->DIO_PinMode == DIO_MODE_OUTPUT) {
			DIO_x->DDRB |= PinConfig->DIO_PinNumber;
		} else if ((PinConfig->DIO_PinMode == DIO_MODE_INPUT_FLO) || (PinConfig->DIO_PinMode == DIO_MODE_INPUT_PU)) {
			DIO_x->DDRB &= ~(PinConfig->DIO_PinNumber);

			if (PinConfig->DIO_PinMode == DIO_MODE_INPUT_PU) {
				DIO_x->PORTB |= PinConfig->DIO_PinNumber;
			} else {
				DIO_x->PORTB &= ~(PinConfig->DIO_PinNumber);
			}

		}
	}


	else if (DIOx == DIOC) {
		if (PinConfig->DIO_PinMode == DIO_MODE_OUTPUT) {
			DIO_x->DDRC |= PinConfig->DIO_PinNumber;
		} else if ((PinConfig->DIO_PinMode == DIO_MODE_INPUT_FLO) || (PinConfig->DIO_PinMode == DIO_MODE_INPUT_PU)) {
			DIO_x->DDRC &= ~(PinConfig->DIO_PinNumber);

			if (PinConfig->DIO_PinMode == DIO_MODE_INPUT_PU) {
				DIO_x->PORTC |= PinConfig->DIO_PinNumber;
			} else {
				DIO_x->PORTC &= ~(PinConfig->DIO_PinNumber);
			}

		}
	}


	else if (DIOx == DIOD) {
		if (PinConfig->DIO_PinMode == DIO_MODE_OUTPUT) {
			DIO_x->DDRD |= PinConfig->DIO_PinNumber;
		} else if ((PinConfig->DIO_PinMode == DIO_MODE_INPUT_FLO) || (PinConfig->DIO_PinMode == DIO_MODE_INPUT_PU)) {
			DIO_x->DDRD &= ~(PinConfig->DIO_PinNumber);

			if (PinConfig->DIO_PinMode == DIO_MODE_INPUT_PU) {
				DIO_x->PORTD |= PinConfig->DIO_PinNumber;
			} else {
				DIO_x->PORTD &= ~(PinConfig->DIO_PinNumber);
			}

		}
	}

	else {
		return;
	}


}




/**================================================================
* @Fn			- MCAL_DIO_WritePin
* @brief 		- write pin value on GPIOx
* @param [in] 	- DIOx: Select DIO PORT (A, B, C, D)
* @param [in] 	- PinNum: Select pin number (0..7)
* @param [in] 	- Value: Pin Value High OR Low
* @retval 		- none
* Note			- none
*
*/

void MCAL_DIO_WritePin(uint8_t DIOx, uint8_t PinNum, uint8_t Value) {

	if (DIOx == DIOA) {
		if (Value != DIO_PIN_RESET) {
			DIO_x->PORTA |= PinNum;
		} else {
			DIO_x->PORTA &= ~PinNum;
		}
	}

	else if (DIOx == DIOB) {
		if (Value != DIO_PIN_RESET) {
			DIO_x->PORTB |= PinNum;
		} else {
			DIO_x->PORTB &= ~PinNum;
		}
	}

	else if (DIOx == DIOC) {
		if (Value != DIO_PIN_RESET) {
			DIO_x->PORTC |= PinNum;
		} else {
			DIO_x->PORTC &= ~PinNum;
		}
	}

	else if (DIOx == DIOD) {
		if (Value != DIO_PIN_RESET) {
			DIO_x->PORTD |= PinNum;
		} else {
			DIO_x->PORTD &= ~PinNum;
		}
	}

	else {
		return;
	}

}




/**================================================================
* @Fn			- MCAL_DIO_WritePort
* @brief 		- write port value on DIOx
* @param [in] 	- DIOx: Select DIO PORT (A, B, C, D)
* @param [in] 	- Value: port Value High OR Low
* @retval 		- none
* Note			- none
*
*/

void MCAL_DIO_WritePort(uint8_t DIOx, uint8_t Value) {

	if (DIOx == DIOA) {
		DIO_x->PORTA = Value;
	}

	else if (DIOx == DIOB) {
		DIO_x->PORTB = Value;
	}

	else if (DIOx == DIOC) {
		DIO_x->PORTC = Value;
	}

	else if (DIOx == DIOD) {
		DIO_x->PORTD = Value;
	}

	else {
		return;
	}
}




/**================================================================
* @Fn			- MCAL_DIO_ReadPin
* @brief 		- Read pin value on DIOx
* @param [in] 	- DIOx: Select DIO PORT (A, B, C, D)
* @param [in] 	- PinNum: Select Pin Number (0..7)
* @param [out] 	- return bitstatus
* @retval 		- none
* Note			- none
*
*/

uint8_t MCAL_DIO_ReadPin(uint8_t DIOx, uint8_t PinNum) {

	uint8_t bitstatus;

	if (DIOx == DIOA) {
		if ((DIO_x->PINA & PinNum) != DIO_PIN_RESET) {
			bitstatus = DIO_PIN_SET;
		} else {
			bitstatus = DIO_PIN_RESET;
		}
	}

	else if (DIOx == DIOB) {
		if ((DIO_x->PINB & PinNum) != DIO_PIN_RESET) {
			bitstatus = DIO_PIN_SET;
		} else {
			bitstatus = DIO_PIN_RESET;
		}
	}

	else if (DIOx == DIOC) {
		if ((DIO_x->PINC & PinNum) != DIO_PIN_RESET) {
			bitstatus = DIO_PIN_SET;
		} else {
			bitstatus = DIO_PIN_RESET;
		}
	}

	else if (DIOx == DIOD) {
		if ((DIO_x->PIND & PinNum) != DIO_PIN_RESET) {
			bitstatus = DIO_PIN_SET;
		} else {
			bitstatus = DIO_PIN_RESET;
		}
	}

	else {
		return -1;
	}

	return bitstatus;
}




/**================================================================
* @Fn			- MCAL_DIO_ReadPort
* @brief 		- Read port value on DIOx
* @param [in] 	- DIOx: Select DIO PORT (A, B, C, D)
* @param [out] 	- return bitstatus
* @retval 		- none
* Note			- none
*
*/

uint8_t MCAL_DIO_ReadPort(uint8_t DIOx)
{
	uint8_t bitstatus;

	if (DIOx == DIOA) {
		bitstatus = DIO_x->PINA;
	}

	else if (DIOx == DIOB) {
		bitstatus = DIO_x->PINB;
	}

	else if (DIOx == DIOC) {
		bitstatus = DIO_x->PINC;
	}

	else if (DIOx == DIOD) {
		bitstatus = DIO_x->PIND;
	}

	else {
		return -1;
	}

	return bitstatus;

}




/**================================================================
* @Fn			- MCAL_DIO_TogglePin
* @brief 		- Toggle pin value on DIOx
* @param [in] 	- DIOx: Select DIO PORT (A, B, C, D)
* @param [in] 	- PinNum: Select Pin Number (0..7)
* @retval 		- none
* Note			- none
*
*/

void MCAL_DIO_TogglePin(uint8_t DIOx , uint8_t PinNum)
{
	if (DIOx == DIOA) {
		DIO_x->PORTA ^= PinNum;
	}

	else if (DIOx == DIOB) {
		DIO_x->PORTB ^= PinNum;
	}

	else if (DIOx == DIOC) {
		DIO_x->PORTC ^= PinNum;
	}

	else if (DIOx == DIOD) {
		DIO_x->PORTD ^= PinNum;
	}

	else {
		return;
	}
}



















