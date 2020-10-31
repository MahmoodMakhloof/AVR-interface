/*
 * LCD_driver.c
 *
 * Created: 18/03/2020 08:12:39 م
 *  Author: BOB
 */ 

#include "LCD_driver.h"

/* Custom char set for alphanumeric LCD Module */
uint8 Character1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 }; //white hurt
uint8 Character2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F }; //mobile phone
uint8 Character3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 }; //alarm
uint8 Character4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 }; //sound
uint8 Character5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 }; //music
uint8 Character6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 }; //electric
uint8 Character7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 }; //smile
uint8 Character8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 }; //black hurt

void LCD_COMMAND(uint8 cmnd)
{
	LCD_DATA_PORT=cmnd;
	CLEARBIT(LCD_COMMAND_PORT,RS); /* RS=0 as command register */
	CLEARBIT(LCD_COMMAND_PORT,RW); /* RW=0 Write operation */
	/* enable pulse */
	SETBIT(LCD_COMMAND_PORT,E);
	_delay_us(1);
	CLEARBIT(LCD_COMMAND_PORT,E);
	/* wait for stability */
	_delay_ms(3);	
}

void LCD_CHAR(uint8 data)
{
	LCD_DATA_PORT=data;
	SETBIT(LCD_COMMAND_PORT,RS); /* RS=1 as data register */
	CLEARBIT(LCD_COMMAND_PORT,RW); /* RW=0 Write operation */
	/* enable pulse */
	SETBIT(LCD_COMMAND_PORT,E);
	_delay_us(1);
	CLEARBIT(LCD_COMMAND_PORT,E);
	/* wait for stability */
	_delay_ms(1);
}

void LCD_INIT(void)
{
	LCD_DATA_DIR=0xff; /* lcd data port as output*/
	LCD_COMMAND_DIR=0xff; /* lcd command port as output*/
	_delay_ms(20); /* lcd power on >15 ms */
	
	LCD_COMMAND (0x38);		/* Initialization of 16X2 LCD in 8bit mode */
	LCD_COMMAND (0x0C);		/* Display ON Cursor OFF */
	LCD_COMMAND (0x06);		/* Auto Increment cursor */
	
	/*sending custom characters by LCD_CUSTOM_CHAR() function to CGRAM in LCD */
	LCD_CUSTOM_CHAR_INIT();
	
	LCD_COMMAND (0x01);		/* Clear display */
	LCD_COMMAND (0x80);		/* Cursor at home position */
	
}

void LCD_STRING (char* str)
{
	int i;
	for (i=0;str[i]!=0;i++)
	{
		LCD_CHAR(str[i]);
	}
}

void LCD_STRING_XY(uint8 row,uint8 colm ,char* str) /*send string to lcd with xy position */
{
	if (row ==0 && colm<16) 
	{
		LCD_COMMAND((colm & 0x0F)|0x80); /* command first row with required position <16 */
	}
	else if (row==1&&colm<16)
	{
		LCD_COMMAND((colm&0x0F)|0xC0); /* command second row with required position <16 */
	}
	
	LCD_STRING(str); /* call lcd_string function and pass str to it */
}

void LCD_CLEAR(void)
{
	LCD_COMMAND (0x01);		/* clear display */
	LCD_COMMAND (0x80);		/* cursor at home position */
}

void LCD_SHIFT_RIGHT(void)
{
	uint8 i;
	uint8 shift =16;
	for (i=0;i<shift;i++)
	{
		LCD_COMMAND(0x1c);
		_delay_ms(300);
	}
}

void LCD_SHIFT_LEFT(void)
{
	uint8 i;
	uint8 shift =32;
	for (i=0;i<shift;i++)
	{
		LCD_COMMAND(0x18);
		_delay_ms(300);
	}
}

void LCD_CUSTOM_CHAR(uint8 loc ,uint8* character)
{
	uint8 i;
	if (loc<8)
	{
		 /* point CGRAM ( volatile memory in LCD )
		  contains 8 byte to store 8 custom characters*/
		LCD_COMMAND(0x40 + (loc*8));
		for (i=0;i<8;i++)
		{
			LCD_CHAR(character[i]);
		}
	}
}

void LCD_CUSTOM_CHAR_INIT(void)
{
	/*pass characters to lcd_custom_function to store it in CGRAM in LCD */
	LCD_CUSTOM_CHAR(0, Character1);  /* Build Character1 at position 0 */
	LCD_CUSTOM_CHAR(1, Character2);  /* Build Character2 at position 1 */
	LCD_CUSTOM_CHAR(2, Character3);  /* Build Character3 at position 2 */
	LCD_CUSTOM_CHAR(3, Character4);  /* Build Character4 at position 3 */
	LCD_CUSTOM_CHAR(4, Character5);  /* Build Character5 at position 4 */
	LCD_CUSTOM_CHAR(5, Character6);  /* Build Character6 at position 5 */
	LCD_CUSTOM_CHAR(6, Character7);  /* Build Character6 at position 6 */
	LCD_CUSTOM_CHAR(7, Character8);  /* Build Character6 at position 7 */
	
}