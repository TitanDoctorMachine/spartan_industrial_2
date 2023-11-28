/* IGNUM4 Parser*/
void SpartanServerNetworkClass::internal_ignum4_interface(){

	String cypher = WebServer.arg("cypher");
	String message = Ignum04.decrypt_message(cypher);

	WebServer.send(403, "text/html",
		"access denied."
	);
}

void SpartanServerNetworkClass::internal_ignum4_challenge(){

	WebServer.send(200, "text/html",
		Ignum04.get_challenge()
	);
}