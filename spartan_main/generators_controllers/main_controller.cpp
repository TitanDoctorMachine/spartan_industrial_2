#ifndef MAIN_CLASS_GENERATOR
#define MAIN_CLASS_GENERATOR

#include "abstract_controller.cpp" // Corrigido o include para corresponder ao nome do arquivo correto

class SpartanControllerClass {
private:
    void render_response(String, std::vector<std::pair<String, String>>, int);
    void internal_perform_request(String, String, std::vector<String>, std::vector<String>, String, String, String, String);

public:
    void start();

    std::function<void()> perform_request() { return [this]() {

        String uri = WebServer.uri();
        String method = (WebServer.method() == HTTP_GET) ? "GET" : "POST";

        std::vector<String> params_array;
        std::vector<String> params_content_array;

        // for (uint8_t i = 0; i < WebServer.args(); i++) {
        //     params_array.push_back(WebServer.argName(i));
        //     params_content_array.push_back(WebServer.arg(i));
        // }

        this->internal_perform_request(uri, method, params_array, params_content_array, WebServer.header("Cookie"), WebServer.header("Accept"), WebServer.header("Host"), WebServer.header("User-Agent"));
    }; }

};

void SpartanControllerClass::start() {};

void SpartanControllerClass::internal_perform_request(String uri, String method, std::vector<String> params_array, std::vector<String> params_content_array, String class_cookies, String class_accept, String class_host, String class_user_agent) {

    SpartanAbstractControllerClass* SpartanAbstractController = new SpartanAbstractControllerClass(uri, method, params_array, params_content_array);
    SpartanAbstractController->load_headers(class_cookies, class_accept, class_host, class_user_agent);
    render_response(SpartanAbstractController->perform_request(), SpartanAbstractController->render_headers(), SpartanAbstractController->code_render());
    delete SpartanAbstractController;

};

void SpartanControllerClass::render_response(String content, std::vector<std::pair<String, String>> array_pairs_render, int code) {

    for (const auto& pair : array_pairs_render) {
        Logger.println(("Sent Header: " + String(pair.first)));
        WebServer.sendHeader(String(pair.first), String(pair.second));
        //    WebServer.sendHeader("Cache-Control","no-cache");
        //    WebServer.sendHeader("Set-Cookie","session_token="+session_token);
    }

    if (content != "") WebServer.send(code, "text/html", content);
};

SpartanControllerClass SpartanController;

#endif