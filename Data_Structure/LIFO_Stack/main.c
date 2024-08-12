/*
 ******************************************************************************
 * Created On     : Aug 8,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#include "LIFO_buffer.h"

#define length   5

unsigned int buffer1[length];

void main()
{
	int i,temp =0;
	
	LIFO_Buf_t uart_buf;
	LIFO_Buf_t i2c_buf;
	
	// static allocation
	LIFO_init(&uart_buf,buffer1,length);
	
	// Dynamic allocation
	unsigned int *buffer2 = (unsigned int *) malloc(length * sizeof(unsigned int));
	LIFO_init(&i2c_buf,buffer2,length);
	
	// Add item
	for(i=0; i<length; i++)
	{
		if(LIFO_Add_item(&uart_buf,i) == LIFO_no_error)
			printf("UART push: %d \n",i);
	}
	
	printf("\n");
	
	// get item
	for(i=0; i<length; i++)
	{
		if(LIFO_get_item(&uart_buf,&temp) == LIFO_no_error)
			printf("UART pop: %d \n",temp);
	}
}