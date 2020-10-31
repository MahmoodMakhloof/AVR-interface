/*
 * ADC_driver.c
 *
 * Created: 12/03/2020 12:57:43 ص
 *  Author: BOB
 */ 

#include "ADC_driver.h"

void ADC_init()
{
	DDRA=0x00; //porta is input
	ADCSRA|=(1<<ADEN); //enable ADC
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2); //division factor =128
}

uint16 ADC_read (uint8 chanel) //pass ADC terminal like 2 for ADC2
{
	volatile uint16 Ain_low;
	volatile uint16 Ain;
	
	ADMUX|=(chanel & 0b00011111); //select terminal
	
	ADCSRA|=(1<<ADSC); //start converting
	while(!(ADCSRA & (1<<ADIF))); //wait for converting interrupt flag =1
	_delay_us(10); // delay for stable
	//store value of data register in Ain
	Ain_low=(uint16)ADCL;
	Ain=(uint16)(ADCH<<8);
	Ain+=Ain_low;
	return Ain;
	
}
