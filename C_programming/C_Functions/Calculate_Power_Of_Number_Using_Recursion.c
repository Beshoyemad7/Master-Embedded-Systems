#include <stdio.h>
#include "string.h"

int Power_Num(int base ,int power );
	

void main()
{
    int base, power;
	printf("Enter base number: ");
	scanf("%d", &base);

	printf("Enter power number(positive integer): ");
	scanf("%d", &power);
	
	printf("%d ^ %d = %d",base,power,Power_Num(base,power));
	
}

int Power_Num(int base ,int power )
{
	if(power != 0)
		return base *Power_Num(base, power-1);
	else
		return 1;

}