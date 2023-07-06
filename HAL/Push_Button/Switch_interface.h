/*
 * Switch_interface.h
 *
 *  Created on: 16 Jun 2023
 *      Author: noor elswefy
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

/**
SW_PULLUP
SW_PULLDOWN
 */

#define SW_PULLUP	3
#define SW_PULLDOWN	2




void SWITCH_voidInit(u8 Copy_PORT_ID,u8 Copy_PIN_ID);
u8 SWITCH_u8GetPressed(u8 Copy_PORT_ID, u8 Copy_PIN_ID) ; //return 1 if pressed or 0 if released



#endif /* SWITCH_INTERFACE_H_ */
