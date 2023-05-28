
#include "EXT_INT1.h"
#include <avr/interrupt.h>
#include "BIT_MATHS.h"
#include "std_types.h"

#define I_BIT (7)  /*The I-bit in the SREG register*/

/*Global variable to hold the address of the callback function in the application*/
void (*g_callBackPtr)(void) = NULL_PTR;

/* External INT1 Interrupt Service Routine */
ISR(INT1_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}

/* External INT1 enable and configuration function */
void INT1_Init(void)
{
	CLR_BIT(SREG, I_BIT);				//Disable interrupts by clearing I-bit, another way to clear the I-bit: clr();
	CLR_BIT(DDRD, PD3);                 //Configure INT1/PD3 as input pin
	SET_BIT(PORTD, PD3);				// Enable the internal pull up resistor at PD3 pin
	SET_BIT(GICR, INT1);                //Enable external interrupt pin INT1
	SET_BIT(MCUCR, ISC11);			    //Trigger INT1 with the falling edge
	CLR_BIT(MCUCR, ISC10);
	SET_BIT(SREG, I_BIT);			   //Enable interrupts by setting I-bit, another way to set the I-bit: sei();
}

/*Set the callback function address*/
void INT1_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}