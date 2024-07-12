/*
 ******************************************************************************
 * Created On     : Jul 12,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/
#include "Platform_Types.h"

#define RCC_BASE         0x40021000
#define GPIOA_BASE       0x40010800
#define RCC_APB2ENR      *(volatile  uint32_t *)(RCC_BASE+ 0x18)
#define GPIOA_CRH        *(volatile  uint32_t *)(GPIOA_BASE+0x04)
#define GPIOA_ODR        *(volatile  uint32_t *)(GPIOA_BASE+0x0C)

typedef union{
	volatile uint32_t all_port;
	struct{
	volatile uint32_t resolved: 13;
	volatile uint32_t p_13: 1;
	} PIN;
} R_ODR_t;

int main(void)
{
	RCC_APB2ENR  |= 1<<2;
	GPIOA_CRH    &= 0xFF0FFFFF;
	GPIOA_CRH    |= 0x00200000;

	volatile R_ODR_t *R = (volatile R_ODR_t*) (GPIOA_BASE+0x0C);

	while(1)
	{
		R->PIN.p_13=1;
		for(int i=0; i<5000; i++);
		R->PIN.p_13=0;
		for(int i=0; i<5000; i++);
	}

return 0;
}
