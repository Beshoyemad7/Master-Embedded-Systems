/*
 ******************************************************************************
 * Created On     : Sep 30,2024
 * File           : main.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

//====================================
//Includes
//====================================

#include "MCAL_DIO.h"
#include "HAL_KEYPAD.h"
#include "HAL_LCD.h"


#define MAX_PARAMETERS 10

uint32_t Parameters[MAX_PARAMETERS]; // Carry all numbers after integration
uint8_t Count_Parameters = 0;

uint8_t Parameter_Digits[MAX_PARAMETERS]; // carry digit by digit -> {1, 2 , ..}
uint8_t Count_Parameter_Digits = 0;

uint8_t Math_Operators[MAX_PARAMETERS]; // carry operation -> {+, - , ..}
uint8_t Count_Math_Operators = 0;

int32_t Result = 0;


uint32_t Calc_Power(uint8_t base, uint8_t exp) {
	uint32_t result = 1;
	for (uint8_t i = 0; i < exp; i++) {
		result *= base;
	}
	return result;
}

void Integrate_Numbers() {
	uint32_t parameter = 0;
	for (uint8_t i = 0; i < Count_Parameter_Digits; i++) {
		uint8_t power = (Count_Parameter_Digits - 1) - i;
		parameter += Parameter_Digits[i] * Calc_Power(10, power);
	}

	Parameters[Count_Parameters] = parameter;
	Count_Parameters++;
	Count_Parameter_Digits = 0;
}

int32_t Perform_Operation() {
	for (uint8_t i = 0; i < Count_Math_Operators - 1; i++) {
		switch (Math_Operators[i]) {
		case '+':	Parameters[i + 1] = Parameters[i] + Parameters[i + 1];	break;
		case '-':	Parameters[i + 1] = Parameters[i] - Parameters[i + 1];	break;
		case '/':	Parameters[i + 1] = Parameters[i] / Parameters[i + 1];	break;
		case '*':	Parameters[i + 1] = Parameters[i] * Parameters[i + 1];	break;
		}
	}
	return Parameters[Count_Parameters - 1];
}

int32_t KPD_Calculator(uint8_t input) {
	if (input == '=' || input == '+' || input == '-' || input == '/' || input == '*') {
		Integrate_Numbers();
		Math_Operators[Count_Math_Operators++] = input;

		if (input == '=') {
			Result = Perform_Operation();
		}
	} else {

		Parameter_Digits[Count_Parameter_Digits] = input - '0';
		Count_Parameter_Digits++;
	}
	return Result;
}

int main(void) {

	HAL_LCD_Init();

	uint8_t key_pressed;
	int32_t result = 0;

	while (1) {
		key_pressed = KPD_GetKeyState();

		switch (key_pressed) {
		case 'A':
			break;

		case '?':
			HAL_LCD_Clean_Screen();

			Count_Parameters = 0;
			Count_Parameter_Digits = 0;
			Count_Math_Operators = 0;
			Result = 0;
			break;

		case '=':

			result = KPD_Calculator(key_pressed);
			HAL_LCD_Send_Char('=');

			if (result < 0) {
				HAL_LCD_Send_Char('-');
				result = -result;
			}

			HAL_LCD_Send_Number(result);
			break;

		default:
			KPD_Calculator(key_pressed);
			HAL_LCD_Send_Char(key_pressed);
			break;
		}

	}

}
