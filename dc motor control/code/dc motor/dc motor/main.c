/*
 * dc motor.c
 *
 * Created: 23/02/2020 01:37:16 م
 * Author : bob
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB=0b00000011;

    while (1) 
    {
		PORTB=0b00000001;
		_delay_ms(2000);
		PORTB=0b00000010;
		_delay_ms(2000);
    }
	return 0;
}

