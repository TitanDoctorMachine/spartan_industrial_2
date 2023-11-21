#ifndef SPARTANMAINCLASS_H 
#define SPARTANMAINCLASS_H

#include <Arduino.h>;
#include "workers/spartan_integrity_class.h"
#include "workers/spartan_interface_class.h"
#include "workers/spartan_server_class.h"

SpartanInterfaceClass SpartanInterface;
SpartanServerClass SpartanServer;
SpartanIntegrityClass SpartanIntegrity;

SpartanInterfaceDisplayClass SpartanInterfaceDisplay;
SpartanInterfaceIoClass SpartanInterfaceIo;

class SpartanMainClass {
  private:
    int val;
      
  public:
		//Construtor
		// SpartanMainClass

		//lets start by the interfaces class
		void start();
		void sustain_loop();

};

void SpartanMainClass::start () {
  Serial.begin(115200);
  Serial.println("Started SpartanMainClass");

	SpartanInterface.start();
	SpartanServer.start();
	SpartanIntegrity.start();

	SpartanInterfaceDisplay.show_progress_bar(25);
	SpartanInterfaceDisplay.write_screen();
	
};

void SpartanMainClass::sustain_loop () {
	//need to put reloop here;	
};
#endif