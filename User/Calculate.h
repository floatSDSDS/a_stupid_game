/*
 * Calculate.h
 *
 *  Created on: 2015��12��30��
 *      Author: floatSD
 */
#include "system.h"

#ifndef CALCULATE_H_
#define CALCULATE_H_



///////////////////////////////////////////////////λ����
bool bitCheck(uint8_t state,uint8_t pos);
int bitAdd(uint8_t state, uint8_t pos);
int bitDel(uint8_t state,uint8_t pos);
///////////////////////////////////////////////////��λ��
uint8_t carry(uint8_t num,uint8_t gate);
void carry_Clock(uint8_t* time);
///////////////////////////////////////////////////�����
uint8_t rand16();
//////////////////////////////////////////////////������ʮ������ת��
uint8_t binary_decimalism(bool* Bi);
void decimalism_4bitLED(uint8_t De);

#endif /* CALCULATE_H_ */
