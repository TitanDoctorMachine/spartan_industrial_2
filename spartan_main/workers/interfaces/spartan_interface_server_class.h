#ifndef SPARTANINTERFACESERVERCLASS_H 
#define SPARTANINTERFACESERVERCLASS_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

class SpartanInterfaceServerClass {
	private:
		int tentativasConexao = 0;
		int maxTentativasConexao = 5;  

		bool server_mode = false;

		String ssid_for_internal_network, 
		password_for_internal_network,
		ssid_for_login,
		password_for_login;

  public:
  	void start();
		bool connect_wifi();
		void start_wifi_worker();
		String get_wifi_connection_status();
		String get_wifi_hotspot_status();

		String get_wifi_connection_IP_status();
		String get_wifi_hotspot_IP_status();

		String get_wifi_connection_name();
		String get_wifi_hotspot_name();
		


};

void SpartanInterfaceServerClass::start () {
	Logger.println("Started SpartanInterfaceServerClass");

	if(SpartanInterfaceFile.read_value("hotspot_ssid") == ""){
		SpartanInterfaceFile.write_value("hotspot_ssid", "SystemSpartanSlave2");
	}
	if(SpartanInterfaceFile.read_value("hotspot_password") == ""){
		SpartanInterfaceFile.write_value("hotspot_password", "0123456789");
	}

	ssid_for_internal_network = SpartanInterfaceFile.read_value("hotspot_ssid");
  password_for_internal_network = SpartanInterfaceFile.read_value("hotspot_password");

	ssid_for_login = SpartanInterfaceFile.read_value("wifi_ssid");
	password_for_login = SpartanInterfaceFile.read_value("wifi_password");

};

void SpartanInterfaceServerClass::start_wifi_worker () {
  
	WiFi.disconnect(true);
  
	if(WiFi.getMode() & WIFI_AP) {
    WiFi.softAPdisconnect(true);
  }
	
	Logger.println("Starting WIFI connection...");
	
	server_mode = !connect_wifi();
  
  if(server_mode){
    WiFi.softAP(ssid_for_internal_network, password_for_internal_network);
    IPAddress myIP = WiFi.softAPIP();
 		Logger.println("Couldn't Start Wifi, starting HOTSPOT:");
		Logger.println(ssid_for_internal_network);
		Logger.println(WiFi.softAPIP().toString());
  } else {
		Logger.println("Started Wifi : ");
		Logger.println(WiFi.localIP().toString());
	}

};

bool SpartanInterfaceServerClass::connect_wifi() {

  
  WiFi.begin(ssid_for_login, password_for_login);
	Logger.println(ssid_for_login);

  while (WiFi.status() != WL_CONNECTED && tentativasConexao < maxTentativasConexao) {
    delay(1000);
    tentativasConexao++;
		Logger.println("...");
  }
  if (WiFi.status() == WL_CONNECTED) {
		return true;
  } else {
    return false;
  }
}

/*Status Readers*/

String SpartanInterfaceServerClass::get_wifi_connection_status () {
	if(server_mode){return  "Offline";} else {return  "Online";}
};

String SpartanInterfaceServerClass::get_wifi_hotspot_status () {
	if(!server_mode){return  "Offline";} else {return  "Online";}
};

String SpartanInterfaceServerClass::get_wifi_connection_IP_status () { 
	if(!server_mode){return WiFi.localIP().toString();} else {return "NONE";}
};

String SpartanInterfaceServerClass::get_wifi_hotspot_IP_status () { 
	if(server_mode){return WiFi.softAPIP().toString();} else {return "NONE";}
};

String SpartanInterfaceServerClass::get_wifi_connection_name () {return ssid_for_login;};
String SpartanInterfaceServerClass::get_wifi_hotspot_name () {return ssid_for_internal_network;};

#endif



/*
	WiFiClient client;
	HTTPClient http;

	http.begin(client, url);

	int codigoResposta = http.GET();
	Logger.println(String(codigoResposta).c_str());

	if (codigoResposta == 200) {
		String plainContent = http.getString();
	}
	http.end();
*/
