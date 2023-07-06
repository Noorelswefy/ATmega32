/*
 * buzzer.c
 *
 *  Created on: 21 Jun 2023
 *      Author: noor elswefy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "BUZZER_interface.h"



int main(){

	/* Initialize Buzzer */

	BUZ_voidInit();

	while(1){

		BUZ_voidON();
	}
}
