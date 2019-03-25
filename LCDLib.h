#ifndef LCDLIB_H
#define LCDLIB_H
#include <Arduino.h>
#include <stdint.h>

#undef LCD16
#define  LCD20

#define LCD_ADDR                0x27

#ifdef LCD16
#define LCD_COL 	              16
#define LCD_ROW                    2
#endif 

#ifdef LCD20
#define LCD_COL 	              20
#define LCD_ROW                    4
#endif

#define MAX_LCD_ROW    (LCD_ROW - 1)
#define MAX_LCD_COL    (LCD_COL - 1)

#define CENTER_ALIGN              25
#define RIGHT_ALIGN      MAX_LCD_COL
#define LEFT_ALIGN                 0
#define AFTER_ARROW_POS			   1

#ifdef LCD16
typedef enum
{
	ONE = 0,
	TWO
} LCD_ROWS;	
#endif

#ifdef LCD20
typedef enum
{
	ONE = 0,
	TWO,
	THREE,
	FOUR
} LCD_ROWS;	
#endif

typedef enum
{
	TO_LEFT = 0,
	TO_RIGHT	
}SCROLL_MOVEMENT;

void LCDInit(void);
void LCDMoveCursor(uint8_t row, uint8_t col);
void ClearLCD(void);
void BlinkDisplay(uint8_t NumTimes);
void LCDPrintString(uint8_t row, uint8_t col, const char * string);
void LCDPrintValue(uint8_t row, uint8_t col, float value);
void LCDPrintValue(uint8_t row, uint8_t col, uint32_t value);
void LCDPrintValue(uint8_t row, uint8_t col, uint16_t value);
void LCDPrintValue(uint8_t row, uint8_t col, uint8_t value);
void LCDPrintChar(uint8_t Row, uint8_t Col, char * Character);
void ClearChar(uint8_t Row, uint8_t Col);
void ClearLCDLine(uint8_t row);
void LCDDisplayLight(bool IsOn);
void LCDBlink(bool IsBlinking);
bool LCDCreateIcon(const uint8_t *Icon, const uint8_t IconNum);
void LCDShowIcon(const uint8_t IconNum, uint8_t Row, uint8_t Col);
void ScrollText(char * Text, uint8_t Where, uint8_t DelayMs, uint8_t ScreenPos);
void LCDPrintMessage(char * Message, uint8_t Row);
#endif