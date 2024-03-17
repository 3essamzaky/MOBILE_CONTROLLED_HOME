/*
 * UART_interface.h
 *
 *  Created on: Feb 6, 2024
 *      Author: hp
 */

#ifndef MINE_MCAL_UART_UART_INTERFACE_H_
#define MINE_MCAL_UART_UART_INTERFACE_H_


void USART_voidInit(void);

void USART_voidSendByte(u8 data);
void USART_voidSendString(u8 *Copy_u8String);

u8 USART_voidRecieveByte(void);
void USART_voidReceiveString(u8 *Copy_u8String);

u8 Compare_string(u8 *str1,u8 *str2);





#endif /* MINE_MCAL_UART_UART_INTERFACE_H_ */
