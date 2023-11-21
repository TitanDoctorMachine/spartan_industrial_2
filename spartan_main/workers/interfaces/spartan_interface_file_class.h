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
	Serial.println("Started SpartanInterfaceFileClass");
	Serial.println("Mount LittleFS");
  if (!LittleFS.begin()) {
    Serial.println("LittleFS mount failed");
    return;
  }}

String SpartanInterfaceFileClass::read_value(String fileName) {
	Serial.println("Reading from: " + fileName);
	
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
	Serial.println("Writing to: '" + fileName + "' the value: " + value);
	
	File file = LittleFS.open(fileName, "w");
	if (file) {
		if (file.print(value)) {
			Serial.println("File written");
		} else {
			Serial.println("Write failed");
		}
	  delay(1000);  // Make sure the CREATE and LASTWRITE times are different
		file.close();
	}

}

#endif