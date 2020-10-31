/*
 * blink_led.c
 *
 * Created: 19/02/2020 05:24:25 م
 * Author : bob
 */ 
#define F_CPU 16000000UL /*speed of cpu that exist in unsigned long variable called F_cpu*/
#include <avr/io.h> /*GPIO*/
#include <util/delay.h> /*delay library*/


int main(void)
{
    DDRB=0b00000001; /*pin 0 of port b is output*/
    while (1) 
    {
		PORTB=0b00000001;/*pin 0 of port b is ON*/
		_delay_ms(1000); /*wait half second*/
		PORTB=0b00000000;/*OFF*/
		_delay_ms(1000);/*wait half second*/
    }
}

