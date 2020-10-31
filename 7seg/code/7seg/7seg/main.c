/*
 * 7seg.c
 *
 * Created: 19/02/2020 06:41:15 م
 * Author : bob
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRC=0b01111111;
	
    while (1) 
    {
		PORTC= 0b00111111;//0
		_delay_ms(1000);
		PORTC=  0b00110000;//1
		_delay_ms(1000);
		PORTC=  0b01011011;//2
		_delay_ms(1000);
		PORTC=  0b01001111;//3
		_delay_ms(1000);
		PORTC=  0b01100110;//4
		_delay_ms(1000);
		PORTC=  0b01101101;//5
		_delay_ms(1000);
		PORTC=  0b01111101;//6
		_delay_ms(1000);
		PORTC=  0b00000111;//7
		_delay_ms(1000);
		PORTC=  0b11111111;//8
		_delay_ms(1000);
		PORTC=  0b01101111;//9
		_delay_ms(1000);
		
		 
    }
	return 0;
}

