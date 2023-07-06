/*
 * BUZZER_program.c
 *
 *  Created on: 14 Jun 2023
 *      Author: noor elswefy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "BUZZER_config.h"
#include "DIO_Interface.h"
#include "BUZZER_interface.h"

BUZ_voidInit()
{
	//Buzzer output direction
	DIO_voidSetPinDirection(BUZZER_PORT, PIN6,PIN_OUTPUT);
}
void BUZ_voidON()
{
	//Set buzzer pin
	DIO_voidSetPinValue(BUZZER_PORT, PIN6, LOGIC_HIGH);

}
void BUZ_voidOFF()
{
	//Clear buzzer pin
	DIO_voidSetPinValue(BUZZER_PORT, PIN6, LOGIC_LOW);
}

void BUZ_voidTOG()
{

	DIO_voidTogglePinValue(HBUZZ_PIN);
	
}
