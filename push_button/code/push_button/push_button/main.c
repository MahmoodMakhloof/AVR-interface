/*
 * push_button.c
 *
 * Created: 19/02/2020 07:46:48 م
 * Author : bob
 */ 
#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	DDRB=0b00000001; /*pb0 as output*/
	DDRC=0b00000000; /*verify port c as input*/
	PORTC=0b11111111; /*enable internal pull_up resistor for port c*/
    while (1) 
    {
		if(PINC==0b11111110) /*if we push down button*/
		{
			PORTB=0b00000001; /* led ON*/
		}
		else /*if we push up button*/
		{
			PORTB=0b00000000; /*led OFF*/
		}
    }
}

