/*
 * Clock.c
 *
 *  Created on: 2015Äê11ÔÂ13ÈÕ
 *      Author: floatSD
 */
#include "Clock.h"


uint32_t Clock_Init(){
	 return SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
			 SYSCTL_OSC_MAIN |
			 SYSCTL_USE_PLL |
			 SYSCTL_CFG_VCO_480), OSC_120MHZ);
}


void Delay(uint32_t CountMs){

	SysCtlDelay(CountMs*sysClock_Fr/3000);

}
