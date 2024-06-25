#include <stdio.h>

struct Sstudent{
	char name[10];
	int roll;
	float marks;
};

void main()
{
struct Sstudent s[10];

	int i;
	printf("Enter Information of students: \n");
	for(i=1; i<=10; i++)
	{
		printf("For roll number %d \n",i);
		printf("Enter name: ");
		scanf("%s",&s[i-1].name);
	
		printf("Enter roll number: ");
		scanf("%d",&s[i-1].roll);
	
		printf("Enter marks: ");
		scanf("%f",&s[i-1].marks);
		printf("\n");
	}
	
	printf("\nDisplaying Information of students\n");
	for(i=1; i<=10; i++)
	{
	printf("Information For roll number %d: \n",i);
	printf("Name: %s\nRoll: %d\nMarks: %.2f",s[i-1].name,s[i-1].roll,s[i-1].marks);
	printf("\n\n");
	}
}

