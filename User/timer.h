/*
 * timer.h
 *
 *  Created on: 2015Äê12ÔÂ30ÈÕ
 *      Author: floatSD
 */


#ifndef TIMER_H_
#define TIMER_H_

#include "system.h"

#define Interrupt   1
#define UnInterrupt 0

#ifdef TIMER_C_

	#define TIMER_C_Extern

#else

	#define TIMER_C_Extern  extern

#endif

TIMER_C_Extern volatile uint8_t TimerCounter;
TIMER_C_Extern volatile uint16_t gate;
TIMER_C_Extern volatile uint8_t state;
TIMER_C_Extern uint8_t timer[4];
TIMER_C_Extern uint8_t bitA,Ans,levelNo[2];
TIMER_C_Extern bool next_home,bitB[4],welcome_t;
uint8_t i;

void Timer_Init();


#endif /* TIMER_H_ */
