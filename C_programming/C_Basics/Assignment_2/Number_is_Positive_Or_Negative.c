#include <stdio.h>

void main()
{
	float x;
	printf("Enter a number: ");
	scanf("%f", &x);
	if(x<0)
	{
		printf("%.2f is negative.",x);
	}
	
	else if(x>0)
	{
		printf("%.2f is positive.",x);
	}
	
	else
	{
		printf("you entered zero");
	}
}