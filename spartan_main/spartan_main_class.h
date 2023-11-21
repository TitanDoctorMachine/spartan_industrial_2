#ifndef SPARTANMAINCLASS_H 
#define SPARTANMAINCLASS_H

#include <Arduino.h>;
#include "workers/spartan_security_class.h"
#include "workers/spartan_integrity_class.h"
#include "workers/spartan_interface_class.h"
#include "workers/spartan_server_class.h"

SpartanSecurityClass SpartanSecurity;
SpartanInterfaceClass SpartanInterface;
SpartanServerClass SpartanServer;
SpartanIntegrityClass SpartanIntegrity;

class SpartanMainClass {
  private:
      
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

  SpartanSecurity.start();
	SpartanInterface.start();
	SpartanServer.start();
	SpartanIntegrity.start();


	SpartanInterfaceDisplay.show_progress_bar(25);
	SpartanInterfaceDisplay.write_screen();

	SpartanInterfaceServer.start_wifi_worker();

	
};

void SpartanMainClass::sustain_loop () {
	
	SpartanServer.sustain_loop();

};
#endif