/*
 * UART.c
 *
 * Created: 10/03/2020 05:40:18 م
 * Author : BOB
 */ 

#include "UARTdriver.h" //include UART driver
#include "LCD_4bit_driver.h"

int main(void)
{
    UART_init(9600); //UART INIT
	LCD_4bit_INIT();
	SETBIT(DDRB,PB0); //PB0 as output
	
    while (1) 
    {
		switch(UART_receive_char())
		{
			case '1':
			SETBIT(PORTB,PB0);
			UART_send_string("LED ON");
			LCD_4bit_CLEAR();
			LCD_4bit_STRING("LED ON   ");
			break;
			
			case '2':
			CLEARBIT(PORTB,PB0);
			UART_send_string("LED OFF");
			LCD_4bit_CLEAR();
			LCD_4bit_STRING("LED OFF  ");
			break;
			
			default:
			break;
		}
    }
}

