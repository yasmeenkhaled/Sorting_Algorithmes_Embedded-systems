/*
 * Lcd.c
 *
 *  Created on: 11 Apr 2023
 *      Author: HP
 */

#include "LCD.h"
#include "stdlib.h"
#define SET_CURSOR_LOCATION (0X80)


//void itoa(int value, char* result, int base) {
	//// check for invalid base
	//if (base < 2 || base > 36) {
		//*result = '\0';
		//return;
	//}
//
	//char* ptr = result, *ptr1 = result, tmp_char;
	//int tmp_value;
//
	//do {
		//tmp_value = value;
		//value /= base;
		//*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
	//} while (value);
//
	//// check for negative sign
	//if (tmp_value < 0) {
		//*ptr++ = '-';
	//}
//
	//// null terminate the result string
	//*ptr-- = '\0';
//
	//// reverse the result string
	//while (ptr1 < ptr) {
		//tmp_char = *ptr;
		//*ptr-- = *ptr1;
		//*ptr1++ = tmp_char;
	//}
//}

void LCD_Init(void) //LCD Initialize function
{
	LCD_DATA_Dir |= 0b00010111; //Set PB0, PB1, PB2, and PB4 as output//
	LCD_Command_Dir |= (1<< RS) | (1 << EN); //Set RS, EN as output//

	_delay_ms(1);       // LCD Power ON delay always >15ms
	LCD_Command(0x02);   /* initialize LCD in 4-bit mode */
	LCD_Command(0x28);   //1nitialize the LCD in 4-bit mode, 2 lines, and 5*8 format
	LCD_Command(0x0C);   /* Display ON, Cursor OFF */
	LCD_Command(0x06);   /* shift cursor from left to right on read/write */
	LCD_Command(0x01);   /* Clear display */
	LCD_Command(0x0C);   /* Display ON, Cursor OFF */
	LCD_Command(0x80);   /* cursor at home position */
}

void LCD_Command(unsigned char cmd)
{
	CLR_BIT(LCD_Command_Port, RS);
	PORTB &=0b11101000;
	PORTB |= (((((cmd & 0xF0) >> 4) & 0b00001000) << 1) | (((cmd & 0xF0) >> 4) & 0b00000111));

	SET_BIT(LCD_Command_Port, EN);
	_delay_us(1);
	CLR_BIT(LCD_Command_Port, EN);
	_delay_ms(2);

	PORTB &= 0b11101000;
	PORTB |=((((cmd & 0x0F) & 0b00001000) << 1)| ((cmd & 0x0F) & 0b00000111));

	SET_BIT(LCD_Command_Port, EN);
	_delay_us(1);
	CLR_BIT(LCD_Command_Port, EN);
	_delay_ms(2);
}

void LCD_Char(unsigned char char_data)
{
	SET_BIT(PORTA, 3);
	
	PORTB &= 0b11101000;
	
	unsigned char high = ((char_data & 0xf0) >> 4);
	unsigned char temp = (((high & 0b00001000) << 1) | (high & 0b00000111));
	
	PORTB |= temp;
	
	CLR_BIT(PORTA, 2);
	SET_BIT(PORTA, 2);
	_delay_ms(1);
	CLR_BIT(PORTA, 2);
	
	PORTB &= 0b11101000;
	
	unsigned char low = (char_data & 0x0f);
	unsigned char temp2 = (((low & 0b00001000) << 1) | (low & 0b00000111));
	
	PORTB |= temp2;
	
	CLR_BIT(PORTA, 2);
	SET_BIT(PORTA, 2);
	_delay_ms(1);
	CLR_BIT(PORTA, 2);
	CLR_BIT(PORTA, 3);
	_delay_ms(5);
}

void LCD_String(char *str)
{
	int i;
	for (i=0;str[i]!=0;i++)
	{
		LCD_Char (str[i]);
	}
}

//void LCD_String(char* str) {
	//while (*str != '\0') {
		//// Send each character to the LCD
		//LCD_Char(*str);
		//// Move to the next character
		//str++;
	//}
//}


void LCD_goToRowColumn(unsigned char row,unsigned char col)
{
	unsigned char Address = 0;

	switch(row)
	{
		case 0 :
		Address=col;
		break;

		case 1:
		Address=col+0x40;
		break;

		case 2:
		Address=col+0x14;
		break;

		case 3:
		Address=col+0x54;
		break;
	}

	LCD_Command(Address | SET_CURSOR_LOCATION);
}

void IntToString(int num, char* str) {
	itoa(num, str, 10);
}


void LCD_Clear(void)
{
	LCD_Command(0x01);
}