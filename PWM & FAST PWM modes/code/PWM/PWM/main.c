/*
 * PWM.c
 *
 * Created: 13/03/2020 07:06:35 م
 * Author : BOB
 *PWM and FAST PWM
 */ 

#include "ADC_8bit_DRIVER.h"

void PWM_init()
{
	//PWM correct phase mode (WGM1:0)
	//non inverted (COM1:0)
	//pre_scaler =1 (CS02:CS00)
	TCCR0=0b01100001;
	//TCNT0 =zero
	//OCR0 = zero
	TCNT0=0x00;
	OCR0=0x00;
	//OC0 pin is output
	SETBIT(DDRB,PB3);
}

void FAST_PWM_init()
{
	//FAST PWM (WGM1:0)
	//non inverted (COM1:0)
	//pre_scaler =1 (CS02:CS00)
	TCCR0=0b01101001;
	//TCNT0 =zero
	//OCR0 = zero
	TCNT0=0x00;
	OCR0=0x00;
	//OC0 pin is output
	SETBIT(DDRB,PB3);
}
int main(void)
{
	ADC_8bit_init();
	PWM_init();
   
    while (1) 
    {
		OCR0=ADC_8bit_read(0);
    }
}

