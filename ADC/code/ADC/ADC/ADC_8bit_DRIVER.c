/*
 * ADC_8bit_DRIVER.c
 *
 * Created: 13/03/2020 07:14:57 م
 *  Author: BOB
 */ 

#include "ADC_8bit_DRIVER.h"

void ADC_8bit_init()
{
	DDRA=0x00; //porta is input
	ADCSRA|=(1<<ADEN); //enable ADC
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2); //division factor =128 (control speed of converting)
	ADMUX|=(1<<ADLAR); //left adjusted 8bit
}

uint16 ADC_8bit_read (uint8 chanel) //pass ADC terminal like 2 for ADC2
{
	volatile uint8 Ain;
	
	ADMUX|=(chanel & 0b00011111); //select terminal
	
	ADCSRA|=(1<<ADSC); //start converting
	while(!(ADCSRA & (1<<ADIF))); //wait for converting interrupt flag =1
	_delay_us(10); // delay for stable
	//store value of data register in Ain
	Ain=ADCH;
	return Ain;
	
}
