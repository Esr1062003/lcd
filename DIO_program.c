/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     DIO_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Author  : Esraa
*Layer    : MCAL
* SWO     : DIO/GPIO

*/ 

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "ErrorState.h"

#include  "DIO_interface.h"
#include  "DIO_private.h"


u8 DIO_voidSetPinDitrection (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Direction)
{
   if (Copy_u8Direction == DIO_PIN_OUTPUT)
   {
        switch (Copy_u8PORT)
        {
         case DIO_PORTA : SET_BIT(DDRA,Copy_u8PIN);break;
         case DIO_PORTB : SET_BIT(DDRB,Copy_u8PIN);break;
         case DIO_PORTC : SET_BIT(DDRC,Copy_u8PIN);break;
         case DIO_PORTD : SET_BIT(DDRD,Copy_u8PIN);break;
         }
         
        }

   else if (Copy_u8Direction == DIO_PIN_INPUT)
   {
         switch (Copy_u8PORT)
        {
         case DIO_PORTA : CLR_BIT(DDRA,Copy_u8PIN);break;
         case DIO_PORTB : CLR_BIT(DDRB,Copy_u8PIN);break;
         case DIO_PORTC : CLR_BIT(DDRC,Copy_u8PIN);break;
         case DIO_PORTD : CLR_BIT(DDRD,Copy_u8PIN);break;
         }


   }
}

u8 DIO_voidSetPinValue      (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value     )
{

   if (Copy_u8Value == DIO_PIN_HIGH)
   {
        switch (Copy_u8PORT)
        {
         case DIO_PORTA : SET_BIT(PORTA,Copy_u8PIN);break;
         case DIO_PORTB : SET_BIT(PORTB,Copy_u8PIN);break;
         case DIO_PORTC : SET_BIT(PORTC,Copy_u8PIN);break;
         case DIO_PORTD : SET_BIT(PORTD,Copy_u8PIN);break;
         }
         

   }
   else if (Copy_u8Value == DIO_PIN_LOW)
   {
         switch (Copy_u8PORT)
        {
         case DIO_PORTA : CLR_BIT(PORTA,Copy_u8PIN);break;
         case DIO_PORTB : CLR_BIT(PORTB,Copy_u8PIN);break;
         case DIO_PORTC : CLR_BIT(PORTC,Copy_u8PIN);break;
         case DIO_PORTD : CLR_BIT(PORTD,Copy_u8PIN);break;
         }


   }
 
}

u8 DIO_voidGetPinValue      (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 *Copy_u8Value   )
{
   u8 LOC_u8Status=0;

   if (Copy_u8PIN<= 7)
   {
	   if (Copy_u8PORT <= 3)

	   {
		   switch (Copy_u8PORT)
		          {
		           case DIO_PORTA : *Copy_u8Value= GET_BIT(PINA,Copy_u8PIN);break;
		           case DIO_PORTB : *Copy_u8Value= GET_BIT(PINB,Copy_u8PIN);break;
		           case DIO_PORTC  :*Copy_u8Value= GET_BIT(PINC,Copy_u8PIN);break;
		           case DIO_PORTD : *Copy_u8Value= GET_BIT(PIND,Copy_u8PIN);break;
		           }
		   LOC_u8Status=1;
	   }
   }


  return LOC_u8Status ;

}

u8 DIO_enumConnectPullup   (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8ConnectPullUp)
{
	//DIO_ErrorStatus LOC_enumstate = DIO_OK ;

}

