/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description : BOOTLOADER DRIVER               */
/*   DATE        : 17 MAY 2023                      */
/*   VERSION     : V02                              */
/****************************************************/


#ifndef FPEC_Interface_h
#define FPEC_Interface_h



/*  
To erase a sector, follow the procedure below:
1. Check that no Flash memory operation is ongoing by checking the BSY bit in the
FLASH_SR register
2. Set the SER bit and select the sector out of the 5 sectors (for STM32F401xB/C) and
out of 7 (for STM32F401xD/E) in the main memory block you wish to erase (SNB) in
the FLASH_CR register
3. Set the STRT bit in the FLASH_CR register
4. Wait for the BSY bit to be cleared



----------------------------------------------------------------------
To perform Mass Erase, the following sequence is recommended:
1. Check that no Flash memory operation is ongoing by checking the BSY bit in the
FLASH_SR register
2. Set the MER bit in the FLASH_CR register
3. Set the STRT bit in the FLASH_CR register
4. Wait for the BSY bit to be cleared
Note: If MERx and SER bits are both set in the FLASH_CR register, mass erase is performed.
If both MERx and SER bits are reset and the STRT bit is set, an unpredictable behavior may
occur without generating any error flag. This condition should be forbidden.
---------------------------------------------------------------------
The Flash memory programming sequence is as follows:
1. Check that no main Flash memory operation is ongoing by checking the BSY bit in the
FLASH_SR register.
2. Set the PG bit in the FLASH_CR register
3. Perform the data write operation(s) to the desired memory address (inside main
memory block or OTP area):
– Byte access in case of x8 parallelism
– Half-word access in case of x16 parallelism
– Word access in case of x32 parallelism
– Double word access in case of x64 parallelism
4. Wait for the BSY bit to be cleared.
Note: Successive write operations are possible without the need of an erase operation when
changing bits from ‘1’ to ‘0’. Writing ‘1’ requires a Flash memory erase operation.
If an erase and a program operation are requested simultaneously, the erase operation is
performed first.










*/


void FPEC_voidEraseAppArea(void);


void FPEC_voidFlashSectorErase(uint8 Copy_u8PageNumber);
void FPEC_voidFlashWrite(uint32 Copy_u32Address, uint16* Copy_u16Data, uint8 Copy_u8Length);






#endif
