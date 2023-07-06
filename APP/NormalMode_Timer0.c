/*
 * main.c
 *
 *  Created on: 18 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "GIE_interface.h"
#include "Timer0_interface.h"




void Timer0_ISR() {

	static u8 counter = 0;
	//u8 preload_value = 247;
	counter++;
	DIO_voidToggelPin(PORTA_ID, PIN4);
	if (counter == 61) {  // No. of overflow

		TCNT0 = 247;
		DIO_voidToggelPin(PORTA_ID, PIN4);
		counter = 0;
	}

}
int main() {
DIO_voidSetPinDirection(PORTA_ID, PIN4, PIN_OUTPUT);
DIO_voidSetPinValue(PORTA_ID, PIN4, PIN_LOW);


TIMER_voidSetCallBack(Timer0_ISR);
	TIMER_voidInit(3); //1024

	//Enable global interrupt
	GIE_voidEnable();
	TIMER_voidEnable();

	while (1) {

	}
}
