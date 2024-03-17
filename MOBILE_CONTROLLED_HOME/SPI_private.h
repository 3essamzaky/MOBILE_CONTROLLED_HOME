#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_





#define   SPDR           *((volatile u8*)0X2F)



#define   SPSR            *((volatile u8*)0X2E)
#define   SPSR_SPIF         7
 #define   SPSR_SPI2X      0



#define   SPCR            *((volatile u8*)0X2D)
#define   SPCR_SPE              6
#define   SPCR_MSTR            4
#define   SPCR_SPR0            0
#define   SPCR_SPR1            1





#endif