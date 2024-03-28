#ifndef SPARTANINTERFACEIOCLASS_H 
#define SPARTANINTERFACEIOCLASS_H

//int DATA_PORT[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

class SpartanInterfaceShiftRegisterClass {
	private:
      
  public:
		void output_all_ports();
		void set_all_ports_low();
		void set_port (int, bool);

};

#ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS
	SpartanInterfaceShiftRegisterClass SpartanInterfaceShiftRegister;
#endif
class SpartanInterfaceIoClass {
  private:
      
  public:
		void start();

		void set_power_port(bool state){
			#ifdef SPARTAN_CONFIG_USE_ENABLE_PORT
				digitalWrite(ENABLE_PORT_PIN, state);
			#endif
		};
  	void set_external_power_supply(bool state){
			#ifdef SPARTAN_CONFIG_USE_POWER_PORT
				digitalWrite(POWER_PORT_PIN, !state);
			#endif
		};
};

void SpartanInterfaceIoClass::start () {
	Logger.println("Started SpartanInterfaceIoClass");
	#ifdef SPARTAN_CONFIG_USE_ENABLE_PORT
		pinMode(ENABLE_PORT_PIN, OUTPUT);
		set_power_port(false);
	#endif
	
	#ifdef SPARTAN_CONFIG_USE_POWER_PORT
	  pinMode(POWER_PORT_PIN, OUTPUT);
		set_external_power_supply(false);
	#endif

	
	#ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS
		SpartanInterfaceShiftRegister.set_all_ports_low();
		SpartanInterfaceShiftRegister.output_all_ports();
	#endif
};

void SpartanInterfaceShiftRegisterClass::set_all_ports_low () {
	#ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS
		for(int i=0; i++; i != 15){
			DATA_PORT[i] = 0;
	  }
	#endif
}

void SpartanInterfaceShiftRegisterClass::set_port (int addr, bool state) {
	#ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS
		DATA_PORT[addr] = state;
		output_all_ports();
	#endif
}

void SpartanInterfaceShiftRegisterClass::output_all_ports () {
	#ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS

		int Data;

		pinMode(CLOCK_PIN, OUTPUT);
		pinMode(DATA_PORT_PIN, OUTPUT);
		pinMode(LATCH_PIN, OUTPUT);

		digitalWrite(LATCH_PIN, 0);
		digitalWrite(DATA_PORT_PIN, 0);
		digitalWrite(CLOCK_PIN, 0);
		
		for (int i=15; i>=0; i--)  {
			
			digitalWrite(CLOCK_PIN, 0);
			
			if (DATA_PORT[i] == 0) { // yes, its inversed;    
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
	
	#endif

};

#endif