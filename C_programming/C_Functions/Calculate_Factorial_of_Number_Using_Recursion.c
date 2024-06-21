#include <stdio.h>

int Factorial_Num(int num);

void main()
{
	int num;
	
	printf("Enter an positive integer: ");
	scanf("%d",&num);
	
	printf("Factorial of %d = %d",num,Factorial_Num(num));
}

int Factorial_Num(int num)
{	
	if(num != 1)
	    return num*Factorial_Num(num-1);		
	else
		return 1;
			
}