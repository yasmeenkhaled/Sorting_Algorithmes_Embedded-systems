/*
 * Timer0.h
 *
 * Created: 5/25/2023 12:52:34 PM
 *  Author: LAPTOP
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#define F_CPU 16000000UL
#include <avr/io.h>                               nn                                                                                                  
#include "BIT_MATHS.h"
#include "std_types.h"
#include "ATmega32_Rrgiosters.h"
 #define overflow 244
 //#define overflow2 977
 //void timer0_init(void);
 //void INI1_setCallBack(void(*a_ptr)(void));

void T0delayonems(void);
void T0delayms(int n);


#endif /* TIMER0_H_ */