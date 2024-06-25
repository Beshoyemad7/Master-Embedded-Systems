#include <stdio.h>

union job{
	char name[32];
	int worker_no;
	float salary;
}u;

struct job1{
	char name[32];
	int worker_no;
	float salary;
}s;
void main()
{
	printf("size of union=%d",sizeof(u));
	printf("\nsize of structure=%d",sizeof(s));
	
}