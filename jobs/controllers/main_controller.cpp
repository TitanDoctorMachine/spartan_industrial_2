#ifndef MAIN_CLASS_GENERATOR
#define MAIN_CLASS_GENERATOR

#include "abstract_controller.cpp"

class SpartanControllerClass {
  private:
		void render_response(String, int);
		void internal_perform_request(String, String, String[32], String[32], String[32], String[32]);

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

      for (uint8_t i = 0; i < 7; i++) {
        header_array[i] = WebServer.headerName(i);
        header_content_array[i] = WebServer.header(i);
      }

      this->internal_perform_request(uri, method, params_array, params_content_array, header_array, header_content_array);
    };}

};

void SpartanControllerClass::start () {};

void SpartanControllerClass::internal_perform_request(String uri, String method, String params_array[32], String params_content_array[32], String header_array[32], String header_content_array[32]) {
  
  SpartanAbstractControllerClass* SpartanAbstractController = new SpartanAbstractControllerClass(uri, method, params_array, params_content_array, header_array, header_content_array);
  String content = SpartanAbstractController->perform_request();
  delete SpartanAbstractController;
  render_response(content, 200);
};

void SpartanControllerClass::render_response(String content, int code) {
  WebServer.send(code, "text/html", content);
};

SpartanControllerClass SpartanController;

#endif