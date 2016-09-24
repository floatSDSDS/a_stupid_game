/*
 * LED.c
 *
 *  Created on: 2015Äê11ÔÂ13ÈÕ
 *      Author: floatSD
 */
#include "LED.h"
#include "Clock.h"

void LED_Init()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
	GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_5);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);
}
void buzzer_run(uint32_t frequency){
	GPIOPinWrite(GPIOM,GPIO_PIN_5,GPIO_PIN_5);
	Delay(frequency);
	GPIOPinWrite(GPIOM,GPIO_PIN_5,0x00);
	Delay(frequency);
}
void buzzer_change(uint32_t freq1,uint32_t freq2,uint32_t length){
	int i;
	for(i=0;i<length;i++){
	GPIOPinWrite(GPIOM,GPIO_PIN_5,GPIO_PIN_5);
	Delay(freq1);
	GPIOPinWrite(GPIOM,GPIO_PIN_5,0x00);
	Delay(freq2);
	}
}
void LED_ON(uint8_t NumLED){
	switch(NumLED)
			{
				case 0: GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_PIN_1);		break;
				case 1: GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_PIN_2);		break;
				case 2: GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,GPIO_PIN_3);		break;
				case 3: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_0,GPIO_PIN_0);		break;
				case 4: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_1,GPIO_PIN_1);		break;
				case 5: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_2,GPIO_PIN_2);		break;
				case 6: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_3,GPIO_PIN_3);		break;
				case 7: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_4,GPIO_PIN_4);		break;
				default: ledclose();			break;
			}
}

void LED_OFF(uint8_t NumLED){
	switch(NumLED)
			{
				case 0: GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0x00);		break;
				case 1: GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0x00);		break;
				case 2: GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0x00);		break;
				case 3: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_0,0x00);		break;
				case 4: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_1,0x00);		break;
				case 5: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_2,0x00);		break;
				case 6: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_3,0x00);		break;
				case 7: GPIOPinWrite(GPIO_PORTL_BASE,GPIO_PIN_4,0x00);		break;
				default: ledclose();			break;
			}
}

void led0(){	ledclose();	LED_ON(0);	LED_ON(1);}
void led1(){	ledclose(); LED_ON(1);	LED_ON(2);}
void led2(){	ledclose();	LED_ON(2);	LED_ON(3);}
void led3(){	ledclose();	LED_ON(3);	LED_ON(4);}
void led4(){	ledclose();	LED_ON(4);	LED_ON(5);}
void led5(){	ledclose();	LED_ON(5);	LED_ON(6);}
void led6(){	ledclose();	LED_ON(6);  LED_ON(7);}
void led7(){	ledclose();	LED_ON(7);	LED_ON(0);}

void ledclose(){
	LED_OFF(0);
	LED_OFF(1);
	LED_OFF(2);
	LED_OFF(3);
	LED_OFF(4);
	LED_OFF(5);
	LED_OFF(6);
	LED_OFF(7);
}

void ledon(){
	LED_ON(0);
	LED_ON(1);
	LED_ON(2);
	LED_ON(3);
	LED_ON(4);
	LED_ON(5);
	LED_ON(6);
	LED_ON(7);
}

void ledbilibili(uint8_t i){
	if(i==0){
	while(true){
		ledclose();
		Delay(96);
		ledon();
		Delay(96);
	}}
	else if(i==1)
		for(;i<5;i++){
		ledclose();
		Delay(96);
		ledon();
		Delay(96);
		}
}
void ledrun(uint8_t i){
	ledclose();
	if(i==0)
	while(1){
		ledclose();
		LED_ON(0);
		LED_ON(2);
		LED_ON(4);
		LED_ON(6);
		Delay(128);
		ledclose();
		LED_ON(1);
		LED_ON(3);
		LED_ON(5);
		LED_ON(7);
		Delay(128);
	}
	else if(i==1)
	for(;i<5;i++){
		LED_ON(0);
		LED_ON(2);
		LED_ON(4);
		LED_ON(6);
		Delay(128);
		ledclose();
		LED_ON(1);
		LED_ON(3);
		LED_ON(5);
		LED_ON(7);
		Delay(128);
	}
}

void led_A16(uint8_t A){
	switch(A){
	case 0:break;
	case 1:LED_ON(3);break;
	case 2:LED_ON(2);break;
	case 3:LED_ON(2);LED_ON(3);break;
	case 4:LED_ON(1);break;
	case 5:LED_ON(1);LED_ON(3);break;
	case 6:LED_ON(1);LED_ON(2);break;
	case 7:LED_ON(1);LED_ON(2);LED_ON(3);break;
	case 8:LED_ON(0);break;
	case 9:LED_ON(0);LED_ON(3);break;
	case 10:LED_ON(0);LED_ON(2);break;
	case 11:LED_ON(0);LED_ON(2);LED_ON(3);break;
	case 12:LED_ON(0);LED_ON(1);break;
	case 13:LED_ON(0);LED_ON(1);LED_ON(3);break;
	case 14:LED_ON(0);LED_ON(1);LED_ON(2);break;
	case 15:LED_ON(0);LED_ON(1);LED_ON(2);LED_ON(3);break;
	}
}
