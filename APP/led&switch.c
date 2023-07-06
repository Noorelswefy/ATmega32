/*
 * main.c
 *
 *  Created on: 21 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "LED_interface.h"

#include "HAL/Push_Button/Switch_interface.h"



void main()
{
	///SWITCH_voidInit(PORTC_ID,PIN5);

	while(1){


		if(SWITCH_u8GetPressed(PORTC_ID, PIN5) == 0)

		LED_TOGGLE(LED_BLUE);

	}
}
