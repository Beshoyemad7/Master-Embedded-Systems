/*
 ******************************************************************************
 * Created On     : Aug 10,2024
 * File           : Linked_list.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#include "Linked_List.h"

struct Sstudent* gpFirstStudent= NULL; //list is empty 

void Add_Student()
{
	struct Sstudent* PNewStudent;
	struct Sstudent* PlastStudent;
	char temp_text[40];
	// check if list is empty
	if(gpFirstStudent == NULL)
	{
		// create new record
		PNewStudent = (struct Sstudent* )malloc(sizeof (struct Sstudent));
		// assign it the newstudent 
		gpFirstStudent= PNewStudent;
	}
	
	// list contains records
	else
	{
		// navigate until reach to the last record
		PlastStudent = gpFirstStudent;
		while(PlastStudent->PNextStudent)
		{
			PlastStudent = PlastStudent->PNextStudent;
		}
		
		// create new record
		PNewStudent = (struct Sstudent* )malloc(sizeof (struct Sstudent));
		PlastStudent->PNextStudent = PNewStudent;
	}
	
	// fill new record
	printf("\nEnter the ID: ");
	gets(temp_text);
	PNewStudent->student.ID = atoi(temp_text);
	
	printf("Enter the Name: ");
	gets(PNewStudent->student.name);
	
	printf("Enter the height: ");
	gets(temp_text);
	PNewStudent->student.height = atof(temp_text);
	
	// set the next pointer (NewStudent) null
	PNewStudent->PNextStudent = NULL;
	
}

int Delete_Student()
{
	char temp_text[40];
	int selected_id;
	printf("\n Enter student ID: ");
	gets(temp_text);
	selected_id = atoi(temp_text);
	
	// list have records
	if(gpFirstStudent)
	{
		struct Sstudent* ppreviousStudent =NULL;
	    struct Sstudent* PSelectedStudent =gpFirstStudent;
		
		// loop on all records starting from gpFirstStudent
		while(PSelectedStudent)
		{
			// compare record ID with the selected_id
			if(PSelectedStudent->student.ID == selected_id)
			{
				if(ppreviousStudent)
				{
					ppreviousStudent->PNextStudent = PSelectedStudent->PNextStudent;
				}
				else
				{
					gpFirstStudent = PSelectedStudent->PNextStudent;
				}
				
				free(PSelectedStudent);
				return 1; // find it 
			}
			
			else
			{
				
			// store previous record pointer
			ppreviousStudent = PSelectedStudent;
			PSelectedStudent =  PSelectedStudent->PNextStudent;
			
			}
			
		}
		
	}
	
	printf("\n The student is not found");
	return 0;
}

void View_Students()
{
	struct Sstudent* pCurrentstudent = gpFirstStudent;
	int count = 0;
	
	if(gpFirstStudent == NULL)
		printf("\n The list is empty");
	
	else
	{
		while(pCurrentstudent)
		{
			printf("\n Record number %d", count+1);
			printf("\n ID: %d", pCurrentstudent->student.ID);
			printf("\n Name: %s", pCurrentstudent->student.name);
			printf("\n Height: %f\n", pCurrentstudent->student.height);
			
			pCurrentstudent = pCurrentstudent->PNextStudent;
			count++;
		}
	}
}

void Delete_All()
{
	struct Sstudent* pCurrentstudent = gpFirstStudent;
	
	if(gpFirstStudent == NULL)
		printf("\n The list is empty");
	
	else
	{
		while(pCurrentstudent)
		{
			struct Sstudent* ptempstudent = pCurrentstudent;
			pCurrentstudent = pCurrentstudent->PNextStudent;
			free(ptempstudent);
		}
		
		gpFirstStudent = NULL;
	}
}

int Get_Nth ()
{
	struct Sstudent* pCurrentstudent = gpFirstStudent;
	int index;
	char temp_text[40];
	int count=0;
	
	printf("\n Enter the index number: ");
	gets(temp_text);
	index =atoi(temp_text);
	
	if(gpFirstStudent == NULL)
	{
		printf("\n The list is empty");
		return 1;
	}
	
	else
	{
		while(pCurrentstudent)
		{
			if(count == index)
			{
				printf("\n The node index (%d) of the data: ", index);
				printf("\n ------------------------------------");
				printf("\n Record number %d", count+1);
				printf("\n ID: %d", pCurrentstudent->student.ID);
				printf("\n Name: %s", pCurrentstudent->student.name);
				printf("\n Height: %f\n", pCurrentstudent->student.height);
				return 0;
			}
			else
			{
				pCurrentstudent = pCurrentstudent->PNextStudent;
				count++;
			}

		}
		
		printf("\n The index is not found");
		return 1;
		
	}
	
	
}

int Iterative_Length_linked_List()
{
	struct Sstudent* pCurrentstudent = gpFirstStudent;
	int count=0;

	if(gpFirstStudent == NULL)
	{
		printf("\n The count = %d",count);
		return 1;
	}
	
	else
	{
		while(pCurrentstudent)
		{
				pCurrentstudent = pCurrentstudent->PNextStudent;
				count++;
		}
		
		printf("\n The count = %d",count);
		return 0;
	}
} 

int Recursive_Length_linked_List(struct Sstudent* plengthstudent)
{
    if (plengthstudent == NULL) 
        return 0;
	
	else
		return 1 + Recursive_Length_linked_List(plengthstudent->PNextStudent);
} 

int Get_Nth_from_the_end ()
{
	struct Sstudent* pmainptr = gpFirstStudent;
	struct Sstudent* prefptr = gpFirstStudent;
	
	int index;
	char temp_text[40];
	int count=0;
	printf("\n Enter the index number: ");
	gets(temp_text);
	index =atoi(temp_text);
	
	if(gpFirstStudent == NULL)
	{
		printf("\n The list is empty");
		return 1;
	}
	
	else
	{
		while(count < index)
		{
			prefptr = prefptr-> PNextStudent;
			count++;
		}
		
		while(prefptr != NULL)
		{
			prefptr = prefptr-> PNextStudent;
			pmainptr = pmainptr -> PNextStudent;
		}
					
		if(pmainptr != NULL)
		{
			printf("\n ID: %d", pmainptr->student.ID);
			printf("\n Name: %s", pmainptr->student.name);
			printf("\n Height: %f\n", pmainptr->student.height);
			return 0;
		}
		else
		{
			printf("\n The index is not found");
			return 1;
		}
	}
	
}

int middle_linked_List()
{
	struct Sstudent* pslowptr = gpFirstStudent;
	struct Sstudent* pfastptr = gpFirstStudent;
	
	if(gpFirstStudent == NULL)
	{
		printf("The list is empty");
		return 1;
	}
	else
	{
		while(pfastptr != NULL && pfastptr -> PNextStudent != NULL)  // even case: pfastptr != NULL , odd case: pfastptr -> PNextStudent != NULL
		{
			pslowptr = pslowptr-> PNextStudent;
			pfastptr = pfastptr-> PNextStudent-> PNextStudent;
		}
		
			printf("\n ID: %d", pslowptr->student.ID);
			printf("\n Name: %s", pslowptr->student.name);
			printf("\n Height: %f\n", pslowptr->student.height);
			return 0;
			
	}
}

int detect_loop()
{
	struct Sstudent* pslowptr = gpFirstStudent;
	struct Sstudent* pfastptr = gpFirstStudent;
	
	if(gpFirstStudent == NULL)
	{
		printf("\n The list is empty");
		return 1;
	}
	
	while(pslowptr != NULL && pfastptr != NULL && pfastptr -> PNextStudent != NULL)
	{
		pslowptr = pslowptr-> PNextStudent; // pslowptr -> move 1 step
		pfastptr = pfastptr-> PNextStudent-> PNextStudent; // pfastptr -> move 2 steps
		if(pfastptr == pslowptr)
		{
			printf("Found loop");
			return 0;
		}
	}
	
	printf("NOT Found loop");
	return 1;
			
}
	
void Reverse_linked_list()
{
	struct Sstudent* pCurrentstudent = gpFirstStudent;
	struct Sstudent* pprevstudent = NULL;
	struct Sstudent* pnextstudent = NULL;
	
	while(pCurrentstudent != NULL)
	{
	
		pnextstudent = pCurrentstudent->PNextStudent; // move to the next node before 
		pCurrentstudent->PNextStudent = pprevstudent; // Reverse the current node to the prev node
		pprevstudent = pCurrentstudent;
		pCurrentstudent = pnextstudent;
	
	}
	
		gpFirstStudent = pprevstudent; // Update the head of the list
	
	
}

