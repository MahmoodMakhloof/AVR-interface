/*
 * ADC_8bit_DRIVER.h
 *
 * Created: 13/03/2020 07:12:56 م
 *  Author: BOB
 * 8bit ADC
 */ 


#ifndef ADC_8BIT_DRIVER_H_
#define ADC_8BIT_DRIVER_H_


#include "microconfig.h"
#include "standardTypes.h"
#include "MACROS.h"

void ADC_8bit_init();
uint16 ADC_8bit_read (uint8 chanel);



#endif /* ADC_8BIT_DRIVER_H_ */