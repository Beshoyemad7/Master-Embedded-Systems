/*
 ******************************************************************************
 * Created On     : Aug 9,2024
 * File           : FIFO_buffer.h
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#ifndef FIFO_buffer_H_
#define FIFO_buffer_H_

#include <stdio.h>
#include <stdint.h>

//User configuration (uint8_t, uint16_t, uint32_t, ...)
#define elemnt_type uint8_t

//create buffer 1
#define width1 5
elemnt_type uart_buff[width1];

// type definitions
typedef struct
{
	uint32_t length ;
	uint32_t count ;
	elemnt_type *base ;
	elemnt_type *head ;
	elemnt_type *tail ;
	
}FIFO_Buf_t;

// Status
typedef enum {
	FIFO_no_error, 
	FIFO_full, 
	FIFO_empty, 
	FIFO_Null
} FIFO_status_t;


// APIs
FIFO_status_t FIFO_init (FIFO_Buf_t* lBuffer , elemnt_type* Buffer_array ,uint32_t length);
FIFO_status_t FIFO_Enqueue_item (FIFO_Buf_t* lBuffer , elemnt_type item);
FIFO_status_t FIFO_Dequeue_item (FIFO_Buf_t* lBuffer , elemnt_type *item);
FIFO_status_t FIFO_Is_Full (FIFO_Buf_t* lBuffer);
void FIFO_Print (FIFO_Buf_t* lBuffer);

#endif