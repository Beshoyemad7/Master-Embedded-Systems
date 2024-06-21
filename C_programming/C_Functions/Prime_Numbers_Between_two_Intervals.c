#include <stdio.h>

int check(int num);

void main() 
{

  int num1,num2,flag;
  printf("Enter two numbers (intervers): ");
  scanf("%d %d", &num1, &num2);

  printf("prime numbers between %d and %d are: ", num1,num2);
  
for(int i=num1+1; i<num2; i++)
{
	flag= check(i);
	if(flag==0)
	{
		printf("%d ",i);
	}
}

}

int check(int num)
{
  int i, flag = 0;
	
  if (num == 0 || num == 1)
     flag = 1;

  for (i = 2; i <= num / 2; ++i) 
  {
    if (num % i == 0) 
	{
      flag = 1;
      break;
    }
  }
  
  return flag;
}