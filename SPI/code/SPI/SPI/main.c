/*
 * SPI.c
 *
 * Created: 30/04/2020 09:08:43 PM
 * Author : BOB
 */ 

#include "microconfig.h"
#include "standardTypes.h"
#include "MACROS.h"
#include "LCD_4bit_driver.h"
#include "SPI_MASTER_driver.h"


int main(void)
{
	SPI_MASTER_Init();
	SS_Enable;
	uint8 ctr=0;
    while (1) 
    {
		SPI_Write(ctr);
		_delay_ms(2000);
		ctr++;
    }
}

