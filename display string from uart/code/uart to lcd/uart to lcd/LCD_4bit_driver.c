/*
 * LCD_4bit_driver.c
 *
 * Created: 19/03/2020 04:09:44 م
 *  Author: BOB
 */
 
#include "LCD_4bit_driver.h"

/* Custom char set for alphanumeric LCD Module */
uint8 Character1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 }; //white hurt
uint8 Character2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F }; //mobile phone
uint8 Character3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 }; //alarm
uint8 Character4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 }; //sound
uint8 Character5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 }; //music
uint8 Character6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 }; //electric
uint8 Character7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 }; //smile
uint8 Character8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 }; //black hurt
	
void LCD_4bit_COMMAND(uint8 cmnd)
{
	/* sending upper nipple to last 4 bit of LCD_port (4-7) */
	LCD_PORT=(LCD_PORT & 0x0F)|(cmnd & 0xF0); 
	CLEARBIT(LCD_PORT,RS); /* RS=0 command register */
	/* enable pulse */
	SETBIT(LCD_PORT,E);
	_delay_us(1);
	CLEARBIT(LCD_PORT,E);
	
	_delay_us(200);
	
	/* sending lower nipple to last 4 bit of LCD_port (4-7) */
	LCD_PORT=(LCD_PORT & 0x0F)|(cmnd<<4); 
	/* enable pulse */
	SETBIT(LCD_PORT,E);
	_delay_us(1);
	CLEARBIT(LCD_PORT,E);
	
	_delay_ms(2);
}

void LCD_4bit_CHAR(uint8 data)
{
	/* sending upper nipple to last 4 bit of LCD_port (4-7) */
	LCD_PORT=(LCD_PORT & 0x0F)|(data & 0xF0);
	SETBIT(LCD_PORT,RS); /* RS=1 DATA register */
	/* enable pulse */
	SETBIT(LCD_PORT,E);
	_delay_us(1);
	CLEARBIT(LCD_PORT,E);
	
	_delay_us(200);
	
	/* sending lower nipple to last 4 bit of LCD_port (4-7) */
	LCD_PORT=(LCD_PORT & 0x0F)|(data<<4);
	/* enable pulse */
	SETBIT(LCD_PORT,E);
	_delay_us(1);
	CLEARBIT(LCD_PORT,E);
	
	_delay_ms(2);
}

void LCD_4bit_INIT(void)
{
	LCD_DIR=0b11111100; /* lcd port from 2 to 7 as output */
	_delay_ms(20); /* lcd power on needs more than 15 milliseconds */
	
	LCD_4bit_COMMAND(0x02);		/* send for 4 bit initialization of LCD  */
	LCD_4bit_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	LCD_4bit_COMMAND(0x0c);              /* Display on cursor off*/
	LCD_4bit_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
	
	//LCD_4bit_CUSTOM_CHAR_INIT();
	
	LCD_4bit_COMMAND(0x01);              /* Clear display screen*/
	_delay_ms(2);
}

void LCD_4bit_STRING (char* str)
{
	int i;
	for (i=0;str[i]!=0;i++)
	{
		LCD_4bit_CHAR(str[i]);
	}
}

void LCD_4bit_STRING_XY(uint8 row,uint8 colm ,char* str) /*send string to lcd with xy position */
{
	if (row ==0 && colm<16) 
	{
		LCD_4bit_COMMAND((colm & 0x0F)|0x80); /* command first row with required position <16 */
	}
	else if (row==1&&colm<16)
	{
		LCD_4bit_COMMAND((colm&0x0F)|0xC0); /* command second row with required position <16 */
	}
	
	LCD_4bit_STRING(str); /* call lcd_string function and pass str to it */
}

void LCD_4bit_CLEAR(void)
{
	LCD_4bit_COMMAND (0x01);		/* clear display */
	LCD_4bit_COMMAND (0x80);		/* cursor at home position */
}

void LCD_4bit_SHIFT_RIGHT(void)
{
	uint8 i;
	uint8 shift =16;
	for (i=0;i<shift;i++)
	{
		LCD_4bit_COMMAND(0x1c);
		_delay_ms(300);
	}
}

void LCD_4bit_SHIFT_LEFT(void)
{
	uint8 i;
	uint8 shift =32;
	for (i=0;i<shift;i++)
	{
		LCD_4bit_COMMAND(0x18);
		_delay_ms(300);
	}
}

void LCD_4bit_CUSTOM_CHAR(uint8 loc ,uint8* character)
{
	uint8 i;
	if (loc<8)
	{
		 /* point CGRAM ( volatile memory in LCD )
		  contains 8 byte to store 8 custom characters*/
		LCD_4bit_COMMAND(0x40 + (loc*8));
		for (i=0;i<8;i++)
		{
			LCD_4bit_CHAR(character[i]);
		}
	}
}

void LCD_4bit_CUSTOM_CHAR_INIT(void)
{
	/*pass characters to lcd_custom_function to store it in CGRAM in LCD */
	LCD_4bit_CUSTOM_CHAR(0, Character1);  /* Build Character1 at position 0 */
	LCD_4bit_CUSTOM_CHAR(1, Character2);  /* Build Character2 at position 1 */
	LCD_4bit_CUSTOM_CHAR(2, Character3);  /* Build Character3 at position 2 */
	LCD_4bit_CUSTOM_CHAR(3, Character4);  /* Build Character4 at position 3 */
	LCD_4bit_CUSTOM_CHAR(4, Character5);  /* Build Character5 at position 4 */
	LCD_4bit_CUSTOM_CHAR(5, Character6);  /* Build Character6 at position 5 */
	LCD_4bit_CUSTOM_CHAR(6, Character7);  /* Build Character6 at position 6 */
	LCD_4bit_CUSTOM_CHAR(7, Character8);  /* Build Character6 at position 7 */
	
}

void LCD_4bit_DISPLAY_VARIABLE(uint32 var)
{
	sprintf(variable,"%lu",var);
	LCD_4bit_STRING(variable);
}	