/*
 * KEYPAD_interface.h
 *
 * Created: 6/12/2023 9:43:26 AM
 *  Author: Abdul
 */ 
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/*************************************************************************************
 *                        Argument and Return Possibilities                          *
 *************************************************************************************/


/*************************************************************************************
 *                               Public Function Prototypes                          *
 *************************************************************************************/
/*
 *  H_KPD_void_Init
 *  	-> This function shall initialize the Keypad i.e., sets all Rows as /P
 *  	   and all Columns as Pulled-up I/P.
 */

void KPD_voidInit(void);

/*
 *  H_KPD_void_GetPressedKey
 *  	-> This function shall return the value of the pressed key
 *  	   or KPD_NOT_PRESSED otherwise.
 */
u8 KPD_voidGetPressedKey(void);

#endif /* KEYPAD_INTERFACE_H_ */