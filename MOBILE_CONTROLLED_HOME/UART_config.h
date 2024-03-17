/*
 * UART_config.h
 *
 *  Created on: Feb 6, 2024
 *      Author: hp
 */

#ifndef MINE_MCAL_UART_UART_CONFIG_H_
#define MINE_MCAL_UART_UART_CONFIG_H_


#define SYSTEM_FREQUENCY     8000000UL
#define USART_BOUND_RATE     9600UL






/*SET SYSTEM SPEED
 * 1-USART_LOWSPEED
 * 2-USART_HIGHSPEED  (DOUBLE SPEED)
 * */

#define USART_SYSTEM_SPEED    USART_LOWSPEED



/*Set Multi-Processor Communication mode
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */

#define USART_MPCM               DISABLE



/*Set Receiver Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define USART_RECIEVER_ENABLE    ENABLE


/*Set Transmitter Enable
 * choose between
 * 1. DISABLE
 * 2. ENABLE
 */

#define USART_TRANSMITTER_ENABLE    ENABLE


/*Set USART Mode Select
 * choose between
 * 1. ASYNCHRONOUS
 * 2. SYNCHRONOUS
 */
#define USART_MODE            ASYNCHRONOUS


/*Set Parity Mode
 * choose between
 * 1. DISABLE
 * 2. EVEN_PARITY
 * 3. ODD_PARITY
 */
#define USART_PARITY_MODE   DISABLE


/*Set Stop bit
 * choose between
 * 1. STOP_BIT_1
 * 2. STOP_BIT_2
 */
#define USART_STOP_BIT    STOP_BIT_1


/*Set Data Size
 * choose between
 * 1. DATA_SIZE_5_BIT
 * 2. DATA_SIZE_6_BIT
 * 3. DATA_SIZE_7_BIT
 * 4. DATA_SIZE_8_BIT
 * 5. DATA_SIZE_9_BIT
 */
#define USART_DATA_SIZE  DATA_SIZE_8_BIT




#endif /* MINE_MCAL_UART_UART_CONFIG_H_ */
