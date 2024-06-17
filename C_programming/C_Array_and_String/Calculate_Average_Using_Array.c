#include "stdio.h"

void main()
{
	float data[20];
	int num;
	int i;
	float sum=0;
	
	printf("Enter the numbers of data: ");
	scanf("%d",&num);
	
	while(num>20 || num<=0)
	{
		printf("Please!!! Set number between 1 to 20\n");
		printf("Enter the numbers of data: ");
		scanf("%d",&num);
	}
	
	for(i=0; i<num; i++)
	{
	    printf("Enter number: ");
        scanf("%f",&data[i]);
        sum=sum	+data[i];	
	}
	
	printf("Average = %.2f",sum/num);
}