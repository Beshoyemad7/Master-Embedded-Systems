#include"stdio.h"

void main()
{
	int x ;
	int sum =0;
	
	printf("Enter an integer: ");
	scanf("%d",&x);
	
	for(int i=1; i<=x; i++)
	{
		sum = sum + i;
	}
	
	printf("sum= %d",sum);
}