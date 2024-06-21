#include <stdio.h>

void main()
{
	char c;
	float num1 , num2;
	printf("Enter operator either + or - or * or /: ");
	scanf("%c",&c);
	
	printf("Enter two operands: ");
	scanf("%f %f", &num1 , &num2);
	
	switch(c)
	{
		case '+':
		  printf("%.1f + %.1f = %.1f",num1 , num2, num1+num2);
		break;
		
		case '-':
		  printf("%.1f - %.1f = %.1f",num1 , num2, num1-num2);    
		break;
		
		case '*':
		  printf("%.1f * %.1f = %.1f",num1 , num2, num1*num2);
		break;
		
		case '/':
		  printf("%.1f / %.1f = %.1f",num1 , num2, num1/num2);
		break;
		
		
		default:
		printf("Error! operator is not correct ");
		break;
		
		
	}
}