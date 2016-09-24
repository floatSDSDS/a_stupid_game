/*
 * system.h
 *
 *  Created on: 2015年7月2日
 *      Author: Administrator
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_



#include <stdint.h>           //标准C库头文件
#include <stdbool.h>          //布尔值头文件
#include "inc/hw_memmap.h"    //寄存器地址头文件
#include "inc/hw_types.h"
#include "driverlib/pin_map.h"//引脚寄存器头文件
#include "driverlib/sysctl.h" //系统定义头文件
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"      //中断向量头文件
#include "driverlib/timer.h"  //定时器头文件
#include "driverlib/i2c.h"    //I2C头文件
#include "inc/hw_i2c.h"
#include "driverlib/adc.h"    //ADC头文件
#include "driverlib/uart.h"   //UART头文件
#include "inc/hw_uart.h"
#include "utils/uartstdio.h"



#include <string.h>

#include "inc/hw_epi.h"
#include "inc/hw_ints.h"
#include "driverlib/epi.h"

#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/systick.h"
#include "driverlib/ssi.h"
#include "driverlib/fpu.h"
#include "TFTinit/TFT_400x240_OTM4001A_16bit.h"

#include "EPIinit/EPIinit.h"



//
// Select floating-point math.
//
//#define MATH_TYPE FLOAT_MATH

#include "IQmath/IQmathLib.h"





#endif /* SYSTEM_H_ */
