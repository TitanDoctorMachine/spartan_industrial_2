/* IGNUM4 Parser*/
void SpartanServerNetworkClass::internal_ignum4_interface(){

	String cypher = WebServer.arg("cypher");
	String message = Ignum04.decrypt_message(cypher);

	if (message == "false"){
		WebServer.send(403, "text/html", "access denied.");
	}else{
		// for each element add in array processing 
		// ignum4_task_list_global


		WebServer.send(200, "text/html", "tasked works.");
	}

}

void SpartanServerNetworkClass::internal_ignum4_challenge(){
	WebServer.send(200, "text/html", Ignum04.get_challenge());
}