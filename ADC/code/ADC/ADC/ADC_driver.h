/*
 * ADC_driver.h
 *
 * Created: 12/03/2020 12:54:59 ص
 *  Author: BOB
 *  //10bit ADC / right adjusted / Aref 
 */ 


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "microconfig.h"
#include "standardTypes.h"
#include "MACROS.h"

void ADC_init();
uint16 ADC_read (uint8 chanel);



#endif /* ADC_DRIVER_H_ */