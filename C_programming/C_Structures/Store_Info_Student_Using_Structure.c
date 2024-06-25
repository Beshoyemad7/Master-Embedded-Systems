#include <stdio.h>

struct Sstudent{
	char name[10];
	int roll;
	float marks;
}s;
void main()
{
	printf("Enter Information of students: \n");
	printf("Enter name: ");
	scanf("%s",&s.name);
	
	printf("Enter roll number: ");
	scanf("%d",&s.roll);
	
	printf("Enter marks: ");
	scanf("%f",&s.marks);
	
	printf("\nDisplaying Information\n");
	printf("Name: %s\nRoll: %d\nMarks: %.2f",s.name,s.roll,s.marks);
	
}