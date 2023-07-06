/*
 * main.c
 *
 *  Created on: 21 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SS_interface.h"
//#include "KEYPAD_interface.h"
#include "HKEYPAD_int.h"
int main()
{
	u8 key;
	s8 counter = 0;

	KPD_voidInit();

	SS_voidInit();

	while (1)
	{
		key = HKEYPAD_enGetPressedKey2();

		if (key == 1) // increment
		{
			counter++;
			SS_voidDisplayRealNumber(counter);
		}
		 if (key == 2) // decrement
		{
			counter--;
			SS_voidDisplayRealNumber(counter);
		}
	}

	return 0;
}
