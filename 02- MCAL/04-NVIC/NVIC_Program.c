/****************************************************/
/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description :   NCIV                          */
/*   DATE        : 7 AGU 2023                      */
/*   VERSION     : V02                              */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.H"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_Config.h"


void NVIC_voidEnableInterrupt(NVIC_POSITION_E Copy_uint8Position)
{
	
	NVIC -> ISER[Copy_uint8Position/32]= (1<<(Copy_uint8Position%32));
	
}
void NVIC_voidDisableInterrupt(NVIC_POSITION_E copy_uint8Position)
{
	
	NVIC -> ICER[copy_uint8Position/32]= (1<<(copy_uint8Position%32));
	
}

void NVIC_voidSetPendingFlag(NVIC_POSITION_E copy_uint8Position)
{
	NVIC -> ISPR[copy_uint8Position/32]= (1<<(copy_uint8Position%32));
}
void NVIC_voidClearPendingFlag(NVIC_POSITION_E copy_uint8Position)
{
	NVIC -> ICPR[copy_uint8Position/32]= (1<<(copy_uint8Position%32));
}
uint8 NVIC_uint8GetActiveFlag (NVIC_POSITION_E copy_uint8Position)
{
	
	return GET_BIT(NVIC ->IABR [copy_uint8Position/32],(copy_uint8Position%32));
	
}
void NVIC_voidPriorityInit(void)
{
	SCB_AIRCR = PRIORITY_DISTRIBUTION;
}


void NVIC_voidSetPriority(NVIC_POSITION_E Copy_uint8Position,uint8 Copy_Priority)
{
	
	NVIC -> IPR[Copy_uint8Position] = (Copy_Priority << 4);

}













