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

	/*For god's sake, this part is complicated...*/

	String buff_loading_page = pre_load_contents(interface_ios_page_html);

	String shift_ports;
	
	if(!digitalRead(POWER_PORT_PIN)){
		buff_loading_page.replace("<*SP_power_port_tag*>", "✓");
	} else {
		buff_loading_page.replace("<*SP_power_port_tag*>", "✗");
	};

	if(digitalRead(ENABLE_PORT_PIN)){
		buff_loading_page.replace("<*SP_ext_supply_port_tag*>", "✓");
	} else {
		buff_loading_page.replace("<*SP_ext_supply_port_tag*>", "✗");
	};
	
	if(USE_SHIFT_PORTS){
		shift_ports += R"=====(<div class="mini-card sub-card" style="width: 89%;"><h1>Shift Register Ports</h1><br>)=====";
		for (const auto& element : system_shift_register) {
			
			if (element.second == ""){
				continue;
			}

			shift_ports += R"=====(<h2 class='grid-32'><span class='button' )=====";
			shift_ports += R"=====(onclick="call_fast_ajax('/set_interface_ios', ')=====";
			shift_ports += String(element.first);
			shift_ports += R"=====(','shift_port');" id=')=====";
			shift_ports += String(element.first);
			shift_ports += "'><b class='big'>";
			
			if(DATA_PORT[element.first]){
				shift_ports += "✓";
			} else {
				shift_ports += "✗";
			};
			shift_ports += "</b>" + element.second + "</span></h2>";
		
		};
		shift_ports += "</div>";

		buff_loading_page.replace("<*SP_shift_ports_tag*>", shift_ports);
	} else {
		buff_loading_page.replace("<*SP_shift_ports_tag*>", "");
	}


  // buff_loading_page.replace("<*SP_system_token_name_tag*>", SpartanInterfaceFile.read_value("system_token"));

	buff_loading_page = render_html_page(buff_loading_page).c_str();
	WebServer.send(200, "text/html", buff_loading_page);
};

void SpartanServerNetworkClass::internal_load_system_gpio_ports_page () {
	authenticate();

	/*For god's sake, this part is complicated...*/

	String buff_loading_page = pre_load_contents(gpio_interface_ios_page_html);
	String gpio_ports;

	for (const auto& element : gpio_map) {
   	gpio_ports += R"=====(<h2 class='grid-32'><span class='button' )=====";
		gpio_ports += R"=====(onclick="call_fast_ajax('/set_interface_ios', ')=====";
		gpio_ports += String(element.first);
		gpio_ports += R"=====(','gpio');" id=')=====";
		gpio_ports += String(element.first);
		gpio_ports += "'><b class='big'>";
		if(digitalRead(element.first)){
			gpio_ports += "✓";
		} else {
			gpio_ports += "✗";
		};
		gpio_ports += "</b>" + element.second + "</span></h2>";
	};
	buff_loading_page.replace("<*SP_D_ports_tag*>", gpio_ports);

	buff_loading_page = render_html_page(buff_loading_page).c_str();
	WebServer.send(200, "text/html", buff_loading_page);
};

void SpartanServerNetworkClass::internal_interface_ios () {
	authenticate();

	String id_system = WebServer.arg("id_system");
	String mode = WebServer.arg("mode");

		if (mode == "power_port"){
			if(digitalRead(POWER_PORT_PIN)){
				pinMode(POWER_PORT_PIN, OUTPUT);
				digitalWrite(POWER_PORT_PIN, LOW);
			} else {
				pinMode(POWER_PORT_PIN, OUTPUT);
				digitalWrite(POWER_PORT_PIN, HIGH);
			};
			Logger.println("Set: Power Port");
		} else
		if (mode == "ext_power_supply"){
			if(digitalRead(ENABLE_PORT_PIN)){
				pinMode(ENABLE_PORT_PIN, OUTPUT);
				digitalWrite(ENABLE_PORT_PIN, LOW);
			} else {
				pinMode(ENABLE_PORT_PIN, OUTPUT);
				digitalWrite(ENABLE_PORT_PIN, HIGH);
			};
			Logger.println("Set: External Power Supply");
		} else
		if (mode == "shift_port"){
			if(DATA_PORT[id_system.toInt()]){
				SpartanInterfaceShiftRegister.set_port(id_system.toInt(), false);
			} else {
				SpartanInterfaceShiftRegister.set_port(id_system.toInt(), true);
			};
			Logger.println("Set: Shift Port " + id_system);
		}else
		if (mode == "gpio"){
			if(digitalRead(id_system.toInt())){
				pinMode(id_system.toInt(), OUTPUT);
				digitalWrite(id_system.toInt(), LOW);
			} else {
				pinMode(id_system.toInt(), OUTPUT);
				digitalWrite(id_system.toInt(), HIGH);
			};
			Logger.println("Set: GPIO Port " + id_system);

		}

	WebServer.send(200, "text/html",
		"setTimeout(() => {window.location.reload();}, 50);"
	);
}