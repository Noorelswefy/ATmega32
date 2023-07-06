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
	u8 customChar_head[] = { 0x00, 0x15, 0x0E, 0x04, 0x1F, 0x15, 0x1F, 0x1F };
	u8 customChar_body[] = { 0x04, 0x04, 0x15, 0x0E, 0x04, 0x04, 0x04, 0x04 };
	u8 customChar_legs[] = { 0x04, 0x04, 0x0A, 0x11, 0x00, 0x00, 0x00, 0x00 };

	u8 customChar_bed1[] = { 0x00, 0x18, 0x18, 0x1B, 0x1B, 0x18, 0x1B, 0x18 };
	u8 customChar_bed2[] = { 0x00, 0x00, 0x00, 0x09, 0x0F, 0x0F, 0x19, 0x00 };
	u8 customChar_bed3[] = { 0x00, 0x00, 0x00, 0x1E, 0x1F, 0x1F, 0x1F, 0x00 };
	u8 customChar_bed4[] = { 0x00, 0x00, 0x0C, 0x0C, 0x0C, 0x1C, 0x1C, 0x0C };
	u8 customChar_bed5[] = { 0x00, 0x00, 0x1F, 0x02, 0x04, 0x08, 0x1F, 0x00 };

	while (1) {
		ldr_reading_digital = ACD_u8GetChannelReading(0);
		ldr_reading_Analog = ldr_reading_digital * (5000UL) / 1024;
		//	LCD_voidGoToXY(0, 0);
		//	LCD_voidWriteNumber(ldr_reading_Analog);
		_delay_ms(25);
		if (ldr_reading_Analog < 400) //it is night ->turn led on // Hamoksha sleeps
				{

			LCD_voidClear();
			LCD_voidGoToXY(0, 0);
			LED_ON(LED_GREEN);
			LCD_voidWriteString("morning Hamoksha");
			LCD_voidWriteSpecialCharToCGRAM(customChar_head, 0, 0, 18);
			LCD_voidWriteSpecialCharToCGRAM(customChar_body, 1, 1, 18);
			LCD_voidWriteSpecialCharToCGRAM(customChar_legs, 2, 2, 18);

		} else {		//it is morning ->turn led off// Hamoksha wakes up
			LED_OFF(LED_GREEN);
			LCD_voidClear();
			LCD_voidGoToXY(0, 0);
			LCD_voidWriteString("nighty Hamoksha");
			LCD_voidWriteSpecialCharToCGRAM(customChar_bed1, 0, 4, 15);
			LCD_voidWriteSpecialCharToCGRAM(customChar_bed2, 1, 4, 16);
			LCD_voidWriteSpecialCharToCGRAM(customChar_bed3, 2, 4, 17);
			LCD_voidWriteSpecialCharToCGRAM(customChar_bed4, 3, 4, 18);
			LCD_voidWriteSpecialCharToCGRAM(customChar_bed5, 4, 1, 5);
		}

	}
}
