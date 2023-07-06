/*
 * SS_interface.h
 *
 *  Created on: 11 Jun 2023
 *      Author: noor elswefy
 */

#ifndef SEVEN_SEGMENT_SS_INTERFACE_H_
#define SEVEN_SEGMENT_SS_INTERFACE_H_

/*COMMMON PA3,2  PB5,6*/
/*BCD input (A,B,C,D) ->  PB0 PB1 PB2 PB4 */
void SS_voidInit(void);
void SS_voidDisplayRealNumber( u8 copy_u8Number);
void SS_voidIncNumber (void);

#endif /* SEVEN_SEGMENT_SS_INTERFACE_H_ */
