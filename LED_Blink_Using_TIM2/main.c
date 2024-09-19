#include "stm32f10x.h"


void delay(int milisecond) {
	TIM2->PSC = 0x11940;	
	TIM2->ARR = milisecond;	

	//TIM2->PSC = 36000 - 1;
	//TIM2->ARR = 2 * milisecond - 1;

	TIM2->SR &= ~(1);      
	TIM2->CR1 |= 1;			
	while(!(TIM2->SR & 1));	
	TIM2->CR1 &= ~(1);
}

int main() {
	RCC->APB2ENR |= (1<<4);
	RCC->APB1ENR |= 1;
	
	GPIOC->CRH |= 3<<20;
	GPIOC->CRH &= ~(3<<22);

	GPIOC->ODR &= ~(1<<13);
	GPIOC->ODR ^= (1<<13);

	while(1) {
		GPIOC->ODR ^= (1<<13);
		delay(1000);
	}
	return 0;
}

	