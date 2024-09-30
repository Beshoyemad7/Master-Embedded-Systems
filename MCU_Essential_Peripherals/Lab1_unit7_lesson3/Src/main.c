/*
 ******************************************************************************
 * Created On     : Sep 25,2024
 * File           : main.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#include "MCAL_GPIO.h"
#include "stm32f103x6.h"

void delay(uint32_t time)
{
	uint32_t i,j;
	for(i= 0; i< time; i++)
		for(j= 0; j< 255; j++);
}

void clock_init(void)
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void GPIO_init(void)
{
	GPIO_PinConfig_t pinConfig;

	pinConfig.GPIO_PinNumber = GPIO_PIN_1;
	pinConfig.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pinConfig);


	pinConfig.GPIO_PinNumber = GPIO_PIN_1;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinConfig);


	pinConfig.GPIO_PinNumber = GPIO_PIN_13;
	pinConfig.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pinConfig);


	pinConfig.GPIO_PinNumber = GPIO_PIN_13;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{

		if( ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)== 0 ) )
		{
			// single press
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)== 0 )  );
		}

		if( ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)== 1 )  )
		{
			// Multi press
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}

		delay(1);

	}

}
