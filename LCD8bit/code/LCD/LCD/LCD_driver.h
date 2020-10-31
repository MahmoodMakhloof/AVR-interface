/*
 * LCD_driver.h
 *
 * Created: 18/03/2020 07:55:06 م
 *  Author: BOB
 * LCD16x2 8 bit AVR ATmega32 interface
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "microconfig.h"
#include "standardTypes.h"
#include "MACROS.h"

#define LCD_DATA_DIR DDRB /* define lcd data port direction */
#define LCD_COMMAND_DIR DDRC /* define lcd command port direction */
#define LCD_DATA_PORT PORTB /* define lcd data port */
#define LCD_COMMAND_PORT PORTC /* define lcd command port */

#define RS PC0 /* define register select (data/command) pin */
#define RW PC1 /* define (read / write) pin*/
#define E PC2 /* define enable signal pin */

/* Custom char set for alphanumeric LCD Module */
uint8 Character1[8] ; //white hurt
uint8 Character2[8] ; //mobile phone
uint8 Character3[8] ; //alarm
uint8 Character4[8] ; //sound
uint8 Character5[8] ; //music
uint8 Character6[8] ; //electric
uint8 Character7[8] ; //smile
uint8 Character8[8] ; //black hurt
	
void LCD_COMMAND (uint8);
void LCD_CHAR (uint8);
void LCD_INIT(void);
void LCD_STRING(char*);
void LCD_STRING_XY(uint8 ,uint8 ,char*);
void LCD_CLEAR(void);
void LCD_SHIFT_RIGHT(void);
void LCD_SHIFT_LEFT(void);
void LCD_CUSTOM_CHAR(uint8 ,uint8*);
void LCD_CUSTOM_CHAR_INIT(void);




#endif /* LCD_DRIVER_H_ */