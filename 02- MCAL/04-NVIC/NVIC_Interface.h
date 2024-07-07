/****************************************************/
/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description :   NCIV                          */
/*   DATE        : 7 AGU 2023                      */
/*   VERSION     : V02                              */
/****************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
 
typedef enum
{
	
	 NVIC_WWDG=0,
	 NCIV_EXTI16PVD,
	 NCIV_EXTI21TAMP_STAMP,
	 NVIC_EXTI22RTC_WKUP,
	 NVIC_FLASH,
	 NVIC_RCC,
	 NVIC_EXTI0,
	 NVIC_EXTI1,
	 NVIC_EXTI2,
	 NVIC_EXTI3,
	 NVIC_EXTI4,
	 NVIC_DMA1_Stream0,
	 NVIC_DMA1_Stream1,
	 NVIC_DMA1_Stream2,
	 NVIC_DMA1_Stream3,
	 NVIC_DMA1_Stream4,
	 NVIC_DMA1_Stream5,
	 NVIC_DMA1_Stream6,
	 NVIC_ADC,
	 NVIC_EXTI9_5=23,
	 NVIC_TIM1_BRK_TIM9,
	 NVIC_TIM1_BRK_TIM10,
	 NVIC_TIM1_TRG_COM_TIM11,
	 NVIC_TIM1_CC,
	 NVIC_TIM2,
	 NVIC_TIM3,
	 NVIC_TIM4,
	 NVIC_I2C1_EV,
	 NVIC_I2C1_ER ,
	 NVIC_I2C2_EV,
	 NVIC_I2C2_ER,
	 NVIC_SPI1,
	 NVIC_SPI2,
	 NVIC_USART1,
	 NVIC_USART2,
	 NVIC_XTI15_10=40,
	 NVIC_EXTI17RTC_Alarm,
	 NVIC_EXTI18OTG_FS_WKUP,
	 NVIC_DMA1_Stream7=47,
	 NVIC_SDIO=49,
	 NVIC_TIM5,
	 NVIC_SPI3,
	 NVIC_DMA2_Stream0=56,
	 NVIC_DMA2_Stream1,
	 NVIC_DMA2_Stream2,
	 NVIC_DMA2_Stream3,
	 NVIC_DMA2_Stream4,
	 NVIC_OTG_FS=67,
	 NVIC_DMA2_Stream5,
	 NVIC_DMA2_Stream6,
	 NVIC_DMA2_Stream7=47,
	 NVIC_USART6,
	 NVIC_I2C3_EV,
	 NVIC_I2C3_ER,
	 NVIC_FPU=81,
	 NVIC_SPI4=84
	 
}NVIC_POSITION_E;

void NVIC_voidEnableInterrupt(NVIC_POSITION_E Copy_uint8Position);
void NVIC_voidDisableInterrupt(NVIC_POSITION_E copy_uint8Position);

void NVIC_voidSetPendingFlag(NVIC_POSITION_E copy_uint8Position);
void NVIC_voidClearPendingFlag(NVIC_POSITION_E copy_uint8Position);

uint8 NVIC_uint8GetActiveFlag (NVIC_POSITION_E copy_uint8Position);

void NVIC_voidPriorityInit(void);
void NVIC_voidSetPriority(NVIC_POSITION_E Copy_uint8Position,uint8 Copy_uint8Priority);

#endif
