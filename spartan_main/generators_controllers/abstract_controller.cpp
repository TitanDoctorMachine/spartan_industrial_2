#include "buffer_renders.h"

class SpartanAbstractControllerClass {
  private:
    String uri, http_verb, params_array[32], params_content_array[32];
    String cookies, accept, host, user_agent;
    String response_compiled;

		void prepare_resources(String, String, String[32], String[32]);
    void copy_array_to_another(String*, String*, int);
    String params(String);
    String headers(String);
    void render_plain(String);
    void post_render();

  public:
	
	  SpartanAbstractControllerClass(String class_uri, String class_method, String class_params_array[32], String class_params_content_array[32]) {
      prepare_resources (class_uri, class_method, class_params_array, class_params_content_array);
    }
    void load_headers(String, String, String, String);

  	String perform_request();
    String generateContent(String);
    String getContentType(String);
    bool  handleFileRead(String);
    void pre_render(String);

};

String SpartanAbstractControllerClass::perform_request () {

  Logger.println("REQUEST PARSER - URI: " + uri);
  Logger.println("REQUEST PARSER - VERB: " + http_verb);
  Logger.println("REQUEST PARSER - Accept: " + headers("Accept"));
  Logger.println("REQUEST PARSER - Cookie: " + headers("Cookie"));
  Logger.println("REQUEST PARSER - Host: " + headers("Host"));
  Logger.println("REQUEST PARSER - User-Agent: " + headers("User-Agent"));

  #include "routes.cpp";

  return response_compiled;
};

void SpartanAbstractControllerClass::prepare_resources (String class_uri, String class_method, String class_params_array[32], String class_params_content_array[32]) {
  uri = class_uri;
  http_verb = class_method;
  
  copy_array_to_another(class_params_array, params_array, sizeof(class_params_array));
  copy_array_to_another(class_params_content_array, params_content_array, sizeof(class_params_content_array));
};

void SpartanAbstractControllerClass::render_plain(String response){
  response_compiled = response;
}

void SpartanAbstractControllerClass::pre_render(String content){
  response_compiled += content;
}

void SpartanAbstractControllerClass::post_render(){
  
  String vars_to_try[128];
  int count_keys = 0;
  
  while (response_compiled.indexOf("<S&=") != -1) {
    int startIndex = response_compiled.indexOf("<S&=");
    int endIndex = response_compiled.indexOf("/>");
    if (endIndex != -1) {
      vars_to_try[count_keys] = response_compiled.substring(startIndex, endIndex + 2); // Include "/>" in the substring
      Serial.print("Replacing view-var: "); 
      Serial.print(vars_to_try[count_keys]); 
      Serial.print(" --> "); 
      Serial.println("."); 
      response_compiled.replace(vars_to_try[count_keys], "");
      /*
        Need to finalize this method
      */


      count_keys++;
    } else {
      break;
    }
  }
}




void SpartanAbstractControllerClass::load_headers (String class_cookies, String class_accept, String class_host, String class_user_agent) {
  cookies = class_cookies; 
  accept = class_accept;
  host = class_host;
  user_agent = class_user_agent;
};

String SpartanAbstractControllerClass::params(String key) {
  for (int i = 0; i < sizeof(params_array); i++) {
    if (strcmp(key.c_str(), params_array[i].c_str())){
      return params_content_array[i];
    }
  }
  return "";
};

String SpartanAbstractControllerClass::headers(String key) {
  if (key == "Accept"){ return accept; } else
  if (key == "Cookie"){ return cookies; } else 
  if (key == "Host"){ return host; } else 
  if (key == "User-Agent"){ return user_agent; } else 
  { return ""; }
};

void SpartanAbstractControllerClass::copy_array_to_another(String* src, String* dst, int len) {
  for (int i = 0; i < len; i++) {
    dst[i] = src[i];
  }
}

String SpartanAbstractControllerClass::generateContent(String compile_content) {
  static char content[16000];
  sprintf(content, "%s", compile_content.c_str());
  return String(content);
}

String SpartanAbstractControllerClass::getContentType(String filename) {
  if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".css")) return "text/css";
  else if (filename.endsWith(".js")) return "application/javascript";
  else if (filename.endsWith(".ico")) return "image/x-icon";
  else if (filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}

bool SpartanAbstractControllerClass::handleFileRead(String path) {

  if (path.endsWith("/")) path += "index.html";          
  String contentType = getContentType(path);             
  String pathWithGz = path + ".gz";
  
  if (LittleFS.exists(pathWithGz) || LittleFS.exists(path)) { 
   
    if (LittleFS.exists(pathWithGz)) path += ".gz";                                         
    
    File file = LittleFS.open(path, "r");                    
    
    size_t sent = WebServer.streamFile(file, contentType);
    
    file.close();                                          
    
    return true;
  }
  return false;
}