#ifndef SPARTANSERVERNETWORKCLASS_H 
#define SPARTANSERVERNETWORKCLASS_H

SpartanSecurityClass LocalSpartanSecurity;

class SpartanServerNetworkClass {
  private:

		void internal_ignum4_interface();
		void internal_ignum4_challenge();
		String perform_job(String);

  public:

		void start();
		void perform_task_loops();

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

/* IGNUM4 Parser*/
void SpartanServerNetworkClass::internal_ignum4_interface(){

	String message = WebServer.arg("cypher");
	String token = WebServer.arg("token");
  Logger.println(message);

	if (SpartanInterfaceFile.read_value("system_token") != token){
  	Logger.println("MSG: FAIL!");
		WebServer.send(403, "text/html", "access denied.");
	}else{

		Logger.println(message);

 		String commands[32]; // we will support consective 32 commands.
    int command_index = 0;

 		char charArray[message.length() + 1];

    message.toCharArray(charArray, sizeof(charArray));
    char *token = strtok(charArray, ".");

    while (token != NULL && command_index < 32) {
      commands[command_index] = String(token);
      command_index++;
      token = strtok(NULL, ".");
    }

		int ignum4_task_list_global_size = sizeof(ignum4_task_list_global);
		int occupied_buffer = 0;
		int commands_size = sizeof(commands); 

		for(int i= 0; i!=126; i++){ // 126 for some security
			if (ignum4_task_list_global[i] != "" and ignum4_task_list_global[i] != NULL){
				occupied_buffer++;
			}
		}

		if ((occupied_buffer + 32) >= 125){
			WebServer.send(500, "text/html", "buffer_exceeded");
		}

		for(int i= 0; i!=31; i++){ // 32 elements in control array
			ignum4_task_list_global[i + occupied_buffer] = commands[i];
		}

		WebServer.send(200, "text/html", "tasked_works");
	}

}

void SpartanServerNetworkClass::perform_task_loops(){
	int occupied_buffer = 0;
	
	for(int i= 0; i!=126; i++){ // 126 for some security
		if (ignum4_task_list_global[i] != "" and ignum4_task_list_global[i] != NULL){
			occupied_buffer++;
		}
	}

	if (occupied_buffer != 0 && sleep_time_in_progress_job <= millis()){
		perform_job(ignum4_task_list_global[0]);
		Logger.println("JOB: " + ignum4_task_list_global[0]);

		for (int i = 0; i < 126 - 1; ++i) { // 126 = size of buffer securely
			if (ignum4_task_list_global[i + 1] != ""){
				ignum4_task_list_global[i] = ignum4_task_list_global[i + 1];
			} else {
				ignum4_task_list_global[i] = "";
				continue;
			}
		}
	}

}

void SpartanServerNetworkClass::internal_ignum4_challenge(){
	WebServer.send(200, "text/html", Ignum04.get_challenge());
}

String SpartanServerNetworkClass::perform_job(String job_id){

  #include "job_performs.h"
	return "OK";
}

#endif