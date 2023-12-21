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
#include "views/interface_ios/interface_ios_page.html.h"
#include "views/interface_ios/gpio_interface_ios_page.html.h"


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
		void internal_load_system_ios_ports_page();
		void internal_load_system_gpio_ports_page();
		void internal_interface_ios();
		void internal_ignum4_interface();
		void internal_ignum4_challenge();
		String perform_job(String);

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
		
		std::function<void()> load_system_ios_ports_page() {return [this]() {
      this->internal_load_system_ios_ports_page();
    };}
		std::function<void()> load_system_gpio_ports_page() {return [this]() {
      this->internal_load_system_gpio_ports_page();
    };}
		std::function<void()> interface_ios() {return [this]() {
      this->internal_interface_ios();
    };}
		std::function<void()> ignum4_interface() {return [this]() {
      this->internal_ignum4_interface();
    };}
		std::function<void()>ignum4_challenge() {return [this]() {
      this->internal_ignum4_challenge();
    };}

		

		
};

void SpartanServerNetworkClass::start () {
	Logger.println("Started SpartanServerNetworkClass");
};

#include "spartan_server_network_actions_class.cpp"
#include "spartan_server_network_renderers_class.cpp"
#include "spartan_server_network_ignum4_class.cpp"

#endif