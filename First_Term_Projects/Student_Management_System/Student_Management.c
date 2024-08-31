/*
 ******************************************************************************
 * Created On     : Aug 31,2024
 * File           : Student_Management.c
 * Author         : Eng. Beshoy Emad
 * version        : V.1
 ******************************************************************************
*/

#include "Student_Management.h"
#include <string.h>

static int s_index =0; // index number of students

/************************************Function Description***********************************/
/*FIFO_init: Initializes a FIFO buffer by setting up its base, head, and tail pointers,
 * along with the buffer length and count.*/
/*******************************************************************************************/
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



/************************************Function Description***********************************/
/*add_student_manually: Adds a new student to the FIFO buffer if there's space and no
 * duplicate Roll Number.*/
/*******************************************************************************************/
FIFO_status_t add_student_manually (FIFO_Buf_t* lBuffer)
{
	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;

	if(FIFO_Is_Full(lBuffer) == FIFO_full)
		return FIFO_full;


	elemnt_type *New_student = &student_buff[s_index];
	elemnt_type *compare = lBuffer->tail;
	int c_index =0;

    printf("---------------------------\n");
	printf("Add the Students Details\n");
	printf("---------------------------\n");

	printf("Enter the Roll Number: ");
	scanf("%d", &(New_student->RollNum));

	printf("Enter the First Name of Student: ");
	scanf("%s", (New_student->FirstName));

	printf("Enter the Last Name of Student: ");
	scanf("%s", (New_student->LastName));

	printf("Enter the GPA you obtained: ");
	scanf("%f", &(New_student->GPA));

	printf("Enter the Course ID of each Course \n");

	while(c_index != course_width)
	{
		printf("Course %d id: ",c_index+1);
		scanf("%d", &(New_student->CourseId[c_index]));

		c_index++;
	}


	for(int i=0; i<lBuffer->count; i++)
	{
		if(compare->RollNum == New_student->RollNum)
		{
			printf("------------------------------------\n");
			printf("[ERROR]: The Roll Number is Taken\n");
			printf("------------------------------------\n");
			return FIFO_error;
		}

		compare++;

	}


    *(lBuffer->head) =student_buff[s_index];
     lBuffer->count++;
     s_index++;

     // circular fifo
	if(lBuffer->head == (lBuffer->base + (lBuffer->length * sizeof(elemnt_type))))
		lBuffer->head = lBuffer->base;
	else
		lBuffer->head++;

    return FIFO_no_error;
}



/************************************Function Description***********************************/
/*delete_student_roll_number: Deletes a student from the FIFO buffer based on the roll number.*/
/*******************************************************************************************/
FIFO_status_t delete_student_roll_number (FIFO_Buf_t* lBuffer)
{
	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;

	if(lBuffer->count == 0)
	{
		printf("------------------------------------------------- \n");
		printf("[ERROR]: The list is Empty\n");
		printf("------------------------------------------------- \n");
		return FIFO_empty;
	}
	
	int f_rollnum;
	int found=0;

	printf("Enter the Roll Number which you want to delete: ");
	scanf("%d",&f_rollnum);

	elemnt_type *compare = lBuffer->tail;

	for(int i=0; i<lBuffer->count; i++)
	{
		if(f_rollnum == compare->RollNum)
		{
			printf("------------------------------------\n");
			printf("The Roll number %d is removed \n",f_rollnum);
			printf("[INFO]: The Roll Number is removed Successfully\n");
			printf("------------------------------------\n");

			*compare = *(lBuffer->tail);
			found =1;
			break;
		}

		compare++;
	}

	if(found == 0 )
	{
		printf("------------------------------------\n");
		printf("[ERROR]: The Roll Number is not found \n");
		printf("------------------------------------\n");
		return FIFO_error;
	}

	lBuffer->count--;
	if(lBuffer->tail == (lBuffer->base + (lBuffer->length * sizeof(elemnt_type))))
		lBuffer->tail = lBuffer->base;
	else
		lBuffer->tail++;

	return FIFO_no_error;
	
}



/************************************Function Description***********************************/
/*FIFO_Is_Full: Checks if the FIFO buffer is full.   */
/*******************************************************************************************/
FIFO_status_t FIFO_Is_Full (FIFO_Buf_t* lBuffer)
{
	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;
	if(lBuffer->count == lBuffer->length)
		return FIFO_full;
	
	return FIFO_no_error;
	
	
}



/************************************Function Description***********************************/
/*show_all_information: Displays all student information stored in the FIFO buffer.   */
/*******************************************************************************************/
FIFO_status_t show_all_information (FIFO_Buf_t* lBuffer)
{
	elemnt_type* compare = lBuffer->tail;;

	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;

	if(lBuffer->count == 0)
	{
		printf("------------------------------------------------- \n");
		printf("[ERROR]: The list is Empty\n");
		printf("------------------------------------------------- \n");
		return FIFO_empty;
	}
	


	printf("*----------------------*Student data*----------------------*\n");

	int c_index=0;
	for(int i=0; i<lBuffer->count; i++)
	{
		printf("Enter the Roll Number: %d\n", compare->RollNum);
		printf("Enter the First Name of Student: %s\n", compare->FirstName);
		printf("Enter the Last Name of Student: %s\n",compare->LastName);
		printf("Enter the GPA you obtained: %.2f\n",compare->GPA);

		while(c_index != course_width)
		{
			printf("Course %d id: %d\n",c_index+1, compare->CourseId[c_index]);

			c_index++;
		}


		printf("---------------------------------------------------------------\n");
		compare++;
		c_index=0;
	}
		
return FIFO_no_error;

}



/************************************Function Description***********************************/
/*find_roll_number:  Searches for a student by roll number in the FIFO buffer.  */
/*******************************************************************************************/
FIFO_status_t find_roll_number(FIFO_Buf_t* lBuffer)
{
	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;

	if(FIFO_Is_Full(lBuffer) == FIFO_full)
		return FIFO_full;

	if(lBuffer->count == 0)
	{
		printf("------------------------------------------------- \n");
		printf("[ERROR]: The list is Empty\n");
		printf("------------------------------------------------- \n");

		return FIFO_empty;
	}

	int f_rollnum;
	int flag=0;
	int c_index=0;

	printf("Enter the Roll number of student :");
	scanf("%d",&f_rollnum);

	elemnt_type *compare = lBuffer->tail;

	for(int i=0; i<lBuffer->count; i++)
	{
		if(compare->RollNum == f_rollnum)
		{
			printf("The student detailes of Roll Number: %d\n", f_rollnum);
			printf("-------------------------------------------------------\n");

			printf("\nThe First Name of Student: %s\n", compare->FirstName);
		    printf("The Last Name of Student: %s\n",compare->LastName);
			printf("The GPA you obtained: %.2f\n",compare->GPA);

			while(c_index != course_width)
			{
				printf("Course %d id: %d\n",c_index+1, compare->CourseId[c_index]);

				c_index++;
			}

			printf("-------------------------------------------------------\n");

			flag = 1;
			c_index=0;
			break;
		}

		compare++;
	}

	if(flag == 0)
	{
		printf("------------------------------------------------- \n");
		printf("[ERROR]: Roll Number %d is not found \n", f_rollnum);
		printf("------------------------------------------------- \n");
	}

	return FIFO_no_error;
}



/************************************Function Description***********************************/
/*find_first_name: Searches for students by their first name in the FIFO buffer.   */
/*******************************************************************************************/
FIFO_status_t find_first_name(FIFO_Buf_t* lBuffer)
{
	if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
			return FIFO_Null;

		if(FIFO_Is_Full(lBuffer) == FIFO_full)
			return FIFO_full;

		if(lBuffer->count == 0)
		{
			printf("------------------------------------------------- \n");
			printf("[ERROR]: The list is Empty\n");
			printf("------------------------------------------------- \n");

			return FIFO_empty;
		}

		char f_firstname[20];
		int flag=0;
		int c_index=0;

		printf("Enter the First Name of student :");
		scanf("%s",f_firstname);

		elemnt_type *compare = lBuffer->tail;

		for(int i=0; i<lBuffer->count; i++)
		{
			if(strcmp(f_firstname, compare->FirstName) == 0)

			{
				printf("The student detailes of Roll Number: %d\n", compare->RollNum);
				printf("-------------------------------------------------------\n");

				printf("\nThe First Name of Student: %s\n", compare->FirstName);
			    printf("The Last Name of Student: %s\n",compare->LastName);
				printf("The GPA you obtained: %.2f\n",compare->GPA);

				while(c_index != course_width)
				{
					printf("Course %d id: %d\n",c_index+1, compare->CourseId[c_index]);

					c_index++;
				}

				printf("-------------------------------------------------------\n");

				c_index=0;
				flag = 1;

			}

				compare++;


		}

		if(flag == 0)
		{
			printf("------------------------------------------------- \n");
			printf("[ERROR]: First Name: %s is not found \n", f_firstname);
			printf("------------------------------------------------- \n");
		}

		return FIFO_no_error;
}



/************************************Function Description***********************************/
/*find_course_id: Searches for students by a specific course ID in the FIFO buffer. */
/*******************************************************************************************/
FIFO_status_t find_course_id(FIFO_Buf_t* lBuffer)
{
	    if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
			return FIFO_Null;

		if(FIFO_Is_Full(lBuffer) == FIFO_full)
			return FIFO_full;

		if(lBuffer->count == 0)
		{
			printf("------------------------------------------------- \n");
			printf("[ERROR]: The list is Empty\n");
			printf("------------------------------------------------- \n");

			return FIFO_empty;
		}

	    int f_courseid ;
	    int c_index =0;
	    int flag = 0;

	    printf("Enter the course id: ");
	    scanf("%d",&f_courseid);

	    elemnt_type *compare = lBuffer->tail;

	    for(int i=0; i<lBuffer->count; i++)
	    {
	    	while(c_index != course_width)
	    	{

	    		if(f_courseid == compare->CourseId[c_index])
	    		{
	    			printf("------------------------------------\n");
	    			printf("The first name: %s\n", compare->FirstName);
	    			printf("The last name: %s\n", compare->LastName);
	    			printf("The Roll number is: %d\n", compare->RollNum);
	    			printf("The GPA is: %.2f\n", compare->GPA);


	    			flag++;
	    			break;
	    		}

	    		c_index++;
	    	}

	    	c_index=0;
	    	compare++;
	    }

	    if(flag == 0)
	    {
	    	printf("------------------------------------------------- \n");
	    	printf("[ERROR:] course ID %d is not found \n",f_courseid);
	    	printf("------------------------------------------------- \n");
	    }

		else
		{
			 printf("------------------------------------------------- \n");
			 printf("[INFO:] Total Number of Student Enrolled: %d\n", flag);
			 printf("------------------------------------------------- \n");
		}


	    return FIFO_no_error;
}



/************************************Function Description***********************************/
/*total_number_student: Returns the total number of students in the FIFO buffer.  */
/*******************************************************************************************/
FIFO_status_t total_number_student(FIFO_Buf_t* lBuffer)
{
    if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;

	if(FIFO_Is_Full(lBuffer) == FIFO_full)
		return FIFO_full;

	if(lBuffer->count == 0)
	{
		printf("------------------------------------------------- \n");
		printf("[ERROR]: The list is Empty\n");
		printf("------------------------------------------------- \n");

		return FIFO_empty;
	}

	printf("------------------------------------------------- \n");
	printf("[INFO]: The total number of student is : %d\n", s_index);
	printf("[INFO]: You can add up to %d students \n", width1);
	printf("[INFO]: You can add %d more students \n", width1 - s_index);
	printf("------------------------------------------------- \n");

	return FIFO_no_error;

}



/************************************Function Description***********************************/
/*update_student_roll_number: Updates the details of a student with a specific roll number. */
/*******************************************************************************************/
FIFO_status_t update_student_roll_number(FIFO_Buf_t* lBuffer)
{
    if(!lBuffer->base || !lBuffer->head || !lBuffer->tail)
		return FIFO_Null;

	if(FIFO_Is_Full(lBuffer) == FIFO_full)
		return FIFO_full;

	if(lBuffer->count == 0)
	{
		printf("------------------------------------------------- \n");
		printf("[ERROR]: The list is Empty\n");
		printf("------------------------------------------------- \n");

		return FIFO_empty;
	}


	int u_option ;
	int f_rollnum;
	int c_index =0;
	int flag=0;

	printf("Enter the Roll number to update the entry :");
	scanf("%d",&f_rollnum);

	elemnt_type* compare = lBuffer->tail;



	 for(int i=0; i<lBuffer->count; i++)
	 {
    	if(f_rollnum == compare->RollNum)
    	{

    		printf("1. first name\n");
    		printf("2. last name\n");
    		printf("3. roll no\n");
    		printf("4. GPA\n");
    		printf("5. courses\n");

    		printf("choose you want updated: ");
    		scanf("%d",&u_option);

    		switch(u_option)
    		{
    			case 1:

    				printf("Enter the new first name: ");
    				scanf("%s",(compare->FirstName));

    				printf("------------------------------------\n");
    				printf("[INFO]: Updated Successfully\n");
    				printf("------------------------------------\n");

    				break;

    			case 2:

    				printf("Enter the new last name: ");
    				scanf("%s",(compare->LastName));

    				printf("------------------------------------\n");
    				printf("[INFO]: Updated Successfully\n");
    				printf("------------------------------------\n");

    				break;

    			case 3:

    				printf("Enter the new Roll number: ");
    				scanf("%d",&(compare->RollNum));

    				printf("------------------------------------\n");
    				printf("[INFO]: Updated Successfully\n");
    				printf("------------------------------------\n");

    				break;

    			case 4:

    				printf("Enter the new GPA: ");
    				scanf("%f",&(compare->GPA));

    				printf("------------------------------------\n");
    				printf("[INFO]: Updated Successfully\n");
    				printf("------------------------------------\n");

    				break;

    			case 5:

    				printf("Enter the new courses: \n");

    				while(c_index != course_width)
    				{
    					printf("Course %d id: ",c_index+1);
    					scanf("%d", &(compare->CourseId[c_index]));

    					c_index++;
    				}

    				printf("------------------------------------\n");
    				printf("[INFO]: Updated Successfully\n");
    				printf("------------------------------------\n");

    				break;


    			default:
    				printf("[ERROR]: Your option is wrong");
					break;
    		}


    		flag =1;
    		break;
    	}

    	compare++;
	 }

	 if(flag==0)
	 {
	     printf("------------------------------------------------- \n");
	     printf("[ERROR:] Roll Number is not found \n");
	     printf("------------------------------------------------- \n");
		 return FIFO_error;
	 }


	 return FIFO_no_error;

}



/************************************Function Description***********************************/
/*add_student_file: Adds student details from a file into the FIFO buffer. */
/*******************************************************************************************/
FIFO_status_t add_student_file(FIFO_Buf_t* lBuffer)
{
    FILE *file = fopen("student.txt", "r");

    if (file == NULL)
    {
        printf("[ERROR]: Could not open file\n");
        return FIFO_Null;
    }


    printf("------------------------------------------------- \n");
    printf("[INFO]: File opened successfully\n");
    printf("------------------------------------------------- \n");

    elemnt_type *New_student = &student_buff[s_index];
    elemnt_type *compare;
    int flag=0;

    // Read student data from the file
    while (fscanf(file, "%d %s %s %f %d %d %d %d %d",
                  &New_student->RollNum,
                  New_student->FirstName,
                  New_student->LastName,
                  &New_student->GPA,
                  &New_student->CourseId[0],
                  &New_student->CourseId[1],
                  &New_student->CourseId[2],
                  &New_student->CourseId[3],
                  &New_student->CourseId[4]) != EOF)
    {

        // Check if FIFO is full before adding a new student
        if (FIFO_Is_Full(lBuffer) == FIFO_full)
        {
            printf("[ERROR]: FIFO is full\n");
            fclose(file);
            return FIFO_full;
        }


        compare = lBuffer->tail;

        for(int i = 0; i < lBuffer->count; i++)
        {
            if(compare->RollNum == New_student->RollNum)
            {
                printf("[ERROR]: The Roll Number %d is already taken\n", New_student->RollNum);
                flag=1;
                break;
            }

           compare++;
        }


        if(flag==0)
        {
            printf("[INFO]: The Roll Number %d saved successfully\n", New_student->RollNum);
            *(lBuffer->head) = student_buff[s_index];
            lBuffer->count++;
            s_index++;
            New_student++;


            if(lBuffer->head == (lBuffer->base + (lBuffer->length * sizeof(elemnt_type))))
                lBuffer->head = lBuffer->base;
            else
                lBuffer->head++;
        }

        flag =0;


    }

    fclose(file);
    return FIFO_no_error;
}

