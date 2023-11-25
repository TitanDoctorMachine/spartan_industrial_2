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

void SpartanServerNetworkClass::internal_load_system_ios_ports_page () {
	authenticate();

	String buff_loading_page = pre_load_contents(interface_ios_page_html);
	/*Capable of internal manipulation*/

  // buff_loading_page.replace("<*SP_system_token_name_tag*>", SpartanInterfaceFile.read_value("system_token"));

	buff_loading_page = render_html_page(buff_loading_page).c_str();
	WebServer.send(200, "text/html", buff_loading_page);
};