/*
 * keypad.c
 *
 * Created: 27/04/2020 01:30:33 PM
 * Author : BOB
 */ 

#include "microconfig.h"
#include "MACROS.h"
#include "standardTypes.h"
#include "LCD_4bit_driver.h"
#include "keypad_DRIVER.h"


int main ()
{
	volatile uint8 c;
	while(1)
	{
		c=keyfind();
		LCD_4bit_CHAR(c);
	}
}