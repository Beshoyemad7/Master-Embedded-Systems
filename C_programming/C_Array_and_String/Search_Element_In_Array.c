#include "stdio.h"

void main()
{
	int data[20];
	int num;
	int i;
	int search, loc;

	
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
	
	printf("\nEnter the elements to be searched: ");
	scanf("%d",&search);
	
	for(i=0; i<num; i++)
	{
	   if(data[i]==search)
	   {
		   printf("Number found at the location= %d", i+1);
		   break;
	   }
	   

	}
	
	if(data[i]!=search)
	{
		printf("The number is not found");
	}
	
	
}