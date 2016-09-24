/*
 * system.h
 *
 *  Created on: 2015��7��2��
 *      Author: Administrator
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_



#include <stdint.h>           //��׼C��ͷ�ļ�
#include <stdbool.h>          //����ֵͷ�ļ�
#include "inc/hw_memmap.h"    //�Ĵ�����ַͷ�ļ�
#include "inc/hw_types.h"
#include "driverlib/pin_map.h"//���żĴ���ͷ�ļ�
#include "driverlib/sysctl.h" //ϵͳ����ͷ�ļ�
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"      //�ж�����ͷ�ļ�
#include "driverlib/timer.h"  //��ʱ��ͷ�ļ�
#include "driverlib/i2c.h"    //I2Cͷ�ļ�
#include "inc/hw_i2c.h"
#include "driverlib/adc.h"    //ADCͷ�ļ�
#include "driverlib/uart.h"   //UARTͷ�ļ�
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
