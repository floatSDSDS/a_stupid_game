/*
 * Button.c
 *
 *  Created on: 2015年7月2日
 *      Author: Administrator
 */

#ifndef BUTTON_C_
#define BUTTON_C_

#include "Button.h"
#include "Clock.h"
#include "LED.h"
#include "select.h"

void Button_Init()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
	GPIOPinTypeGPIOInput(GPIOP, GPIO_PIN_2);//配置行输入
	GPIOPinTypeGPIOInput(GPION, GPIO_PIN_2|GPIO_PIN_3);
	GPIOPinTypeGPIOInput(GPIOD, GPIO_PIN_0);

	GPIOPinTypeGPIOOutput(GPIOD, GPIO_PIN_1);//配置列输出
	GPIOPinTypeGPIOOutput(GPIOH, GPIO_PIN_2|GPIO_PIN_3);
	GPIOPinTypeGPIOOutput(GPIOM, GPIO_PIN_3);
}


/******************************************************************************
  * 函数：  ButtonScan()
  * 描述：  按键判断
  * 输入值：无
  *	返回值：Key -> 按下的键码序列
  ******************************************************************************/
uint8_t Button_Scan()
{
	uint8_t KeyValue;
	uint8_t ScanColNum = 0;

	switch(ScanColNum)
	{
		case 0: COL1_LOW();    //1.第一列处于低电平
				COL2_HIGH();
				COL3_HIGH();
				COL4_HIGH();
				Delay(5);
				KeyValue = Button_SearchKeyValue(ScanColNum);
				if(KeyValue != NJ)
				{
					break;
				}

				ScanColNum++;

		case 1: COL2_LOW();    //2.第二列处于低电平
				COL1_HIGH();
				COL3_HIGH();
				COL4_HIGH();
				Delay(5);
				//ScanColNum ++;
				KeyValue = Button_SearchKeyValue(ScanColNum);
				if(KeyValue != NJ)
				{
					break;
				}

				ScanColNum++;

		case 2: COL3_LOW();    //3.第三列处于低电平
				COL1_HIGH();
				COL2_HIGH();
				COL4_HIGH();
				Delay(5);
				//ScanColNum ++;
				KeyValue = Button_SearchKeyValue(ScanColNum);

				if(KeyValue != NJ)
				{
					break;
				}

				ScanColNum++;

		case 3:	COL4_LOW();    //4.第四列处于低电平
				COL1_HIGH();
				COL2_HIGH();
				COL3_HIGH();
				Delay(5);
				//ScanColNum ++;
				KeyValue = Button_SearchKeyValue(ScanColNum);
				if(KeyValue != NJ)
				{
					break;
				}

		default:break;

	}

	return KeyValue;
}

/******************************************************************************
  * 函数：  SearchKeyValue()
  * 描述：  搜索键码
  * 输入值：无
  *	返回值：Key -> 按下的键码序列
  ******************************************************************************/
uint8_t Button_SearchKeyValue(uint8_t ScanColNum)
{
	uint8_t PinStatus,KeyValue;
	uint8_t Step = 0;


	switch(Step)
	{
		case 0: PinStatus = GPIOPinRead(GPIOP, GPIO_PIN_2);
				if((PinStatus&GPIO_PIN_2) == KEYPRESS)
				{
					Delay(10);
					if((PinStatus&GPIO_PIN_2) == KEYPRESS)
					{
						KeyValue = J1 + 4*ScanColNum;
						break;
					}
				}

				Step ++;


		case 1: PinStatus = GPIOPinRead(GPION, GPIO_PIN_3);
				if((PinStatus&GPIO_PIN_3) == KEYPRESS)
				{
					Delay(10);
					if((PinStatus&GPIO_PIN_3) == KEYPRESS)
					{
						KeyValue = J5 + 4*ScanColNum;
						break;
					}
				}

				Step ++;

		case 2: PinStatus = GPIOPinRead(GPION, GPIO_PIN_2);
				if((PinStatus&GPIO_PIN_2) == KEYPRESS)
				{
					Delay(10);
					if((PinStatus&GPIO_PIN_2) == KEYPRESS)
					{
						KeyValue = J9 + 4*ScanColNum;
						break;
					}
				}

				Step ++;

		case 3: PinStatus = GPIOPinRead(GPIOD, GPIO_PIN_0);
				if((PinStatus&GPIO_PIN_0) == KEYPRESS)
				{
					Delay(10);
					if((PinStatus&GPIO_PIN_0) == KEYPRESS)
					{
						KeyValue = J13 + 4*ScanColNum;
						break;
					}
				}

		default:KeyValue = NJ;
				break;

	}


	return KeyValue;
}


void Button_run(){
	uint8_t Key = Button_Scan();
			switch(Key)
			{
				case J1: break;
				case J2: break;
				case J3: buzzer_run(500000);button3();break;
				case J4: break;
				case J5: buzzer_run(500000);button5();break;
				case J6: buzzer_run(500000);button6();break;
				case J7: buzzer_run(500000);button7();break;
				case J8: break;

				case J9: buzzer_run(500000);button9();break;
				case J10: buzzer_run(500000);button10();break;
				case J11: buzzer_run(500000);button11();break;
				case J12: break;
				case J13:buzzer_run(500000); button13();break;
				case J14: buzzer_run(500000);button14();break;
				case J15: buzzer_run(500000);button15();break;
				case J16: break;
				default:		break;
			}
}

#endif /* BUTTON_C_ */
