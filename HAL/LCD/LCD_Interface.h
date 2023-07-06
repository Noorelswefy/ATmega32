#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H




void LCD_voidInit(void);

void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);

void LCD_voidWriteString(const u8 *copy_str);

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);

void LCD_voidClear(void);

void LCD_voidWriteNumber( u32 Copy_u8num );


void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum, u8 row,u8 col );

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ) ;


void LCD_voidCharPos(u8 copy_u8Byte,u8 copy_u8row ,u8 copy_u8col);

void LCD_voidStringPos(u8 const * copy_str,u8 copy_u8row ,u8 copy_u8col);

void LCD_voidNumPos(u8 copy_u8Byte,u8 copy_u8row ,u8 copy_u8col);

#endif
