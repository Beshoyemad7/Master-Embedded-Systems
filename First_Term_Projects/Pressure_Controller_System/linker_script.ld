/*
 ******************************************************************************
 * Created On     : Jul 24,2024
 * File           : linker_script_cortexM3.s
 * Author         : Beshoy Emad
 ******************************************************************************
*/


MEMORY
{
	flash(RX)	: ORIGIN = 0x08000000, LENGTH = 128k 
	sram(RWX)	: ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
	.text : {
			*(.vectors*)     /* *(.vectors*) == any file (.vectors) + any name */
			*(.text*)
			*(.rodata)
			
			. = ALIGN(4);
			_E_text = . ;
	}>flash
	
	
	.data : {
			_S_data = . ;
			
			*(.data)
			
			_E_data = . ;
	
	}> sram AT> flash
	
	.bss : {
			_S_bss = . ;
			
			*(.bss)
			
			_E_bss = . ;
			
			. = ALIGN(4);
			. = . +0X1000 ; 
			
			stack_top = .;
	
	}>sram

}