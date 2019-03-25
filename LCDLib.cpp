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

void LCDMoveCursor(short row, short col)
{
	lcd_main.setCursor(col, row);
}

void BlinkDisplay(short NumTimes, short PulseTime)
{
	short num = 0, Pulse = PulseTime;
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
void LCDPrintString(short row, short col, char * string)
{
	uint8_t Len = strlen(string);
  if(row > MAX_LCD_ROW || Len > MAX_LCD_ROW + 1 )
  {
	lcd_main.clear();
	if(Len > MAX_LCD_COL + 1)
	{
		col = CENTER_ALIGN;
		string = "STRING TOO BIG";
	}
	else
	{
		col = CENTER_ALIGN;
		row = MAX_LCD_ROW;
		string = "OVER DIMENSION";		
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

void LCDPrintValue(short row, short col, float value)
{
  char ValStr[21];
  uint8_t Len = 0;
  snprintf(ValStr, 21, "%.4f", value);
  Len = strlen(ValStr);
  if(row > MAX_LCD_ROW || Len > MAX_LCD_COL + 1)
  {
	lcd_main.clear();
	col = CENTER_ALIGN;
	row = MAX_LCD_ROW;
	snprintf(ValStr, 21, "%s", "OVER DIMENSION");
    return;
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

void LCDPrintValue(short row, short col, uint32_t value)
{
  char ValStr[21];
  uint8_t Len = 0;
  snprintf(ValStr, 21, "%d", value);
  Len = strlen(ValStr);
  if(row > MAX_LCD_ROW || Len > MAX_LCD_COL + 1)
  {
	lcd_main.clear();
	col = CENTER_ALIGN;
	row = MAX_LCD_ROW;
    snprintf(ValStr, 21, "%s", "OVER DIMENSION");
    return;
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

void LCDPrintChar(short Row, short Col, char * Character)
{
	lcd_main.setCursor(Row, Col);
	lcd_main.print(Character);
}


void ClearChar(short Row, short Col)
{
	lcd_main.setCursor(Col, Row); 
	lcd_main.print(" ");
}

void ClearLCDLine(short row)
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

bool LCDCreateIcon(short Icon[], short IconNum)
{
	bool Created = false;
	if(IconNum < 7)
	{
		lcd_main.createChar((uint8_t)IconNum, (uint8_t*)Icon);
		Created = true;
	}
	else
	{
		Created = false;
	}
	return Created;
}

void LCDShowIcon(short IconNum, short Row, short Col)
{
	lcd_main.setCursor(Col, Row);
	lcd_main.write(IconNum);
}

void ScrollText(char * Text, short Where, short DelayMs, short ScreenPos)
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

void LCDPrintMessage(char * Message, short Row)
{
	ClearLCD();
	LCDPrintString(Row, CENTER_ALIGN, Message);
	delay(1500);
	ClearLCD();
}