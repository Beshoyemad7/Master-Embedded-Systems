/*
 ******************************************************************************
 * Created On     : Aug 8,2024
 * File           : LIFO_buffer.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include "LIFO_buffer.h"

LIFO_status_t LIFO_Add_item(LIFO_Buf_t* lBuffer , unsigned int item)
{
	if(!lBuffer->base || !lBuffer->head)
		return LIFO_Null;
	
	if(lBuffer->count == lBuffer->length)
		return LIFO_full;
	
	*(lBuffer->head) = item;
	lBuffer->head++ ;
	lBuffer->count++ ;
	
	return LIFO_no_error;
}

LIFO_status_t LIFO_get_item(LIFO_Buf_t* lBuffer , unsigned int *item)
{

	if(!lBuffer->base || !lBuffer->head)
		return LIFO_Null;
	
	if(lBuffer->count == 0)
		return LIFO_empty;
	

	lBuffer->head-- ;
	*item = *(lBuffer->head);
	lBuffer->count-- ;
	
	return LIFO_no_error;
}

LIFO_status_t LIFO_init(LIFO_Buf_t* lBuffer , unsigned int* Buffer_array ,unsigned int length)
{
	if(Buffer_array == NULL)
		return LIFO_Null;
	
	lBuffer->base = Buffer_array;
	lBuffer->head = Buffer_array;
	lBuffer->length = length;
	lBuffer->count = 0;
	
	return LIFO_no_error;
}