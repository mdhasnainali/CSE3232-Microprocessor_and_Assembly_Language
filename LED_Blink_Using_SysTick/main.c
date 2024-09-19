#include "stm32f10x.h"


void delay(int miliseconds){
	SysTick->LOAD = miliseconds;
	SysTick->CTRL |= 0x5;
	// while(!(SysTick->CTRL & (1<<15)));
	while((SysTick->CTRL & 0x10000) == 0);
	SysTick->CTRL &= 0;
}


int main(){
	RCC->APB2ENR |= (1<<4);
	GPIOC->CRH ^= (1<<22);
	GPIOC->CRH = (3<<20);
	
	while(1){
		GPIOC->ODR ^= (1<<13);
		
		// for(int i=0;i<1000;i++);
		delay(800000000);
	}

}