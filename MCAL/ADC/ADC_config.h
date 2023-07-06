#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*choose
 * AREF
 * AVCC
 * INTERNAL_2.56V
 * */

#define ADC_u8_REF_SELECTION  AVCC


/*choose prescaler
 * 1- DIVIED _BY_2
 * 2- DIVIED _BY_4
 * 3- DIVIED _BY_8
 * 4- DIVIED _BY_16
 * 5- DIVIED _BY_32
 * 6- DIVIED _BY_64
 * 7- DIVIED _BY_128
 * */

#define ADC_u8_PRESCALER_SELECTION   DIVIED_BY_128
/*Choose ADC required channel
 * single ended:
 * ADC0   00000
 * ADC1   00001
 * ADC2   00010
 * ADC3   00011
 * ADC4   00100
 * ADC5   00101
 * ADC6   00110
 * ADC7   00111
 * */

#endif

