#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "SYSTICK_interface.h"

#include "WIFI_interface.h"
#include "WIFI_private.h"
#include "WIFI_config.h"


void HESP_voidInit(void)
{
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
		MUSART_voidTransmit("AT\r\n");//         ENABLE ECHO
		Local_u8Result = validation(100000);
	}

	Local_u8Result=0;
	while(Local_u8Result==0)
	{
		u8 Local_u8CommandMode[]="AT+CWMODE=1\r\n";
		MUSART_voidTransmit(Local_u8CommandMode); // WIFI MODE Enable
		Local_u8Result = validation(10000);
	}
}
void HESP_voidConnectToNetwork(void)
{
	u8 Local_u8Result=0;
	u8 Local_u8CommandNetwork[]="AT+CWJAP_CUR=\"HUAWEI-B311-D3E4\",\"E327FDE4883\"\r\n";
	while(Local_u8Result==0)
	{
		MUSART_voidTransmit(Local_u8CommandNetwork);
		Local_u8Result = validation(100000);
	}

}
void HESP_voidConnectToServer(void)
{
	u8 Server[]="AT+CIPSTART=\"TCP\",\"162.253.155.227\",80\r\n";
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
		MUSART_voidTransmit(Server); //20ms
		Local_u8Result = validation(40000);
	}

}

u8 HESP_u8GetData(void)
{
    volatile u8 Local_u8Send=0,Localu8Get=1;
    u8 Local_u8CommondSend[]="AT+CIPSEND=38\r\n";
    u8 Local_u8CommondGet[]="GET http://ahmed777.6te.net/file.txt\r\n";

    	HESP_voidConnectToServer();

        MUSART_voidTransmit(Local_u8CommondSend);//SEND Dir Of file TO READ DATA
        Local_u8Send=validation(40000);

        MUSART_voidTransmit(Local_u8CommondGet);
        Localu8Get=validation(1000000);
        return Localu8Get;
}




u8 validation (u32 Local_u8Time)
{
	u8 Local_u8Counter=0;
	u8 Local_u8ReceivedChar=0;

	u8 Local_u8Response[100]={0};
	while(Local_u8ReceivedChar < 128)
	{
		Local_u8ReceivedChar = MUSART_u8Receive(Local_u8Time);
		Local_u8Response[Local_u8Counter] = Local_u8ReceivedChar;
		Local_u8Counter++;
	}

	for(u8 i=0; i<100; i++)
	{
		if(Local_u8Response[i] != 'S' && Local_u8Response[i+1]=='C'&&Local_u8Response[i+2]=='O')
		{
			return 1;
		}
		else if (Local_u8Response[i] == 'N' && Local_u8Response[i+1] == 'D'&& Local_u8Response[i+3] == 'O' && Local_u8Response[i+4] == 'K')
		{
			/*+IPD,1:1CLOSED*/
			return Local_u8Response [i+16];
		}
		else if(Local_u8Response[i] == 'O' && Local_u8Response[i+1] == 'K')
		{
			return 1;
		}
	}
	return 0;
}
