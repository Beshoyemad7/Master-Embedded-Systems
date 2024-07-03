#include<stdio.h>
#include<string.h>

void print(char* ptr)
{
	for(int i=10; i>=0; i--)
	{
		printf("%c",*(ptr+i));
	}
}
void main()
{
  
char arr[11];
 
printf("Input a string : ");
gets(arr); 
printf("Reverse of the string is : ");
print(arr);

}