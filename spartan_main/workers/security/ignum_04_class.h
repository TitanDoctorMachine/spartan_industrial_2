#ifndef IGNUM04CLASS_H 
#define IGNUM04CLASS_H

class Ignum04Class {
  private:
		String absolute_challenge;
      
  public:
		void start();
		void generate_new_challenge();
		String get_challenge();
		String decrypt_message(String challenge);

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

String Ignum04Class::decrypt_message(String challenge){
	return "in development";
}

Ignum04Class Ignum04;

#endif