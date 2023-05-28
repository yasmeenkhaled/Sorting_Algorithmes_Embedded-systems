#include "Timer0.h"

void T0delayonems(){
	//setup Timer 0 = 255 - 16 +1=240
	TCNT0 = 240;		//load count value for 1ms time delay
	// res= 1 /time = pre / F_cpu = 1024/16M = 64 micro(time of one tick)
	// ticks = 1m / 64 micro = 15.625
	TCCR0 = 0b00000101;	//normal mode with 1024 pre-scalar
	
	while(!(TIFR & (1<<TOV0)));	//wait until TOV0 flag is set
	TCCR0 = 0;		//turn off timer 0
	TIFR |= (1<<TOV0);	//clear TOV0 flag
}

void T0delayms(int n){//n = 1 for 1ms		3s=3000
	for(int i = 0; i < n; i++){
		T0delayonems();
	}//i= 0 ,1 ,2, ---------------,2999
}

//void (*g_callBackptr)(void)= NULL_PTR;
//
//ISR(TIMER0_OVF_vect)
//{
	//
	//if (g_callBackptr!= NULL_PTR)
	//{
		//(*g_callBackptr)();
	//}
//}
//void timer0_init(void)
//{
	//
	//TCNT0=0;
	//SET_BIT(TIMSK,TOIE0);
	//TCCR0=(1<<CS02);
	//SET_BIT(SREG,I_BIT);
//}
//
//void INI1_setCallBack(void(*a_ptr)(void))
//{
	//
	//g_callBackptr=a_ptr;
//}