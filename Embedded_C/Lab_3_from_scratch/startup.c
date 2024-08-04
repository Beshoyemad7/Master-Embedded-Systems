/*
 ******************************************************************************
 * Created On     : Jul 31,2024
 * File           : startup.c_cortexM4.s
 * Author         : Beshoy Emad
 ******************************************************************************
*/
#include <stdint.h>

void reset_handler(void);
void default_handler(void)
{
	reset_handler();
}
extern int main(void);
void NMI_handler() __attribute__((weak, alias ("default_handler")));;
void H_FAULT_handler() __attribute__((weak, alias ("default_handler")));;


// BOOKING 1024 byte located by .bss through unintialized array of int 256 Elment (256*4=1024)
static unsigned long Stack_top[256];


/* uint32_t vectors [] __attribute__((section(".vectors"))) = {
	(uint32_t) (&Stack_top[0] + sizeof(Stack_top)), // 4 byte
	(uint32_t) &reset_handler, // 4 byte
	(uint32_t) &NMI_handler,   //  .....
	(uint32_t) &H_FAULT_handler,
}; */

void (* const global_p_func_vectors[])() __attribute__((section(".vectors"))) = {
	(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)), 
	 &reset_handler, 
	 &NMI_handler,  
	 &H_FAULT_handler
};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_handler(void)
{
	
	// copy data from flash to Ram
	unsigned int DATA_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;   
	unsigned char* P_src = (unsigned char*)&_E_text;  // P_src: carry first address .data in flash
	unsigned char* P_dst = (unsigned char*)&_S_data;  // P_dst: carry first address .data in sram
	
	for(int i=0; i<DATA_size; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	
	// init .bss section in SRAM = 0
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss;
	
	for(int i=0; i<bss_size; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}
	
	
	// jump main
	main();
}