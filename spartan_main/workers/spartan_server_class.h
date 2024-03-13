#ifndef SPARTANSERVERCLASS_H 
#define SPARTANSERVERCLASS_H

ESP8266WebServer WebServer(80);

#include "server/spartan_server_network_class.h"
#include "../generators_controllers/main_controller.cpp"

SpartanServerNetworkClass SpartanServerNetwork;

class SpartanServerClass {
  private:

  public:
		void start();
		void sustain_loop();

};

void SpartanServerClass::start () {
	Logger.println("Started SpartanServerClass");
	SpartanServerNetwork.start();

  WebServer.on("/api/v1/ignum4", HTTP_GET, SpartanServerNetwork.ignum4_interface());
  WebServer.on("/api/v1/ignum4_challenge", HTTP_GET, SpartanServerNetwork.ignum4_challenge());

  WebServer.onNotFound(SpartanController.perform_request());

  // track cookies server
  const char * headerkeys[] = {
    "Accept",
    "Accept-Encoding",
    "Accept-Language",
    "Connection",
    "Cookie",
    "Host",
    "User-Agent"
  };

  size_t headerkeyssize = sizeof(headerkeys)/sizeof(char*);
  WebServer.collectHeaders(headerkeys, headerkeyssize);

	WebServer.begin();
};


void SpartanServerClass::sustain_loop() {
  
  WebServer.handleClient();
  
}

SpartanServerClass SpartanServer;

#endif