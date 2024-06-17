#include "stdio.h"

void main()
{
	int data[20];
	int num;
	int i;
	int insert, loc;

	
	printf("Enter no of elements: ");
	scanf("%d",&num);
	
	while(num>20 || num<=0)
	{
		printf("Please!!! Set number between 1 to 20\n");
		printf("Enter the numbers of data: ");
		scanf("%d",&num);
	}
	
	for(i=0; i<num; i++)
	{
        scanf("%d",&data[i]);
	}
	
	for(i=0; i<num; i++)
	{
        printf("%d  ",data[i]);
	}
	
	printf("\nEnter the elements to be inserted: ");
	scanf("%d",&insert);
	
	printf("Enter the Location: ");
	scanf("%d",&loc);
	
	data[loc-1]=insert;
	for(i=0; i<num; i++)
	{
        printf("%d  ",data[i]);
	}
	
	
	
	
}