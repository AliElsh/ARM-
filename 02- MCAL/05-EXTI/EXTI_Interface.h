#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum
{
	LINE0 ,
	LINE1 ,
	LINE2 ,
	LINE3 ,
	LINE4 ,
	LINE5 ,
	LINE6 ,
	LINE7 ,
	LINE8 ,
	LINE9 ,
	LINE10,
	LINE11,
	LINE12,
	LINE13,
	LINE14,
	LINE15
}EXTI_LINS_e;


typedef enum
{
	FALING_EDGE,
	RISING_EDGE,
	ON_CHANGE
}EXTI_MODES_e;

typedef enum
{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC
	
}EXTI_PORTS_e;



void EXTI_voidConfig(EXTI_LINS_e copy_Line ,EXTI_MODES_e Copy_Mode ,EXTI_PORTS_e Copy_Port);


#endif