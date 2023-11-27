#ifndef SPARTANMAINCLASS_H 
#define SPARTANMAINCLASS_H

#include <Arduino.h>;

#include <unordered_map>
#include "workers/spartan_configs_static_class.h"
#include "workers/spartan_logger_class.h"
#include "workers/spartan_security_class.h"
#include "workers/spartan_interface_class.h"
#include "workers/spartan_server_class.h"
#include "workers/spartan_time_thread_class.h"
#include "workers/spartan_integrity_class.h"

SpartanTimeThreadClass thread_server_1(2);
SpartanTimeThreadClass thread_server_2(3);
SpartanTimeThreadClass thread_server_3(4);
SpartanTimeThreadClass thread_server_4(5);

SpartanTimeThreadClass TimeLoop1;
SpartanTimeThreadClass TimeLoop2;
SpartanTimeThreadClass TimeLoop3;


class SpartanMainClass {
  private:
      
  public:
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

	Logger.hide_progress_bar();

	SpartanInterfaceServer.start_wifi_worker();

};

void SpartanMainClass::sustain_loop () {
	
	if(thread_server_1.run()){
		SpartanServer.sustain_loop();
	}

	if(thread_server_2.run()){
	}

	if(thread_server_3.run()){
	}

	if(thread_server_4.run()){
	}

	if(TimeLoop1.every_x_milliseconds(1000)){
		// Logger.println("Run 1s");
	}

	if(TimeLoop2.every_x_milliseconds(4000)){
		// Logger.println("Run 4s");
	}

	if(TimeLoop3.every_x_milliseconds(600000)){
		SpartanInterfaceDisplay.clear_screen();
		SpartanInterfaceDisplay.write_screen();
	}

};

#endif