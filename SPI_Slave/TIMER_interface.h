#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


#define TCNT0_Register  TCNT0
#define OCR0_Register   OCR0
#define NULL (void*)0
void TIMER0_Init(void);
void TIMER0_voidSetOcrValue(u8 Copy_u8Value);
void TIMER2_Init(void);
void TIMER2_voidSetOcrValue(u8 Copy_u8Value);

void TIMER1_voidInit(void);
void TIMER1_voidSetOcrValue(u16 Copy_u16value);
void TIMER1_voidSetIcrValue(u16 Copy_u16value);







#endif
