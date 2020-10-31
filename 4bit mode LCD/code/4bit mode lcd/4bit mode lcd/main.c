/*
 * 4bit mode lcd.c
 *
 * Created: 18/03/2020 10:47:37 م
 * Author : bob
 */ 

#include "LCD_4bit_driver.h"

int main(void)
{
	LCD_4bit_INIT();
	
	LCD_4bit_STRING("I ");
	LCD_4bit_CHAR(7);
	LCD_4bit_STRING(" ALLAH");
	_delay_ms(1000);
	
	LCD_4bit_STRING_XY(1,0,"I LOVE MOHAMED ");
	LCD_4bit_CHAR(6);
	_delay_ms(1000);
	
	LCD_4bit_SHIFT_RIGHT();
	LCD_4bit_SHIFT_LEFT();
	
	LCD_4bit_CLEAR();
	
	uint8 i=0;
	
    while (1) 
    {
		LCD_4bit_STRING("i= ");
		LCD_4bit_DISPLAY_VARIABLE(i);
		_delay_ms(100);
		if (i==255)
		{
			LCD_4bit_STRING_XY(1,0,"Over Flow");
			_delay_ms(1000);
		}
		i++;
		LCD_4bit_CLEAR();
		
    }
}

