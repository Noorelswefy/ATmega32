#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"

static u8 *ADC_pu8Channel_Arr = NULL;
static u16 *ADC_pu16Result_Arr = NULL;
static u8 ADC_u8ChannelsLength;
static void (*ADC_pvNotificationFunc)(void) = NULL;   //call back function pointer
static u8 ADC_u8Channel_Index;

static u8 ADC_u8State = ADC_IDLE;

void ADC_voidInit() {
	/*1- set reference voltage*/
#if  ADC_u8_REF_SELECTION == AREF
	CLR_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
#elif  ADC_u8_REF_SELECTION == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif  ADC_u8_REF_SELECTION == INTERNAL_2_56V
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "wrong ADC_u8_REF_SELECTION configuration"
#endif

	/*Left adjust*/
	SET_BIT(ADMUX, ADMUX_ADLAR);
	// Right adjustment
//	CLR_BIT(ADMUX,ADMUX_ADLAR);

	/*set pre-scaler configuration*/
	ADCSRA &= ADC_PRESCALER_SELECTION_BIT_MASK;
	ADCSRA |= ADC_u8_PRESCALER_SELECTION;

	/*Enable ADC*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u16 ADC_u8GetChannelReading(u8 Copy_u8Channel) {
	/*set the required channel*/

	ADMUX &= ADC_CHANNEL_SELECTION_BIT_MASK;
	ADMUX |= Copy_u8Channel;

	/* Start conversion */
	SET_BIT(ADCSRA, ADCSRA_ADSC);
	/* polling until the conversion complete*/

	while ((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0);

	/*Clear the interrupt flag*/
	//SET_BIT(ADCSRA, ADCSRA_ADIF);

	/*RETURN VALUE FROM DATA REG FOR 8 BITS*/
	return ADCL; //RETURN ACD IF 10 BITS

}
u8 ADC_u8GetChainAysnc(Chain_t *Copy_chain) {
	u8 Local_u8ErrorState = OK;

	if (NULL != Copy_chain) {
		/*Initialize Channels Array*/
		ADC_pu8Channel_Arr = Copy_chain->Channel_Arr;
		/*Initialize Result Array*/
		ADC_pu16Result_Arr = Copy_chain->Result_Arr;
		/*Initialize Length of conversion channels */
		ADC_u8ChannelsLength = Copy_chain->Length;
		/*Initialize chain Notification function (callback func)*/
		ADC_pvNotificationFunc = Copy_chain->Notification;
		/*Initialize Channel index */
		ADC_u8Channel_Index = 0;

		/*set the first channel in chain*/

		ADMUX &= ADC_CHANNEL_SELECTION_BIT_MASK;
		ADMUX |= Copy_chain->Channel_Arr[ADC_u8Channel_Index];
		/* Start conversion */
		SET_BIT(ADCSRA, ADCSRA_ADSC);
		/*Enable ADC interrupt  */
		SET_BIT(ADCSRA, ADCSRA_ADEI);

	} else
		Local_u8ErrorState = NULL_POINTER;

	return Local_u8ErrorState;
}

/*  ADC chain conversion complete ISR*/
void __vector_16(void)__attribute__((signal,used)); //attribute to avoid linker optimization
void __vector_16(void) {

	/*ADC is busy */
	ADC_u8State = ADC_BUSY;
	/* read the current conversion result*/
	ADC_pu16Result_Arr[ADC_u8Channel_Index] = ADCH; //Assume 8 bit
	ADC_u8Channel_Index++;
	if (ADC_u8Channel_Index != ADC_u8ChannelsLength) {
		/*Conversion not completed */
		if (ADC_u8State == ADC_IDLE){
			//Idle then, start conversion
		/*set the nextt channel in chain*/

		ADMUX &= ADC_CHANNEL_SELECTION_BIT_MASK;
		ADMUX |= ADC_pu8Channel_Arr[ADC_u8Channel_Index];
		/* Start conversion */
		SET_BIT(ADCSRA, ADCSRA_ADSC);
		}
	} else {
		/* ADC now idle*/
		ADC_u8State = ADC_BUSY;

		/* chain conversion complete*/
		ADC_pvNotificationFunc();

		CLR_BIT(ADCSRA, ADCSRA_ADEI);
	}

}
