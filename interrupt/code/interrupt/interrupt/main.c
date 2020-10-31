/*
 * interrupt.c
 *
 * Created: 25/02/2020 12:57:05 ص
 * Author : bob
 */ 

#include "microconfig.h"
#include "standardTypes.h"
#include "MACROS.h"
#include <avr/interrupt.h> /* Interrupt lib call*/


int main(void)
{
	/*PA0 and PB0 as Output*/
    SETBIT(DDRA,PA0);
	SETBIT(DDRB,PB0);
	/*PD2 as Input and enable internal pull up res*/
	CLEARBIT(DDRD,PD2);
	SETBIT(PORTD,PD2);
	/*enable Falling edge , enable INT0 and enable general interrupt */
	SETBIT(MCUCR,ISC01);
	SETBIT(GICR,INT0);
	sei();
	
	
    while (1) 
    {
		TOGGLEBIT(PORTA,PA0); /*reverse bit*/
		_delay_ms(2000); /* wait 2 sec */
    }
	
	return 0;
}
/* interrupt program*/
ISR(INT0_vect)
{
	TOGGLEBIT(PORTB,PB0); /*reverse bit*/
}

