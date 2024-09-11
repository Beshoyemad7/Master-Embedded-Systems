/*
 ******************************************************************************
 * Created On     : Sep 11,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR *(volatile uint32_t *)(RCC_BASE + 0x00)

/**********************************Description*******************************************/
/*Configure Board to run with the
Following rates:
- APB1 Bus frequency 16MHZ
- APB2 Bus frequency 8MHZ
- AHB frequency 32MHZ
- SysClk 32MHZ
- Use only internal HSI_RC*/
/****************************************************************************************/

int main(void)
{

/* Register: RCC_APB2ENR
Bit 2 -> IOPAEN: I/O port A clock enable
		 Set and cleared by software.
		 0: I/O port A clock disabled
		 1:I/O port A clock enabled
*/
RCC_APB2ENR |= 1<<2;

/* Register: RCC_CFGR
Bits 1:0 -> SW[1:0]: System clock Switch
 	 	 	 10: PLL selected as system clock

Bits 7:4 ->  HPRE[3:0]: AHB prescaler
			0xxx: SYSCLK not divided

Bits 10:8 -> PPRE1[2:0]: APB Low-speed prescaler (APB1)
			100: HCLK divided by 2

Bits 13:11 ->  PPRE2[2:0]: APB high-speed prescaler (APB2)
			101: HCLK divided by 4

Bit 16     -> PLLSRC: PLL entry clock source
			0: HSI oscillator clock / 2 selected as PLL input clock

Bits 21:18  -> PLLMUL: PLL multiplication factor
			0110: PLL input clock x 8
*/
RCC_CFGR |= 0b10<<0;
RCC_CFGR |= 0b0000<<4;
RCC_CFGR |= 0b100<<8;
RCC_CFGR |= 0b101<<11;
RCC_CFGR |= 0<<16;
RCC_CFGR |= 0b0110<<18;

/* Register: RCC_CR
Bit 24 -> PLLON: PLL enable
		1: PLL ON
*/
RCC_CR |= 1<<24;

//Init GPIOA
GPIOA_CRH &= 0xFF0FFFFF;
GPIOA_CRH |= 0x00200000;

while(1)
{
GPIOA_ODR |= 1<<13 ;
for (int i = 0; i < 5000; i++); // arbitrary delay
GPIOA_ODR &= ~(1<<13) ;
for (int i = 0; i < 5000; i++); // arbitrary delay
}

}

