#define F_CPU 16000000UL

#include <util/delay.h>
#include <stdlib.h>
#include "Lcd.h"
#include "KEYPAD2.h"
#include "segment.h"
#include "std_types.h"
#include "Timer0.h"
#include <string.h>
uint8 g_tick=0;
uint8 g_tick1=0;
	//static int Array_of_nums[4]; // because of garbage value
//int size;
//void delay()
//{
	//g_tick++;
	//if (g_tick==overflow)
	//{ 
		//i++;
		//disply_number(Array_of_nums[i]);
		//g_tick=0;
	//}
		 //
	//}
	
	
//void Todelay()
//{
	//g_tick1++;
	//if (g_tick1==overflow2)
	//{
		//
		//g_tick1=0;
	//}
//}

void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}



void main()
{
	char key;
	char Number[6];
	int pos = 0;
	int size = 0;
	int digit_count=0;
	int confirmation = 0; // Flag variable for confirmation
    //timer0_init();
	keybad_init();
	LCD_Init();
	Seven_Seg_Init();
	LCD_String(" Enter Size: ");
   T0delayonems();
	while (!confirmation)
	{
		key = keybad_get_value_debounced();
		if (key == 'C')
		{
			LCD_Clear();
			LCD_String(" Enter Size: ");
			pos = 0;
		}
		
		
		else if (key == '=')
		{
			confirmation = 1; // Set confirmation flag to indicate end of entering size
			break;
		}
		else if (key != INVALID_KEYPAD_PRESS)
		{
			Number[pos] = key;
			pos++;
			LCD_Char(key);
		}
	}

	LCD_Clear();
	size = atoi(Number);
	static int Array_of_nums[4]; // because of garbage value
	LCD_String(" Enter Numbers: ");

	int i = 0;
	while(1){
		
		while (1)
		{
			key = keybad_get_value_debounced();
			if (key == 'C')
			{
				LCD_Clear();
				LCD_String(" Enter Numbers: ");
				LCD_goToRowColumn(0,15);
				Array_of_nums[i] = 0;
			}
			else if (key == '=')
			{
				i++;
				digit_count=0;
				LCD_Char(' ');
				break;
			}
			else if (key != INVALID_KEYPAD_PRESS && i < size)
			{
				digit_count++;
				if(digit_count<=4){
					Array_of_nums[i]*=10;
					Array_of_nums[i] += key - '0';
					LCD_Char(key);
				}
				
			}
		}
		
		if(i==size) break;
		
	}
	
	bubbleSort(Array_of_nums,size);
	
	// Display the entered array on the LCD
	LCD_Clear(); // Clear the LCD display
	LCD_String(" Array: ");
	char numStr[6];
	
	for(int j=0; j<6; j++) numStr[j]=' ';
	
	for (i = 0; i < size; i++) {
		IntToString(Array_of_nums[i], numStr);
		LCD_String(numStr);
		LCD_Char(' '); // Add a space between numbers
	}
		//INI1_setCallBack(Todelay);
		 T0delayms(4000);
	
	LCD_Clear();
	
	while(1)
	
	{
		for (int i = 0; i < size; i++)
		{
			disply_number(Array_of_nums[i]);
			CLR_SEV_SEG();
			//_delay_ms(1000);
			//timer0_init();
			T0delayms	(1000);
			CLR_SEV_SEG();
			LCD_Clear();

		}
		
	}
	

	
}

