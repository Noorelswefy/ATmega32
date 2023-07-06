/*
 * avo.c
 *
 *  Created on: 6 Jul 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "LCD_Interface.h"

int main() {
	u8 Local_u8Readings, Local_u8DigitalValue, Local_u8Vout;

	LCD_voidInit();
	ADC_voidInit();

	while (1) {

		LCD_voidGoToXY(1, 0);

		Local_u8Readings = ADC_u16GetChannelReading(0);
		Local_u8DigitalValue = (Local_u8Readings * 5000UL) / 1023;
		Local_u8Vout = Local_u8DigitalValue / 1000UL;
		_delay_ms(500);

		LCD_voidWriteNumber(Local_u8Vout);
		LCD_voidWriteString("Volt = ");
	}
}
