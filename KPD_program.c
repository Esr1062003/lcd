/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Author  : Esraa
*Layer    : HAL
* SWC     : KPD

*/
#include <util/delay.h>

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "ErrorState.h"


#include  "DIO_interface.h"

#include  "KPD_config.h"
#include  "KPD_private.h"



void KPD_init(void)
{
	DIO_enumConnectPullup   (KPD_PORT , KPD_R0 , DIO_PIN_HIGH);
	DIO_enumConnectPullup   (KPD_PORT , KPD_R1 , DIO_PIN_HIGH);
	DIO_enumConnectPullup   (KPD_PORT , KPD_R2 , DIO_PIN_HIGH);
	DIO_enumConnectPullup   (KPD_PORT , KPD_R3 , DIO_PIN_HIGH);


	DIO_voidSetPinDitrection (KPD_PORT , KPD_C0 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDitrection (KPD_PORT , KPD_C1 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDitrection (KPD_PORT , KPD_C2 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDitrection (KPD_PORT , KPD_C3 , DIO_PIN_OUTPUT);

	DIO_voidSetPinValue     (KPD_PORT , KPD_C0 , DIO_PIN_HIGH);
	DIO_voidSetPinValue     (KPD_PORT , KPD_C1 , DIO_PIN_HIGH);
	DIO_voidSetPinValue     (KPD_PORT , KPD_C2 , DIO_PIN_HIGH);
	DIO_voidSetPinValue     (KPD_PORT , KPD_C3 , DIO_PIN_HIGH);


}

u8 KPD_u8GetPressed (void)
{
	u8 Loc_u8ReturnData = NOTPRRESSED ;
	u8 Loc_u8GetPressed ;

	u8 Loc_u8Row ;
	u8 Loc_u8Col ;

	for (Loc_u8Col= 0 + KPD_COL_INIT ; Loc_u8Col < KPD_COL_END +1 ;Loc_u8Col++ )

	{
		DIO_voidSetPinValue ( KPD_PORT ,Loc_u8Col , DIO_PIN_LOW);

		for (Loc_u8Row = 0 + KPD_ROW_INIT ; Loc_u8Row < KPD_ROW_END +1 ;Loc_u8Row++ )
		{
			DIO_voidGetPinValue (KPD_PORT ,Loc_u8Row , & Loc_u8GetPressed );

			if (Loc_u8GetPressed == 0)
			{

				_delay_ms(50);

				DIO_voidGetPinValue     (KPD_PORT ,Loc_u8Row , Loc_u8GetPressed );
				if (Loc_u8GetPressed == 0)
				{
					Loc_u8ReturnData =KPD_u8Buttons[Loc_u8Row - KPD_ROW_INIT][Loc_u8Col - KPD_COL_INIT];


				}
				DIO_voidGetPinValue (KPD_PORT ,Loc_u8Row , & Loc_u8GetPressed );
				{
					while (DIO_PIN_LOW ==  Loc_u8GetPressed)

					DIO_voidGetPinValue (KPD_PORT ,Loc_u8Row , & Loc_u8GetPressed );
				}
				break;



			}
		}

		DIO_voidSetPinValue(KPD_PORT, Loc_u8Col , DIO_PIN_HIGH);

	}



return Loc_u8ReturnData;
}
