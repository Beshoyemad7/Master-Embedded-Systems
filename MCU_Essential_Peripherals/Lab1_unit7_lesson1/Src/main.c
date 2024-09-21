/*
 ******************************************************************************
 * Created On     : Sep 20,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
#define GPIOA_BASE 		0x40010800
#define GPIOA_CRL 		*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH 		*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR 		*(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR 		*(volatile uint32_t *)(GPIOA_BASE + 0x08)

#define GPIOB_BASE 		0x40010C00
#define GPIOB_CRL 		*(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH 		*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR 		*(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR 		*(volatile uint32_t *)(GPIOB_BASE + 0x08)

#define RCC_BASE 		0x40021000
#define RCC_APB2ENR 	*(volatile uint32_t *)(RCC_BASE + 0x18)

void delay(uint32_t time)
{
	uint32_t i,j;
	for(i= 0; i< time; i++)
		for(j= 0; j< 255; j++);
}

void clock_init(void)
{
	RCC_APB2ENR |= (1<<2);
	RCC_APB2ENR |= (1<<3);
}

void GPIO_init(void)
{
	GPIOA_CRL = 0;
	GPIOA_CRH = 0;
	GPIOA_CRL |= (1<<6); // A1 input floating
	GPIOA_CRH |= (1<<22); // A13 input floating


	GPIOB_CRL = 0;
	GPIOB_CRH = 0;
	GPIOB_CRL |= (1<<4); // B1 output pull-push
	GPIOB_CRH |= (1<<20); // B13 output pull-push

}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{

		if( ( ((GPIOA_IDR & (1<<1)) >> 1) == 0 ) )
		{
			// single press
			GPIOB_ODR ^= (1<<1);
			while(( ((GPIOA_IDR & (1<<1)) >> 1) == 0) );
		}

		if( ( ((GPIOA_IDR & (1<<13)) >> 13) == 1 ) )
		{
			// Multi press
			GPIOB_ODR ^= (1<<13);
		}

		delay(1);

	}

}
