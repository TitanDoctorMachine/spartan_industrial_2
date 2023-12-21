#ifndef IGNUM04CLASS_H 
#define IGNUM04CLASS_H

String ignum4_task_list_global[];

class Ignum04Class {
  private:
		String absolute_challenge;
      
  public:
		void start();
		void generate_new_challenge();
		String get_challenge();
		String decrypt_message(String content);

};

void Ignum04Class::start () {
	generate_new_challenge();
}

void Ignum04Class::generate_new_challenge() {
	absolute_challenge = SpartanSecurity.random_code();
}

String Ignum04Class::get_challenge() {
	return absolute_challenge; 
}

String Ignum04Class::decrypt_message(String content){
	String current_key = SpartanSecurity.hash_256(absolute_challenge + SpartanInterfaceFile.read_value("system_token"));
	String command = SpartanSecurity.decrypt(content, current_key, absolute_challenge);

	if(command.indexOf("SYSTEM_OK") != -1){
		
		String substringToRemove = "SYSTEM_OK";
    int substringIndex = command.indexOf(substringToRemove);
	  command = command.substring(0, substringIndex) + command.substring(substringIndex + substringToRemove.length());

		Logger.println(command);
		return command; // its simplest by the way to return the JSON
	} else {
		Logger.println("MSG: FAIL!");
		return "false";
	}

}

Ignum04Class Ignum04;

#endif