/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     lcd_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Author  : Esraa
*Layer    : HAL
* SWO     : DIO/GPIO

*/
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "ErrorState.h"

#include  "DIO_interface.h"
#include  "DIO_private.h"
#include  "DIO_config.h"

#include  "lcd_interface.h"
#include  "lcd_private.h"
#include  "lcd_config.h"


void CLCD_voidInit (void)
{

 #if CLCD_MODE == 8

_delay_ms(50);

	//DIO_voidSetPortDitrection (CLCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPinDitrection  (CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT);
	DIO_voidSetPinDitrection  (CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT);
	DIO_voidSetPinDitrection  (CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT);

	CLCD_voidSendCommand(lcd_Home);

	_delay_ms(1);

	CLCD_voidSendCommand(EIGHT_BITS);
	_delay_ms(1);

	CLCD_voidSendCommand(lcd_DisPlayOn_cursorOff);
	_delay_ms(1);

	CLCD_voidClearScreen ();

	CLCD_voidSendCommand(lcd_EntryMode);
	_delay_ms(1);


	void CLCD_voidSendData(u8 copy_u8Data)
	{
      #if CLCD_MODE == 8



	    DIO_voidSetPortValue (CLCD_DATA_PORT, copy_u8Data);
	    DIO_voidSetPinValue  (CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH);
	    DIO_voidSetPinValue  (CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW);
	   // DIO_voidSendFallingEdge();


        #elif CLCD_MODE == 4
        #endif
	    _delay_ms(1);
	}

	void CLCD_voidSendCommand(u8 copy_u8Command)
		{
	      #if CLCD_MODE == 8



		    DIO_voidSetPortValue (CLCD_DATA_PORT, copy_u8Command);
		    DIO_voidSetPinValue  (CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW);
		    DIO_voidSetPinValue  (CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW);
		    DIO_voidSendFallingEdge();

	        #elif CLCD_MODE == 4


	        #endif

		    _delay_ms(1);
		}


	void CLCD_voidSendString   (u8 * copy_u8ptrString         )
	{
		u8 Local_Iterate =0 ;

		while (copy_u8ptrString[Local_Iterate]!='\0')
		{
			CLCD_voidSendData(copy_u8ptrString[Local_Iterate]);
			Local_Iterate++;
		}
	}



void CLCD_voidSetPosition (u8 copy_u8Row , u8 copy_u8Col)
{
	u8 LOC_u8data ;

	if (copy_u8Row >2 ||copy_u8Row <1|| copy_u8Col >16 || copy_u8Col <1)
	{
		LOC_u8data = lcd_SetCursor ;
	}

	else if (copy_u8Row == CLCD_ROW_1)
	{
		LOC_u8data = (lcd_SetCursor) + (copy_u8Col -1) ;
	}

	else if (copy_u8Row == CLCD_ROW_2)
		{
			LOC_u8data = (lcd_SetCursor) +(64) + (copy_u8Col -1) ;
		}
}

static void DIO_voidSendFallingEdge(void)
{
	 DIO_voidSetPinValue  (CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_HIGH);
	 _delay_ms(1);
     DIO_voidSetPinValue  (CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_LOW);
    _delay_ms(1);

}

void CLCD_voidClearScreen (void    )
{
	CLCD_voidSendCommand(lcd_clear);
	_delay_ms(10);


}




#endif
}

