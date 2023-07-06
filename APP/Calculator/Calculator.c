/*
 * mai.c
 *
 *  Created on: 21 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "KEYPAD_interface.h"
#include "LCD_Interface.h"

u16 calc_sum(u8 a[], u8 b[], u8 n, u8 m);
u16 calc_sub(u8 a[], u8 b[], u8 n, u8 m);
u16 calc_multi(u8 a[], u8 b[], u8 n, u8 m);
u16 calc_div(u8 a[], u8 b[], u8 n, u8 m);

 u8 counter = 0;



u8 u8digitCounter = 0;
u8 u8KeypadValue = '\0';        //variable to store the pressed button for Keypad
u8 NumberOfDigit = 0;    //variable to calculate the number of digit of password

u8 Local_u8FristNum[4];
u8 Local_u8SecondNum[4];

u8 Local_u8leftDigit[4];
u8 Local_u8rightDigit[4];

u8 reset=0;
int main() {

	u8 Local_u8Operation;
	u8 counter2=counter+1;
	u8 counter3=0;



	LCD_voidInit();
	KPD_voidInit();
//	LCD_Init();					 //Initialise LCD
/*	sei();
	EXIT_Interrupts_Init(EXIT_INT0, EXIT_EDGE_RAISING);
	EXIT_Set_CallBack(EXIT_INT0, INT0_Interrupt);
*/
	LCD_voidClear();
	LCD_voidWriteString("Calculator is ready!");
	_delay_ms(200);
	LCD_voidClear();

	while(1)
	{
		u8KeypadValue = KPD_voidGetPressedKey;
		LCD_voidWriteNumber(u8KeypadValue);

		do {		//get 1st left digit

			u8KeypadValue = KPD_voidGetPressedKey;
			LCD_voidGoToXY( 3,2);
		}while(u8KeypadValue == '\0');
		if(u8KeypadValue == '+' || u8KeypadValue == '-'|| u8KeypadValue == '*'|| u8KeypadValue == '/' )
		{
			Local_u8Operation = u8KeypadValue;
			LCD_voidCharPos(u8KeypadValue , 1 , 1);
			break;
		}
		Local_u8FristNum[counter] = u8KeypadValue;
		counter ++;
		LCD_voidCharPos(u8KeypadValue , 1 ,counter);

	}
	/*    Getting The Second Number    */
	while (1)
	{
		do {
			u8KeypadValue = KPD_voidGetPressedKey;
			_delay_ms(200);
		} while (u8KeypadValue == '\0');
		if (u8KeypadValue == '=') {
			LCD_voidCharPos(u8KeypadValue, 1, counter2 + 1);
			break;
		}
		Local_u8SecondNum[counter3] = u8KeypadValue;
		counter2++;
		counter3++;
		LCD_voidNumPos(u8KeypadValue, 1, counter2);
	}
		/*     switch which operation was Selected */
		switch (Local_u8Operation) {
		{
			case '+': LCD_voidNumPos(calc_sum(Local_u8FristNum,Local_u8SecondNum,counter,counter3),1,counter2+3);break;
			case '-': LCD_voidNumPos(calc_sub(Local_u8FristNum,Local_u8SecondNum,counter,counter3),1,counter2+3);break;
			case '*': LCD_voidNumPos(calc_multi(Local_u8FristNum,Local_u8SecondNum,counter,counter3),1,+3);break;
			case '/': LCD_voidNumPos(calc_div(Local_u8FristNum,Local_u8SecondNum,counter,counter3),1,counter2+3);break;
		}

		_delay_ms(3000);
		LCD_voidClear();

	}

}

void INT0_Interrupt() {
	reset = 0;
}

u16 calc_sum(u8 a[], u8 b[], u8 n, u8 m) {
	u16 num1 = a[0];
	u16 num2 = b[0];
	for (u8 counter = 1; counter < n; counter++) {

		num1 = num1 * 10 + a[counter];
	}

	for (u8 counter = 1; counter < m; counter++) {
		num2 = num2 * 10 + b[counter];
	}

	return (num1 + num2);
}

u16 calc_sub(u8 a[], u8 b[], u8 n, u8 m) {
	u16 num1 = a[0];
	u16 num2 = b[0];
	for (u8 counter = 1; counter < n; counter++) {
		num1 = num1 * 10 + a[counter];
	}

	for (u8 counter = 1; counter < m; counter++) {
		num2 = num2 * 10 + b[counter];
	}

	return (num1 - num2);
}
u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1*num2);
}

u16 calc_div(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1/num2);
}

