/*
 * Calculate.c
 *
 *  Created on: 2015年12月30日
 *      Author: floatSD
 */
#include "Calculate.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#ifndef CALCULATE_C_
#define CALCULATE_C_

///////////////////////////////////////////////////位运算
//检查state的第pos位是否为1
bool bitCheck(uint8_t state, uint8_t pos){
    return state & 1<< pos;
}
//将state的第pos位的值设为1
int bitAdd(uint8_t state, uint8_t pos){
    return state | (1 << (pos));
}
//将state的第pos位的值设为0
int bitDel(uint8_t state,uint8_t pos){
    return state & (~(1 << (pos)));
}
///////////////////////////////////////////////////进位器
//单个数字进位，数字num，进制gate（实验中为十进制和六进制）
uint8_t carry(uint8_t num,uint8_t gate){
	if(num==(gate-1))
		return 1;
	else
		return num++;
}
//时间进位器
void carry_Clock(uint8_t* time){
	if(time[3]==9){
		if(time[2]==5){
			if(time[1]==9){
				if(time[0]==5){
					time[0]=0;
					time[1]=0;
					time[2]=0;
					time[3]=0;
				}
				else {
					time[0]=time[0]+1;
					time[1]=0;
					time[2]=0;
					time[3]=0;
				}
			}
			else {
				time[0]=time[0];
				time[1]=time[1]+1;
				time[2]=0;
				time[3]=0;
			}
		}
		else {
			time[0]=time[0];
			time[1]=time[1];
			time[2]=time[2]+1;
			time[3]=0;
		}
	}
	else {
		time[0]=time[0];
		time[1]=time[1];
		time[2]=time[2];
		time[3]=time[3]+1;
	}
}



uint8_t rand16(){
/*将当前时间设置成随机函数的种子，所以每次产生的数都不一样*/
srand( (unsigned)time( NULL ) );
return rand()%15;
}

uint8_t binary_decimalism(bool* Bi){
	return 8*Bi[0]+4*Bi[1]+2*Bi[2]+Bi[3];
}

#endif /* CALCULATE_C_ */
