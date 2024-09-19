#define GPIOC_BASE 0x40011000
#define RCC_BASE 0x40021000
#define TIM2_BASE 0x40000000
#define GPIOC_CRH (*(volatile unsigned int*)(GPIOC_BASE+0x04))
#define RCC_APB1ENR (*(volatile unsigned int*)(RCC_BASE+0x1C))
#define RCC_APB2ENR (*(volatile unsigned int*)(RCC_BASE+0x18))
#define GPIOC_ODR (*(volatile unsigned int*)(GPIOC_BASE+0x0C))
#define TIM2_PSC (*(volatile unsigned int*)(TIM2_BASE+0x28))
#define TIM2_SR (*(volatile unsigned int*)(TIM2_BASE+0x10))
#define TIM2_ARR (*(volatile unsigned int*)(TIM2_BASE+0x2C))
#define TIM2_CR1 (*(volatile unsigned int*)(TIM2_BASE+0x00))


void delay(int milisecond) {
	TIM2_PSC = 8000;	
	TIM2_ARR = milisecond;		    
	TIM2_SR &= ~(1);      
	TIM2_CR1 |= 1;			
	while(!(TIM2_SR & 1));	
	TIM2_CR1 &= ~(1);
}

int main() {
	RCC_APB2ENR |= (1<<4);
	RCC_APB1ENR |= 1;
	
	GPIOC_CRH |= 3<<20;
	GPIOC_CRH &= ~(3<<22);

	GPIOC_ODR &= ~(1<<13);
	GPIOC_ODR ^= (1<<13);

	while(1) {
		GPIOC_ODR ^= (1<<13);
		delay(1000);
	}
	return 0;
}

