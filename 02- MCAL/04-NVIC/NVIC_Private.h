/****************************************************/
/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description :   NCIV                          */
/*   DATE        : 7 AGU 2023                      */
/*   VERSION     : V02                              */
/****************************************************/
#ifndef  NVIC_Privat_H
#define NVIC_Privat_H

 typedef struct
 {
	 volatile uint32 ISER[32];
	 volatile uint32 ICER[32];
	 volatile uint32 ISPR[32];
	 volatile uint32 ICPR[32];
	 volatile uint32 IABR[64];
	 volatile uint8  IPR[84] ;
 } NVIC_t;
 
 
#define BASE_ADRESS                            0xE000E100
#define NVIC                 (( NVIC_t*)BASE_ADRESS)

#define NVIC_STIR *((uint32*)0xE000EE00)


/* 
   * REG FROM SYSTEM CONTROL BLOCK(SCB) -> TO CONTROL GOUPING 
   * IN NESTING 
   * HINT :PASSWORD FOR THIS REG -> (0x05FA0000)
*/
#define SCB_AIRCR     *((volatile uint32 *)0xE000ED0C)






#endif



