/*
 * UARTdriver.c
 *
 * Created: 11/03/2020 12:34:19 م
 *  Author: BOB
 */ 

#include "UARTdriver.h" // include definition

//UART INIT 
void UART_init(uint32 baud_rate) //we will pass baud rate argument
{
	uint16 UBRR_value=lrint(((F_CPU)/(16UL*baud_rate))-1); //UBRR value
	UBRRL=(uint8)UBRR_value; //first 8bit to UBRRL
	UBRRH=(uint8)(UBRR_value>>8);//second 8bit to UBRRH
	UCSRB|=(1<<RXEN)|(1<<TXEN); /*enable receive and transmit*/
	UCSRC|=(3<<UCSZ0)|(1<<URSEL); /*enable UCSZ0 and UCSZ1 that equal UCSRC|=(1<<UCSZ0)|(1<<UCSZ1); for char size and we enabled URSEL recently*/
}

void UART_send_char(char data) //pass a char
{
	while(!(UCSRA &(1<<UDRE))); //if MCU ready to transmit or receive ?
	UDR=data; //put data in UDR register
}

char UART_receive_char()
{
	while (!(UCSRA &(1<<RXC))); //if MCU ready to receive ?
	return UDR; 
}


void UART_send_string(char *data) //pass string 
/* string in C finished by Null that equal 0*/
{
	while(*data>0) // while the string not finished yet
	{
		UART_send_char(*data++); // send a char and move to send the next
	}
}

