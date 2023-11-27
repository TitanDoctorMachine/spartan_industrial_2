#ifndef SPARTANSTATICCONFIGSCLASS_H 
#define SPARTANSTATICCONFIGSCLASS_H

bool USE_SHIFT_PORTS = false;
int LATCH_PIN, CLOCK_PIN, DATA_PORT_PIN, ENABLE_PORT_PIN, POWER_PORT_PIN, SDA_LCD, SDB_LCD;
std::unordered_map<int, String> system_shift_register, gpio_map;


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
  
  LATCH_PIN = 12; //D6
  CLOCK_PIN = 4; //D2  
  DATA_PORT_PIN = 5; //D1

  ENABLE_PORT_PIN = 13; //D7
  POWER_PORT_PIN = 16; //D0

  SDA_LCD = 14; //D5
  SDB_LCD = 0; //D3
  
  gpio_map[16] = "D0";
  gpio_map[5] = "D1";
  gpio_map[4] = "D2";
  gpio_map[0] = "D3";
  gpio_map[2] = "D4";
  gpio_map[14] = "D5";
  gpio_map[12] = "D6";
  gpio_map[13] = "D7";
  gpio_map[15] = "D8";
  gpio_map[3] = "D9";
  gpio_map[1] = "D10";
  gpio_map[9] = "D11";
  gpio_map[10] = "D12";
  gpio_map[11] = "D13";
  gpio_map[6] = "D14";
  gpio_map[7] = "D15";

  system_shift_register[0] = "Port_1";
  system_shift_register[1] = "Port_2";
  system_shift_register[2] = "Port_3";
  system_shift_register[3] = "Port_4";
  system_shift_register[4] = "Port_5";
  system_shift_register[5] = "Port_6";
  system_shift_register[6] = "Port_7";
  system_shift_register[7] = "Port_8";
  system_shift_register[8] = "Port_9";
  system_shift_register[9] = "Port_10";
  system_shift_register[10] = "Port_11";
  system_shift_register[11] = "Port_12";
  system_shift_register[12] = "Port_13";
  system_shift_register[13] = "Port_14";

}

  // for (const auto& elemento : mapa) {
  //   Logger.println(elemento.first);
  //   Logger.println(elemento.second);
  // }


SpartanConfigsStaticClass SpartanConfigsStatic;

#endif