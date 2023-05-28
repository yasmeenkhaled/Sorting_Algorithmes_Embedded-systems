/*
 * Lcd.h
 *
 *  Created on: 11 Apr 2023
 *      Author: HP
 */

#ifndef LCD_H_
#define LCD_H_
#include"BIT_MATHS.h"
#include"ATMEGA32_RRGIOSTERS.h"
#include<util/delay.h>

#define LCD_DATA_PORT      PORTB   //Define LCD data port
#define LCD_DATA_Dir       DDRB    //Define LCD data port direction
#define LCD_Command_Port   PORTA   //Define LED command port
#define LCD_Command_Dir    DDRA    //Define LCD command port direction
#define RS                 3    //Define Register Select (data/command)
#define EN                 2    //Define Enable signal pin

void LCD_Init(void);
void LCD_Comand(unsigned char cmd);
void LCD_Char(unsigned char char_data);
void LCD_String(char *str);
void LCD_Clear(void);
void LCD_goToRowColumn(unsigned char row,unsigned char col);
void LCD_Clear(void);
void IntToString(int num, char* str) ;

#endif /* LCD_H_ */
