/*
 ******************************************************************************
 * Created On     : Sep 15,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define GPIOA_BASE  0x40010800
#define GPIOA_CRL   *(volatile uint32_t *)(GPIOA_BASE + 0x00) // A0: input
#define GPIOA_IDR   *(volatile uint32_t *)(GPIOA_BASE + 0x08h)
#define GPIOA_CRH   *(volatile uint32_t *)(GPIOA_BASE + 0x04) // A15: output
#define GPIOA_ODR   *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define AFIO_BASE   0x40010000
#define AFIO_EXTICR1   *(volatile uint32_t *)(AFIO_BASE + 0x08)

#define EXTI_BASE   0x40010400
#define EXTI0_IMR       *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI0_RTSR      *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI0_SWIER     *(volatile uint32_t *)(EXTI_BASE + 0x10)
#define EXTI0_PR        *(volatile uint32_t *)(EXTI_BASE + 0x14)

#define RCC_BASE    0x40021000
#define RCC_CR              *(volatile uint32_t *)(RCC_BASE + 0x00)
#define RCC_APB2ENR         *(volatile uint32_t *)(RCC_BASE + 0x18)

#define NVIC_ISER0          *(volatile uint32_t *)(0xE000E100)

void clock_init(void)
{
	RCC_APB2ENR |= (1<<0);
	RCC_APB2ENR |= (1<<2);
}

void GPIO_init(void)
{
	GPIOA_CRL |= (1<<2);
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
}

int main(void)
{
	clock_init();
	GPIO_init();

	// AFIO_EXTICR1 init
	AFIO_EXTICR1 |= 0;

	// 0: Interrupt request from Line 0 is masked
	// 1: Rising trigger enabled Interrupt for input line.
	// 0: SW disable
	EXTI0_IMR  |=  (1<<0);
	EXTI0_RTSR |= (1<<0);
	EXTI0_SWIER = 0;

	// Enable IQR_6
	NVIC_ISER0 |= (1<<6);

	while(1);
}

void EXTI0_IRQHandler(void)
{
	GPIOA_ODR ^= (1<<13);
	EXTI0_PR |= (1<<0);
}
