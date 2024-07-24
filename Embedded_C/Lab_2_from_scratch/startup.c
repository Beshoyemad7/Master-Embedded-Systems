/*
 ******************************************************************************
 * Created On     : Jul 24,2024
 * File           : startup.c_cortexM3.s
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
void NM_FAULT_handler() __attribute__((weak, alias ("default_handler")));;
void HARD_FAULT_handler() __attribute__((weak, alias ("default_handler")));;
void BUS_FAULT_handler() __attribute__((weak, alias ("default_handler")));;
void USAGE_FAULT_handler() __attribute__((weak, alias ("default_handler")));;

extern unsigned int stack_top;
uint32_t vectors [] __attribute__((section(".vectors"))) = {
	(uint32_t) &stack_top,     // 4 byte
	(uint32_t) &reset_handler, // 4 byte
	(uint32_t) &NMI_handler,   //  .....
	(uint32_t) &NM_FAULT_handler,
	(uint32_t) &HARD_FAULT_handler,
	(uint32_t) &BUS_FAULT_handler,
	(uint32_t) &USAGE_FAULT_handler
			/*....*/
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
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_data;
	
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