#include <stdio.h>

struct Sfeet_inch{
	int feet;
	float inch;
};

void Add_feet_inch(struct Sfeet_inch num1, struct Sfeet_inch num2);

void main()
{
	struct Sfeet_inch num1,num2;
	
	Add_feet_inch(num1,num2);
}

void Add_feet_inch(struct Sfeet_inch num1, struct Sfeet_inch num2)
{
	struct Sfeet_inch n1;
	struct Sfeet_inch n2;
	float sum_inch;
	int sum_feet;
	
	printf("Enter information for 1st distance\n");
	printf("Enter feet: ");
	scanf("%d",&n1.feet);
	printf("Enter inch: ");
	scanf("%f",&n1.inch);
	
	printf("\nEnter information for 1st distance\n");
	printf("Enter feet: ");
	scanf("%d",&n2.feet);
	printf("Enter inch: ");
	scanf("%f",&n2.inch);
	
	sum_inch = n1.inch+n2.inch; 
	sum_feet= n1.feet+n2.feet;
	
	if(sum_inch>12)
	{
		sum_inch=sum_inch-12.0;
		++sum_feet;
	}
	
	printf("sum of distances= %.1d - %.1f", sum_feet,sum_inch);
}