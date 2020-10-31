/*
 * ADC.c
 *
 * Created: 11/03/2020 05:57:20 م
 * Author : BOB
 */ 

#include "ADC_driver.h"

//10bit ADC / right adjusted / Aref 

volatile uint16 ADC_VALUE;

int main(void)
{
	
    DDRC=0xff; //portc is output
	DDRD=0xff; //portd is output
	ADC_init();
	
    while (1) 
    {
		
		ADC_VALUE=ADC_read(2); //read analog from ADC2
		//out value of adc to c & d ports
		PORTC=ADC_VALUE;
		PORTD=ADC_VALUE>>8;
		
    }
}

