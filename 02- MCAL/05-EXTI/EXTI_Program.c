#include "STD_TYPES.H"
#include "BIT_MATH.H"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "Det.h"

#define NULL (void*)0
void (*EXTI_globalCallBack) (void) = NULL;

void EXTI_voidConfig(EXTI_LINS_e copy_Line ,EXTI_MODES_e Copy_Mode ,EXTI_PORTS_e Copy_Port)
{
	SET_BIT(EXTI -> IMR, copy_Line);
	switch (Copy_Mode)
	{
		case FALING_EDGE: SET_BIT(EXTI->FTSR,copy_Line);break;
		case RISING_EDGE: SET_BIT(EXTI->RTSR,copy_Line);break;
		case ON_CHANGE  : SET_BIT(EXTI->FTSR,copy_Line);
		                  SET_BIT(EXTI->RTSR,copy_Line);break;
	//	default:Det_ReportError(DET_EXTIModule_ID ,EXTI_Config,EXTI_InvaildModeID);break;
	}
	
	switch(Copy_Port)
	{
		case EXTI_PORTA:
		        switch(copy_Line)
				{
					case LINE0: 
					case LINE1: 
					case LINE2: 
					case LINE3: SYSCFG->EXTICR1 &=~(0b1111)<<(copy_Line*4);break;
					
					case LINE4: 
					case LINE5: 
					case LINE6: 
					case LINE7: SYSCFG->EXTICR2 &=~(0b1111)<<((copy_Line-4)*4);break;
					
					case LINE8: 
					case LINE9: 
					case LINE10: 
					case LINE11: SYSCFG->EXTICR3 &=~(0b1111)<<((copy_Line-8)*4);break;
					
					case LINE12: 
					case LINE13: 
					case LINE14: 
					case LINE15: SYSCFG->EXTICR4 &=~(0b1111)<<((copy_Line-12)*4);break;

				}break;
		
		case EXTI_PORTB:
		
		        switch(copy_Line)
		        {
					case LINE0: 
					case LINE1: 
					case LINE2: 
					case LINE3: SYSCFG->EXTICR1 |=(1)<<(copy_Line*4);break;
					
					case LINE4: 
					case LINE5: 
					case LINE6: 
					case LINE7: SYSCFG->EXTICR2 |=(1)<<((copy_Line-4)*4);break;
					
					case LINE8: 
					case LINE9: 
					case LINE10: 
					case LINE11: SYSCFG->EXTICR3 |=(1)<<((copy_Line-8)*4);break;
					
					case LINE12: 
					case LINE13: 
					case LINE14: 
					case LINE15: SYSCFG->EXTICR4 |=(1)<<((copy_Line-8)*4);break;
	}break;
		case EXTI_PORTC:
		
		        switch(copy_Line)
				{
					case LINE0: 
					case LINE1: 
					case LINE2: 
					case LINE3: SYSCFG->EXTICR1 |=(2)<<(copy_Line*4);break;
					
					case LINE4: 
					case LINE5: 
					case LINE6: 
					case LINE7: SYSCFG->EXTICR2 |=(2)<<((copy_Line-4)*4);break;
					
					case LINE8: 
					case LINE9: 
					case LINE10: 
					case LINE11: SYSCFG->EXTICR3 |=(2)<<((copy_Line-8)*4);break;
					
					case LINE12: 
					case LINE13: 
					case LINE14: 
					case LINE15: SYSCFG->EXTICR4 |=(2)<<((copy_Line-8)*4);break;
		         }		 
		
	    
}
}
void EXTI_voidCallBack(void (*callBackPtr) (void))
{
	EXTI_globalCallBack = callBackPtr;
}

void EXTI0_IRQHandler(void)
{
	EXTI_globalCallBack();
	EXTI -> PR = 1;
}
