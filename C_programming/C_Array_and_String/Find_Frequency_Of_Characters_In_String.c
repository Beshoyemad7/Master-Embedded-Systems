#include <stdio.h>
#include <string.h>

void main()
{
	char str[50];
	char c;
	int i;
	int count=0;
	
	printf("Enter a string: ");
	gets(str);
	printf("%s",str);
	
	printf("\nEnter a character to find frequency: ");
	scanf("%c",&c);
	
	for(i=0; i<strlen(str); i++)
	{
		if(str[i]==c)
		{
			count=count+1;
		}
	}
	
	printf("Frequency of %c = %d", c, count);
}