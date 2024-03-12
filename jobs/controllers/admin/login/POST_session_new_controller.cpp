  /*
    Authentication Method
  */

  Logger.set_activity_percent(50);

	String session_token = LocalSpartanSecurity.random_code();

	if(SpartanInterfaceFile.read_value("admin_password") == ""){
		SpartanInterfaceFile.write_value("admin_password", LocalSpartanSecurity.hash_256("admin"));
	}
	
	delay(200);

  Logger.hide_progress_bar();

	if(SpartanInterfaceFile.read_value("admin_password") == LocalSpartanSecurity.hash_256(WebServer.arg("password"))){
		SpartanInterfaceFile.write_value("session_token_system", session_token);
	
		add_header("Location","/admin/");
		add_header("Set-Cookie","session_token=" + session_token + "; Path=/admin/;SameSite=Strict;");
    
    set_view_var("new_token", session_token);
	} else {
		render_plain("open_notification('Wrong Password!');");
	}