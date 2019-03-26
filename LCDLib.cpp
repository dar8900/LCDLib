#include "LCDLib.h"
#include <LiquidCrystal_I2C.h> // Libreria LCD I2C
#include <Wire.h>

LiquidCrystal_I2C lcd_main(LCD_ADDR, LCD_COL, LCD_ROW);

void LCDInit()
{
	lcd_main.begin();
}

void ClearLCD()
{
    //delay(10);
    lcd_main.clear();
    //lcd_main.home();
}

void LCDMoveCursor(uint8_t row, uint8_t col)
{
	lcd_main.setCursor(col, row);
}

void BlinkDisplay(uint8_t NumTimes, uint8_t PulseTime)
{
	uint8_t num = 0, Pulse = PulseTime;
	if(Pulse < 20)
		Pulse = 20;
	for(num = 0; num < NumTimes; num++)
	{
		LCDDisplayLight(true);
		delay(Pulse);
		LCDDisplayLight(false);
		delay(Pulse);
	}
	LCDDisplayLight(true);
}

// Utilizzano un oggetto di tipo LCD
void LCDPrintString(uint8_t row, uint8_t col, const char * string)
{
  uint8_t Len = strlen(string);
  if(row > MAX_LCD_ROW || Len > MAX_LCD_COL + 1 )
  {
	lcd_main.clear();
	if(Len > MAX_LCD_COL + 1)
	{
		col = CENTER_ALIGN;
		string = "STRING TOO BIG";
		Len = strlen(string);
	}
	else
	{
		col = CENTER_ALIGN;
		row = TWO;
		string = "OVER DIMENSION";
        Len = strlen(string);	
	}
  }
  switch(col)
  {
    case CENTER_ALIGN:
      col = ((MAX_LCD_COL+1) - Len) / 2;
      break;
    case RIGHT_ALIGN:
      col = (MAX_LCD_COL+1) - Len;
      break;
    case LEFT_ALIGN:
      col = 0;
      break;
    default:
      break;
  }
  lcd_main.setCursor(col, row);
  lcd_main.print(string);

}

void LCDPrintValue(uint8_t row, uint8_t col, float value)
{
  char ValStr[21];
  uint8_t Len = 0;
  snprintf(ValStr, 21, "%.4f", value);
  Len = strlen(ValStr);
  if(row > MAX_LCD_ROW || Len > MAX_LCD_COL + 1)
  {
	lcd_main.clear();
	col = CENTER_ALIGN;
	row = TWO;
	snprintf(ValStr, 21, "%s", "OVER DIMENSION");
	Len = strlen(ValStr);
  }

  switch(col)
  {
    case CENTER_ALIGN:
      col = ((MAX_LCD_COL+1) - Len) / 2;
      break;
    case RIGHT_ALIGN:
      col = (MAX_LCD_COL+1) - Len;
      break;
    case LEFT_ALIGN:
      col = 0;
      break;
    default:
      lcd_main.home();
      break;
  }
  lcd_main.setCursor(col, row);
  lcd_main.print(ValStr);
}

void LCDPrintValue(uint8_t row, uint8_t col, uint32_t value)
{
  char ValStr[21];
  uint8_t Len = 0;
  snprintf(ValStr, 21, "%d", value);
  Len = strlen(ValStr);
  if(row > MAX_LCD_ROW || Len > MAX_LCD_COL + 1)
  {
	lcd_main.clear();
	col = CENTER_ALIGN;
	row = TWO;
    snprintf(ValStr, 21, "%s", "OVER DIMENSION");
    Len = strlen(ValStr);
  }

  switch(col)
  {
    case CENTER_ALIGN:
      col = ((MAX_LCD_COL+1) - Len) / 2;
      break;
    case RIGHT_ALIGN:
      col = (MAX_LCD_COL+1) - Len;
      break;
    case LEFT_ALIGN:
      col = 0;
      break;
    default:
      lcd_main.home();
      break;
  }
  lcd_main.setCursor(col, row);
  lcd_main.print(ValStr);
}

void LCDPrintValue(uint8_t row, uint8_t col, uint16_t value)
{
  char ValStr[21];
  uint8_t Len = 0;
  snprintf(ValStr, 21, "%d", value);
  Len = strlen(ValStr);
  if(row > MAX_LCD_ROW || Len > MAX_LCD_COL + 1)
  {
	lcd_main.clear();
	col = CENTER_ALIGN;
	row = TWO;
    snprintf(ValStr, 21, "%s", "OVER DIMENSION");
    Len = strlen(ValStr);
  }

  switch(col)
  {
    case CENTER_ALIGN:
      col = ((MAX_LCD_COL+1) - Len) / 2;
      break;
    case RIGHT_ALIGN:
      col = (MAX_LCD_COL+1) - Len;
      break;
    case LEFT_ALIGN:
      col = 0;
      break;
    default:
      lcd_main.home();
      break;
  }
  lcd_main.setCursor(col, row);
  lcd_main.print(ValStr);
}

void LCDPrintValue(uint8_t row, uint8_t col, uint8_t value)
{
  char ValStr[21];
  uint8_t Len = 0;
  snprintf(ValStr, 21, "%d", value);
  Len = strlen(ValStr);
  if(row > MAX_LCD_ROW || Len > MAX_LCD_COL + 1)
  {
	lcd_main.clear();
	col = CENTER_ALIGN;
	row = TWO;
    snprintf(ValStr, 21, "%s", "OVER DIMENSION");
    Len = strlen(ValStr);
  }

  switch(col)
  {
    case CENTER_ALIGN:
      col = ((MAX_LCD_COL+1) - Len) / 2;
      break;
    case RIGHT_ALIGN:
      col = (MAX_LCD_COL+1) - Len;
      break;
    case LEFT_ALIGN:
      col = 0;
      break;
    default:
      lcd_main.home();
      break;
  }
  lcd_main.setCursor(col, row);
  lcd_main.print(ValStr);
}

void LCDPrintChar(uint8_t Row, uint8_t Col, char * Character)
{
	lcd_main.setCursor(Row, Col);
	lcd_main.print(Character);
}


void ClearChar(uint8_t Row, uint8_t Col)
{
	lcd_main.setCursor(Col, Row); 
	lcd_main.print(" ");
}

void ClearLCDLine(uint8_t row)
{
	lcd_main.setCursor(0, row); 
#ifdef LCD16	
	lcd_main.print("                ");	
#endif
#ifdef LCD20
	lcd_main.print("                    ");	
#endif
}

void LCDDisplayLight(bool IsOn)
{
	if(IsOn)
		lcd_main.backlight();
	else
		lcd_main.noBacklight();
}

void LCDBlink(bool IsBlinking)
{
	if(IsBlinking)
		lcd_main.blink();
	else
		lcd_main.noBlink();
}

bool LCDCreateIcon(uint8_t *Icon, const uint8_t IconNum)
{
	bool Created = false;
	if(IconNum < 7)
	{
		lcd_main.createChar(IconNum, Icon);
		Created = true;
	}
	else
	{
		Created = false;
	}
	return Created;
}

void LCDShowIcon(const uint8_t IconNum, uint8_t Row, uint8_t Col)
{
	lcd_main.setCursor(Col, Row);
	lcd_main.write(IconNum);
}

void ScrollText(char * Text, uint8_t Where, uint8_t DelayMs, uint8_t ScreenPos)
{
	uint8_t ScrollLen = 0;
	uint8_t Len = strlen(Text);
	if(ScreenPos == CENTER_ALIGN)
	{
		ScrollLen = (MAX_LCD_COL - Len) + MAX_LCD_COL;
	}
	for(uint8_t i = 0; i < ScrollLen; i++)
	{
		if(Where == TO_LEFT)
			lcd_main.scrollDisplayLeft();
		else
			lcd_main.scrollDisplayRight();
		delay(DelayMs);
	}	
}

void LCDPrintMessage(char * Message, uint8_t Row)
{
	ClearLCD();
	LCDPrintString(Row, CENTER_ALIGN, Message);
	delay(1500);
	ClearLCD();
}