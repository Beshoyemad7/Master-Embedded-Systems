/*
 ******************************************************************************
 * Created On     : Sep 15,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

#define IO_BASE    0x20

#define PORTD      *(volatile uint32_t *)(IO_BASE + 0x12)
#define DDRD       *(volatile uint32_t *)(IO_BASE + 0x11)
#define PIND       *(volatile uint32_t *)(IO_BASE + 0x10)

#define PORTB      *(volatile uint32_t *)(IO_BASE + 0x18)
#define DDRB       *(volatile uint32_t *)(IO_BASE + 0x17)
#define PINB       *(volatile uint32_t *)(IO_BASE + 0x16)

#define SREG       *(volatile uint32_t *)(IO_BASE + 0x3F)

#define MCUCR      *(volatile uint32_t *)(IO_BASE + 0x35)
#define MCUCSR     *(volatile uint32_t *)(IO_BASE + 0x34)
#define GICR       *(volatile uint32_t *)(IO_BASE + 0x3B)
#define GIFR       *(volatile uint32_t *)(IO_BASE + 0x3A)

void GPIO_init(void)
{
	DDRD &= ~(1<<2); // PD.2: input
	DDRD &= ~(1<<3); // PD.3: input
	DDRB &= ~(1<<2); // PB.2: input
	DDRD |= (1<<5); //  PD.5: output
	DDRD |= (1<<6); //  PD.6: output
	DDRD |= (1<<7); //  PD.7: output
}

int main(void)
{
	GPIO_init();

	SREG  |= (1<<7);

	// any logical edge INT0
	MCUCR |= (1<<0);
	MCUCR &= ~(1<<1);

	// Rising edge INT1
	MCUCR |= (1<<2);
	MCUCR |= (1<<3);

	// Falling edge INT2
	MCUCSR &= ~(1<<6);

	// External Interrupt Request (0,1,2) Enable
	GICR  |= (1<<5);
	GICR  |= (1<<6);
	GICR  |= (1<<7);

	while(1);


}

ISR(INT0_vect)
{
	PORTD |= (1<<5);
	_delay_ms(100);
	PORTD &= ~(1<<5);

}

ISR(INT1_vect)
{
	PORTD |= (1<<6);
	_delay_ms(100);
	PORTD &= ~(1<<6);

}

ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(100);
	PORTD &= ~(1<<7);

}

