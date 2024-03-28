#ifndef SPARTANASYNCJOBCLASS_H 
#define SPARTANASYNCJOBCLASS_H

class SpartanAsyncJobClass {
  private:
    int val;
      
  public:
		void start();
		void run_threads();

};

void SpartanAsyncJobClass::start () {
	Logger.println("Started SpartanAsyncJobClass");
};

void SpartanAsyncJobClass::run_threads () {

	if(thread_server_3.run()){
		#include "../../../async_jobs/async_job_1.cpp"
	}

	if(thread_server_4.run()){
		#include "../../../async_jobs/async_job_2.cpp"
	}

	if(thread_server_5.run()){
		#include "../../../async_jobs/async_job_3.cpp"
	}

	if(thread_server_6.run()){
		#include "../../../async_jobs/async_job_4.cpp"
	}

};


SpartanAsyncJobClass SpartanAsyncJob;
#endif