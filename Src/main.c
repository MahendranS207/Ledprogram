

#include <stdint.h>
#define RCC 0x40023800UL
#define GPIOB 0x40020400UL
#define GPIOC 0x40020800UL
#define RCC_AHB1ENR *(volatile uint32_t*)(RCC + 0x30U)
#define GPIOB_MODER *(volatile uint32_t*)(GPIOB + 0x00U)
#define GPIOC_MODER *(volatile uint32_t*)(GPIOC + 0x00U)
#define GPIOB_ODR *(volatile uint32_t*)(GPIOB + 0x14U)
#define GPIOC_ODR *(volatile uint32_t*)(GPIOC+ 0x14U)

int main(void)
{
    RCC_AHB1ENR |=(1<<1);
    RCC_AHB1ENR |=(1<<2);

    GPIOC_MODER &= ~(3<<12);
    GPIOB_MODER &= ~(3<<26);
    GPIOB_MODER &= ~(3<<28);
    GPIOB_MODER &= ~(3<<30);
    GPIOC_MODER &= ~(3<<18);

    GPIOC_MODER |= (1<<12);
    GPIOB_MODER |= (1<<26);
    GPIOB_MODER |= (1<<28);
    GPIOB_MODER |= (1<<30);
    GPIOC_MODER |= (1<<18);

    GPIOC_ODR &= ~(1<<12);
    GPIOB_ODR &= ~(1<<26);
    GPIOB_ODR &= ~(1<<28);
    GPIOB_ODR &= ~(1<<30);

    for(;;)
    {
    	GPIOC_ODR ^= (1<<6);
     	for(uint32_t x=0;x<100000;x++);
    	GPIOB_ODR ^= (1<<13);
     	for(uint32_t x=0;x<200000;x++);
    	GPIOB_ODR ^= (1<<14);
     	for(uint32_t x=0;x<300000;x++);
    	GPIOB_ODR ^= (1<<15);

    	 //GPIOC_ODR ^= (1<<9);
    	for(uint32_t x=0;x<400000;x++);
    }
}
