#ifndef SPARTANINTERFACEDISPLAYCLASS_H 
#define SPARTANINTERFACEDISPLAYCLASS_H

class SpartanInterfaceDisplayClass {
  private:
      
  public:
		void start();

		void clear_screen(){display.clear();};
		void write_screen(){display.display();};
		
		void show_progress_bar(int counter);

};

void SpartanInterfaceDisplayClass::start () {
	Logger.println("Started SpartanInterfaceDisplayClass");

  // display.init();
  // display.flipScreenVertically();
	//Started in logger class

}

void SpartanInterfaceDisplayClass::show_progress_bar(int counter){
	display.drawProgressBar(0, 32, 120, 10, counter);
	display.setTextAlignment(TEXT_ALIGN_CENTER);
}




#endif