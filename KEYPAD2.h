/*
 * KEYPAD2.h
 *
 *  Created on: 11 Apr 2023
 *      Author: HP
 */

#ifndef KEYPAD2_H_
#define KEYPAD2_H_
#include"BIT_MATHS.h"
#include"ATMEGA32_RRGIOSTERS.h"
#include<util/delay.h>

#define KEYPAD_PORT PORTC
#define KEYPAD_PIN PINC
#define KEYPAD_DDR DDRC


#define INVALID_KEYPAD_PRESS (0xFF)
void keybad_init();
unsigned char keybad_get_value_debounced();


#endif /* KEYPAD2_H_ */
