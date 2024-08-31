/*
 ******************************************************************************
 * Created On     : Aug 31,2024
 * File           : Student_Management.h
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#ifndef FIFO_buffer_H_
#define FIFO_buffer_H_

#include <stdint.h>
#include <stdio.h>

// Type Definitions student management
typedef struct
{
	char FirstName[20];
	char LastName[20];
	int  RollNum;
	float GPA;
	int CourseId[10];

}S_info;


//User configuration (stack)
#define elemnt_type S_info

//Create student Data buffer with MaxStudent = 50
#define width1 50
elemnt_type student_buff[width1];

// 5 Courses are registered in one semester
#define course_width  5

// Type Definitions FIFO buffer
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
	FIFO_Null,
	FIFO_error
} FIFO_status_t;


// APIs
FIFO_status_t FIFO_init (FIFO_Buf_t* lBuffer , elemnt_type* Buffer_array ,uint32_t length);
FIFO_status_t add_student_manually (FIFO_Buf_t* lBuffer);
FIFO_status_t delete_student_roll_number (FIFO_Buf_t* lBuffer);
FIFO_status_t FIFO_Is_Full (FIFO_Buf_t* lBuffer);
FIFO_status_t find_roll_number(FIFO_Buf_t* lBuffer);
FIFO_status_t find_first_name(FIFO_Buf_t* lBuffer);
FIFO_status_t find_course_id(FIFO_Buf_t* lBuffer);
FIFO_status_t total_number_student(FIFO_Buf_t* lBuffer);
FIFO_status_t update_student_roll_number(FIFO_Buf_t* lBuffer);
FIFO_status_t show_all_information (FIFO_Buf_t* lBuffer);
FIFO_status_t add_student_file(FIFO_Buf_t* lBuffer);


#endif
