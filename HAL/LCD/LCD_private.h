
#ifndef LCD_LCD_PRIVATE_H_
#define LCD_LCD_PRIVATE_H_




#define FUNCTION_SET_8BIT_2LINES_5X7_DOTS  0x38
#define FUNCTION_SET_4BIT_2LINES_5X7_DOTS  0x28

#define DISPLAY_ON_CURSOR_ON_BLink_OFF     0x0E
#define DISPLAY_ON_CURSOR_OFF              0x0C

#define DISPLAY_CLEAR                      0x01
#define ENTRY_MODE_SET                     0x06
#define  RETURN_HOME                       0x02





//#define SET_DDRAM_ADDRESS  0b10000000
#define SET_DDRAM_ADDRESS  0x80

//#define SET_CGRAM_ADDRESS  0b01000000
#define SET_CGRAM_ADDRESS  0x40


#endif /* LCD_LCD_PRIVATE_H_ */
