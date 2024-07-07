/*   AUTHOR      : ALI ELSHEIKH                     */
/*   Description : GPIO DRIVER                       */
/*   DATE        : 11 MAY 2023                      */
/*   VERSION     : V02                              */
/****************************************************/
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
pin_info configPin[pin_number]={

				{PORTA,PIN5,AF,NOT_USED,NOT_USED,FLOATING,AF5},
				{PORTA,PIN6,AF,NOT_USED,NOT_USED,FLOATING,AF5},
				{PORTA,PIN7,AF,NOT_USED,NOT_USED,FLOATING,AF5},

				{PORTA,PIN0,OUTPUT,PUSH_PULL,Medium_speed,NOT_USED,NOT_USED},
				{PORTA,PIN1,OUTPUT,PUSH_PULL,Medium_speed,NOT_USED,NOT_USED},

				{PORTA,PIN9,OUTPUT,PUSH_PULL,Medium_speed,NOT_USED,NOT_USED},




};

