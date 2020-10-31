/*
 * SPI_SLAVE_driver.h
 *
 * Created: 30/04/2020 09:37:16 PM
 *  Author: BOB
 */ 


#ifndef SPI_SLAVE_DRIVER_H_
#define SPI_SLAVE_DRIVER_H_


#include "microconfig.h"

#define MOSI 5									/* Define SPI bus pins */
#define MISO 6
#define SCK 7
#define SS 4

void SPI_SLAVE_Init();								/* SPI Initialize function */
char SPI_Transmit(char);						/* SPI transmit data function */
char SPI_Receive();								/* SPI Receive data function */




#endif /* SPI_SLAVE_DRIVER_H_ */