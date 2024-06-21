#include <stdio.h>

void main()
{
	int x;
	int factorial =1;
	printf("Enter an integer: ");
	scanf("%d",&x);
	
	if(x<0)
	{
		printf("Error!!! Factorial of negative number doesn't exist");
	}
	
	else
	{
		for(int i=1; i<=x; i++)
		{
			factorial= factorial*i;
		}
	    printf("Factorial = %d", factorial);
	}
}