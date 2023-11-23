#ifndef SPARTANMAINCLASS_H 
#define SPARTANMAINCLASS_H

#include <Arduino.h>;

#include "workers/spartan_logger_class.h"
SpartanLoggerClass Logger;

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
  Logger.start();
  Logger.println("Started SpartanMainClass");

	Logger.set_activity_percent(10);

  SpartanSecurity.start();

	Logger.set_activity_percent(30);

	SpartanInterface.start();

	Logger.set_activity_percent(50);

	SpartanServer.start();

	Logger.set_activity_percent(70);

	SpartanIntegrity.start();

	Logger.set_activity_percent(90);


	if (SpartanInterfaceFile.read_value("system_token") == ""){
    SpartanInterfaceFile.write_value("system_token", SpartanSecurity.random_code());
  }

	/*SpartanInterfaceDisplay.show_progress_bar(25);
	SpartanInterfaceDisplay.write_screen();*/
	Logger.hide_progress_bar();

	SpartanInterfaceServer.start_wifi_worker();


};

void SpartanMainClass::sustain_loop () {
	
	SpartanServer.sustain_loop();

};
#endif