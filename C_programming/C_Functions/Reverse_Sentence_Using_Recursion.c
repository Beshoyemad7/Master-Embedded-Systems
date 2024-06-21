#include <stdio.h>

void reverse_sent();

void main()
{
    printf("Please enter a sentence: ");
    reverse_sent();
}

void reverse_sent()
{
    char c;
    scanf("%c", &c);
    if (c != '\n') 
        reverse_sent();      
	
	printf("%c", c);
}