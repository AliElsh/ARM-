/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description : RCC DRIVER                       */
/*   DATE        : 5 MAY 2023                      */
/*   VERSION     : V02                              */
/****************************************************/



#ifndef RCC_INTERFACE
#define RCC_INTERFACE


// FUNCTION IDS
/*
typedef enum
{
 RCC_voidInitializeSystemClock,
 RCC_voidResetPeripheral,
 RCC_voidEnablePeripheralClock,
 RCC_voidDisablePeripheralClock	
	
	
	
}RCC_FunctionID_E;


typedef enum
{
RCC_InvaildBusID,
RCC_InvaildPeripheralID
	
	
}RCC_ERORID_E





*/

typedef enum
{
	RCC_AHB ,
	RCC_APB1,
	RCC_APB2
}busId_E;




void RCC_voidInitializeSystemClock(void);
void RCC_voidResetPeripheral(uint8 local_busId, uint8 local_peripheralId);
void RCC_voidEnablePeripheralClock(busId_E local_busId, uint8 local_peripheralId);
void RCC_voidDisablePeripheralClock(busId_E local_busId, uint8 local_peripheralId);

#endif
