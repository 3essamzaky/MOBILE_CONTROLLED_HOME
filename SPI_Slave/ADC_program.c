#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_private.h"

#include "ADC_interface.h"
#include "DIO_interface.h"

void ADC_voidInit(void)
{
	//set vcc as ref voltage
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
	//set left adj result
	SET_BIT(ADMUX,ADMUX_ADLAR);
	ADCSRA &= 0b00000111;


	//ADC ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADEN);





}
u8 ADC_u8GetChannalReading(u8 Copy_u8Channal)
{
	ADMUX &=0b11100000;
	ADMUX |=Copy_u8Channal;
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0)
	{
		asm("NOP");
	}
	SET_BIT(ADCSRA,ADCSRA_ADIF);


	return ADCH;

}


