/*
 ******************************************************************************
 * Created On     : Sep 26,2024
 * File           : main.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#include "MCAL_DIO.h"
#include  "HAL_LCD.h"

int main()
{
	HAL_LCD_Init();

	HAL_LCD_Send_String("Learn In Depth");
	HAL_LCD_GOTO_XY(2,0);
	HAL_LCD_Send_String("Eng. Beshoy Emad");

	while(1);
}


