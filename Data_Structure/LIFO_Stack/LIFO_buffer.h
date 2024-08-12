/*
 ******************************************************************************
 * Created On     : Aug 8,2024
 * File           : LIFO_buffer.h
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#ifndef LIFO_buffer_H_
#define LIFO_buffer_H_

#include <stdio.h>

// type definitions
typedef struct
{
	unsigned int *base ;
	unsigned int *head ;
	unsigned int length ;
	unsigned int count ;
}LIFO_Buf_t;

// Status
typedef enum {
	LIFO_no_error, 
	LIFO_full, 
	LIFO_empty, 
	LIFO_Null
} LIFO_status_t;


// APIs
LIFO_status_t LIFO_Add_item(LIFO_Buf_t* lBuffer , unsigned int item);
LIFO_status_t LIFO_get_item(LIFO_Buf_t* lBuffer , unsigned int *item);
LIFO_status_t LIFO_init(LIFO_Buf_t* lBuffer , unsigned int* Buffer_array ,unsigned int length);

#endif