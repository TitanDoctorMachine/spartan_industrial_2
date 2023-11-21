#ifndef SPARTANINTERFACEDISPLAYCLASS_H 
#define SPARTANINTERFACEDISPLAYCLASS_H

#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, 14, 0); //D5 e D3

class SpartanInterfaceDisplayClass {
  private:
      
  public:
		void start();

		void clear_screen(){display.clear();};
		void write_screen(){display.display();};
		
		void show_progress_bar(int counter);

};

void SpartanInterfaceDisplayClass::start () {
	Serial.println("Started SpartanInterfaceDisplayClass");

  display.init();
  display.flipScreenVertically();

}

void SpartanInterfaceDisplayClass::show_progress_bar(int counter){
	display.drawProgressBar(0, 32, 120, 10, counter);
	display.setTextAlignment(TEXT_ALIGN_CENTER);
}




#endif