/*
 ******************************************************************************
 * Created On     : Sep 21,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include <util/delay.h>
#include <stdint.h>

#define IO_BASE    0x20

#define PORTD      *(volatile uint32_t *)(IO_BASE + 0x12)
#define DDRD       *(volatile uint32_t *)(IO_BASE + 0x11)
#define PIND       *(volatile uint32_t *)(IO_BASE + 0x10)

#define SREG       *(volatile uint32_t *)(IO_BASE + 0x3F)



void GPIO_init(void)
{
	DDRD |= (1<<4); //  PD.4: output
	DDRD |= (1<<5); //  PD.5: output
	DDRD |= (1<<6); //  PD.6: output
	DDRD |= (1<<7); //  PD.7: output
}

int main(void)
{
	GPIO_init();

	PORTD |= (1<<5);
	_delay_ms(100);
	PORTD &= ~(1<<5);
	_delay_ms(100);

	PORTD |= (1<<6);
	_delay_ms(100);
	PORTD &= ~(1<<6);
	_delay_ms(100);

	PORTD |= (1<<7);
	_delay_ms(100);
	PORTD &= ~(1<<7);
	_delay_ms(100);

	// Buzzer
	PORTD |= (1<<4);


	while(1);


}


