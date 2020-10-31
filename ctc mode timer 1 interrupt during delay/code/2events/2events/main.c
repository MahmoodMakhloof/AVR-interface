/*
 * 2events.c
 *
 * Created: 20/03/2020 02:45:44 م
 * Author : bob
 */ 

#include "microconfig.h"
#include "standardTypes.h"
#include "MACROS.h"
#include <avr/interrupt.h>

//millis counter
uint32 millis_ctr=0;

/*1 milli second timer */
void milli_second_timer()
{
	/*initialization 16_bit timer 1 */
	/*CTC mode, no prescaler and enable interrupt for compare match */
	TCCR1B|=(1<<WGM12);
	TCCR1B|=(1<<CS10);
	TIMSK|=(1<<OCIE1A);
	/*ocr = (F_CPU/(2*prescaler*freq)-1)*/
	OCR1A=(F_CPU/(1*1*1000))-1;
	
}




int main(void)
{
	
	/*PB0 & PB1 as o/p */
	SETBIT(DDRB,PB0);
	SETBIT(DDRB,PB1);
	
	//led1 on
	SETBIT(PORTB,PB0);
	/*global interrupt enable*/
	sei();
	
	/*start timer*/
	milli_second_timer();
	
	while (1)
	{
		//toggle led2 every 2 seconds
		TOGGLEBIT(PORTB,PB1);
		_delay_ms(3000);
	}
}

/*interrupt service routine*/
ISR(TIMER1_COMPA_vect)
{
	millis_ctr++;
	//after 1 sec
	if (millis_ctr>=500)
	{
		TOGGLEBIT(PORTB,PB0); /*the event of interrupt is toggle led1 state */
		millis_ctr=0; //counter=0
	}
	
}

