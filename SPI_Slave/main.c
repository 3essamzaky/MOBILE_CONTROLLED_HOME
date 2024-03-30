#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "ADC_interface.h"
#include "TIMER_interface.h"
#include "CLCD_interface.h"
int main()
{
	DIO_voidSetPinDir(PORTA_REG,PIN0,PIN_DIR_IN);
	DIO_voidSetPinDir(PORTA_REG,PIN1,PIN_DIR_IN);
	//DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_LOW);

	DIO_voidSetPinDir(PORTD_REG,PIN0,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTD_REG,PIN1,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTD_REG,PIN2,PIN_DIR_OUT);
	DIO_voidSetPortDir(PORTC_REG,PORT_DIR_OUT);


	DIO_voidSetPinDir(PORTB_REG,PIN5,PIN_DIR_IN);
	DIO_voidSetPinDir(PORTB_REG,PIN6,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTB_REG,PIN7,PIN_DIR_IN);
	DIO_voidSetPinDir(PORTB_REG,PIN4,PIN_DIR_IN);
	DIO_voidSetPinDir(PORTB_REG,PIN3,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTD_REG,PIN7,PIN_DIR_OUT);

	u8 reading=0,Get_u8Reading=0,temp=0;
	u16 analog1,millivolt,LDR;

	ADC_voidInit();
	CLCD_voidInit();
	SPI_voidInitSlave();
	TIMER2_Init();
	TIMER0_Init();
	u8 Local_u8Data = 0;

	while(1)
	{


		Local_u8Data = SPI_u8Tranceive(10);
		if(Local_u8Data ==1)
		{
			//CLCD_voidSendNum(reading);
			reading = ADC_u8GetChannalReading(1);
			analog1 = (reading*5)/256;
			LDR =((5*1000)-(1000*analog1))/analog1;
			//CLCD_voidSetPos(1,0);
		    //CLCD_voidSendNum(reading);

			if(LDR>400)
			{
				TIMER0_voidSetOcrValue(0);

			}
			else if(LDR <400 && LDR >200)
			{
				TIMER0_voidSetOcrValue(150);
			}
			else if(LDR <200)
			{
				TIMER0_voidSetOcrValue(255);
			}

		}
		else if(Local_u8Data==2)
		{
			Get_u8Reading=ADC_u8GetChannalReading(0);
			millivolt= ((u32)Get_u8Reading*5000UL)/256UL;
			temp = millivolt/10;
			//CLCD_voidSendNum(Get_u8Reading);
			//CLCD_voidSendNum(DIO_u8GetPinVal(PORTA_REG,PIN0));
			if(temp>40)
			{
				TIMER2_voidSetOcrValue(255);

			}
			else if(temp <40 && temp >30)
			{
				TIMER2_voidSetOcrValue(200);
			}
			else if(temp <30)
			{
				TIMER2_voidSetOcrValue(0);
			}

		}
		else if(Local_u8Data == 3)
		{
			TIMER0_voidSetOcrValue(255);

		}
		else if(Local_u8Data == 4)
		{
			TIMER0_voidSetOcrValue(0);

		}
		else if(Local_u8Data == 5)
		{
			TIMER2_voidSetOcrValue(255);

		}
		else if(Local_u8Data == 6)
		{
			TIMER2_voidSetOcrValue(0);

		}
		else
		{
			asm("NOP");
		}




	}





	return 0;
}


