/*
 ******************************************************************************
 * Created On     : Aug 10,2024
 * File           : main.c
 * Author         : Beshoy Emad
 * Project		  : Create a student DATA BASE by linked list
 ******************************************************************************
*/

#include "Linked_List.h"

extern struct Sstudent* gpFirstStudent;

void main()
{
	char temp_text[40];
	
	while(1)
	{
		printf("\n ==================");
		printf("\n\t choose on the following options \n");
		printf("\n 1:  AddStudent ");
		printf("\n 2:  DeleteStudent ");
		printf("\n 3:  ViewStudents ");
		printf("\n 4:  DeleteAll ");
		printf("\n 5:  GetNth ");
		printf("\n 6:  Iterative Length of a Linked List ");
		printf("\n 7:  Recursive Length of a Linked List ");
		printf("\n 8:  GetNth from the end ");
		printf("\n 9:  the middle of students list ");
		printf("\n 10: Check if there is a loop or not ");
		printf("\n 11: Reverse a linked list ");
		printf("\n Enter option number: ");
		
		gets(temp_text);
		printf("\n ==================");
		
		switch(atoi (temp_text))
		{
			case 1: 
				Add_Student() ;
				break;
			case 2: 
				Delete_Student(); 
				break;
			case 3: 
				View_Students(); 
				break;
			case 4: 
				Delete_All() ;
				break;
			case 5: 
				Get_Nth ();
				break;
			case 6: 
				Iterative_Length_linked_List();
				break;
			case 7: 
				printf("\n The count = %d",Recursive_Length_linked_List(gpFirstStudent));
				break;
			case 8: 
				Get_Nth_from_the_end();
				break;
			case 9: 
				middle_linked_List();
				break;
			case 10: 
				detect_loop();
				break;
			case 11: 
				Reverse_linked_list();
				break;
			default: 
				printf("\n wrong options ");
				break;
		}
		
	}
}