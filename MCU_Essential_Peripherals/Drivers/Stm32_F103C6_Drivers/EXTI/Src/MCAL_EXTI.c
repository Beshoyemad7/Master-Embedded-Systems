/*
 ******************************************************************************
 * Created On     : Oct 1,2024
 * File           : MCAL_EXTI.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#include "MCAL_EXTI.h"


void (* GP_ISR_CallBack[16])(void);


#define AFIO_GPIO_EXTI_Mapping(x)		(   (x == GPIOA)? 0 : \
											(x == GPIOB)? 1 : \
											(x == GPIOC)? 2 : \
											(x == GPIOD)? 3 : 0   )




/**================================================================
* @Fn			- Enable_NVIC
* @brief 		- Enable NVIC ISR for Selected EXTI
* @param [in] 	- IRQ: Selected EXTI   (EXTI0....EXTI15)
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
		case 0: 	NVIC_IRQ6_EXTI0_Enable;			break;
		case 1: 	NVIC_IRQ7_EXTI1_Enable;			break;
		case 2: 	NVIC_IRQ8_EXTI2_Enable;			break;
		case 3: 	NVIC_IRQ9_EXTI3_Enable;			break;
		case 4: 	NVIC_IRQ10_EXTI4_Enable;		break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:		NVIC_IRQ23_EXTI5_9_Enable;		break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:	NVIC_IRQ40_EXTI10_15_Enable;	break;

	}
}




/**================================================================
* @Fn			- Disable_NVIC
* @brief 		- Disable NVIC ISR for Selected EXTI
* @param [in] 	- IRQ: Selected EXTI   (EXTI0....EXTI15)
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
		case 0: 	NVIC_IRQ6_EXTI0_Disable;			break;
		case 1: 	NVIC_IRQ7_EXTI1_Disable;			break;
		case 2: 	NVIC_IRQ8_EXTI2_Disable;			break;
		case 3: 	NVIC_IRQ9_EXTI3_Disable;			break;
		case 4: 	NVIC_IRQ10_EXTI4_Disable;			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:		NVIC_IRQ23_EXTI5_9_Disable;			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:	NVIC_IRQ40_EXTI10_15_Disable;		break;

	}
}




/**================================================================
* @Fn			- Update_EXTI
* @brief 		- The function configures the external interrupt (EXTI) pin Config,
* 				  input mode, AFIO routing, trigger edges (rising, falling, or both),
* 				  IRQ callback, and NVIC enabling/disabling.
* @param [in] 	- EXTI_Config: Information pin Config
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	//1- Configure pin as AF input -> Floating input
	GPIO_PinConfig_t pincfg;
	pincfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	pincfg.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &pincfg);

	//==================================================================================================

	//2- UPDATE AFIO to Route between EXTI Line with PORT A,B,C,D
	uint8_t AFIO_EXTICR_Index = 	(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) / 4;
	uint8_t AFIO_EXTICR_Position =  ((EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) % 4) * 4;
	// Clear the four bit
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Position) ;
	// Set
	AFIO->EXTICR[AFIO_EXTICR_Index] |=  (AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) & 0xF) << AFIO_EXTICR_Position ;

	//==================================================================================================

	// 3- UPDATE Rising and falling Edge
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_RISING)
	{
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	{
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

	//==================================================================================================

	// 4- Update IRQ Handling Callback
	GP_ISR_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_ISR_CallBack;

	// 5- Enable & Disable IRQ & NVIC
	if(EXTI_Config->ISR_EN == EXTI_ISR_Enable)
	{
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else
	{
		EXTI->IMR &= ~ (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}


}




/**================================================================
* @Fn			- MCAL_EXTI_GPIO_DeInit
* @brief 		- the function Reset state for EXTI & NVIC
* @param [out] 	- none
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/


void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR =  	0x00000000;
	EXTI->EMR =  	0x00000000;
	EXTI->RTSR =  	0x00000000;
	EXTI->FTSR =  	0x00000000;
	EXTI->SWIER =  	0x00000000;
	EXTI->PR =  	0xFFFFFFFF;

	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;

}




/**================================================================
* @Fn			- MCAL_EXTI_GPIO_Init
* @brief 		- the function Init the pin Config
* @param [in] 	- EXTI_Config: Information pin Config
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}




/**================================================================
* @Fn			- MCAL_EXTI_GPIO_Update
* @brief 		- it is the same previous function but name indicates change config at Run time
* @param [in] 	- EXTI_Config: Information pin Config
* @param [out] 	- none
* @retval 		- none
* Note			- none
*
*/

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}



/************************ ISR Handler Functions ***********************
 *
 **********************************************************************/

void EXTI0_IRQHandler()
{
	EXTI->PR |= 1<<0;

	GP_ISR_CallBack[0]();
}

void EXTI1_IRQHandler()
{
	EXTI->PR |= 1<<1;

	GP_ISR_CallBack[1]();
}

void EXTI2_IRQHandler()
{
	EXTI->PR |= 1<<2;

	GP_ISR_CallBack[2]();
}

void EXTI3_IRQHandler()
{
	EXTI->PR |= 1<<3;

	GP_ISR_CallBack[3]();
}

void EXTI4_IRQHandler()
{
	EXTI->PR |= 1<<4;

	GP_ISR_CallBack[4]();
}

void EXTI9_5_IRQHandler()
{
	if(EXTI->PR  & 1<<5)	{ EXTI->PR |= 1<<5;	GP_ISR_CallBack[5](); }
	if(EXTI->PR  & 1<<6)	{ EXTI->PR |= 1<<6;	GP_ISR_CallBack[6](); }
	if(EXTI->PR  & 1<<7)	{ EXTI->PR |= 1<<7;	GP_ISR_CallBack[7](); }
	if(EXTI->PR  & 1<<8)	{ EXTI->PR |= 1<<8;	GP_ISR_CallBack[8](); }
	if(EXTI->PR  & 1<<9)	{ EXTI->PR |= 1<<9;	GP_ISR_CallBack[9](); }
}

void EXTI15_10_IRQHandler()
{
	if(EXTI->PR  & 1<<10)	{ EXTI->PR |= 1<<10;	GP_ISR_CallBack[10](); }
	if(EXTI->PR  & 1<<11)	{ EXTI->PR |= 1<<11;	GP_ISR_CallBack[11](); }
	if(EXTI->PR  & 1<<12)	{ EXTI->PR |= 1<<12;	GP_ISR_CallBack[12](); }
	if(EXTI->PR  & 1<<13)	{ EXTI->PR |= 1<<13;	GP_ISR_CallBack[13](); }
	if(EXTI->PR  & 1<<14)	{ EXTI->PR |= 1<<14;	GP_ISR_CallBack[14](); }
	if(EXTI->PR  & 1<<15)	{ EXTI->PR |= 1<<15;	GP_ISR_CallBack[15](); }
}


