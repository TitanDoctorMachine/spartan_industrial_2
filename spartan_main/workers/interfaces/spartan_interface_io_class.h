#ifndef SPARTANINTERFACEIOCLASS_H 
#define SPARTANINTERFACEIOCLASS_H

int LATCHPIN = 12; //D6
int CLOCKPIN = 4; //D2  
int DataPortPin = 5; //D1 Port1
int EnablePortPin = 13; //D7 Port1
int PowerPortPin = 16; //D0 Port1
int DATAPORT[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

class SpartanInterfaceIoClass {
  private:
      
  public:
		void start();

		void set_power_port(bool state){digitalWrite(EnablePortPin, !state);};
  	void set_external_power_supply(bool state){digitalWrite(PowerPortPin, state);};

		void output_all_ports();
		void set_all_ports_low();
		void set_port (int, bool);
};

void SpartanInterfaceIoClass::start () {
	Serial.println("Started SpartanInterfaceIoClass");
  
	pinMode(EnablePortPin, OUTPUT);
  pinMode(PowerPortPin, OUTPUT);
	
	set_power_port(false);
	set_external_power_supply(false);
	set_all_ports_low();
	output_all_ports();
};

void SpartanInterfaceIoClass::set_all_ports_low () {
	for(int i=0; i++; i != 15){
    DATAPORT[i] = 0;
  }
}

void SpartanInterfaceIoClass::set_port (int addr, bool state) {
	if(addr < 0 && addr > 15){
		DATAPORT[addr] = state;
	}
}

void SpartanInterfaceIoClass::output_all_ports () {
	int Data;

	pinMode(CLOCKPIN, OUTPUT);
	pinMode(DataPortPin, OUTPUT);
	pinMode(LATCHPIN, OUTPUT);

	digitalWrite(LATCHPIN, 0);
	digitalWrite(DataPortPin, 0);
	digitalWrite(CLOCKPIN, 0);
  
  for (int i=15; i>=0; i--)  {
    
    digitalWrite(CLOCKPIN, 0);
    
    if (DATAPORT[i] == 0) { // yes, its inversed;    
      digitalWrite(DataPortPin, 1);
    } else {    
      digitalWrite(DataPortPin, 0);
    }
        
    digitalWrite(CLOCKPIN, 1);
    digitalWrite(DataPortPin, 0);
  }

	digitalWrite(CLOCKPIN, 0);
	digitalWrite(LATCHPIN, 1);
	delay(300);
	digitalWrite(LATCHPIN, 0);

};

#endif