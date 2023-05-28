
#include "segment.h"
#include "ATmega32_Rrgiosters.h"
#include "BIT_MATHS.h"
#include "std_types.h"
#include <util/delay.h>


void Seven_Seg_Init(void)
{
	
	SET_BIT(DDRB,0);
	SET_BIT(DDRB,1);
	SET_BIT(DDRB,2);
	SET_BIT(DDRB,4);
	PORTB &= 0b11101000;
	
	
	SET_BIT(DDRB,6);
	SET_BIT(DDRB,5);
	SET_BIT(DDRA,2);
	SET_BIT(DDRA,3);
	
}

void Seven_Seg_Display(int num)
{
PORTB &= 0b11101000;
PORTB |= (((num & 0b00001000)<<1)|(num & 0b00000111));
}
void disply_number(int number)
{
	int digit4 = ( number / 1000) % 10;
	int digit3 = ( number / 100) % 10;
	int digit2 = ( number / 10) % 10;
	int digit1 =  (number/ 1 ) % 10;

	// Display the digits on the four-digit seven-segment display
	uint16 start_time = 0;
	while (start_time < 1000)//elay for 1 seconds
	{
		
		Seven_Seg_Display(digit4);
		_delay_ms(2);
		TOGGLE_BIT(PORTB,6);
		Seven_Seg_Display(digit3);
		_delay_ms(2);
		TOGGLE_BIT(PORTB,5);
		Seven_Seg_Display(digit2);
		_delay_ms(2);
		TOGGLE_BIT(PORTA,2);
		Seven_Seg_Display(digit1);
		_delay_ms(2);
		TOGGLE_BIT(PORTA,3);
		
		start_time += 5;

		
	}
}
void CLR_SEV_SEG()
{
	SET_BIT(PORTB,6);
	SET_BIT(PORTB,5);
	SET_BIT(PORTA,2);
	SET_BIT(PORTA,3);
	
}

