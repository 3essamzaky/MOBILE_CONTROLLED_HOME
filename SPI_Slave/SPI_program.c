#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_interface.h"


void SPI_voidInitMstr(void)
{
   //INIT AS A MASTER
	SET_BIT(SPCR,SPCR_MSTR);
	//PRE SCALER 64
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
	//ENABLE CIRCUIT
	SET_BIT(SPCR,SPCR_SPE);

}
void SPI_voidInitSlave(void)
{
	CLR_BIT(SPCR,SPCR_MSTR);
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	SPDR=Copy_u8Data;
	while((GET_BIT(SPSR,SPSR_SPIF))==0);
	return SPDR;

}
