#ifndef SPARTANINTERFACEFILECLASS_H 
#define SPARTANINTERFACEFILECLASS_H

#include <LittleFS.h>

class SpartanInterfaceFileClass {
  private:
      
  public:
		void start();
		String read_value(String);
		void write_value(String, String);

};

void SpartanInterfaceFileClass::start () {
	Logger.println("Started SpartanInterfaceFileClass");
	Logger.println("Mount LittleFS");
  if (!LittleFS.begin()) {
    Logger.println("LittleFS mount failed");
    return;
  }}

String SpartanInterfaceFileClass::read_value(String fileName) {
	Logger.println("Reading from: " + fileName);
	
	File file = LittleFS.open(fileName, "r");
	if (file) {

  	size_t filesize = file.size();
  	String data = file.readString();

		//while (file.available()) { value += file.read(); }
  	file.close();

		return data.c_str();
	}
	return ""; 
}

void SpartanInterfaceFileClass::write_value(String fileName, String value) {
	Logger.println("Writing to: '" + fileName + "' the value: " + value);
	Logger.set_activity_percent(50);
	File file = LittleFS.open(fileName, "w");
	if (file) {
		if (file.print(value)) {
			Logger.hide_progress_bar();
			Logger.println("File written");

		} else {
			Logger.println("Write failed");
		}
	  delay(1000);  // Make sure the CREATE and LASTWRITE times are different
		file.close();
	}

}

#endif