/*
 * SS_config.h
 *
 *  Created on: 11 Jun 2023
 *      Author: noor elswefy
 */

#ifndef SEVEN_SEGMENT_SS_CONFIG_H_
#define SEVEN_SEGMENT_SS_CONFIG_H_
/*Seven segment multiplexed BCD decoder*/

/*#define SS_LED_A_PIN		Pb0
#define SS_LED_B_PIN		Pb1
#define SS_LED_C_PIN		PA2
#define SS_LED_D_PIN		PA4*/
/*#define SS_LED_A_PIN		PA1
#define SS_LED_B_PIN		PA2
#define SS_LED_C_PIN		PA3
#define SS_LED_D_PIN		PA4
#define SS_LED_E_PIN		PA5
#define SS_LED_F_PIN		PA6
#define SS_LED_G_PIN		PA7
#define SS_LED_DP_PIN		PB0*/

#define SS_COM1_PIN		PB6
#define SS_COM2_PIN		PB5
#define SS_COM3_PIN		PA2
#define SS_COM4_PIN		PA3

//Please configure the DISPLAY_TIME
#define HSSD_DISPLAY_TIME 	250

// Choose SSD Type
// 1- HSSD COMMON ANODE
// 2- HSSD COMMON CATHODE

#endif /* SEVEN_SEGMENT_SS_CONFIG_H_ */
