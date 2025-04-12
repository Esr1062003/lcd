/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   KPD_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* Author  : Esraa
*Layer    : HAL
* SWC     : KPD

*/

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define NOTPRRESSED 0xff

void KPD_init(void);
u8 KPD_u8GetPressed (void);
//u8 KPD_u8Buttons[4][4];
#endif
