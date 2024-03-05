#ifndef MAIN_CLASS_GENERATOR
#define MAIN_CLASS_GENERATOR

#include "abstract_controller.cpp"

class SpartanControllerClass {
  private:
		void render_response(const char *, int);
		void internal_perform_request(String, String, String[32], String[32], String, String, String, String);

  public:
		void start();

		std::function<void()> perform_request() {return [this]() {
      
      String uri = WebServer.uri();
      String method = (WebServer.method() == HTTP_GET) ? "GET" : "POST";
      
      String params_array[32];
      String params_content_array[32];

      String header_array[32];
      String header_content_array[32];

      for (uint8_t i = 0; i < WebServer.args(); i++) {
        params_array[i] = WebServer.argName(i);
        params_content_array[i] = WebServer.arg(i);
      }

      this->internal_perform_request(uri, method, params_array, params_content_array, WebServer.header("Cookie"), WebServer.header("Accept"), WebServer.header("Host"), WebServer.header("User-Agent"));
    };}

};

void SpartanControllerClass::start () {};

void SpartanControllerClass::internal_perform_request(String uri, String method, String params_array[32], String params_content_array[32], String class_cookies, String class_accept, String class_host, String class_user_agent) {
  
  SpartanAbstractControllerClass* SpartanAbstractController = new SpartanAbstractControllerClass(uri, method, params_array, params_content_array);
  SpartanAbstractController->load_headers(class_cookies, class_accept, class_host, class_user_agent);
  const char * content = SpartanAbstractController->perform_request().c_str();
  delete SpartanAbstractController;

  //  SpartanInterfaceFile.write_value("buffer_view", "0");
  // maybe using files to caching?

  render_response(content, 200);
};

void SpartanControllerClass::render_response(const char * content, int code) {
	//WebServer.sendHeader("Cache-Control","no-cache");
  if (content != "") WebServer.send(code, "text/html", content);
};

SpartanControllerClass SpartanController;

#endif