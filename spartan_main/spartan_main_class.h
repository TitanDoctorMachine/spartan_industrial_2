#ifndef SPARTANMAINCLASS_H 
#define SPARTANMAINCLASS_H

#include <Arduino.h>;

#define SYSTEM_IDENTIFIER "UNIT_00001"

#include <unordered_map>
#include <string>
#include <ESP8266WiFi.h>

#include "workers/spartan_configs_static_class.h"
#include "workers/spartan_logger_class.h"
#include "workers/spartan_security_class.h"
#include "workers/spartan_interface_class.h"
#include "workers/security/ignum_04_class.h"
#include "workers/spartan_server_class.h"
#include "workers/spartan_time_thread_class.h"
#include "workers/spartan_integrity_class.h"

SpartanTimeThreadClass thread_server_1(2);
SpartanTimeThreadClass thread_server_2(3);
SpartanTimeThreadClass thread_server_3(4);
SpartanTimeThreadClass thread_server_4(5);
SpartanTimeThreadClass thread_server_5(6);
SpartanTimeThreadClass thread_server_6(7);

SpartanTimeThreadClass TimeLoop1;
SpartanTimeThreadClass TimeLoop2;
SpartanTimeThreadClass TimeLoopBase;

#include "workers/async_jobs_performer/spartan_async_job_class.h"

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

	Ignum04.start();

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
		SpartanServerNetwork.perform_task_loops();
	}

	if(TimeLoopBase.every_x_milliseconds(600000)){
		SpartanInterfaceDisplay.clear_screen();
		SpartanInterfaceDisplay.write_screen();
	}

	SpartanAsyncJob.run_threads();

};

#endif