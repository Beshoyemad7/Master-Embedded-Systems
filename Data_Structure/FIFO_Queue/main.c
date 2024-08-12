/*
 ******************************************************************************
 * Created On     : Aug 9,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include "FIFO_buffer.h"

void main()
{
	FIFO_Buf_t FIFO_uart;
	
	elemnt_type i, temp;
	if( FIFO_init(&FIFO_uart, uart_buff, width1) == FIFO_no_error)
		printf("fifo init is  ----------> Done \n");
	
	for(i=0; i<7; i++)
	{
		printf("fifo enqueue (%d) \n", i);
		if(FIFO_Enqueue_item(&FIFO_uart, i) == FIFO_no_error)
			printf("\t fifo enqueue is  ----------> Done \n");
		else
			printf("\t fifo enqueue is  ----------> failed \n");
	}
	
	FIFO_Print(&FIFO_uart);
	
	if(FIFO_Dequeue_item(&FIFO_uart, &temp) == FIFO_no_error)
		printf("\n\t fifo dequeue %d  ----------> Done \n",temp);
	if(FIFO_Dequeue_item(&FIFO_uart, &temp) == FIFO_no_error)
		printf("\t fifo dequeue %d  ----------> Done \n",temp);
	
	FIFO_Print(&FIFO_uart);

}