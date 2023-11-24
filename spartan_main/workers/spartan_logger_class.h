#ifndef SPARTANLOGGERCLASS_H 
#define SPARTANLOGGERCLASS_H

#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, SDA_LCD, SDB_LCD); // Start LCD here to help with logger, the interface will use this object;

class SpartanLoggerClass {
  private:
		bool lcd_mode = true;
		String buffer_text[5];
		int activity_percent = 0;

  public:
		//Construtor
		// SpartanLoggerClass

		void start();

 		void println(const __FlashStringHelper *);
    void println(const String &s);
    void println(const char[]);
    void println(char);
    void println(unsigned char, int = DEC);
    void println(int, int = DEC);
    void println(unsigned int, int = DEC);
    void println(long, int = DEC);
    void println(unsigned long, int = DEC);
    void println(double, int = 2);
    void println(const Printable&);
    void println(void);

		void print_lcd(String);
		void set_activity_percent(int);
		void hide_progress_bar();

};

void SpartanLoggerClass::start () {
	Serial.begin(115200);
	Serial.println("\nStarted SpartanLoggerClass");
  display.init();
  display.flipScreenVertically();
	display.setFont(ArialMT_Plain_10);
};

void SpartanLoggerClass::set_activity_percent(int percent) {
	activity_percent = percent;
	display.drawProgressBar(0, 50, 120, 8, activity_percent);
	display.display();
};

void SpartanLoggerClass::hide_progress_bar() {
	activity_percent = 0;
};

void SpartanLoggerClass::print_lcd(String text){
  if (lcd_mode){
		for (int i = 5 - 1; i > 0; i--) {
			buffer_text[i] = buffer_text[i - 1];
		}
		buffer_text[0] = text;

		display.clear();
		
		display.drawString(0, 0,  buffer_text[4]);
		display.drawString(0, 10, buffer_text[3]);
		display.drawString(0, 20, buffer_text[2]);
		display.drawString(0, 30, buffer_text[1]);
		display.drawString(0, 40, buffer_text[0]);

		if (activity_percent > 0 && activity_percent < 101){
			display.drawProgressBar(0, 55, 120, 10, activity_percent);
		}

		display.display();
	}

}

void SpartanLoggerClass::println(void)
{
  Serial.println("");
	print_lcd("");
}

void SpartanLoggerClass::println(const String &s)
{
  Serial.println(s);
	print_lcd(s);

}

void SpartanLoggerClass::println(const char c[])
{
 	Serial.println(c);
	print_lcd(String(c));
}

void SpartanLoggerClass::println(char c)
{
 	Serial.println(c);
	print_lcd(String(c));
}

void SpartanLoggerClass::println(unsigned char b, int base)
{
  Serial.println(b, base);
}

void SpartanLoggerClass::println(int num, int base)
{
  Serial.println(num, base);
}

void SpartanLoggerClass::println(unsigned int num, int base)
{
  Serial.println(num, base);
}

void SpartanLoggerClass::println(long num, int base)
{
  Serial.println(num, base);
}

void SpartanLoggerClass::println(unsigned long num, int base)
{
  Serial.println(num, base);
}

void SpartanLoggerClass::println(double num, int digits)
{
  Serial.println(num, digits);
}

void SpartanLoggerClass::println(const Printable& x)
{
  Serial.println(x);
}




#endif