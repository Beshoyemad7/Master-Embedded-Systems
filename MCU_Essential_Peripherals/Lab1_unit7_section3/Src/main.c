/*
 ******************************************************************************
 * Created On     : Sep 28,2024
 * File           : main.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#include "MCAL_GPIO.h"
#include "HAL_KEYPAD.h"
#include "HAL_LCD.h"

#include <stdint.h>


#define ZERO 		0x00
#define ONE 		0x01
#define TWO 		0x02
#define THREE 		0x03
#define FOUR 		0x04
#define FIVE 		0x05
#define SIX 		0x06
#define SEVEN		0x07
#define EIGHT 		0x08
#define NINE 		0x09



uint8_t Seven_SEG[]={ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
uint8_t LCD_Display[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};


void wait_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);

}


void clock_init(void)
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();

}


void Seven_SEG_init(void)
{
	// Seven Segment Port GPIOB pins from 12->15

	GPIO_PinConfig_t pinConfig;

	pinConfig.GPIO_PinNumber = GPIO_PIN_12;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_13;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_14;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	pinConfig.GPIO_PinNumber = GPIO_PIN_15;
	pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

}



int main(void)
{
	clock_init();
	HAL_LCD_Init();
	Seven_SEG_init();

	uint8_t Key_pressed;

	HAL_LCD_Send_String("HEY");
	wait_ms(70);
	HAL_LCD_Clean_Screen();


	for(uint8_t i=0; i<11; i++)
	{
		HAL_LCD_Send_Char(LCD_Display[i]);
		MCAL_GPIO_WritePort(GPIOB, (Seven_SEG[i]<<12) );
		wait_ms(100);

	}


	HAL_LCD_Clean_Screen();
	HAL_LCD_Send_String("KEYPAD IS READY!");
	wait_ms(50);
	HAL_LCD_Clean_Screen();


	while (1)
	{
		Key_pressed = KPD_GetKeyState();

		switch (Key_pressed)
		{
		case 'A':
			break;

		case '?':
			HAL_LCD_Clean_Screen();
			break;

		default:
			HAL_LCD_Send_Char(Key_pressed);
			break;
		}

	}


}
