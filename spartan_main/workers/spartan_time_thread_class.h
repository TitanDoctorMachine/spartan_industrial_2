#ifndef SPARTANTIMETHREADCLASS_H 
#define SPARTANTIMETHREADCLASS_H

class SpartanTimeThreadClass {
  private:
		void start();

    unsigned long next_running_time = 0;
    String time_run_in_milli_seconds_string = "0";

  public:
		//Construtor
		SpartanTimeThreadClass(void){}
		
		SpartanTimeThreadClass(int time_run) {
      time_run_in_milli_seconds_string = String(time_run);
    }
    bool run();
    bool every_x_milliseconds(int);

};

void SpartanTimeThreadClass::start () {
};

bool SpartanTimeThreadClass::run () {
	if (String(millis()).endsWith(time_run_in_milli_seconds_string)){
		return true;
	}
	return false;
};

bool SpartanTimeThreadClass::every_x_milliseconds (int time_run_in_milli_seconds_int) {
	if (millis() > next_running_time && millis() < (next_running_time + 100) ){
		next_running_time += time_run_in_milli_seconds_int;
		return true;
	}

	if (millis() > next_running_time){
		next_running_time += time_run_in_milli_seconds_int;
		return false;
	}
	return false;
};


#endif