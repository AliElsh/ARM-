/****************************************************/
/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description :DET.H                            */
/*   DATE        : 7 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/


#ifndef DET
#define DET


typedef enum
{
	DET_RCCModuleId,
	DET_GPIOModuleId, 
	DET_SYSTICKModuleID,
	DET_STPModuleID,
	DET_EXTIModule_ID
}DET_moduleId_E;

typedef enum
{
RCC_ResetPeripheral,
RCC_InitializeSystemClock,
RCC_EnablePeripheralClock,
RCC_DisablePeripheralClock,
GPIO_SetPinsMode,
GPIO_SetPinValue,
GPIO_GetPinValue,
EXTI_Config
 
}DET_FunctionID_E;


typedef enum
{
RCC_InvaildBusID,
RCC_InvaildPeripheralID,
GPIO_InvaildPortID,
GPIO_PIN_Value_PORTA,
GPIO_PIN_Value_PORTB,
GPIO_PIN_Value_PORTC,
EXTI_InvaildModeID

}DET_ERORID_E;


void Det_ReportError (
		DET_moduleId_E moduleId,
		DET_FunctionID_E functionId,
		DET_ERORID_E errorId);


#endif
