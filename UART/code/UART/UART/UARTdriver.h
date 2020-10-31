/*
 * UARTdriver.h
 *
 * Created: 11/03/2020 12:15:49 م
 *  Author: BOB
 * this driver for UART we can config , send char or string and receive a char 
 */ 


#ifndef UARTDRIVER_H_
#define UARTDRIVER_H_

#include "microconfig.h" //configuration
#include "standardTypes.h" //standard Types
#include "MACROS.h" //not used but we can use it in UARTdriver.c instead of complex shifting
#include <math.h> //because of lrint function to approximate UBRR_value

uint16 UBRR_value; //16 bit
void UART_init(uint32); //UART INIT
void UART_send_char(char ); // send char
char UART_receive_char(); //receive char
void UART_send_string(char*); //send string




#endif /* UARTDRIVER_H_ */