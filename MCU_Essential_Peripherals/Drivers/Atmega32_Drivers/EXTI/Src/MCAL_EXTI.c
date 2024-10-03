/*
 ******************************************************************************
 * Created On     : Oct 3,2024
 * File           : MCAL_EXTI.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

//======================================
//Includes
//======================================

#include "MCAL_EXTI.h"

void (*GP_ISR_CallBack[3])(void);

// General Interrupt Control position
#define INT_Position(x)			(	(x == EXTI0)? 6 : \
									(x == EXTI1)? 7 : \
									(x == EXTI2)? 5 : 6 )




/**================================================================
 * @Fn			- Update_EXTI
 * @brief 		- The function configures the external interrupt (EXTI) pin Config,
 * 				  input mode, trigger edges, Enable EXTI and Global Interrupt
 * 				  IRQ callback.
 * @param [in] 	- EXTI_Config: Information pin Config
 * @param [out] 	- none
 * @retval 		- none
 * Note			- none
 *
 */

void Update_EXTI(EXTI_PinConfig_t* EXTI_Config) {

	//1- Configure pin as input -> Floating input
	DIO_PinConfig_t pinCFC;
	pinCFC.DIO_PinNumber = EXTI_Config->EXTI_PIN.DIO_PIN;
	pinCFC.DIO_PinMode = DIO_MODE_INPUT_FLO;
	MCAL_DIO_Init(EXTI_Config->EXTI_PIN.DIO_Port, &pinCFC);

	//===================================================================================

	//2- UPDATE Trigger Edge
	if (EXTI_Config->EXTI_PIN.DIO_Port == DIOD) {
		if(EXTI_Config->EXTI_PIN.EXTI_INT_Line == EXTI0){
			MCUCR |= EXTI_Config->Trigger_Case << 0;
		}
		else if(EXTI_Config->EXTI_PIN.EXTI_INT_Line == EXTI1){
			MCUCR |= EXTI_Config->Trigger_Case << 2;
		}
	}

	else if (EXTI_Config->EXTI_PIN.DIO_Port == DIOB) {
		if (EXTI_Config->Trigger_Case == EXTI_Trigger_RISING) {
			MCUCSR |= 1 << 6;
		}

		else if (EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING) {
			MCUCSR |= 0 << 6;
		}

	}

	//===================================================================================

	//3- ISR function
	GP_ISR_CallBack[EXTI_Config->EXTI_PIN.EXTI_INT_Line] = EXTI_Config->P_ISR_CallBack;

	//4- Enable EXTI_ISR
	GICR |= EXTI_Config->INT_EN << INT_Position(EXTI_Config->EXTI_PIN.EXTI_INT_Line);

	//5- Global_EXTI
	SREG |= EXTI_Config->Global_INT_EN << 7;

}




/**================================================================
 * @Fn			- MCAL_EXTI_GPIO_DeInit
 * @brief 		- the function Reset state for EXTI & Global Interrupt
 * @param [out] 	- none
 * @param [out] 	- none
 * @retval 		- none
 * Note			- none
 *
 */

void MCAL_EXTI_DIO_DeInit(void) {

	MCUCR = 0b0000;    // Reset Control INT0 , INT1
	MCUCSR = 0 << 6;      // Reset Control INT2
	GICR = 0b000 << 5;	// Reset INT0 , INT1, INT2 Disable
	GIFR = 0b000 << 5;  // Reset INT0 , INT1, INT2 Flag Disable
	SREG = 0 << 7;	    // Reset Global Interrupt Disable
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

void MCAL_EXTI_DIO_Init(EXTI_PinConfig_t* EXTI_Config) {

	Update_EXTI(EXTI_Config);
}




/**================================================================
 * @Fn			- MCAL_EXTI_GPIO_Update
 * @brief 		- it is the same previous function but name indicates change config at Run time
 * @param [in] 	- EXTI_Config: Information pin Config
 * @param [out] - none
 * @retval 		- none
 * Note			- none
 *
 */

void MCAL_EXTI_DIO_Update(EXTI_PinConfig_t* EXTI_Config) {
	Update_EXTI(EXTI_Config);
}




/************************ ISR Handler Functions ***********************
 *
 **********************************************************************/

void __vector_1(void) __attribute__ ((signal,used, externally_visible));
void __vector_1(void) {

	GP_ISR_CallBack[0]();
}

void __vector_2(void) __attribute__ ((signal,used, externally_visible));
void __vector_2(void) {

	GP_ISR_CallBack[1]();
}

void __vector_3(void) __attribute__ ((signal,used, externally_visible));
void __vector_3(void) {

	GP_ISR_CallBack[2]();
}

