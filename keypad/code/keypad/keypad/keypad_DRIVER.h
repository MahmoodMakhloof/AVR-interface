/*
 * keypad_DRIVER.h
 *
 * Created: 27/04/2020 01:52:35 PM
 *  Author: BOB
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

/*********** method 1 *************
#include "microconfig.h"

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define keypad_PORT PORTD
#define keypad_DDR DDRD
#define keypad_PIN PIND

void keypad_init (void);
char keypad_getchar();
*/

/**************** method 2 ***************/
#include "microconfig.h"
#define KEY_PRT 	PORTD
#define KEY_DDR		DDRD
#define KEY_PIN		PIND

char keyfind();

#endif /* KEYPAD_DRIVER_H_ */