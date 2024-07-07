#ifndef EXTI_Private_h
#define EXTI_Private_h


#define BASE_ADRESS                     0X40013C00
#define EXTI                  ((EXTI_t*)BASE_ADRESS)
typedef struct
{
	unsigned long  int IMR   ;
	unsigned long  int EMR   ;
	unsigned long  int RTSR  ;
	unsigned long  int FTSR	 ;
	unsigned long  int SWIER ;
	unsigned long  int PR    ;
	
}EXTI_t;




typedef struct
{
	unsigned long  int reserved[2] ;
	unsigned long  int EXTICR1     ;
	unsigned long  int EXTICR2     ;
	unsigned long  int EXTICR3     ;
	unsigned long  int EXTICR4     ;
}SYSCFG_t;
#define SYSCFG ((SYSCFG_t*)0x40013800)

#endif
