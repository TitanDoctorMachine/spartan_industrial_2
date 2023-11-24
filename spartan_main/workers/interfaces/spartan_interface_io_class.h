#ifndef SPARTANINTERFACEIOCLASS_H 
#define SPARTANINTERFACEIOCLASS_H

int DATAPORT[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

class SpartanInterfaceShiftRegisterClass {
	private:
      
  public:
		void output_all_ports();
		void set_all_ports_low();
		void set_port (int, bool);

};
SpartanInterfaceShiftRegisterClass SpartanInterfaceShiftRegister;

class SpartanInterfaceIoClass {
  private:
      
  public:
		void start();

		void set_power_port(bool state){digitalWrite(ENABLE_PORT_PIN, !state);};
  	void set_external_power_supply(bool state){digitalWrite(POWER_PORT_PIN, state);};
};

void SpartanInterfaceIoClass::start () {
	Logger.println("Started SpartanInterfaceIoClass");
  
	pinMode(ENABLE_PORT_PIN, OUTPUT);
  pinMode(POWER_PORT_PIN, OUTPUT);
	
	set_power_port(false);
	set_external_power_supply(false);
	SpartanInterfaceShiftRegister.set_all_ports_low();
	SpartanInterfaceShiftRegister.output_all_ports();
};

void SpartanInterfaceShiftRegisterClass::set_all_ports_low () {
	for(int i=0; i++; i != 15){
    DATAPORT[i] = 0;
  }
}

void SpartanInterfaceShiftRegisterClass::set_port (int addr, bool state) {
	if(addr < 0 && addr > 15){
		DATAPORT[addr] = state;
	}
	output_all_ports();
}

void SpartanInterfaceShiftRegisterClass::output_all_ports () {
	int Data;

	pinMode(CLOCK_PIN, OUTPUT);
	pinMode(DATA_PORT_PIN, OUTPUT);
	pinMode(LATCH_PIN, OUTPUT);

	digitalWrite(LATCH_PIN, 0);
	digitalWrite(DATA_PORT_PIN, 0);
	digitalWrite(CLOCK_PIN, 0);
  
  for (int i=15; i>=0; i--)  {
    
    digitalWrite(CLOCK_PIN, 0);
    
    if (DATAPORT[i] == 0) { // yes, its inversed;    
      digitalWrite(DATA_PORT_PIN, 1);
    } else {    
      digitalWrite(DATA_PORT_PIN, 0);
    }
        
    digitalWrite(CLOCK_PIN, 1);
    digitalWrite(DATA_PORT_PIN, 0);
  }

	digitalWrite(CLOCK_PIN, 0);
	digitalWrite(LATCH_PIN, 1);
	delay(300);
	digitalWrite(LATCH_PIN, 0);

};

#endif