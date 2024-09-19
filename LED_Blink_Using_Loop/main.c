#include "stm32f10x.h"

int main(){
	RCC->APB2ENR |= (1<<4);
	GPIOC->CRH ^= (1<<22);
	GPIOC->CRH 
	|= (3<<20);
	
	while(1){
		GPIOC->ODR ^= (1<<13);
		
		for(int i=0;i<10000;i++);
	}

}