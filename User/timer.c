/*
 * timer.c
 *
 *  Created on: 2015��12��30��
 *      Author: floatSD
 */

#ifndef TIMER_C_
#define TIMER_C_

#include "timer.h"
#include "Button.h"
#include "LED.h"
//#include "I2C.h"
#include "Clock.h"
#include "Calculate.h"

void Timer_Init(){
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); 	//ʹ�����趨ʱ��
	TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_PERIODIC);//��TIMER0B����Ϊ16λ���ڶ�ʱ��
	TimerLoadSet(TIMER0_BASE,TIMER_B,30000);            //��������Ϊ1ms����1ms����1���ж�
	IntMasterEnable();
	TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT); //ʹ��TIMER����ж�
	IntEnable(INT_TIMER0B);  							//ʹ�ܴ�������TIMER0B�ж�
	TimerEnable(TIMER0_BASE, TIMER_B); 				//��TIMER0B
	TimerCounter = 0;
	gate=200;
	state=0;
	for(i=0;i<4;i++){timer[i]=0;};


//	TimerIntFlag = UnInterrupt;
}

void TIMER0B_Handler(){
	TimerCounter++;
/*
		if(TimerCounter==gate)
		{
			carry_Clock(timer);
		}
		else if(TimerCounter==2*gate){
			carry_Clock(timer);
			TimerCounter=0;
		}
//		else if(TimerCounter<2*gate){
//			ledclose();
//		}
//		else if(TimerCounter==2*gate){
//			TimerCounter=0;
//		}
*/

		if(TimerCounter%10 == 0){
			Button_run();
		}
		TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);  //����жϱ�־

}


#endif /* TIMER_C_ */
