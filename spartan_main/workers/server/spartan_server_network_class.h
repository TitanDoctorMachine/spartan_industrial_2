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

#include "spartan_server_network_ignum4_class.cpp"

#endif