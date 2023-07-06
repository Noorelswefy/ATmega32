#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define AVCC 				1
#define AREF 				5
#define INTERNAL_2_56V		6

#define ADC_PRESCALER_SELECTION_BIT_MASK  0b11111000
#define DIVIED_BY_2			1
#define DIVIED_BY_4			2
#define DIVIED_BY_8			3
#define DIVIED_BY_16		4
#define DIVIED_BY_32		5
#define DIVIED_BY_64		6
#define DIVIED_BY_128		7

#define ADC_CHANNEL_SELECTION_BIT_MASK 0b11100000
#define ADC0   00000
#define ADC1   00001
#define ADC2   00010
#define ADC3   00011
#define ADC4   00100
#define ADC5   00101
#define ADC6   00110#define ADC7   00111



#define  ADMUX   *((volatile u8*) 0x27)  	/*ADC multiplexer selection register*/
#define ADMUX_REFS1   		 7				/*Reference volt selection  bit1*/
#define ADMUX_REFS0			 6				/*Reference volt selection  bit0*/
#define ADMUX_ADLAR		     5   			/*left adjustment result*/

#define  ADCSRA *((volatile u8*) 0x26)		/*ADC control and status register*/
#define  ADCSRA_ADEN		7				/*ADC ENALBE*/
#define  ADCSRA_ADSC		6  				/*ADC Start conversion*/
#define  ADCSRA_ADATE		5				/*ADC Auto trigger interrupt source Enable*/
#define  ADCSRA_ADIF		4				/*ADC interrupt flag*/
#define  ADCSRA_ADEI		3				/*ADC interrupt*/

#define  ADCL   *((volatile u8*) 0x25) 	/*ADC High data register*/
#define  ADCH   *((volatile u8*) 0x24)		/*ADC Low data register*/
#define  ADC    *((volatile u16*) 0x24)	/*ADC Data register*/

#define  SFIOR  *((volatile u8*) 0x50)		/*Special function Input / output  register*/
#define  SFIOR_ADTS2 		7					//SFIOR ADTS2 ADTS1 ADTS0
#define  SFIOR_ADTS3		6
#define  SFIOR_ADTS1		5


#define ADC_BUSY 0
#define ADC_IDLE 1

#endif 



