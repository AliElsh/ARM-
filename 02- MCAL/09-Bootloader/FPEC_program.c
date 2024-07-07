/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description : BOOTLOADER DRIVER               */
/*   DATE        : 17 MAY 2023                      */
/*   VERSION     : V02                              */
/****************************************************/




#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "FPEC_interface.h"
#include "FPEC_Private.h"
#include "FPEC_Config.h"





void FPEC_voidFlashSectorErase(uint8 Copy_u8SSECTORNumber)
{

	/* Check that no flash memory operation is going.*/
	while (GET_BIT(FLASH->SR,16) == 1);

	// If flash is locked or not.
	if(1 == FLASH->CR.B.LOCK)
	{
		FLASH->KEYR = 0x45670123;
		FLASH->KEYR = 0xCDEF89AB;
	}

    // sector erase
	FLASH->CR.B.SER = 1;

	/* Select the sector you wash to erase.*/
	FLASH->CR.B.SNB = Copy_u8SSECTORNumber;

	/* Set start bit in CR.*/
	FLASH->CR.B.STRT = 1;
	
	
	/* Wait busy to be cleared.*/
	while (GET_BIT(FLASH->SR,16) == 1);

 	//FPEC->FLASH_CR.B.SER=0;
}
void FPEC_voidEraseAppArea(void)
{
volatile uint8 local_u8Counter;

for(local_u8Counter=1;local_u8Counter<=5;local_u8Counter++)
{
	FPEC_voidFlashSectorErase(local_u8Counter);

}
}

void FPEC_voidFlashWrite(uint32 Copy_u32Address, uint16* Copy_u16Data, uint8 Copy_u8Length)
{
	volatile uint8 local_counter;
	volatile uint16 local_temp;
	/* Check that no flash memory operation is going.*/
		while (GET_BIT(FLASH->SR,16) == 1);

		// If flash is locked or not.
		if(1 == FLASH->CR.B.LOCK)
		{
			FLASH->KEYR = 0x45670123;
			FLASH->KEYR = 0xCDEF89AB;
		}
		for(local_counter=0;local_counter<Copy_u8Length;local_counter++)
		{
          FLASH->CR.B.PG=1;
          local_temp = Copy_u16Data[local_counter];
        *((volatile uint16*)Copy_u32Address) = Copy_u16Data[local_counter];
          while(1 == GET_BIT(FLASH->SR, 16));

		}

}




