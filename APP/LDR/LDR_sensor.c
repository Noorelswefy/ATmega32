/*
 * main.c
 *
 *  Created on: 21 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "LCD_Interface.h"
#include "LED_interface.h"

int main() {
	u16 ldr_reading_digital = 0;
	u16 ldr_reading_Analog = 0;
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	ACD_voidInit();
	LCD_voidInit();

	while (1) {
		ldr_reading_digital = ACD_u8GetChannelReading(0);
		ldr_reading_Analog = ldr_reading_digital * (5000UL) / 1024;
		LCD_voidGoToXY(0, 0);
		LCD_voidWriteNumber(ldr_reading_Analog);
		_delay_ms(500);


	}
}
