/*
 * Clock.h
 *
 *  Created on: 2015Äê11ÔÂ13ÈÕ
 *      Author: floatSD
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "system.h"
#define OSC_120MHZ 12000000
#define sysClock_Fr 5000000
uint32_t Clock_Init();
void Delay(uint32_t CountMs);


#endif /* CLOCK_H_ */
