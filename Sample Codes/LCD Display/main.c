#include "lcd.h"

int main (void) 
{
  init_lcd();
	
	delay(1000*1000);
	lcd_clear();
	lcd_gotoxy(0, 0);
	lcd_clear();	
	lcd_putstring(0,"      RDL    ");
	lcd_putstring(1,"     TECH    ");
  while (1)  
  {
		
  }
}
