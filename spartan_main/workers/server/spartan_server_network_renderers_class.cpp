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