/*  
   LCD16x2 8 bit AVR ATmega32 interface
   BY BOB
*/
#include "LCD_driver.h"

int main ()
{
	/*lcd initialization */
	LCD_INIT();
	
	while(1)
	{
		/*print i (love emotion) Allah */
		LCD_STRING("I ");
		LCD_CHAR(7);
		LCD_STRING(" ALLAH");
		
		/*print i love mohamed (smile face) */
		LCD_STRING_XY(1,0,"I LOVE MOHAMED ");
		LCD_CHAR(6);
		
		/*shift right then shift left */
		LCD_SHIFT_RIGHT();
		LCD_SHIFT_LEFT();
		
		/*clear lcd*/
		LCD_CLEAR();
	}
	return 0;	
}