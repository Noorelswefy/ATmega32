/*
 * LED_interface.h
 *
 *  Created on: 13 Jun 2023
 *      Author: noor elswefy
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_



#define LED_RED 	1
#define LED_BLUE	2
#define LED_GREEN	3
#define LED_YELLOW	4

#define LED_RED_PIN 		PIN7
#define LED_BLUE_PIN		PIN5
#define LED_GREEN_PIN		PIN4
#define LED_YELLOW_PIN		PIN6

#define LED_RED_PORT 		PORTB_ID
#define LED_BLUE_PORT		PORTA_ID
#define LED_GREEN_PORT		PORTA_ID
#define LED_YELLOW_PORT		PORTA_ID

typedef u8 Led_ID;


void LED_OFF(Led_ID copy_u8LedColor);
void LED_ON (Led_ID copy_u8LedColor);
void LED_TOGGLE(Led_ID copy_u8LedColor);

#endif /* LED_LED_INTERFACE_H_ */
