#include<stdio.h>
#include<string.h>

void main()
{
  int size;
  
  printf("Input the number of elements to store in the array (max 15) : ");
  scanf("%d",&size);
 
  int arr[size];
  int *ptr = arr;
  
  printf("Input 5 number of elements in the array : \n");

  for(int i=1; i<=size; i++)
  {
	  printf("element - %d : ",i);
	  scanf("%d",(ptr+i));
  }
  
  printf("\nThe elements of array in reverse order are : \n");
  
   for(int i=size; i>0; i--)
  {
	  printf("element - %d : %d\n",i,*(ptr+i));
	  
  }
 

}