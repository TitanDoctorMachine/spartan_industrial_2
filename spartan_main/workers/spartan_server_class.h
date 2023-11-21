#ifndef SPARTANSERVERCLASS_H 
#define SPARTANSERVERCLASS_H

class SpartanServerClass {
  private:
    int val;
      
  public:
		//Construtor
		// SpartanServerClass

		void start();

};

void SpartanServerClass::start () {
	Serial.println("Started SpartanServerClass");
};
#endif