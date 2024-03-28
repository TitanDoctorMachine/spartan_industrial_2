#ifndef SPARTANSTATICCONFIGSCLASS_H 
#define SPARTANSTATICCONFIGSCLASS_H

bool DATA_PORT[16];
int LATCH_PIN, CLOCK_PIN, DATA_PORT_PIN, ENABLE_PORT_PIN, POWER_PORT_PIN, SDA_LCD, SDB_LCD;
std::unordered_map<int, String> system_shift_register, gpio_map;
int size_of_mapped_commands = 14;


#define SPARTAN_CONFIG_USE_DISPLAY //use this if using OLED display
#define SPARTAN_CONFIG_USE_SHIFT_PORTS // use if want to use shift_port interface
#define SPARTAN_CONFIG_USE_POWER_PORT
#define SPARTAN_CONFIG_USE_ENABLE_PORT


class SpartanConfigsStaticClass {
  private:
      
  public:
		//Construtor
		// SpartanConfigsStaticClass
    void start();
    SpartanConfigsStaticClass(void){
      start();
    };
};

void SpartanConfigsStaticClass::start(){
  #ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS
    LATCH_PIN = 12; //D6
    CLOCK_PIN = 4; //D2  
    DATA_PORT_PIN = 5; //D1
  #endif

  #ifdef SPARTAN_CONFIG_USE_POWER_PORT
    POWER_PORT_PIN = 13; //D7
  #endif

  #ifdef SPARTAN_CONFIG_USE_ENABLE_PORT
   ENABLE_PORT_PIN = 16; //D0
  #endif
  
  #ifdef SPARTAN_CONFIG_USE_DISPLAY
    SDA_LCD = 14; //D5
    SDB_LCD = 0; //D3
  #endif
  
  #ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS
    system_shift_register[1] = "Port_1";
    system_shift_register[2] = "Port_2";
    system_shift_register[3] = "Port_3";
    system_shift_register[4] = "Port_4";
    system_shift_register[5] = "Port_5";
    system_shift_register[6] = "Port_6";
    system_shift_register[7] = "Port_7";
    system_shift_register[9] = "Port_8";
    system_shift_register[10] = "Port_9";
    system_shift_register[11] = "Port_10";
    system_shift_register[12] = "Port_11";
    system_shift_register[13] = "Port_12";
    system_shift_register[14] = "Port_13";
    system_shift_register[15] = "Port_14";

    DATA_PORT[1] = false; 
    DATA_PORT[2] = false; 
    DATA_PORT[3] = false; 
    DATA_PORT[4] = false; 
    DATA_PORT[5] = false; 
    DATA_PORT[6] = false; 
    DATA_PORT[7] = false; 
    DATA_PORT[9] = false; 
    DATA_PORT[10] = false; 
    DATA_PORT[11] = false; 
    DATA_PORT[12] = false; 
    DATA_PORT[13] = false; 
    DATA_PORT[14] = false; 
    DATA_PORT[15] = false; 
  #endif

  gpio_map[16] = "D0";
  // gpio_map[5] = "D1";
  // gpio_map[4] = "D2";
  // gpio_map[0] = "D3";
  gpio_map[2] = "D4";
  // gpio_map[14] = "D5";
  // gpio_map[12] = "D6";
  gpio_map[13] = "D7";
  gpio_map[15] = "D8";
  gpio_map[3] = "D9";
  gpio_map[1] = "D10";
  // gpio_map[9] = "D11"; // better not use this pin (esp resets)
  gpio_map[10] = "D12";
  // gpio_map[11] = "D13"; // better not use this pin (esp resets)
  // gpio_map[6] = "D14"; // better not use this pin (esp resets)
  // gpio_map[7] = "D15"; // better not use this pin (esp resets)

}

SpartanConfigsStaticClass SpartanConfigsStatic;

#endif