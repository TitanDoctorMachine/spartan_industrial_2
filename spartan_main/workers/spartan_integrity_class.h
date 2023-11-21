#ifndef SPARTANINTEGRITYCLASS_H 
#define SPARTANINTEGRITYCLASS_H

class SpartanIntegrityClass {
  private:
    int val;
      
  public:
		//Construtor
		// SpartanIntegrityClass

		void start();

};

void SpartanIntegrityClass::start () {
	Serial.println("Started SpartanIntegrityClass");
};
#endif