/*
 ******************************************************************************
 * Created On     : Jul 31,2024
 * File           : main.c
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#define SYSCTL_RCGC2_R        *(volatile unsigned int*)(0x400FE108)
#define GPIO_PORTF_DIR_R      *(volatile unsigned int*)(0x40025400)
#define GPIO_PORTF_DEN_R      *(volatile unsigned int*)(0x4002551c)
#define GPIO_PORTF_DATA_R     *(volatile unsigned int*)(0x400253FC)


int main(void)
{
	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0x20; // Enable the GPIO port 
	
	// delay to make sure GPIOF is up and running
	for(delay_count=0; delay_count<200; delay_count++);

	GPIO_PORTF_DIR_R |= 1<<3;  //  Set (PF3) the direction as output
	GPIO_PORTF_DEN_R |= 1<<3;  // enable the GPIO pin
	
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;    // GPIO_PORTF_DATA_R 1
		for(delay_count=0; delay_count<200000; delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3); // GPIO_PORTF_DATA_R 0
		for(delay_count=0; delay_count<200000; delay_count++);
	}
	return 0;
}