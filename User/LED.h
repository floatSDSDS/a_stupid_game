/*
 * GPIO.h
 *
 *  Created on: 2015Äê11ÔÂ13ÈÕ
 *      Author: floatSD
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "system.h"

void LED_Init();
#define GPIOM       GPIO_PORTM_BASE

void buzzer_run(uint32_t frequency);
void buzzer_change(uint32_t freq1,uint32_t freq2,uint32_t length);

void led0();
void led1();
void led2();
void led3();
void led4();
void led5();
void led6();
void led7();
void ledclose();
void ledon();
void ledbilibili(uint8_t i);
void ledrun(uint8_t i);

void LED_ON(uint8_t NumLED);
void LED_OFF(uint8_t NumLED);

void led_A16(uint8_t A);
#endif /* GPIO_H_ */
