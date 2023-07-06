/*
 * mai.c
 *
 *  Created on: 21 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "KEYPAD_interface.h"
#include "LCD_Interface.h"

u8 Pasword[16];						 //array to store the password when set
u8 CheckPassword[16];
u8 KpValue = 255;
u8 NumberOfDigit = 0;
u8 counter = 0;

u8 Check_Password(u8 a[], u8 b[], u8 n);

int main() {
	/* Set Password for First time */
	LCD_voidStringPos("Set password", 1, 1);
	while (1) {
		do {
			KpValue = KPD_voidGetPressedKey();
		} while (KpValue == '\0');
		NumberOfDigit++;
		if (KpValue == '&')
			break;
		LCD_voidNumPos(KpValue, 2, NumberOfDigit);
		_delay_ms(200);
		LCD_voidCharPos('*', 2, NumberOfDigit);
		Pasword[NumberOfDigit] = KpValue;
	}

	while (1) {
		/* Get Password To Check It */
		LCD_voidClear();

		_delay_ms(100);
		LCD_voidStringPos("check password", 1, 1);
		KpValue = '\0';
		counter = 0;
		while (1) {
			do {
				KpValue = KPD_voidGetPressedKey();
			} while (KpValue == '\0');
			counter++;
			if (KpValue == '&')
				break;
			LCD_voidNumPos(KpValue, 2, counter);
			_delay_ms(200);
			LCD_voidCharPos('*', 2, counter);
			CheckPassword[counter] = KpValue;
		}

		while(1)
			{

				/*    Get Password To Check It    */
				LCD_voidClear();
				_delay_ms(100);
				LCD_Send_String_Pos("check password",1,1);
				KpValue='\0';
				counter=0;
				while(KpValue != '&'){

					do{
						KpValue = KP_GetPressed();
					}while(KpValue == '\0');
					counter++;
					if(KpValue == '&') break;
					LCD_Send_Number_Pos(KpValue,2,counter);
					_delay_ms(200);
					LCD_Send_Char_Pos('*',2,counter);
					CheckPassword[counter] =KpValue;
				}

		/* Check if Password is correct or not */
		if (Check_Password(CheckPassword, Pasword, NumberOfDigit)) {
			/* Loading to Start Calculator */
			LCD_voidClear();
			LCD_voidStringPos("Loading", 1, 1);
			for (u8 counter = 0; counter < 4; counter++) {
				LCD_voidCharPos('.', 1, counter + 8);
				_delay_ms(500);
			}
			_delay_ms(200);
			LCD_voidClear();
			LCD_voidStringPos("Welcome", 1, 1);
		}
		/* This Segment if The Password is Wrong */
		else {
			LCD_voidClear();
			LCD_voidStringPos("Wrong password", 1, 1);
			_delay_ms(2000);
		}
	}
}

u8 Check_Password(u8 a[], u8 b[], u8 n) {
	u8 ret = 0;
	for (u8 counter = 0; counter < n - 1; counter++) {
		if (a[counter] == b[counter]) {
			ret++;
		}
	}
	if (ret == n - 1)
		return 1;
	else
		return 0;
}
