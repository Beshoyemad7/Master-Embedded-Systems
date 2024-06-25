#include <stdio.h>
#define Pi          3.14
#define r_square    radius*radius

void main()
{
	int radius;
	float area;
	
	printf("Enter the radius: ");
	scanf("%d",&radius);

	printf("Area= %.2f",Pi*r_square);
	
}