/*
 * SPI_MASTER_driver.h
 *
 * Created: 30/04/2020 09:22:40 PM
 *  Author: BOB
 */ 


#ifndef SPI_MASTER_DRIVER_H_
#define SPI_MASTER_DRIVER_H_


#include "microconfig.h"

#define MOSI 5								/* Define SPI bus pins */
#define MISO 6
#define SCK 7
#define SS 4
#define SS_Enable PORTB &= ~(1<<SS)			/* Define Slave enable */
#define SS_Disable PORTB |= (1<<SS)			/* Define Slave disable */

void SPI_MASTER_Init();							/* SPI initialize function */
void SPI_Write(char);						/* SPI write data function */
char SPI_Read();							/* SPI read data function */



#endif /* SPI_MASTER_DRIVER_H_ */