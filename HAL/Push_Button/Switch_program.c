
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "Switch_config.h"
#include "Switch_interface.h"

void SWITCH_voidInit(u8 Copy_PORT_ID, u8 Copy_PIN_ID) {

    /* Switch pin direction */
    DIO_voidSetPinDirection(Copy_PORT_ID, Copy_PIN_ID, PIN_INPUT);

    /* Switch initial value */
#if SW_MODE == SW_PULLDOWN
    DIO_voidSetPinValue(Copy_PORT_ID, Copy_PIN_ID, 0);
#elif SW_MODE == SW_PULLUP
    DIO_voidSetPinValue(Copy_PORT_ID, Copy_PIN_ID, 1);
#endif

}

u8 SWITCH_u8GetPressed(u8 Copy_PORT_ID, u8 Copy_PIN_ID) {

    static u8 previousState = PIN_HIGH; // Initial value assuming switch is released
    u8 currentState;

    currentState = DIO_u8GetPinValue(Copy_PORT_ID, Copy_PIN_ID);
    if (currentState != previousState) {
        u16 delayCounter = 0;
        while (delayCounter < 1000) {  // Adjust the loop count for desired delay duration
            delayCounter++;  // Increment the delay counter
        }
        currentState = DIO_u8GetPinValue(Copy_PORT_ID, Copy_PIN_ID);

        if (currentState != previousState) {
            previousState = currentState;

#ifdef SW_MODE
#if SW_MODE == SW_PULLUP
            // Check if the switch is pressed (active low for pull-up configuration)
            if (currentState == PIN_LOW) {
                return 1;  // Switch is pressed
            }

#elif SW_MODE == SW_PULLDOWN

            if (currentState == PIN_HIGH) {
                           return 1;  // Switch is pressed
            }
#endif
#endif

        }
    }

    return 0;  // Switch is not pressed
}
