#ifndef SPARTANINTERFACEDISPLAYCLASS_H 
#define SPARTANINTERFACEDISPLAYCLASS_H

class SpartanInterfaceDisplayClass {
  private:
      
  public:
		void start();

		void clear_screen(){
			#ifdef SPARTAN_CONFIG_USE_DISPLAY 
				display.clear();
			#endif
		};
		void write_screen(){
			#ifdef SPARTAN_CONFIG_USE_DISPLAY 
				display.display();
			#endif
		};
		
		void show_progress_bar(int counter);

};

void SpartanInterfaceDisplayClass::start () {
	Logger.println("Started SpartanInterfaceDisplayClass");
}

void SpartanInterfaceDisplayClass::show_progress_bar(int counter){
	#ifdef SPARTAN_CONFIG_USE_DISPLAY 
		display.drawProgressBar(0, 32, 120, 10, counter);
		display.setTextAlignment(TEXT_ALIGN_CENTER);
	#endif

}




#endif