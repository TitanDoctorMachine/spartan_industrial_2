#ifndef SPARTANINTERFACESERVERCLASS_H 
#define SPARTANINTERFACESERVERCLASS_H

class SpartanInterfaceServerClass {
  private:
    int val;
      
  public:
		//Construtor
		// SpartanInterfaceServerClass

		void start();

};

void SpartanInterfaceServerClass::start () {
	Serial.println("Started SpartanInterfaceServerClass");
};
#endif