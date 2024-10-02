/*
 ******************************************************************************
 * Created On     : Sep 25,2024
 * File           : MCAL_GPIO.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/


//-----------------------------
//Includes
//-----------------------------

#include "MCAL_GPIO.h"


/**================================================================
* @Fn			- Get_CRLH_Position
* @brief 		- Get pin position on CRL or CRH Each pin has 4-bit MODE[0,1] CNF[0,1]
* @param [in] 	- PinNumber: switch on your pin Number  -> includes (GPIO_PIN_0 ... GPIO_PIN_15)
* @param [out] 	- return position
* @retval 		- none
* Note			- none
*
*/

uint16_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:	return 0;
	break;

	case GPIO_PIN_1:	return 4;
	break;

	case GPIO_PIN_2:	return 8;
	break;

	case GPIO_PIN_3:	return 12;
	break;

	case GPIO_PIN_4:	return 16;
	break;

	case GPIO_PIN_5:	return 20;
	break;

	case GPIO_PIN_6:	return 24;
	break;

	case GPIO_PIN_7:	return 28;
	break;

	case GPIO_PIN_8:	return 0;
	break;

	case GPIO_PIN_9:	return 4;
	break;

	case GPIO_PIN_10:	return 8;
	break;

	case GPIO_PIN_11:	return 12;
	break;

	case GPIO_PIN_12:	return 16;
	break;

	case GPIO_PIN_13:	return 20;
	break;

	case GPIO_PIN_14:	return 24;
	break;

	case GPIO_PIN_15:	return 28;
	break;

	default:  return -1;
	break;

	}


}




/**================================================================
* @Fn			- MCAL_GPIO_Init
* @brief 		- Initialization the GPIOx PINy according to your pinConfig
* @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [in] 	- PinConfig: pointer to the GPIO_PinConfig_t structure that contains the configuration
* 				  information for the GPIO pin
* @retval 		- none
* Note			- stm32F103C6 MCU has GPIO A...E Modules
* 				  but LQFP48 Package has only GPIO A,B part of C,D exported as external pins from the MCU
*/

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t *PinConfig)
{
	// Check Pin is CRL (GPIO_PIN_0...GPIO_PIN_7) OR CRH (GPIO_PIN_8...GPIO_PIN_15)
	volatile uint32_t *configregister = NULL;
	uint8_t pin_config =0;

	if(PinConfig->GPIO_PinNumber < GPIO_PIN_8)
		configregister = &GPIOx->CRL;
	else
		configregister = &GPIOx->CRH;

	// Clear CRL OR CRH for Pin used
	(*configregister) &=  ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	// IF Pin is Output
	if((PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_OD) ||(PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_AF_PP) ||(PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_AF_OD))
	{
		// pin_config: carry 4-bit for bin MODE[0,1] , CNF[0,1]
		pin_config = ( (((PinConfig->GPIO_PinMode - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0F);

	}

	// If Pin is Input
	else
	{

		if((PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_FLO) ||  (PinConfig->GPIO_PinMode == GPIO_MODE_Analog))
		{
			pin_config = ( (((PinConfig->GPIO_PinMode) << 2) | (0x0)) & 0x0F);

		}

		else if((PinConfig->GPIO_PinMode == GPIO_MODE_AF_INPUT))
		{
			pin_config = ( (((GPIO_MODE_INPUT_FLO) << 2) | (0x0)) & 0x0F);
		}

		else
		{
			if((PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_PU))
			{
				// PxODR = 1 ->  Input Pull-up
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;


			}
			else
			{
				// PxODR = 0 -> Input Pull-down
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);

			}

		}

	}

	// write on CRL OR CRH
	(*configregister) |=  (	(pin_config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber)	);

}




/**================================================================
* @Fn			- MCAL_GPIO_DeInit
* @brief 		- DeInitialization the GPIOx (Reset)
* @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @retval 		- none
* Note			- none
*
*/

void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}

}




/**================================================================
* @Fn			- MCAL_GPIO_ReadPin
* @brief 		- Read pin value from GPIOx
* @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [in] 	- PinNum: Choose the pin Number that I want to read (GPIO_PIN_0 ... GPIO_PIN_15)
* @param [out] 	- bitstatus: return status value
* @retval 		- none
* Note			- none
*
*/

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNum)
{
	uint8_t bitstatus;

	if(	((GPIOx->IDR) & PinNum) != (uint32_t)GPIO_PIN_RESET)
	{
		bitstatus = GPIO_PIN_SET;
	}

	else
	{
		bitstatus = GPIO_PIN_RESET;
	}

	return bitstatus;


}




/**================================================================
* @Fn			- MCAL_GPIO_ReadPort
* @brief 		- Read PORT value
* @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [out] 	- portvalue: return port value
* @retval 		- none
* Note			- none
*
*/

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	uint16_t portvalue ;
	portvalue = (uint16_t)GPIOx->IDR;

	return portvalue;
}




/**================================================================
* @Fn			- MCAL_GPIO_WritePin
* @brief 		- write pin value on GPIOx
* @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [in] 	- PinNum: Choose the pin Number that I want to write (GPIO_PIN_0 ... GPIO_PIN_15)
* @param [in] 	- Value: write value = 1; value = 0
* @retval 		- none
* Note			- none
*
*/

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx , uint16_t PinNum, uint8_t Value)
{
	if(Value != GPIO_PIN_RESET)
	{
		//GPIOx->ODR |= PinNum;
		// OR
		GPIOx->BSRR = (uint32_t)PinNum;
	}

	else
	{
		//GPIOx->ODR &= ~PinNum;
		// OR
		GPIOx->BRR = (uint32_t)PinNum;
	}


}




/**================================================================
* @Fn			- MCAL_GPIO_WritePort
* @brief 		- write port value on GPIOx
* @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [in] 	- Value: write value = 1; value = 0
* @retval 		- none
* Note			- none
*
*/

void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}




/**================================================================
* @Fn			- MCAL_GPIO_TogglePin
* @brief 		- Toggle pin value on GPIOx
* @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [in] 	- PinNum: Choose the pin Number that I want to Toggle (GPIO_PIN_0 ... GPIO_PIN_15)
* @retval 		- none
* Note			- none
*
*/

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx , uint16_t PinNum)
{
	GPIOx->ODR ^= (uint32_t)PinNum;
}




/**================================================================
* @Fn			- MCAL_GPIO_LockPin
* @brief 		- When the LOCK sequence has been applied on a port bit it is no longer possible to
* 				  modify the value of the port bit until the next reset.
* @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
* @param [in] 	- PinNum: Choose the pin Number that I want to lock (GPIO_PIN_0 ... GPIO_PIN_15)
* @retval 		- none
* Note			- none
*
*/

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx , uint16_t PinNum)
{
	volatile uint32_t temp = 1<<16;
	temp |= PinNum;

	GPIOx->LCKR = temp; 	//write 1
	GPIOx->LCKR = PinNum;	//write 0
	GPIOx->LCKR = temp;		//write 1

	temp = GPIOx->LCKR ;  // Read 0


	// Read 1 and check
	if((uint16_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_OK;
	}

	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}
}









