/* IGNUM4 Parser*/
void SpartanServerNetworkClass::internal_ignum4_interface(){

	// String cypher = WebServer.arg("cypher");
	// String message = Ignum04.decrypt_message(cypher);

	String message = WebServer.arg("cypher");
	String token = WebServer.arg("token");
  Logger.println(message);

	// if (message == "false"){
	if (SpartanInterfaceFile.read_value("system_token") != token){
  	Logger.println("MSG: FAIL!");
		WebServer.send(403, "text/html", "access denied.");
	}else{
		Logger.println(message);
		String return_value = perform_job(message);
		WebServer.send(200, "text/html", return_value);
	}

}

void SpartanServerNetworkClass::internal_ignum4_challenge(){
	WebServer.send(200, "text/html", Ignum04.get_challenge());
}

String SpartanServerNetworkClass::perform_job(String job_id){

	if (job_id == "LIGHT_UP"){
		SpartanInterfaceShiftRegister.set_port(1, true);
	} else
	
	if (job_id == "LIGHT_DOWN"){
		SpartanInterfaceShiftRegister.set_port(1, false);
	} else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	{
		return "FAIL";
	};

	return "OK";

}