#ifndef SPARTANSERVERNETWORKCLASS_H 
#define SPARTANSERVERNETWORKCLASS_H

#include "views/base_layouts/logob64.png.h"
#include "views/base_layouts/application.css.h"
#include "views/base_layouts/application.js.h"
#include "views/base_layouts/pre_load_screen.html.h"

#include "views/login/login_page.html.h"
#include "views/sidebar.html.h"
#include "views/dashboard/dashboard.html.h"
#include "views/wifi/wifi_page.html.h"
#include "views/security/security_page.html.h"


SpartanSecurityClass LocalSpartanSecurity;

class SpartanServerNetworkClass {
  private:
		String input_js_in_page(String);
		String input_css_in_page(String);
  	String input_logo_in_page(String);
  	String input_side_bar_html_in_page(String);
  	String pre_load_contents(String);
		
		String render_html_page(String);	

		void authenticate();	

		/*For  loading the pages*/
 		void internal_load_dashboard_page();
 		void internal_load_wifi_page();
 		void internal_update_hotspot_params();
 		void internal_update_network_params();
 		void internal_load_login_page();
 		void internal_login_method();
		void internal_load_security_screen();
		void internal_update_system_password();

  public:

		void start();

		/*The call of the pages class render*/
	  //LOGIN
		std::function<void()> load_login_page() {return [this]() {
      this->internal_load_login_page();
    };}
		std::function<void()> login_method() {return [this]() {
      this->internal_login_method();
    };}
		
		//Views
		std::function<void()> load_dashboard_page() {return [this]() {
      this->internal_load_dashboard_page();
    };}

	  std::function<void()> load_wifi_page() {return [this]() {
      this->internal_load_wifi_page();
    };}

	  std::function<void()> update_hotspot_params() {return [this]() {
      this->internal_update_hotspot_params();
    };}

    std::function<void()> update_network_params() {return [this]() {
      this->internal_update_network_params();
    };}

    std::function<void()> load_security_screen() {return [this]() {
      this->internal_load_security_screen();
    };}

    std::function<void()> update_system_password() {return [this]() {
      this->internal_update_system_password();
    };}
		


		
		
};

void SpartanServerNetworkClass::start () {
	Logger.println("Started SpartanServerNetworkClass");
};

/*NORMAL PAGES*/

void SpartanServerNetworkClass::internal_load_dashboard_page () {
	authenticate();

	String buff_loading_page = pre_load_contents(dashboard_html);
	/*Capable of internal manipulation*/
	
	buff_loading_page = render_html_page(buff_loading_page).c_str();
	WebServer.send(200, "text/html", buff_loading_page);
};

void SpartanServerNetworkClass::internal_load_wifi_page () {
	authenticate();

	String buff_loading_page = pre_load_contents(wifi_page_html_html);
	/*Capable of internal manipulation*/

	buff_loading_page.replace("<*SP_wifi_connection_tag*>", SpartanInterfaceServer.get_wifi_connection_status());
	buff_loading_page.replace("<*SP_wifi_hotspot_tag*>", SpartanInterfaceServer.get_wifi_hotspot_status());
	
	buff_loading_page.replace("<*SP_wifi_connection_ip_tag*>", SpartanInterfaceServer.get_wifi_connection_IP_status());
	buff_loading_page.replace("<*SP_wifi_hotspot_ip_tag*>", SpartanInterfaceServer.get_wifi_hotspot_IP_status());

	buff_loading_page.replace("<*SP_wifi_connection_name_tag*>", SpartanInterfaceServer.get_wifi_connection_name());
	buff_loading_page.replace("<*SP_wifi_hotspot_name_tag*>", SpartanInterfaceServer.get_wifi_hotspot_name());

	buff_loading_page = render_html_page(buff_loading_page).c_str();
	WebServer.send(200, "text/html", buff_loading_page);
};

void SpartanServerNetworkClass::internal_update_hotspot_params () {
	authenticate();

	String wifi_name = WebServer.arg("wifi_name");
	String wifi_pass = WebServer.arg("wifi_pass");
	SpartanInterfaceFile.write_value("hotspot_ssid", wifi_name);
	SpartanInterfaceFile.write_value("hotspot_password", wifi_pass);
	WebServer.send(200, "text/html",
		"open_notification('Updated Register! Please Reboot Your System Manually!');"
	);
}

void SpartanServerNetworkClass::internal_update_network_params () {
	authenticate();

	String wifi_name = WebServer.arg("wifi_name");
	String wifi_pass = WebServer.arg("wifi_pass");
	SpartanInterfaceFile.write_value("wifi_ssid", wifi_name);
	SpartanInterfaceFile.write_value("wifi_password", wifi_pass);
	WebServer.send(200, "text/html",
		"open_notification('Updated Register! Please Reboot Your System Manually!');"
	);
}


void SpartanServerNetworkClass::internal_load_security_screen () {
	authenticate();

	String buff_loading_page = pre_load_contents(security_page_html);
	/*Capable of internal manipulation*/

	// SpartanInterfaceFile.write_value("admin_password", LocalSpartanSecurity.hash_256(passwd));

  buff_loading_page.replace("<*SP_system_token_name_tag*>", SpartanInterfaceFile.read_value("system_token"));


	buff_loading_page = render_html_page(buff_loading_page).c_str();
	WebServer.send(200, "text/html", buff_loading_page);
};

void SpartanServerNetworkClass::internal_update_system_password () {
	authenticate();

	Logger.set_activity_percent(50);

	String output;

	String passwd = WebServer.arg("password");
	String system_token = WebServer.arg("system_token");
	
	if ((SpartanInterfaceFile.read_value("system_token") == system_token) && (passwd == "")){
		output = R"(
			open_notification('Nothing to Update!');
		)";
	}

	if ((SpartanInterfaceFile.read_value("system_token") == system_token) && (passwd != "")){	
		SpartanInterfaceFile.write_value("admin_password", LocalSpartanSecurity.hash_256(passwd));
		output = R"(
			open_notification('Password Updated Succesfully!');
			setCookie('session_token', '0', 1);
			setTimeout(() => {
				window.location.href = '/login'
			}, 2000);
		)";
	}
	
	if ((SpartanInterfaceFile.read_value("system_token") != system_token) && (passwd == "")){	
		SpartanInterfaceFile.write_value("system_token", system_token);
		output = R"(
			open_notification('Token Updated Succesfully!');
		)";
	}

 	Logger.hide_progress_bar();
	
	WebServer.send(200, "text/html", output);
}


/* RENDER PARTS BLOCK*/
String SpartanServerNetworkClass::pre_load_contents(String page_input){
	String buff_loading_page = pre_load_screen;
	buff_loading_page.replace("<*SP_content_tag*>", page_input);
	return buff_loading_page;
}

String SpartanServerNetworkClass::render_html_page(String page_input){
	
	page_input = input_css_in_page(page_input); // css
	page_input = input_js_in_page(page_input); // js

	page_input = input_side_bar_html_in_page(page_input); //sidebar

	page_input = input_logo_in_page(page_input); // image assets

	return page_input;

}

String SpartanServerNetworkClass::input_logo_in_page(String page_input){
	page_input.replace("<*SP_logo_tag*>", logo_image_b64);
	return page_input;
}

String SpartanServerNetworkClass::input_css_in_page(String page_input){
	page_input.replace("<*SP_css_tag*>", application_css);
	return page_input;
}

String SpartanServerNetworkClass::input_js_in_page(String page_input){
  page_input.replace("<*SP_js_tag*>", application_js);
	return page_input;
}

String SpartanServerNetworkClass::input_side_bar_html_in_page(String page_input){
  page_input.replace("<*SP_sidebar_tag*>", side_bar_html);
	return page_input;
}


/*AUTHENTICATION*/
void SpartanServerNetworkClass::authenticate() {
	String cookie = WebServer.header("Cookie");
	if (!(cookie.indexOf("session_token=" + SpartanInterfaceFile.read_value("session_token_system")) != -1)) {
  	WebServer.send(200, "text/html", R"(
			<html><head><meta charset="utf-8"/>
				<meta http-equiv="refresh" content="0; URL='/login'"/> 
			</head></html>)");
	}
}

void SpartanServerNetworkClass::internal_load_login_page () {	
	String buff_loading_page = pre_load_contents(login_page_html);
	buff_loading_page = render_html_page(buff_loading_page).c_str();
	WebServer.send(200, "text/html", buff_loading_page);
};

void SpartanServerNetworkClass::internal_login_method () {
  Logger.set_activity_percent(50);

	String session_token = LocalSpartanSecurity.random_code();

	if(SpartanInterfaceFile.read_value("admin_password") == ""){
		SpartanInterfaceFile.write_value("admin_password", LocalSpartanSecurity.hash_256("admin"));
	}
	
	delay(200);

  Logger.hide_progress_bar();


	if(SpartanInterfaceFile.read_value("admin_password") == LocalSpartanSecurity.hash_256(WebServer.arg("password"))){
		SpartanInterfaceFile.write_value("session_token_system", session_token);
	
		WebServer.sendHeader("Location","/");
		WebServer.sendHeader("Cache-Control","no-cache");
		WebServer.sendHeader("Set-Cookie","session_token="+session_token);

		String output = R"(
			open_notification('User Logged Succesfully!');
			setCookie('session_token', ')";
		output += session_token;
		output += R"(', 1);
			setTimeout(() => {
				window.location.href = '/'
			}, 2000);
		)";
		WebServer.send(200, "text/html", output);

	} else {
		WebServer.send(200, "text/html", "open_notification('Wrong Password!');");
	}
};

#endif