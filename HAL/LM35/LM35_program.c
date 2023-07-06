 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/
#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "LM35_interface.h"
/*divide by 10 for 10mv --> 1 C*/
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
u8 LM35_getTemperature(void)
{
	u8 temp_value = 0;
	//u16 temp_value = 0;

	u16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ACD_u8GetChannelReading(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	//temp_value = (u8)(((u32)adc_value*SENSOR_MAX_TEMPERATURE*5)/(5*SENSOR_MAX_VOLT_VALUE));
	temp_value = (5000UL* (u32)adc_value)/1024UL;

	return temp_value;
}

