#ifndef SPARTANINTERFACECLASS_H 
#define SPARTANINTERFACECLASS_H

#include "interfaces/spartan_interface_file_class.h"
SpartanInterfaceFileClass SpartanInterfaceFile;

#include "interfaces/spartan_interface_display_class.h"
#include "interfaces/spartan_interface_io_class.h"
#include "interfaces/spartan_interface_server_class.h"

SpartanInterfaceDisplayClass SpartanInterfaceDisplay;
SpartanInterfaceIoClass SpartanInterfaceIo;
SpartanInterfaceServerClass SpartanInterfaceServer;

class SpartanInterfaceClass {
  private:
    int val;
      
  public:
		//Construtor
		// SpartanInterfaceClass

		void start();

};

void SpartanInterfaceClass::start () {
	Logger.println("Started SpartanInterfaceClass");

  SpartanInterfaceFile.start();
	SpartanInterfaceDisplay.start();
  SpartanInterfaceIo.start();
  SpartanInterfaceServer.start();

};

SpartanInterfaceClass SpartanInterface;

#endif