#include "spartan_main/spartan_main_class.h"

SpartanMainClass Main;

void setup() {
  Main.start();
}

void loop() {
  Main.sustain_loop();
}




/*


int LATCHPIN = 12; //D6
int CLOCKPIN = 4; //D2  
int DataPortPin = 5; //D1 Port1
int EnablePortPin = 13; //D7 Port1
int PowerPortPin = 16; //D0 Port1

int count_test = 0;

int DATAPORT[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};


SSD1306Wire  display(0x3c, 14, 0); //D5 e D3

void setup() {
  OutputAllPorts(CLOCKPIN, LATCHPIN);

  pinMode(EnablePortPin, OUTPUT);
  pinMode(PowerPortPin, OUTPUT);
  
  digitalWrite(PowerPortPin, 1);
  digitalWrite(EnablePortPin, 1);
  delay(1000);
  digitalWrite(EnablePortPin, 0);

  display.init();
  display.flipScreenVertically();

}

void loop() {

  for(int i=0; i++; i != 15){
    DATAPORT[i] = 0;
  }
  OutputAllPorts(CLOCKPIN, LATCHPIN);
  
  DATAPORT[count_test] = 1;

  ProgressBar(count_test);
  
  count_test++;

  if(count_test == 16){
    count_test = 0;
    DATAPORT[0] = 0;
    DATAPORT[1] = 0;
    DATAPORT[2] = 0;
    DATAPORT[3] = 0;
    DATAPORT[4] = 0;
    DATAPORT[5] = 0;
    DATAPORT[6] = 0;
    DATAPORT[7] = 0;
    DATAPORT[8] = 0;
    DATAPORT[9] = 0;
    DATAPORT[10] = 0;
    DATAPORT[11] = 0;
    DATAPORT[12] = 0;
    DATAPORT[13] = 0;
    DATAPORT[14] = 0;
    DATAPORT[15] = 0;
    DATAPORT[16] = 0;
  }
  
  delay(800);

}

void OutputAllPorts(int Clock, int Latch) {

int Data;

pinMode(Clock, OUTPUT);
pinMode(DataPortPin, OUTPUT);
pinMode(Latch, OUTPUT);

digitalWrite(Latch, 0);
digitalWrite(DataPortPin, 0);
digitalWrite(Clock, 0);
  
  for (int i=15; i>=0; i--)  {
    
    digitalWrite(Clock, 0);
    
    if (DATAPORT[i] == 0) { // yes, its inversed;    
      digitalWrite(DataPortPin, 1);
    } else {    
      digitalWrite(DataPortPin, 0);
    }
        
    digitalWrite(Clock, 1);
  
    digitalWrite(DataPortPin, 0);
    
  }

digitalWrite(Clock, 0);
digitalWrite(Latch, 1);
delay(300);
digitalWrite(Latch, 0);
}


//print uma barra de progresso
void ProgressBar(int counter){

    int convert17[] = {1, 6, 12, 19, 25, 31, 37, 43, 49, 57, 63, 69, 77, 83, 89, 95, 100};
  
    display.clear();
    //Desenha a barra de progresso
    display.drawProgressBar(0, 32, 120, 10, convert17[counter]);
    //Atualiza a porcentagem completa
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.display();
}
*/