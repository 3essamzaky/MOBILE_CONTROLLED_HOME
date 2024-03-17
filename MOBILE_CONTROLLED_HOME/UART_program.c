/*
 * UART_program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: hp
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include <util/delay.h>







void USART_voidInit(void)
{
	u8 Local_u8UCSRC=0;

	/*Calculate The Baud Rate From The Equation */
	u16 Local_u8UBRR=(u16)((SYSTEM_FREQUENCY/(16*USART_BOUND_RATE))-1);

	UBRRH=(u8)(Local_u8UBRR>>8);
	UBRRL=(u8)Local_u8UBRR;





#if(USART_MODE==ASYNCHRONOUS)&&(USART_SYSTEM_SPEED==USART_LOWSPEED)
	CLR_BIT(UCSRA,UCSRA_U2X);

#elif(USART_MODE==ASYNCHRONOUS)&&(USART_SYSTEM_SPEED==USART_HIGHSPEED)
	Local_u8UBRR/=2;
	SET_BIT(UCSRA,UCSRA_U2X);

#elif(USART_MODE==SYNCHRONOUS)
	Local_u8UBRR/=8;

#else
		#error "Wrong USART_MODE or USART_SYSTEM_SPEED config"
	#endif





#if USART_MODE==ASYNCHRONOUS
	CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);

#elif USART_MODE==SYNCHRONOUS

    SET_BIT(Local_u8UCSRC,UCSRC_UMSEL);

#else
		#error "Wrong USART_MODE config"
	#endif




#if USART_PARITY_MODE==DISABLE
    CLR_BIT(Local_u8UCSRC,UCSRC_UPM1);
    CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);

#elif USART_PARITY_MODE==EVEN_PARITY

    SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
    CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);

#elif USART_PARITY_MODE==ODD_PARITY

    SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
    SET_BIT(Local_u8UCSRC,UCSRC_UPM0);
#else
		#error "Wrong USART_PARITY_MODE config"
	#endif


#if USART_DATA_SIZE==DATA_SIZE_5_BIT

    CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
    CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif USART_DATA_SIZE==DATA_SIZE_6_BIT

    SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
    CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
    CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif USART_DATA_SIZE==DATA_SIZE_7_BIT

     SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
     CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
     CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif USART_DATA_SIZE==DATA_SIZE_8_BIT

     SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
     SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
     CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif USART_DATA_SIZE==DATA_SIZE_9_BIT
     SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
     SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
     SET_BIT(UCSRB,UCSRB_UCSZ2);
#else
		#error "Wrong USART_DATA_SIZE config"
	#endif



#if USART_STOP_BIT==STOP_BIT_1

        CLR_BIT(Local_u8UCSRC,UCSRC_USBS);
#elif   USART_STOP_BIT==STOP_BIT_2
     SET_BIT(Local_u8UCSRC,UCSRC_USBS);
#else
		#error "Wrong USART_STOP_BIT config"
	#endif


     SET_BIT(Local_u8UCSRC,UCSRC_URSEL);
     UCSRC=Local_u8UCSRC;

     SET_BIT(UCSRB,UCSRB_TXEN);
     SET_BIT(UCSRB,UCSRB_RXEN);


}








void USART_voidSendByte(u8 data)
{
	while(!(GET_BIT(UCSRA,UCSRA_UDRE)));
	UDR=data;

}




u8 USART_voidRecieveByte(void)
{
	while(!(GET_BIT(UCSRA,UCSRA_RXC)));

 return UDR;
}



void USART_voidSendString(u8 *Copy_u8String)
{
	u8 i=0;
	while(Copy_u8String[i] !='\0')
	{
		USART_voidSendByte(Copy_u8String[i]);
		i++;
	}
}
void USART_voidReceiveString(u8 *Copy_u8String)
{
	u8 i=0;
	Copy_u8String[i]=USART_voidRecieveByte();

	while(Copy_u8String[i] !=' ')
	{
		i++;
		Copy_u8String[i]=USART_voidRecieveByte();


	}
	Copy_u8String[i]='\0';


}
//u8 Compare_string(u8 *str,u8 *str2)
//{
//
//   u8 count=0;
//   u8 flag=1;
//   while(str2[count]!='\0')
//   {
//	  if(str[count]==str2[count])
//	  {
//		  flag=1;
//	  }
//	  else
//	  {
//		  flag=0;
//		  break;
//	  }
//
//	  count++;
//
//
//   }
//   return flag;
//
//}
u8 Compare_string(u8 *str1,u8 *str2)
{

   u8 i=0;
   u8 flag=1;
   while(str2[i]!='\0')
   {
	  if(str1[i]==str2[i])
	  {
		  flag=1;
	  }
	  else
	  {
		  flag=0;
		  break;
	  }

	  i++;
   }
   return flag;

}

//u16 UART_u16Receive()
//{
//    // Wait for data to be received
//    while(GET_BIT(UCSRA,UCSRA_RXC) ==0);
//
//    // Get and return received data from buffer
//    return (((u16)UDR) << 8) | (u16)UDR;
//}


