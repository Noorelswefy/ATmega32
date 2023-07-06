/*
 * main.c
 *
 *  Created on: 22 Jun 2023
 *      Author: noor elswefy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LM35_interface.h"

int main() {

	DIO_voidSetPortDirection(PORTA_ID, ALL_PORT_INPUT);

	u16 adc_value = 0;
	u16 temp = 0;

	ACD_voidInit();
	LCD_voidInit();

	LCD_voidClear();
	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_voidWriteString("Temp =    C");

	while (1) {
		adc_value = ACD_u8GetChannelReading(1);
		temp = LM35_getTemperature(adc_value);

		LCD_voidWriteNumber(temp);

		LCD_voidWriteData(' ');

	}
}

