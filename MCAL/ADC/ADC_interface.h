#ifndef ACD_INTERFACE_H
#define ACD_INTERFACE_H

typedef struct{
	u8* Channel_Arr;
	u16* Result_Arr;
	u8 Length;   //No. of conversions in the chain
	void (*Notification)(void);
}Chain_t;

void ADC_voidInit();
/*Sync Function  */
u16 ADC_u16GetChannelReading(u8 Copy_u8Channel); //Read Channel USING POLLING
u8 ADC_u8GetChainAysnc(Chain_t*  Copy_chain);  //pointer to struct to save memory and access the value to change them

#endif
