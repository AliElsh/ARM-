/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description : RCC DRIVER                       */
/*   DATE        : 5 MAY 2023                      */
/*   VERSION     : V02                              */
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DET.h"

void RCC_voidInitializeSystemClock(void)
{
	#if CLOCK_SELECTION == HSE
	RCC -> CR   = 0x00010000;
    //SET_BIT(RCC -> CR, HSE_ON);	
	RCC -> CFGR = 0x00000001; 
	
	#elif CLOCK_SELECTION == HSI
	RCC -> CR   = 0x00000081;	
	RCC -> CFGR = 0x00000000;
	
	#elif CLOCK_SELECTION == HSI
	RCC -> CR   = 0x00000081;	
	RCC -> CFGR = 0x00000000;
	
	#elif CLOCK_SELECTION == PLL
	
	#else
		
	#endif
}
void RCC_voidResetPeripheral(uint8 local_busId, uint8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_AHB  : SET_BIT(RCC -> AHB1RSTR, local_peripheralId);break;
			case RCC_APB1 : SET_BIT(RCC -> APB1RSTR, local_peripheralId);break;
			case RCC_APB2 : SET_BIT(RCC -> APB2RSTR, local_peripheralId);break;
			default: Det_ReportError(DET_RCCModuleId,RCC_ResetPeripheral,RCC_InvaildBusID);
			break;
		}
	}
	else
	{
		Det_ReportError(DET_RCCModuleId,RCC_ResetPeripheral,RCC_InvaildPeripheralID);
	}
}
void RCC_voidEnablePeripheralClock(busId_E local_busId, uint8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_AHB  : SET_BIT(RCC -> AHB1ENR, local_peripheralId);break;
			case RCC_APB1 : SET_BIT(RCC -> APB1ENR, local_peripheralId);break;
			case RCC_APB2 : SET_BIT(RCC -> APB2ENR, local_peripheralId);break;
			default:Det_ReportError(DET_RCCModuleId, RCC_EnablePeripheralClock,RCC_InvaildBusID);
			break;
		}
	}
	else
	{
		Det_ReportError(DET_RCCModuleId, RCC_EnablePeripheralClock,RCC_InvaildPeripheralID);
	}
}
void RCC_voidDisablePeripheralClock(busId_E local_busId, uint8 local_peripheralId)
{
	if(local_peripheralId <= 31)
	{
		switch(local_busId)
		{
			case RCC_AHB  : CLR_BIT(RCC -> AHB1ENR, local_peripheralId);break;
			case RCC_APB1 : CLR_BIT(RCC -> APB1ENR, local_peripheralId);break;
			case RCC_APB2 : CLR_BIT(RCC -> APB2ENR, local_peripheralId);break;
			default: Det_ReportError(DET_RCCModuleId, RCC_DisablePeripheralClock,RCC_InvaildBusID);
			break;
		}
	}
	else
	{
		Det_ReportError(DET_RCCModuleId, RCC_DisablePeripheralClock,RCC_InvaildPeripheralID);
	}
}
