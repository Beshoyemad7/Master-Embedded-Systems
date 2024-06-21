#include <stdio.h>
#include <string.h>

void main()
{
	int matrix[20][20];
	int r, c;
	int i,j;
	
	printf("Enter rows and column of matrix: ");
	scanf("%d  %d",&r, &c);
	
	while(r>20 || r<=0  || c>20 || c<=0)
	{
		printf("Please!!! Set rows and column between 1 to 20\n");
	    printf("Enter rows and column of matrix: ");
	    scanf("%d  %d",&r, &c);
	}

    printf("Enter elements of matrix: \n");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("Enter elements a%d%d: ", i+1, j+1);
			scanf("%d",&matrix[i][j]);
		}
		
	}
	
	printf("Enter Matrix:\n");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("%d\t",matrix[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	printf("\nTranspose of Matrix:\n");
	for(i=0; i<c; i++)
	{
		for(j=0; j<r; j++)
		{
			printf("%d\t",matrix[j][i]);
			
		}
		
		printf("\n");
		
	}
}