/*
 * MACROS.h
 *
 * Created: 07/04/2018 04:41:23 م
 *  Author: MAKHLOUF
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#include "standardTypes.h"

#define SETBIT(REG,BIT)  ((REG)|=(1<<(BIT)))
#define CLEARBIT(REG,BIT)  ((REG)&=(uint8)~(1<<(BIT)))
#define TOGGLEBIT(REG,BIT)  ((REG)^=(1<<(BIT)))
#define IS_BIT_SET(REG,BIT)   ((REG)&(1<<(BIT)))
#define IS_BIT_CLEAR(REG,BIT)  (!((REG)&(1<<(BIT))))



#endif /* MACROS_H_ */