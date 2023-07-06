/*
 * main.c
 *
 *  Created on: 19 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "Timer1_interface.h"
#include "DIO_Interface.h"

int main() {
	Timer1_voidInit();
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_OUTPUT);

	while (1) {
		Timer1_voidSetCompChA(750);
		_delay_ms(1000);
		Timer1_voidSetCompChA(2000);
		_delay_ms(1000);

	}
}
