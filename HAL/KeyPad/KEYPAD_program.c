/*
 * KEYPAD_program.c
 *
 * Created: 6/12/2023 9:43:05 AM
 *  Author: Abdul
 */ 

/*************************************************************************************
 *                                  Files Inclusion                                  *
 *************************************************************************************/
#define F_CPU 16000000UL

/* User Defined Library Files */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_interface.h"


/* Module Header Files */
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"




/*************************************************************************************
 *                             Static Objects Definition                             *
 *************************************************************************************/


static u8 arr_COL_pins[4]={COL_0,COL_1,COL_2,COL_3};
static u8 arr_COL_port[4]={KPD_PORT_COL0,KPD_PORT_COL1,KPD_PORT_COL2,KPD_PORT_COL3};

static u8 arr_ROW_pins[4]={ROW_0,ROW_1,ROW_2,ROW_3};
static u8 arr_ROW_port[4]={KPD_PORT_ROW0,KPD_PORT_ROW1,KPD_PORT_ROW2,KPD_PORT_ROW3} ;



/*************************************************************************************
 *                               Public Function Definition                          *
 *************************************************************************************/


void KPD_voidInit(void)
{

	u8 counter=ZERO ;
	for(;counter<4;counter++)
	{
		DIO_voidSetPinDirection(arr_COL_port[counter],arr_COL_pins[counter],PIN_INPUT);
		DIO_voidSetPinValue(arr_COL_port[counter],arr_COL_pins[counter],PIN_HIGH);


		DIO_voidSetPinDirection(arr_ROW_port[counter],arr_ROW_pins[counter],PIN_OUTPUT);
		DIO_voidSetPinValue(arr_ROW_port[counter],arr_ROW_pins[counter],PIN_HIGH);
	}

}



u8 KPD_voidGetPressedKey(void)
{
	u8 counter1 ;                  //counter loop1
	u8 counter2 ;                 //counter loop2
	u8 get_key=KPD_NOT_PRESSED ; //init val
	u8 pin_val ;                // to get val of pin if 0 or 1

	u8 SwitchVal[ROW_SIZE][COL_SIZE] = KEYPAD_ARR ;

	for(counter1=ZERO ; counter1 < ROW_SIZE ; counter1++ )
	{
		DIO_voidSetPinValue(arr_ROW_port[counter1],arr_ROW_pins[counter1],PIN_LOW);

		for(counter2=ZERO ; counter2 < COL_SIZE ; counter2++ )
		{

			pin_val=DIO_voidGetBitValue( ( arr_COL_port[counter2] ) , (arr_COL_pins[counter2]) );

			if(pin_val==KPD_PRESSED)
			{
				get_key=SwitchVal[counter1][counter2]  ;

				while(pin_val==KPD_PRESSED)
				{
					pin_val=DIO_voidGetBitValue( ( arr_COL_port[counter2] ) , (arr_COL_pins[counter2]) );
				}
				//	_delay_ms(20);
				return get_key ;
			}



		}
		DIO_voidSetPinValue(arr_ROW_port[counter1],arr_ROW_pins[counter1],PIN_HIGH);
	}

	return get_key;
}


