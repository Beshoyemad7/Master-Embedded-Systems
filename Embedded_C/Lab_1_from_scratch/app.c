#include "uart.h"

unsigned char string_buffer_1[100] = "learn-in-depth: <Beshoy Emad>";
unsigned char const string_buffer_2[100] = "Embedded System";
void main(void)
{
	uart_send_string(string_buffer_1);
}	