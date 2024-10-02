/*
 ******************************************************************************
 * Created On     : Oct 2,2024
 * File           : main.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#include "MCAL_GPIO.h"
#include "MCAL_EXTI.h"
#include "HAL_LCD.h"

void delay(uint32_t time)
{
	uint32_t i,j;
	for(i= 0; i< time; i++)
		for(j= 0; j< 255; j++);
}

void clock_Init(void)
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void EXTI9_Callback(void)
{
	HAL_LCD_Send_String("IRQ EXTI9 is Happened _|-");
	delay(1000);
}

int main(void)
{
	clock_Init();
	HAL_LCD_Init();

	EXTI_PinConfig_t PINCFG;
	PINCFG.EXTI_PIN = EXTI9PB9;
	PINCFG.Trigger_Case = EXTI_Trigger_RISING;
	PINCFG.ISR_EN = EXTI_ISR_Enable;
	PINCFG.P_ISR_CallBack = EXTI9_Callback;
	MCAL_EXTI_GPIO_Init(&PINCFG);


	while(1)
	{
		HAL_LCD_Clean_Screen();
	}


}
