/*
 ******************************************************************************
 * Created On     : Sep 28,2024
 * File           : ATmega32.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************/

#ifndef INC_ATMEGA32_H_
#define INC_ATMEGA32_H_


//======================================
//Includes
//======================================

#include "stdlib.h"
#include "stdint.h"


//-----------------------------
//Base addresses for Memories
//-----------------------------

// Program_Memory
#define FLASH_Program_Memory_Base														0x0000UL

// Data Memory
#define GENERAL_Purpose_Registers_Base													0x0000UL
#define IO_Registers_Base							   									0x0020UL
#define External_Registers_Base															0x0060UL
#define Internal_SRAM_Registers_Base													0x0100UL


//--------------------------------------
//Base addresses for Peripherals
//--------------------------------------

#define IO_BASE 																		0x20


//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-


//-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct {

	volatile uint8_t PIND;    	// 0x00
	volatile uint8_t DDRD;		// 0x01
	volatile uint8_t PORTD;		// 0x02

	volatile uint8_t PINC;		// 0x03
	volatile uint8_t DDRC;		// 0x04
	volatile uint8_t PORTC;		// 0x05

	volatile uint8_t PINB;		// 0x06
	volatile uint8_t DDRB;		// 0x07
	volatile uint8_t PORTB;     // 0x08

	volatile uint8_t PINA;		// 0x09
	volatile uint8_t DDRA;		// 0x0A
	volatile uint8_t PORTA;		// 0x0B

} DIO_TypeDef;



//=========================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-

#define DIO 			((DIO_TypeDef *)(IO_BASE+0x10))   //0x30



#endif /* INC_ATMEGA32_H_ */
