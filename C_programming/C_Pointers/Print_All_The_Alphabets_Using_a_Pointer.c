#include<stdio.h>

void print(char* ptr)
{
	for(int i=0; i<26; i++)
	{
		printf("%c ",*ptr);
		ptr++;
	}
}
void main()
{
  char arr[26];
  for(int i=0; i<26; i++)
  {
	  arr[i]= 65+i;
  }
   print(arr);
}