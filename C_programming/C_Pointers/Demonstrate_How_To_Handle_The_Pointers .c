#include<stdio.h>

void main()
{
	
unsigned int m = 29;
unsigned int* ab = &m;

printf("Address of m: 0x%p\nValue of m: %d\n",&m,m);

printf("\nAddress of pinter ab: 0x%p\ncontent of pinter ab: %d\n",ab,*ab);

m=34;	
printf("\nAddress of pinter ab: 0x%p\ncontent of pinter ab: %d\n",ab,*ab);

m=7;
printf("\nAddress of m: 0x%p\nValue of m: %d\n",ab,*ab);
	
}