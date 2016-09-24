/*
 * gamepage.c
 *
 *  Created on: 2015年12月31日
 *      Author: floatSD
 */

#ifndef GAMEPAGE_C_
#define GAMEPAGE_C_
#include "gamepage.h"
#include "timer.h"
#include "Clock.h"
#include "Calculate.h"
#include "LED.h"
#include "button.h"

void page_home(){
	state=1;next_home=0;
	TFTLCD_CLEAR(BLACK);
	int x=120,y=120,flag=0;
    TFTLCD_showLed(x,y,CYAN,BLACK,9);
    TFTLCD_showLed(x,y,RED,BLACK,9);
    TFTLCD_ShowString(60,200,"Binary Bit Trace",WHITE,BLACK,10000);
    TFTLCD_ShowString(60,250,">  Game Start  <",LBBLUE,BLACK,1);
    TFTLCD_ShowString(68,290,">  Tutorial  <",WHITE,BLACK,1);
    while(state==1){
    	if(flag==0){
    		TFTLCD_showLed(x,y,CYAN,BLACK,9);
    		flag=1;
    	}
    	else {
    		TFTLCD_showLed(x,y,RED,BLACK,9);
    		flag=0;
    	}
    }
}


void page_selectLevel(){
	state=3;
	levelNo[0]=0;levelNo[1]=0;
	int x1=70,x2=170,y1=60,y2=160,flag=0;//x44=92,y44=240;
	TFTLCD_CLEAR(BLACK);
	TFTLCD_showLed(x1,y1,CYAN,BLACK,8);
	TFTLCD_showLed(x1,y2,CYAN,BLACK,8);
	TFTLCD_showLed(x2,y1,CYAN,BLACK,8);
	TFTLCD_showLed(x2,y2,CYAN,BLACK,8);
	TFTLCD_ShowString(x1-4,y1+8,"1",CYAN,BLACK,1);
	TFTLCD_ShowString(x2-4,y1+8,"2",CYAN,BLACK,1);
	TFTLCD_ShowString(x1-4,y2+8,"3",CYAN,BLACK,1);
	TFTLCD_ShowString(x2-4,y2+8,"4",CYAN,BLACK,1);
	TFTLCD_ShowString(x1-20,y2-40,">  Select Level  <",CYAN,BLACK,1);
	//TFTLCD_showButton(x44,y44,CYAN,BLACK,0);
	/////////////////////////////////////////////////////////////键盘示意
	while(state==3){
		if(flag==0){
			switch(2*levelNo[0]+levelNo[1]+1){
			case 1:TFTLCD_showLed(x1,y1,RED,BLACK,9);break;
			case 2:TFTLCD_showLed(x2,y1,RED,BLACK,9);break;
			case 3:TFTLCD_showLed(x1,y2,RED,BLACK,9);break;
			case 4:TFTLCD_showLed(x2,y2,RED,BLACK,9);break;
			}
			flag=1;		}
		else{
			switch(2*levelNo[0]+levelNo[1]+1){
			case 1:TFTLCD_showLed(x1,y1,CYAN,BLACK,9);break;
			case 2:TFTLCD_showLed(x2,y1,CYAN,BLACK,9);break;
			case 3:TFTLCD_showLed(x1,y2,CYAN,BLACK,9);break;
			case 4:TFTLCD_showLed(x2,y2,CYAN,BLACK,9);break;
			}
			flag=0;		}
	}
}

void page_game(){
	state=4;
	ledclose();
	bitA=rand16();
	led_A16(bitA);
	bitB[0]=0;bitB[1]=0;bitB[2]=0;bitB[3]=0;
	int x=120,y=120;//x44=92,y44=260;
    TFTLCD_CLEAR(BLACK);
    TFTLCD_ShowString(50,80,"the Expected Result",WHITE,BLACK,1);
	TFTLCD_showLed(x,y,CYAN,BLACK,0);TFTLCD_showLed(x,y,CYAN,BLACK,1);
	TFTLCD_showLed(x,y,CYAN,BLACK,2);TFTLCD_showLed(x,y,CYAN,BLACK,3);
	TFTLCD_showLed(x,y,LBBLUE,BLACK,4);TFTLCD_showLed(x,y,LBBLUE,BLACK,5);
	TFTLCD_showLed(x,y,LBBLUE,BLACK,6);TFTLCD_showLed(x,y,LBBLUE,BLACK,7);
	switch(2*levelNo[0]+levelNo[1]){
	case 0:{
		Ans=0;
		TFTLCD_ShowString(x-4,y+8,"1",CYAN,BLACK,1);
	};break;
	case 1:{
		Ans=15;
		drawled_Ans(Ans);
		TFTLCD_ShowString(x-4,y+8,"2",CYAN,BLACK,1);
	};break;
	case 2:{
		Ans=7;
		drawled_Ans(Ans);
		TFTLCD_ShowString(x-4,y+8,"3",CYAN,BLACK,1);
	};break;
	case 3:{
		Ans=rand16();
		drawled_Ans(Ans);
		TFTLCD_ShowString(x-4,y+8,"4",CYAN,BLACK,1);
	};break;}

}

void video_tutorial(){
	TFTLCD_CLEAR(BLACK);
	ledclose();
	    state=2;Ans=9;bitA=8;
	    int x=120,y=120,x44=92,y44=260,i;
	    TFTLCD_ShowString(50,30,"Tutorial",WHITE,BLACK,100000);
		TFTLCD_ShowString(50,70,"This is your LED",WHITE,BLACK,100000);
		Delay(500000000);
		TFTLCD_showLed(x,y,CYAN,BLACK,0);TFTLCD_showLed(x,y,CYAN,BLACK,1);
		TFTLCD_showLed(x,y,CYAN,BLACK,2);TFTLCD_showLed(x,y,CYAN,BLACK,3);
		TFTLCD_showLed(x,y,LBBLUE,BLACK,4);TFTLCD_showLed(x,y,LBBLUE,BLACK,5);
		TFTLCD_showLed(x,y,LBBLUE,BLACK,6);TFTLCD_showLed(x,y,LBBLUE,BLACK,7);
		Delay(500000000);
		TFTLCD_ShowString(50,70,"This is your LED",BLACK,BLACK,100000);
		TFTLCD_ShowString(50,70,"a 4bit number A",WHITE,BLACK,1);
		for(i=0;i<4;i++){
			TFTLCD_showLed(x,y,CYAN,BLACK,0);TFTLCD_showLed(x,y,CYAN,BLACK,1);
			TFTLCD_showLed(x,y,CYAN,BLACK,2);TFTLCD_showLed(x,y,CYAN,BLACK,3);
			Delay(5000000);
			TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,RED,BLACK,1);
			TFTLCD_showLed(x,y,RED,BLACK,2);TFTLCD_showLed(x,y,RED,BLACK,3);
			Delay(5000000);
		}
		TFTLCD_showLed(x,y,CYAN,BLACK,0);TFTLCD_showLed(x,y,CYAN,BLACK,1);
		TFTLCD_showLed(x,y,CYAN,BLACK,2);TFTLCD_showLed(x,y,CYAN,BLACK,3);
		TFTLCD_ShowString(50,70,"a 4bit number B",WHITE,BLACK,1);
		for(i=0;i<4;i++){
			TFTLCD_showLed(x,y,LBBLUE,BLACK,4);TFTLCD_showLed(x,y,LBBLUE,BLACK,5);
			TFTLCD_showLed(x,y,LBBLUE,BLACK,6);TFTLCD_showLed(x,y,LBBLUE,BLACK,7);
			Delay(5000000);
			TFTLCD_showLed(x,y,RED,BLACK,4);TFTLCD_showLed(x,y,RED,BLACK,5);
			TFTLCD_showLed(x,y,RED,BLACK,6);TFTLCD_showLed(x,y,RED,BLACK,7);
			Delay(5000000);
		}
		TFTLCD_showLed(x,y,LBBLUE,BLACK,4);TFTLCD_showLed(x,y,LBBLUE,BLACK,5);
		TFTLCD_showLed(x,y,LBBLUE,BLACK,6);TFTLCD_showLed(x,y,LBBLUE,BLACK,7);
		TFTLCD_ShowString(x44-30,y44+100,"and 4x4 button",WHITE,BLACK,1);
		TFTLCD_showButton(x44,y44,CYAN,BLACK,0);
		Delay(500000000);
		TFTLCD_ShowString(x44-60,y44-40,"numberB is related to",WHITE,BLACK,1);
		TFTLCD_ShowString(x44-30,y44-20,"these buttons",WHITE,BLACK,1);
		for(i=0;i<4;i++){
			TFTLCD_showLed(x,y,LBBLUE,BLACK,4);TFTLCD_showLed(x,y,LBBLUE,BLACK,5);
			TFTLCD_showLed(x,y,LBBLUE,BLACK,6);TFTLCD_showLed(x,y,LBBLUE,BLACK,7);
			TFTLCD_showButton(x44,y44,CYAN,BLACK,5);TFTLCD_showButton(x44,y44,CYAN,BLACK,6);
			TFTLCD_showButton(x44,y44,CYAN,BLACK,7);TFTLCD_showButton(x44,y44,CYAN,BLACK,8);
			Delay(5000000);
			TFTLCD_showLed(x,y,RED,BLACK,4);TFTLCD_showLed(x,y,RED,BLACK,5);
			TFTLCD_showLed(x,y,RED,BLACK,6);TFTLCD_showLed(x,y,RED,BLACK,7);
			TFTLCD_showButton(x44,y44,RED,BLACK,5);TFTLCD_showButton(x44,y44,RED,BLACK,6);
			TFTLCD_showButton(x44,y44,RED,BLACK,7);TFTLCD_showButton(x44,y44,RED,BLACK,8);
			Delay(5000000);
		}
		TFTLCD_FillBlock(0,240,y44-60,y44-20,BLACK);
		TFTLCD_ShowString(50,70,"the Ans we need",WHITE,BLACK,200000);
		TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,CYAN,BLACK,1);
		TFTLCD_showLed(x,y,CYAN,BLACK,2);TFTLCD_showLed(x,y,RED,BLACK,3);
		TFTLCD_showLed(x,y,LBBLUE,BLACK,4);TFTLCD_showLed(x,y,LBBLUE,BLACK,5);
		TFTLCD_showLed(x,y,LBBLUE,BLACK,6);TFTLCD_showLed(x,y,LBBLUE,BLACK,7);
		TFTLCD_ShowString(50,200,"is now here above",WHITE,BLACK,20000);
		LED_ON(0);
		TFTLCD_ShowString(50,240," make A+/-B=Ans",WHITE,BLACK,20000);
		TFTLCD_showButton(x44,y44,GREEN,BLACK,12);
		TFTLCD_ShowString(30,y44+100,"submit with the GREEN",WHITE,BLACK,20000);
}

void video_tutorial_Init(){
	state=0;welcome_t=0;
	int x44=92,y44=160,a=16,i;
	TFTLCD_CLEAR(BLACK);
	TFTLCD_ShowString(50,80,"a Welcome Tutorial",WHITE,BLACK,200000);
	TFTLCD_showButton(x44,y44,CYAN,BLACK,0);
	Delay(500000000);
	TFTLCD_ShowString(x44,y44-40,"This is your",WHITE,BLACK,200000);
	TFTLCD_ShowString(x44,y44-20,"4x4 button",WHITE,BLACK,200000);
	Delay(500000000);
	TFTLCD_ShowString(x44,y44+3*a+20,"up down",WHITE,BLACK,1);
	TFTLCD_ShowString(x44,y44+3*a+38,"left right",WHITE,BLACK,1);
	Delay(500000000);
	for(i=0;i<5;i++){
		TFTLCD_showButton(x44,y44,RED,BLACK,11);
		TFTLCD_showButton(x44,y44,RED,BLACK,14);
		TFTLCD_showButton(x44,y44,RED,BLACK,15);
		TFTLCD_showButton(x44,y44,RED,BLACK,16);
		Delay(10000);
		TFTLCD_showButton(x44,y44,CYAN,BLACK,11);
		TFTLCD_showButton(x44,y44,CYAN,BLACK,14);
		TFTLCD_showButton(x44,y44,CYAN,BLACK,15);
		TFTLCD_showButton(x44,y44,CYAN,BLACK,16);
		Delay(10000);
	}
	TFTLCD_showButton(x44,y44,LBBLUE,BLACK,11);
	TFTLCD_showButton(x44,y44,LBBLUE,BLACK,14);
	TFTLCD_showButton(x44,y44,LBBLUE,BLACK,15);
	TFTLCD_showButton(x44,y44,LBBLUE,BLACK,16);
	Delay(5000000);

	TFTLCD_ShowString(x44+60,y44+2*a,"Enter",WHITE,BLACK,1);
	for(i=0;i<5;i++){
		TFTLCD_showButton(x44,y44,RED,BLACK,12);
		Delay(10000);
		TFTLCD_showButton(x44,y44,CYAN,BLACK,12);
		Delay(10000);
	}
	TFTLCD_showButton(x44,y44,RED,BLACK,12);
	Delay(5000000);
	TFTLCD_ShowString(x44+60,y44+3*a,"go Back",WHITE,BLACK,1);
	for(i=0;i<5;i++){
		TFTLCD_showButton(x44,y44,RED,BLACK,10);
		Delay(10000);
		TFTLCD_showButton(x44,y44,CYAN,BLACK,10);
		Delay(10000);
	}
	TFTLCD_showButton(x44,y44,RED,BLACK,10);
	Delay(5000000);
	TFTLCD_CLEAR(BLACK);
	TFTLCD_ShowString(40,80,"Now,",WHITE,BLACK,500000);
	TFTLCD_ShowString(72,80,"do you understand?",WHITE,BLACK,100000);
	TFTLCD_ShowString(92,120,">  yes  <",LBBLUE,BLACK,1);
	TFTLCD_ShowString(92,140,">not yet<",WHITE,BLACK,1);
	while(state==0){
		Button_run();
		Delay(5000000);
	}
}

void drawled_Ans(uint8_t An){
	int x=120,y=120;
	switch(An){
	case 0:break;
	case 1:TFTLCD_showLed(x,y,RED,BLACK,3);break;
	case 2:TFTLCD_showLed(x,y,RED,BLACK,2);break;
	case 3:TFTLCD_showLed(x,y,RED,BLACK,2);TFTLCD_showLed(x,y,RED,BLACK,3);break;
	case 4:TFTLCD_showLed(x,y,RED,BLACK,1);break;

	case 5:TFTLCD_showLed(x,y,RED,BLACK,1);TFTLCD_showLed(x,y,RED,BLACK,3);break;
	case 6:TFTLCD_showLed(x,y,RED,BLACK,1);TFTLCD_showLed(x,y,RED,BLACK,2);break;
	case 7:TFTLCD_showLed(x,y,RED,BLACK,1);TFTLCD_showLed(x,y,RED,BLACK,2);TFTLCD_showLed(x,y,RED,BLACK,2);break;
	case 8:TFTLCD_showLed(x,y,RED,BLACK,0);break;
	case 9:TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,RED,BLACK,3);break;

	case 10:TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,RED,BLACK,2);break;
	case 11:TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,RED,BLACK,2);TFTLCD_showLed(x,y,RED,BLACK,3);break;
	case 12:TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,RED,BLACK,1);break;
	case 13:TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,RED,BLACK,1);TFTLCD_showLed(x,y,RED,BLACK,3);break;
	case 14:TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,RED,BLACK,1);TFTLCD_showLed(x,y,RED,BLACK,2);break;
	case 15:TFTLCD_showLed(x,y,RED,BLACK,0);TFTLCD_showLed(x,y,RED,BLACK,1);TFTLCD_showLed(x,y,RED,BLACK,2);TFTLCD_showLed(x,y,RED,BLACK,3);break;
	}
}

#endif /* GAMEPAGE_C_ */
