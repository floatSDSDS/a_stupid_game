/*
 * timer.c
 *
 *  Created on: 2015年12月30日
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
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); 	//使能外设定时器
	TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_PERIODIC);//将TIMER0B配置为16位周期定时器
	TimerLoadSet(TIMER0_BASE,TIMER_B,30000);            //设置周期为1ms，即1ms触发1次中断
	IntMasterEnable();
	TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT); //使能TIMER输出中断
	IntEnable(INT_TIMER0B);  							//使能处理器的TIMER0B中断
	TimerEnable(TIMER0_BASE, TIMER_B); 				//打开TIMER0B
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
		TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);  //清除中断标志

}


#endif /* TIMER_C_ */
