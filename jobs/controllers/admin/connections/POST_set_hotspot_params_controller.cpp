  String wifi_name = params("wifi_name");
	String wifi_pass = params("wifi_pass");
	SpartanInterfaceFile.write_value("hotspot_ssid", wifi_name);
	SpartanInterfaceFile.write_value("hotspot_password", wifi_pass);
	render_plain("open_notification('Updated Register! Please Reboot Your System Manually!');");