/*
 * Button.h
 *
 *  Created on: 2015年7月2日
 *      Author: Administrator
 */

#ifndef BUTTON_H_
#define BUTTON_H_

/* Private include-------------------------------------------------------------*/
#include "system.h"

/* Private define-------------------------------------------------------------*/

#define LOW       0x00
#define KEYPRESS  0X00

/*按键值-与开发板上的对应*/
#define NJ   0   //没有按下键码
#define J1   1   //按下J1
#define J5   2
#define J9   3
#define J13  4

#define J2   5
#define J6   6
#define J10  7
#define J14  8

#define J3   9
#define J7   10
#define J11  11
#define J15  12

#define J4   13
#define J8   14
#define J12  15
#define J16  16


/*GPIO地址*/
#define GPIOP         GPIO_PORTP_BASE
#define GPION         GPIO_PORTN_BASE
#define GPIOD         GPIO_PORTD_BASE
#define GPIOH         GPIO_PORTH_BASE
#define GPIOM         GPIO_PORTM_BASE


/*输入输出模式配置*/



/*引脚高低配置*/
#define COL1_HIGH()   	 GPIOPinWrite(GPIOD,GPIO_PIN_1,GPIO_PIN_1);//PD1
#define COL1_LOW()		 GPIOPinWrite(GPIOD,GPIO_PIN_1,LOW);
#define COL2_HIGH()      GPIOPinWrite(GPIOH,GPIO_PIN_3,GPIO_PIN_3);//PH3
#define COL2_LOW()		 GPIOPinWrite(GPIOH,GPIO_PIN_3,LOW);
#define COL3_HIGH()      GPIOPinWrite(GPIOH,GPIO_PIN_2,GPIO_PIN_2);//PH2
#define COL3_LOW()		 GPIOPinWrite(GPIOH,GPIO_PIN_2,LOW);
#define COL4_HIGH()      GPIOPinWrite(GPIOM,GPIO_PIN_3,GPIO_PIN_3);//PM3
#define COL4_LOW()		 GPIOPinWrite(GPIOM,GPIO_PIN_3,LOW);








/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void    Button_Init(void);
uint8_t Button_Scan(void);
uint8_t Button_SearchKeyValue(uint8_t ScanColNum);
void Button_run();

#endif /* BUTTON_H_ */
