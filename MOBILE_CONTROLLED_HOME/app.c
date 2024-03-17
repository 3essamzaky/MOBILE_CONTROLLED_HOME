#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "TIMER_interface.h"
#include "SPI_interface.h"
#include <util/delay.h>


/*founctions declaretion*/
void Alarm(void);
void func(u8 *PTR);

typedef struct{
	u8 username[10];
	u8 password[10];
}LOGG_t;


LOGG_t user_arr[10] = {{"ABDO","1111"},
		{"HANY","2222"},
		{"BEBO","3333"},
		{"HODA","4444"},
		{"EYAD","5555"},
		{"YOUSEF","6666"},
		{"AOUF","7777"},
		{"ASEM","8888"},
		{"ZAKY","9999"},
		{"AHMED","1122"}};

u8 static flag = 0;

void main(void)
{
	/*Direction*/
	DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
	DIO_voidSetPortDir(PORTC_REG,PORT_DIR_OUT);

	DIO_voidSetPinDir(PORTD_REG,PIN7,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTD_REG,PIN5,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTD_REG,PIN0,PIN_DIR_IN);
	DIO_voidSetPinDir(PORTD_REG,PIN1,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTB_REG,PIN3,PIN_DIR_OUT);

	/*select master output*/
	DIO_voidSetPinDir(PORTB_REG,PIN5,PIN_DIR_OUT);
	/**/
	DIO_voidSetPinDir(PORTB_REG,PIN4,PIN_DIR_OUT);
	DIO_voidSetPinVal(PORTB_REG,PIN4,PIN_VAL_LOW);
	DIO_voidSetPinDir(PORTB_REG,PIN6,PIN_DIR_IN);
	/*CS*/
	DIO_voidSetPinDir(PORTB_REG,PIN7,PIN_DIR_OUT);



	/*Initial*/
	CLCD_voidInit();
	USART_voidInit();
	TIMER1_voidInit();
	TIMER1_voidSetIcrValue(20000);
	SPI_voidInitMstr();

	/*local variables*/
	u8 user_name[10];

	while(1)
	{
		user_name[10];

		CLCD_voidSetClear();
		CLCD_voidSendString("Ente username");

		USART_voidSendString("Enter The User Name\r\n");
		_delay_ms(100);

		USART_voidReceiveString(user_name);
		_delay_ms(100);



		if(Compare_string(user_name,user_arr[0].username))
		{

			func(user_arr[0].password);

		}

		else if(Compare_string(user_name,user_arr[1].username))
		{

			func(user_arr[1].password);

		}
		else if(Compare_string(user_name,user_arr[2].username))
		{

			func(user_arr[2].password);

		}
		else if(Compare_string(user_name,user_arr[3].username))
		{

			func(user_arr[3].password);

		}
		else if(Compare_string(user_name,user_arr[4].username))
		{

			func(user_arr[4].password);

		}
		else if(Compare_string(user_name,user_arr[5].username))
		{

			func(user_arr[5].password);

		}
		else if(Compare_string(user_name,user_arr[6].username))
		{

			func(user_arr[6].password);

		}

		else if(Compare_string(user_name,user_arr[7].username))
		{

			func(user_arr[7].password);

		}
		else if(Compare_string(user_name,user_arr[8].username))
		{

			func(user_arr[8].password);

		}
		else if(Compare_string(user_name,user_arr[9].username))
		{

			func(user_arr[9].password);

		}
		else
		{
			USART_voidSendString("\r\nusername not found\r\n");
			_delay_ms(500);

		}


	}

}

void func(u8 *PTR)
{
	u8 copy_u8tries = 3;
	u8 pass[10];

	while(copy_u8tries)
	{
		CLCD_voidSetClear();

		CLCD_voidSendString("Enter Passward");
		CLCD_voidSetPos(1,0);
		CLCD_voidSendString("tries :");
		CLCD_voidSetPos(1,6);
		CLCD_voidSendNum(copy_u8tries);

		USART_voidSendString("\r\nEnter Your Passward\r\n");
		_delay_ms(100);

		USART_voidReceiveString(pass);



		if(Compare_string(pass,PTR))
		{
			flag = 1;

			CLCD_voidSetClear();
			CLCD_voidSendString("welcome");
			USART_voidSendString("\r\nwelcome\r\n");
			break;



		}
		else
		{


			copy_u8tries--;
			if(copy_u8tries == 0)
			{
				CLCD_voidSetClear();
				CLCD_voidSendString("ALARM");
				while(1)
				{
					Alarm();

				}
			}
			else
			{
				CLCD_voidSetClear();
				CLCD_voidSendString("wrong password");

			}

			_delay_ms(500);


		}

	}
	while(flag)
	{

		u8 Local_u8choise =0;
		u8 Local_u8Data = 0;
		USART_voidSendString("\r\nchoose:\r\n");
		USART_voidSendString("1 for open the door");
		USART_voidSendString("\r\n");

		USART_voidSendString("2 for close the door");
		USART_voidSendString("\r\n");

		USART_voidSendString("3 for open the light");
		USART_voidSendString("\r\n");

		USART_voidSendString("4 for close the light");
		USART_voidSendString("\r\n");

		USART_voidSendString("5 for open the fan");
		USART_voidSendString("\r\n");

		USART_voidSendString("6 for close the fan");
		USART_voidSendString("\r\n");

		USART_voidSendString("7 for adjust brightness");
		USART_voidSendString("\r\n");

		USART_voidSendString("8 for adjust fan speed");
		USART_voidSendString("\r\n");

		CLCD_voidSetClear();
		CLCD_voidSendString("choose:1or2or3");
		CLCD_voidSetPos(1,0);
		CLCD_voidSendString("4or5or6or7or8");
		Local_u8choise = USART_voidRecieveByte();
		if(Local_u8choise == '1' )
		{
			CLCD_voidSetClear();
			CLCD_voidSendString("The door opened");
			for(u16 j= 750;j<1500;j++)
			{


				TIMER1_voidSetOcrValue(j);
				_delay_ms(1);
			}


		}
		else if(Local_u8choise =='2' )
		{
			CLCD_voidSetClear();
			CLCD_voidSendString("The door closed");
			for(u16 j= 1500;j>750;j--)
			{


				TIMER1_voidSetOcrValue(j);
				_delay_ms(1);
			}

		}
		else if(Local_u8choise == '3' )
		{
			CLCD_voidSetClear();
			CLCD_voidSendString("The light opened");
			DIO_voidSetPinVal(PORTC_REG,PIN6,PIN_VAL_HIGH);
			DIO_voidSetPinVal(PORTC_REG,PIN7,PIN_VAL_HIGH);

		}
		else if(Local_u8choise == '4' )
		{
			CLCD_voidSetClear();
			CLCD_voidSendString("The light closed");
			DIO_voidSetPinVal(PORTC_REG,PIN6,PIN_VAL_LOW);
			DIO_voidSetPinVal(PORTC_REG,PIN7,PIN_VAL_LOW);

		}
		else if(Local_u8choise == '5')
		{
			CLCD_voidSetClear();
			CLCD_voidSendString("The fan opened");
			DIO_voidSetPinVal(PORTC_REG,PIN4,PIN_VAL_HIGH);


		}
		else if(Local_u8choise == '6')
		{
			CLCD_voidSetClear();
			CLCD_voidSendString("The fan closed");
			DIO_voidSetPinVal(PORTC_REG,PIN4,PIN_VAL_LOW);

		}
		else if(Local_u8choise == '7')
		{

			SPI_u8Tranceive(1);


		}
		else if(Local_u8choise == '8')
		{

			SPI_u8Tranceive(2);

		}
		else
		{
			CLCD_voidSetClear();
			CLCD_voidSendString("Wrong choise !!");
			_delay_ms(2000);

		}

	}

}
void Alarm(void)
{
	DIO_voidSetPinVal(PORTC_REG,PIN5,PIN_VAL_HIGH);
	DIO_voidSetPinVal(PORTC_REG,PIN3,PIN_VAL_HIGH);
	_delay_ms(200);
	DIO_voidSetPinVal(PORTC_REG,PIN5,PIN_VAL_LOW);
	DIO_voidSetPinVal(PORTC_REG,PIN3,PIN_VAL_LOW);

	_delay_ms(200);
	DIO_voidSetPinVal(PORTC_REG,PIN5,PIN_VAL_HIGH);
	DIO_voidSetPinVal(PORTC_REG,PIN3,PIN_VAL_HIGH);

	_delay_ms(200);
	DIO_voidSetPinVal(PORTC_REG,PIN5,PIN_VAL_LOW);
	DIO_voidSetPinVal(PORTC_REG,PIN3,PIN_VAL_LOW);

	_delay_ms(200);
	DIO_voidSetPinVal(PORTC_REG,PIN5,PIN_VAL_HIGH);
	DIO_voidSetPinVal(PORTC_REG,PIN3,PIN_VAL_HIGH);

	_delay_ms(500);
	DIO_voidSetPinVal(PORTC_REG,PIN5,PIN_VAL_LOW);
	DIO_voidSetPinVal(PORTC_REG,PIN3,PIN_VAL_LOW);

	_delay_ms(200);

}
