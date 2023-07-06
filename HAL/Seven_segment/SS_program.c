/*
 * SS_program.c
 *
 *  Created on: 11 Jun 2023
 *      Author: noor elswefy
 */
#include <avr/delay.h>
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "DIO_Interface.h"
#include  "SS_config.h"
//#include  "SS_private.h"
#include  "SS_interface.h"

void SS_voidInit(void) {

//OUTPUT DIRECTION A,B,C,D
	DIO_voidSetPinDirection(PORTB_ID, PIN0, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN1, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN2, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_OUTPUT);

//COMMON ANODE 7SEGMENT
	DIO_voidSetPinDirection(PORTA_ID, PIN3, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA_ID, PIN2, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_OUTPUT);
//ON  CA  -> low
	DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_LOW);  //COM1
	DIO_voidSetPinValue(PORTA_ID, PIN2, LOGIC_LOW);  //COM2
	DIO_voidSetPinValue(PORTB_ID, PIN5, LOGIC_HIGH);  //COM3
	DIO_voidSetPinValue(PORTB_ID, PIN6, LOGIC_HIGH); //COM4

}

void SS_voidDisplayRealNumber(u8 copy_u8Number) {

	u8 Local_u8Uints = copy_u8Number % 10;
	u8 Local_u8Tens = copy_u8Number / 10;
	u16 i;
	if (copy_u8Number < 99) {

		/*  DIO_voidSetPinValue(PORTB_ID, PIN0, GET_BIT(copy_u8Number, 7)); //A
		 DIO_voidSetPinValue(PORTB_ID, PIN1, GET_BIT(copy_u8Number, 6)); //B
		 DIO_voidSetPinValue(PORTB_ID, PIN2, GET_BIT(copy_u8Number, 5)); //C
		 DIO_voidSetPinValue(PORTB_ID, PIN4, GET_BIT(copy_u8Number, 4)); //D

		 //ENABLE DIGIT 1
		 DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_HIGH);
		 //DISABLE DIGIT 2
		 DIO_voidSetPinValue(PORTA_ID, PIN2, LOGIC_LOW);
		 _delay_ms(2);
		 //DISABLE DIGIT 1
		 DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_LOW);

		 /*	DIO_voidSetPinValue(PORTB_ID, PIN0, GET_BIT(Local_u8Tens, 3)); //A
		 DIO_voidSetPinValue(PORTB_ID, PIN1, GET_BIT(Local_u8Tens, 2)); //B
		 DIO_voidSetPinValue(PORTB_ID, PIN2, GET_BIT(Local_u8Tens, 1)); //C
		 DIO_voidSetPinValue(PORTB_ID, PIN4, GET_BIT(Local_u8Tens, 0)); //D


		 ///DISABLE DIGIT 1
		 DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_LOW);
		 //ENBLE DIGIT 2
		  *
		  *
		  *
		  *
		  *
		  *
		  *
		  *
		  *
		  *
		  *
		  *
		 DIO_voidSetPinValue(PORTA_ID, PIN2, LOGIC_HIGH);
		 _delay_ms(2);
		 //DISABLE DIGIT 2
		 DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_LOW);
		 */

		for (i = 0; i < 255; i++) {

			switch (Local_u8Uints) {
			case 0:
				DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
				break;
			case 1:
				DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_HIGH);
				DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
				break;
			case 2:
				DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_HIGH);
				DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
				break;

			case 3:
				DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_HIGH);
				DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_HIGH);
				DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
				break;

			case 4:
				DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_LOW);
				DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_HIGH);
				DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
				break;

			}
			//ENABLE DIGIT 1
			DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_LOW);
			//DISABLE DIGIT 2
			DIO_voidSetPinValue(PORTA_ID, PIN2, LOGIC_HIGH);
			_delay_ms(1);
			//DISABLE DIGIT 1
			DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_HIGH);


			 switch (Local_u8Tens) {
			 case 0:
			 DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
			 break;
			 case 1:
			 DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_HIGH);
			 DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
			 break;
			 case 2:
			 DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_HIGH);
			 DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
			 break;

			 case 3:
			 DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_HIGH);
			 DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_HIGH);
			 DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
			 break;

			 case 4:
			 DIO_voidSetPinValue(PORTB_ID, PIN0, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN1, LOGIC_LOW);
			 DIO_voidSetPinValue(PORTB_ID, PIN2, LOGIC_HIGH);
			 DIO_voidSetPinValue(PORTB_ID, PIN4, LOGIC_LOW);
			 break;

			 }
			 //DISABLE DIGIT 1
			 DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_HIGH);
			 //ENBLE DIGIT 2
			 DIO_voidSetPinValue(PORTA_ID, PIN2, LOGIC_LOW);
			 _delay_ms(1);
			 //DISABLE DIGIT 2
			 DIO_voidSetPinValue(PORTA_ID, PIN3, LOGIC_HIGH);


		}
	}

}

/*digit				input		output //IF
 PB0,PB1,PB2,PB4	D,C,B,A		a,b,c,d,e,f,g
 0					0x00		0000 001
 1					0x01		1001 111
 2					0x02		0010 010
 3 					0x03		0000 110
 4					0x04		1001 100
 5					0x05		0100 100
 6					0x06		0100 000
 7					0x07		0001 111
 8					0x08		0000 000
 9					0x09		0000 100*/
