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

#define V_IN		(5)
int main() {
	u8 Local_u8Readings, Local_u8DigitalVout ;
	u8 Local_u8R1 = 10000; /*known resistance 10kohm*/
	u8 Local_u8R2 ;		   /*Unknown resistance*/
	LCD_voidInit();
	ADC_voidInit();

	while (1) {

		LCD_voidGoToXY(1, 0);

		Local_u8Readings = ADC_u16GetChannelReading(0);
		Local_u8DigitalVout = (Local_u8Readings * 5UL) / 1023;
		/*R2 = (Vout * R1) / (Vin - Vout)*/
		Local_u8R2 = ( Local_u8R1 * Local_u8DigitalVout ) / ( V_IN - Local_u8DigitalVout);
		_delay_ms(500);

		LCD_voidWriteNumber(Local_u8R2);
		LCD_voidWriteString("R = 	");
		LCD_voidWriteString("  ohm");
	}
}
