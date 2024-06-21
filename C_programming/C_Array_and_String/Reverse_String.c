#include <stdio.h>
#include <string.h>

void main()
{
	char str[20];
	char Reverse[20];
	int count=1;
	
	printf("Enter a string: ");
	gets(str);
	
	//hello
	for(int i=0; i<strlen(str); i++)
	{
		Reverse[i]= str[strlen(str)-count];
		count++;
	}
	
	printf("Reverse string is: %s",Reverse);
	
}