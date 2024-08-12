/*
 ******************************************************************************
 * Created On     : Aug 9,2024
 * File           : FIFO_buffer.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include "FIFO_buffer.h"

// APIs
FIFO_status_t FIFO_init (FIFO_Buf_t* lBuffer , elemnt_type* Buffer_array ,uint32_t length)
{
	if(Buffer_array==NULL)
		return FIFO_Null;
	
	lBuffer->base =Buffer_array;
	lBuffer->head =Buffer_array;
	lBuffer->tail =Buffer_array;
	lBuffer->length =length;
	lBuffer->count =0;
	
	return FIFO_no_error;
}

FIFO_status_t FIFO_Enqueue_item (FIFO_Buf_t* lBuffer , elemnt_type item)
{
	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;
	if(FIFO_Is_Full(lBuffer) == FIFO_full)
		return FIFO_full;
 
*(lBuffer->head) =item;
lBuffer->count++;

// circular fifo
	if(lBuffer->head == (lBuffer->base + (lBuffer->length * sizeof(elemnt_type))))
		lBuffer->head = lBuffer->base;
	else
		lBuffer->head++;
	
return FIFO_no_error;
}

FIFO_status_t FIFO_Dequeue_item (FIFO_Buf_t* lBuffer , elemnt_type *item)
{
	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;
	if(lBuffer->count == 0)
		return FIFO_empty;
	
	*item = *(lBuffer->tail);
	lBuffer->count--;
	
	if(lBuffer->tail == (lBuffer->base + (lBuffer->length * sizeof(elemnt_type))))
		lBuffer->tail = lBuffer->base;
	else
		lBuffer->tail++;

	return FIFO_no_error;
	
}
FIFO_status_t FIFO_Is_Full (FIFO_Buf_t* lBuffer)
{
	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;
	if(lBuffer->count == lBuffer->length)
		return FIFO_full;
	
	return FIFO_no_error;
	
	
}
void FIFO_Print (FIFO_Buf_t* lBuffer)
{
	elemnt_type* temp;
	uint32_t i;
	if(lBuffer->count == 0)
	{
		printf("fifo is ----------> empty");
	}
	
	else
	{
		temp = lBuffer->tail;
		printf("=====fifo print=====\n");
		for(i=0; i<lBuffer->count; i++)
		{
			printf("\t %d \n", *temp);
			temp++;
		}
		
		printf("===============");
	}
}