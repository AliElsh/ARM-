#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"

void STP_voidSendData (uint8 data)
{

	uint8 bit;
	sint8 Counter = 0;
	for(Counter=7; Counter>=0; Counter--)
	{
		bit = GET_BIT(data, Counter);
		GPIO_voidSetPinValue(STP_SERIAL_DATA, bit);
		
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK, HIGH);
		SYSTICK_voidSynchUsecondsDelay(1);
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK, LOW);
		SYSTICK_voidSynchUsecondsDelay(1);
	}
	GPIO_voidSetPinValue(STP_STORAGE_CLOCK, HIGH);
	SYSTICK_voidSynchUsecondsDelay(1);
	GPIO_voidSetPinValue(STP_STORAGE_CLOCK, LOW);
	SYSTICK_voidSynchUsecondsDelay(1);
}