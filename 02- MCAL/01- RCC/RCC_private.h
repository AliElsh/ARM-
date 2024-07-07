/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description : RCC DRIVER                       */
/*   DATE        : 5 MAY 2023                      */
/*   VERSION     : V02                              */
/****************************************************/


#ifndef RCC_PRIVATE
#define RCC_PRIVATE


#define RCC_BASE_ADDRESS 0x40023800 
typedef struct
{
	uint32 CR;
	uint32 PLLCFGR;
	uint32 CFGR;
	uint32 CIR;
	uint32 AHB1RSTR;
	uint32 AHB2RSTR;
	uint32 RESERVED2;
	uint32 RESERVED3;
	uint32 APB1RSTR;
	uint32 APB2RSTR;
	uint32 RESERVED0;
	uint32 RESERVED1;
	uint32 AHB1ENR;
	uint32 AHB2ENR;
	uint32 RESERVED4;
	uint32 RESERVED5;
	uint32 APB1ENR;
	uint32 APB2ENR;
}RCC_type;

#define RCC  ((RCC_type *)RCC_BASE_ADDRESS)



#define 	        HSI   0
#define     	    HSE   1
#define 	        PLL   2
/*AHB peripheral IDs*/
#define     GPIOA       0
#define	    GPIOB       1
#define	    GPIOC       2
#define	    GPIOH       7
#define	    DMA1        21
#define  	DMA2        22
#define  	CRCRST      12
/*APB1 peripheral IDs*/
#define        TIM2    0
#define        TIM3    1
#define        TIM4    2
#define        TIM5    3
#define        WWDG    1
#define        SPI2    14
#define        SPI3    15
#define        TIM5    3
#define        USART2  17
#define        I2C1    21
#define        I2C2    22
#define        I2C3    23
#define        PWR     28
/*APB2 peripheral IDs*/
#define        TIM1       0
#define        USART1     4
#define        USART6     5
#define        ADC1       8
#define        SDIO      11
#define        SPI1      12
#define        SPI4      13
#define        SYSCFG    14
#define        TIM9      16
#define        TIM10     17
#define        TIM11     18





#endif
