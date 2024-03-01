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

  WebServer.on("/login", HTTP_GET, SpartanServerNetwork.load_login_page());
  WebServer.on("/login", HTTP_POST, SpartanServerNetwork.login_method());

  WebServer.on("/", HTTP_GET, SpartanServerNetwork.load_dashboard_page());
 
  WebServer.on("/connections", HTTP_GET, SpartanServerNetwork.load_wifi_page());
  WebServer.on("/set_hotspot_params", HTTP_POST, SpartanServerNetwork.update_hotspot_params());
  WebServer.on("/set_network_params", HTTP_POST, SpartanServerNetwork.update_network_params());
 
  WebServer.on("/security", HTTP_GET, SpartanServerNetwork.load_security_screen());
  WebServer.on("/set_system_password", HTTP_POST, SpartanServerNetwork.update_system_password());

  WebServer.on("/interface_gpios", HTTP_GET, SpartanServerNetwork.load_system_gpio_ports_page());
  WebServer.on("/interface_ios", HTTP_GET, SpartanServerNetwork.load_system_ios_ports_page());
  WebServer.on("/set_interface_ios", HTTP_POST, SpartanServerNetwork.interface_ios());
  
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