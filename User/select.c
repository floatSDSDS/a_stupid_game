/*
 * select.c
 *
 *  Created on: 2016年1月3日
 *      Author: floatSD
 */

#ifndef SELECT_C_
#define SELECT_C_

#include "gamepage.h"
#include "select.h"
#include "Clock.h"
#include "timer.h"
#include "LED.h"
#include "Calculate.h"

void button14(){
	int x=120,y=120,x44,y44,i;
	switch(state){
	case 0:{
		if(welcome_t==0){
			state=9;
			page_home();
		}
		else video_tutorial_Init();
	};break;
	case 1:{
		if(next_home==0){
			page_selectLevel();
		}
		else{
			video_tutorial();
		}
	};break;
	case 2:{
		if((bitA+binary_decimalism(bitB)==Ans)||(bitA-binary_decimalism(bitB)==Ans)){
		for(i=0;i<5;i=i+4){
		buzzer_change(15-i,1+i,40);
		}
		TFTLCD_showLed(x,y,RED,BLACK,8);
		Delay(10000);
		TFTLCD_showLed(x,y,CYAN,BLACK,8);
		Delay(10000);
		TFTLCD_showLed(x,y,RED,BLACK,8);
		Delay(10000);
		TFTLCD_showLed(x,y,CYAN,BLACK,8);
		Delay(10000);
		TFTLCD_showLed(x,y,RED,BLACK,8);
		TFTLCD_CLEAR(BLACK);
		TFTLCD_ShowString(50,220,"Congratulations!",WHITE,BLACK,400000);
		TFTLCD_ShowString(50,250,"now have fun",WHITE,BLACK,300000);
		Delay(8000000);
		page_selectLevel();
			}
		else{
			buzzer_change(1,15,40);
			Delay(50000);
			buzzer_change(1,15,40);
			TFTLCD_ShowString(50,220,"try again",WHITE,BLACK,300000);}
	};break;
	case 3:page_game();break;
	case 4:{
		x=120,y=120,x44=92,y44=260;
		int i;
		if((bitA+binary_decimalism(bitB)==Ans)||(bitA-binary_decimalism(bitB)==Ans)){
			for(i=0;i<5;i=i+4){
			buzzer_change(15-i,1+i,40);
			}
			TFTLCD_showLed(x,y,RED,BLACK,8);
			Delay(10000);
			TFTLCD_showLed(x,y,CYAN,BLACK,8);
			Delay(10000);
			TFTLCD_showLed(x,y,RED,BLACK,8);
			Delay(10000);
			TFTLCD_showLed(x,y,CYAN,BLACK,8);
			Delay(10000);
			TFTLCD_showLed(x,y,RED,BLACK,8);
			TFTLCD_ShowString(50,220,"Congratulations!",WHITE,BLACK,300000);
			Delay(3000000);
			TFTLCD_showButton(x44,y44,CYAN,BLACK,0);
			TFTLCD_ShowString(30,y44+80,"use this button to play",WHITE,BLACK,100000);
			TFTLCD_ShowString(30,y44+100,"same level another time",WHITE,BLACK,100000);
			for(i=0;i<3;i++){
					TFTLCD_showButton(x44,y44,RED,BLACK,16);
					Delay(10000);
					TFTLCD_showButton(x44,y44,CYAN,BLACK,16);
					Delay(10000);
				}
			TFTLCD_showButton(x44,y44,RED,BLACK,16);

		}};break;
	}
}
void button6(){
	switch(state){
	case 1:break;
	case 2:page_home();break;
	case 3:page_home();break;
	case 4:ledclose();page_selectLevel();break;
	}
}
////////////////////////////上下左右
void button10(){
	int x1=70,x2=170,y1=60,y2=160;
	switch(state){
	case 0:{
		if(welcome_t==0){
			TFTLCD_ShowString(92,120,">  yes  <",WHITE,BLACK,10000);
			TFTLCD_ShowString(92,140,">not yet<",LBBLUE,BLACK,10000);
			welcome_t=1;Delay(3000);
		}
		else{
			TFTLCD_ShowString(92,120,">  yes  <",LBBLUE,BLACK,10000);
			TFTLCD_ShowString(92,140,">not yet<",WHITE,BLACK,10000);
			welcome_t=0;Delay(3000);
		}
	};break;
	case 1:{
		if(next_home==0){
			TFTLCD_ShowString(60,250,">  Game Start  <",WHITE,BLACK,1);
			next_home=1;
			TFTLCD_ShowString(68,290,">  Tutorial  <",LBBLUE,BLACK,1);
			Delay(3000);
		}
		else {
			TFTLCD_ShowString(68,290,">  Tutorial  <",WHITE,BLACK,1);
			next_home=0;
			TFTLCD_ShowString(60,250,">  Game Start  <",LBBLUE,BLACK,1);
			Delay(3000);
		}
	};break;
	case 2:break;
	case 3:{
		if(levelNo[0]==0){
			TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
			levelNo[0]=1;
		}
		else{
			TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
			levelNo[0]=0;
		}
	};break;
	case 4:break;
	default:break;
	}
}
void button9(){
	int x1=70,x2=170,y1=60,y2=160;
	switch(state){
	case 0:{
			if(welcome_t==0){
				TFTLCD_ShowString(92,120,">  yes  <",WHITE,BLACK,1);
				TFTLCD_ShowString(92,140,">not yet<",LBBLUE,BLACK,1);
				welcome_t=1;Delay(3000);
			}
			else{
				TFTLCD_ShowString(92,120,">  yes  <",LBBLUE,BLACK,1);
				TFTLCD_ShowString(92,140,">not yet<",WHITE,BLACK,1);
				welcome_t=0;Delay(3000);
			}
		};break;
	case 1:{
		if(next_home==0){
			TFTLCD_ShowString(60,250,">  Game Start  <",WHITE,BLACK,1);
			next_home=1;
			TFTLCD_ShowString(68,290,">  Tutorial  <",LBBLUE,BLACK,1);
			Delay(3000);
		}
		else {
			TFTLCD_ShowString(68,290,">  Tutorial  <",WHITE,BLACK,1);
			next_home=0;
			TFTLCD_ShowString(60,250,">  Game Start  <",LBBLUE,BLACK,1);
			Delay(3000);
		}
	};break;
	case 2:break;
	case 3:{
		if(levelNo[0]==1){
			TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
			levelNo[0]=0;
		}
		else {
			TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
			levelNo[0]=1;
		}
	};break;
	case 4:break;
	default:break;
	}
}

void button5(){
	int x1=70,x2=170,y1=60,y2=160;
	switch(state){
	case 1:break;
	case 2:break;
	case 3:{
		if(levelNo[1]==1){
			TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
			levelNo[1]=0;
		}
		else {
			TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
			levelNo[1]=1;
		}};break;
	case 4:break;
	default:page_home();break;
	}
}
void button13(){
	int x1=70,x2=170,y1=60,y2=160;
	switch(state){
	case 1:break;
	case 2:break;
	case 3:{
		if(levelNo[1]==1){
			TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
			levelNo[1]=0;
		}
		else {
			TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
			TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
			levelNo[1]=1;
		}};break;
	case 4:page_game();break;
	default:page_home();break;
	}
}

void button3(){
	if(state==4||state==2){
		if(bitB[0]==0){
			bitB[0]=1;
			LED_ON(7);
		}
		else {
			bitB[0]=0;
			LED_OFF(7);
		}
	}Delay(3000);
}
void button7(){
	if(state==4||state==2){
		if(bitB[1]==0){
			bitB[1]=1;
			LED_ON(6);
		}
		else {
			bitB[1]=0;
			LED_OFF(6);
		}
	}Delay(3000);
}
void button11(){
	if(state==4||state==2){
		if(bitB[2]==0){
			bitB[2]=1;
			LED_ON(5);
		}
		else {
			bitB[2]=0;
			LED_OFF(5);
		}
	}Delay(3000);
}
void button15(){
	if(state==4||state==2){
		if(bitB[3]==0){
			bitB[3]=1;
			LED_ON(4);
		}
		else {
			bitB[3]=0;
			LED_OFF(4);
		}
	}Delay(3000);
}

#endif /* SELECT_C_ */
