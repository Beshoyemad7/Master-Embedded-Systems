/*
 ******************************************************************************
 * Created On     : Aug 31,2024
 * File           : main.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#include "Student_Management.h"


int main()
{
	int option;

	// intialization s_FIFO buffer
	FIFO_Buf_t s_FIFO;
	FIFO_init (&s_FIFO ,student_buff ,width1);

	
	while(1)
	{
	printf("\nWelcome to the Student Management System \n");
	printf("choose the option that you want to perform\n");

	printf("1. Add the Student Details Manually\n");
	printf("2. Add the Student Details From the Text File\n");
	printf("3. Find the Student Details by Roll Number\n");
	printf("4. Find the Student Details by First Name\n");
	printf("5. Find the Student Details by Course Id\n");
	printf("6. Find the Total Number of Students\n");
	printf("7. Delete the Student Details by Roll Number\n");
	printf("8. Update the Student Details by Roll Number\n");
	printf("9. Show all information\n");
	printf("10. To Exit\n");

	printf("Enter your choice to perform the option: ");
	scanf("%d", &option);
	


	switch(option)
	 {
		case 1:
			if(add_student_manually(&s_FIFO) == FIFO_no_error)
			{
				printf("------------------------------------\n");
				printf("[INFO]:Student added successfully.\n");
				printf("------------------------------------\n");
			}

		break;

		case 2:
			add_student_file(&s_FIFO);
		break;

		case 3:
			find_roll_number(&s_FIFO);
		break;

	    case 4:
			find_first_name(&s_FIFO);
		break;

		case 5:
			find_course_id(&s_FIFO);
		break;

		case 6:
			total_number_student(&s_FIFO);
		break;

		case 7:
			delete_student_roll_number(&s_FIFO);
		break;

		case 8:
			update_student_roll_number(&s_FIFO);
		break;

		case 9:
			show_all_information(&s_FIFO);
		break;

		case 10:
			exit(0);
		break;

		default:
		printf("your option is not found");
		break;
	 }
	}

	return 0;
}
