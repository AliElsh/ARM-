#ifndef   OS_Private
#define   OS_Private

typedef struct 
{
 	void (*OS_Ptr2Task)(void);
	uint32 PRIORITY;
   	uint32 FIRST_DEALY;
	uint32 PERIODICITY;
	
}TCB_t;


#endf