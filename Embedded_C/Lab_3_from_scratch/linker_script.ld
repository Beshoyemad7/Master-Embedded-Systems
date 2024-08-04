/*
 ******************************************************************************
 * Created On     : Jul 31,2024
 * File           : linker_script_cortexM4.s
 * Author         : Beshoy Emad
 ******************************************************************************
*/


MEMORY
{
	flash(RX)	: ORIGIN = 0x00000000, LENGTH = 512M 
	sram(RWX)	: ORIGIN = 0x20000000, LENGTH = 512M
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
			
	}>sram

}