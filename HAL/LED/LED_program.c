/*
 * LED_program.c
 *
 *  Created on: 13 Jun 2023
 *      Author: noor elswefy
 */
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "LED_interface.h"
#include "DIO_interface.h"
#include "DIO_private.h"


void LED_ON(Led_ID copy_u8LedColor)
{

	switch(copy_u8LedColor){ //high
			case LED_RED	: DIO_voidSetPinValue(LED_RED_PORT,LED_RED_PIN,LOGIC_HIGH); break;
			case LED_BLUE	: DIO_voidSetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOGIC_HIGH); break;
			case LED_GREEN  : DIO_voidSetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOGIC_HIGH); break;
			case LED_YELLOW : DIO_voidSetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOGIC_HIGH); break;
		}
}
void LED_OFF (Led_ID copy_u8LedColor)
{
	switch(copy_u8LedColor){ //low
			case LED_RED	: DIO_voidSetPinValue(LED_RED_PORT,LED_RED_PIN,LOGIC_LOW); break;
			case LED_BLUE	: DIO_voidSetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOGIC_LOW); break;
			case LED_GREEN  : DIO_voidSetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOGIC_LOW); break;
			case LED_YELLOW : DIO_voidSetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOGIC_LOW); break;
		}


}

void LED_TOGGLE(Led_ID copy_u8LedColor)
{

 switch(copy_u8LedColor)
 {
			case LED_RED	: DIO_voidToggelPin(LED_RED_PORT,LED_RED_PIN); break;
			case LED_BLUE	: DIO_voidToggelPin(LED_BLUE_PORT,LED_BLUE_PIN); break;
			case LED_GREEN  : DIO_voidToggelPin(LED_GREEN_PORT,LED_GREEN_PIN); break;
			case LED_YELLOW : DIO_voidToggelPin(LED_YELLOW_PORT,LED_YELLOW_PIN); break;
 }
}
