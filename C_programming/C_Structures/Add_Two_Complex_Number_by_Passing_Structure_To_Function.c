#include <stdio.h>

struct Scomplex{
	float real;
	float imaginary;
};

void Add_Complex(struct Scomplex num1, struct Scomplex num2);

void main()
{
struct Scomplex num1 , num2;

	Add_Complex(num1,num2);
}

void Add_Complex(struct Scomplex num1, struct Scomplex num2)
{
	struct Scomplex n1;
	struct Scomplex n2;
	
	printf("For 1st complex number\n");
	printf("Enter real and imaginary repectively: ");
	scanf("%f",&n1.real);
	scanf("%f",&n1.imaginary);
	
	printf("\nFor 1st complex number\n");
	printf("Enter real and imaginary repectively: ");
	scanf("%f",&n2.real);
	scanf("%f",&n2.imaginary);
	
	printf("sum = %.1f + %.1fi", n1.real+n2.real,n1.imaginary+n2.imaginary);
}