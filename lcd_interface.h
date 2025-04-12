/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     lcd_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Author  : Esraa
*Layer    : HAL
* SWO     : DIO/GPIO

*/

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_
/**************************************************************************/
#if CLCD_MODE == 4
#define FOUR_BITS  0x28

#else if CLCD_MODE == 8
#define EIGHT_BITS  0x38

#endif
/**************************************************************************/

#define lcd_DisPlayOn_cursorOff      0x0c
#define lcd_DisPlayOn_cursorOn       0x0e
#define lcd_DisPlayOff_cursorOff     0x08

#define lcd_clear                    0x01
#define lcd_EntryMode                0x06
#define lcd_Home                     0x02
#define lcd_DGRAM                    0x40
#define lcd_SetCursor                0x80
#define lcd_FunctionReset            0x30


/**************************************************************************/

/**************************************************************************/

#define CLCD_ROW_1  1
#define CLCD_ROW_2  2

#define CLCD_COL_1  1
#define CLCD_COL_2  2
#define CLCD_COL_3  3
#define CLCD_COL_4  4
#define CLCD_COL_5  5
#define CLCD_COL_6  6
#define CLCD_COL_7  7
#define CLCD_COL_8  8
#define CLCD_COL_9  9
#define CLCD_COL_10 10
#define CLCD_COL_11 11
#define CLCD_COL_12 12
#define CLCD_COL_13 13
#define CLCD_COL_14 14
#define CLCD_COL_15 15
#define CLCD_COL_16 16


typedef struct
{
	u8 RS;

	u8 EN;

}LCD_8bit;

/**************************************************************************/
void CLCD_voidInit         (void                          );
void CLCD_voidSendData     (u8 copy_u8Data                );
void CLCD_voidSendCommand  (u8 copy_u8Command             );
void CLCD_voidSetPosition  (u8 copy_u8Row , u8 copy_u8Col );
void CLCD_voidClearScreen  (void                          );
void CLCD_voidSendString   (u8 * copy_u8ptrString         );
void LCD_Print_String      (LCD_8bit *lcd , u8 *Data      );

#endif
