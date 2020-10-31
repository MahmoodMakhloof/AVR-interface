/*
 * uart to lcd.c
 *
 * Created: 20/03/2020 10:15:05 م
 * Author : bob
 * i wanna print characters on lcd from uart but it is not working
 */ 

#include "UARTdriver.h"
#include "LCD_4bit_driver.h"


int main(void)
{
	UART_init(9600);
	LCD_4bit_INIT();
	
    while (1)
	{
		
		LCD_4bit_CHAR(UART_receive_char());
	}
    
}


	 