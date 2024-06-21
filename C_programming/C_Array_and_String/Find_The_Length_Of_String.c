#include <stdio.h>
#include <string.h>

void main()
{
	int count=0;
	char str[20];
	
	printf("Enter a string: ");
	gets(str);
	printf("%s",str);
	
	for(int i=0; i<20; i++)
	{
		if(str[i]==0)
		{
			break;
		}
		count++;
	}
	
	printf("\nLength of string: %d",count);
	
	
}