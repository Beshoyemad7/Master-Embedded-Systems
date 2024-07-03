#include<stdio.h>
#include<string.h>

struct Employee
{
	char* Exmployee_Name;
	int   Employee_ID;
};

void main()
{
 struct Employee emb = {"Alex",1002};
 struct Employee (*arr[])= {&emb};
 struct Employee (*(*ptr)[1])= &arr;
 
 printf("Exmployee Name : ");
 printf("%s\n",(**(*ptr)).Exmployee_Name);
  
 printf("Employee ID : ");
 printf("%d",(*(*ptr))->Employee_ID);
 


}