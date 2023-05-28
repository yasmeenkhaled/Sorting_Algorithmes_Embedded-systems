/*
 * Registers.h
 *
 * Created: 3/10/2023 8:13:36 PM
 *  Author: nedaa.ahmed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#define DDRA	*(volatile unsigned char*)(0x3A)
#define PORTA	*(volatile unsigned char*)(0x3B)
#define PINA	*(volatile unsigned char*)(0x39)

#define DDRB	*(volatile unsigned char*)(0x37)
#define PORTB	*(volatile unsigned char*)(0x38)
#define PINB	*(volatile unsigned char*)(0x36)

#define DDRC	*(volatile unsigned char*)(0x34)
#define PORTC	*(volatile unsigned char*)(0x35)
#define PINC	*(volatile unsigned char*)(0x33)

#define DDRD	*(volatile unsigned char*)(0x31)
#define PORTD	*(volatile unsigned char*)(0x32)
#define PIND	*(volatile unsigned char*)(0x30)

#define SREG	*(volatile unsigned char*)(0x5F)

#define PIN0		(0)
#define PIN1		(1)
#define PIN2		(2)
#define PIN3		(3)
#define PIN4		(4)
#define PIN5		(5)
#define PIN6		(6)
#define PIN7		(7)
#endif /* REGISTERS_H_ */