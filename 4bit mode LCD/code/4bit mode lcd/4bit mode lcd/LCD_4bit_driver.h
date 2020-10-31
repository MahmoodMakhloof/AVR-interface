/*
 * LCD_4bit_driver.h
 *
 * Created: 19/03/2020 04:08:26 م
 *  Author: BOB
 */ 


#ifndef LCD_4BIT_DRIVER_H_
#define LCD_4BIT_DRIVER_H_

#include "microconfig.h"
#include "standardTypes.h"
#include "MACROS.h"
#include <stdio.h>

#define LCD_DIR DDRC
#define LCD_PORT PORTC
#define RS PC2
#define E PC3

char variable[100];

/* Custom char set for alphanumeric LCD Module */
uint8 Character1[8] ; //white hurt
uint8 Character2[8] ; //mobile phone
uint8 Character3[8] ; //alarm
uint8 Character4[8] ; //sound
uint8 Character5[8] ; //music
uint8 Character6[8] ; //electric
uint8 Character7[8] ; //smile
uint8 Character8[8] ; //black hurt

void LCD_4bit_COMMAND(uint8);
void LCD_4bit_CHAR(uint8);
void LCD_4bit_INIT(void);
void LCD_4bit_STRING (char*);
void LCD_4bit_STRING_XY(uint8 ,uint8  ,char* );
void LCD_4bit_CLEAR(void);
void LCD_4bit_SHIFT_RIGHT(void);
void LCD_4bit_SHIFT_LEFT(void);
void LCD_4bit_CUSTOM_CHAR(uint8  ,uint8* );
void LCD_4bit_CUSTOM_CHAR_INIT(void);
void LCD_4bit_DISPLAY_VARIABLE(uint32);



#endif /* LCD_4BIT_DRIVER_H_ */