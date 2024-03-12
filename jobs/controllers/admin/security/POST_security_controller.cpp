
	Logger.set_activity_percent(50);

	String output;
	String passwd = params("password");
	String system_token = params("system_token");
	
	if ((SpartanInterfaceFile.read_value("system_token") == system_token) && (passwd == "")){
		render_plain("open_notification('Nothing to Update!');");
	}

	if ((SpartanInterfaceFile.read_value("system_token") == system_token) && (passwd != "")){	
		SpartanInterfaceFile.write_value("admin_password", LocalSpartanSecurity.hash_256(passwd));
    render_plain(R"(
			open_notification('Password Updated Succesfully!');
			setCookie('session_token', '0', 1);
			setTimeout(() => {
				window.location.href = '/login'
			}, 2000);
		)");
	}
	
	if ((SpartanInterfaceFile.read_value("system_token") != system_token) && (passwd == "")){	
		SpartanInterfaceFile.write_value("system_token", system_token);
		render_plain("open_notification('Token Updated Succesfully!');");
	}

 	Logger.hide_progress_bar();