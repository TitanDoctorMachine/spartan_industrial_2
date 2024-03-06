#include "buffer_renders.h"
#include <vector>
#include <utility>

class SpartanAbstractControllerClass {
private:
  String uri, http_verb, cookies, accept, host, user_agent;
  String response_compiled;
  std::vector<String> params_keys, params_values;
  std::vector<std::pair<String, String>> view_vars;
  static const int MAX_VIEW_VARS = 128;

  void prepare_resources(String, String, const std::vector<String>&, const std::vector<String>&);
  void copy_array_to_another(const String*, String*, int);
  String params(const String&);
  String headers(const String&);
  void render_plain(const String&);
  void post_render();
  void internal_set_view_var(const String&, const String&);
  String load_partial(const String&);
  void render_partial(const String&, const String&);
  std::vector<std::pair<String, String>> headers_to_render;

public:
  int var_code_render = 200;

  SpartanAbstractControllerClass(String class_uri, String class_method, const std::vector<String>& class_params_keys, const std::vector<String>& class_params_values) {
    prepare_resources(class_uri, class_method, class_params_keys, class_params_values);
  }
  void load_headers(String, String, String, String);

  String perform_request();
  String getContentType(const String&);
  void pre_render(const String&);
  void pre_render_layout(const String&);
  void set_view_var(const String&, const String&);
  void set_view_var(const String&, int);
  void set_view_var(const String&, float);
  void set_view_var(const String&, const char*);
  void run_application();
  int code_render(){return var_code_render;}
  std::vector<std::pair<String, String>> render_headers(){return headers_to_render;}
  void add_header(const String&, const String&);
};

void SpartanAbstractControllerClass::prepare_resources(String class_uri, String class_method, const std::vector<String>& class_params_keys, const std::vector<String>& class_params_values) {
  uri = class_uri;
  http_verb = class_method;
  copy_array_to_another(class_params_keys.data(), params_keys.data(), class_params_keys.size());
  copy_array_to_another(class_params_values.data(), params_values.data(), class_params_values.size());
};

void SpartanAbstractControllerClass::copy_array_to_another(const String* src, String* dst, int len) {
  for (int i = 0; i < len; i++) {
    dst[i] = src[i];
  }
}

String SpartanAbstractControllerClass::perform_request() {
  Logger.println("REQUEST PARSER - URI: " + uri);
  Logger.println("REQUEST PARSER - VERB: " + http_verb);
  Logger.println("REQUEST PARSER - Accept: " + headers("Accept"));
  Logger.println("REQUEST PARSER - Cookie: " + headers("Cookie"));
  Logger.println("REQUEST PARSER - Host: " + headers("Host"));
  Logger.println("REQUEST PARSER - User-Agent: " + headers("User-Agent"));

  #include "routes.cpp";

  var_code_render = 200;

  return response_compiled;
};

void SpartanAbstractControllerClass::set_view_var(const String& key, const String& value) {
  if (view_vars.size() < MAX_VIEW_VARS) {
    view_vars.push_back(std::make_pair(key, value));
  }
}

void SpartanAbstractControllerClass::add_header(const String& key, const String& value) {
  headers_to_render.push_back(std::make_pair(key, value));
}

void SpartanAbstractControllerClass::set_view_var(const String& key, int value) {
  set_view_var(key, String(value));
}

void SpartanAbstractControllerClass::set_view_var(const String& key, float value) {
  set_view_var(key, String(value));
}

void SpartanAbstractControllerClass::set_view_var(const String& key, const char* value) {
  set_view_var(key, String(value));
}

void SpartanAbstractControllerClass::load_headers(String class_cookies, String class_accept, String class_host, String class_user_agent) {
  cookies = class_cookies;
  accept = class_accept;
  host = class_host;
  user_agent = class_user_agent;
};

String SpartanAbstractControllerClass::params(const String& key) {
  for (int i = 0; i < params_keys.size(); i++) {
    if (params_keys[i] == key) {
      return params_values[i];
    }
  }
  return "";
};

String SpartanAbstractControllerClass::headers(const String& key) {
  if (key == "Accept") return accept;
  else if (key == "Cookie") return cookies;
  else if (key == "Host") return host;
  else if (key == "User-Agent") return user_agent;
  return "";
};

String SpartanAbstractControllerClass::getContentType(const String& filename) {
  if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".css")) return "text/css";
  else if (filename.endsWith(".js")) return "application/javascript";
  else if (filename.endsWith(".ico")) return "image/x-icon";
  else if (filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}

void SpartanAbstractControllerClass::run_application() {
  #include "../../jobs/controllers/application.cpp"
  Logger.println("Loaded Application.cpp");
}

void SpartanAbstractControllerClass::pre_render(const String& content) {
  response_compiled.replace("<S&= render_absolute_view />", content);
}

void SpartanAbstractControllerClass::pre_render_layout(const String& layout) {
  #include "buffer_layouts.h"
}

String SpartanAbstractControllerClass::load_partial(const String& partial) {
  #include "buffer_partials.h"
}

void SpartanAbstractControllerClass::render_partial(const String& partial, const String& key) {
  set_view_var(key, load_partial(partial));
}


void SpartanAbstractControllerClass::render_plain(const String& response) {
  response_compiled = response;
}

void SpartanAbstractControllerClass::post_render() {
  const int MAX_VARS = 128;
  String vars_to_try[MAX_VARS];
  int count_keys = 0;
  
  while (response_compiled.indexOf("<S&=") != -1) {
    int startIndex = response_compiled.indexOf("<S&=");
    int endIndex = response_compiled.indexOf("/>", startIndex); // Search from startIndex
    if (endIndex != -1) {
      vars_to_try[count_keys] = response_compiled.substring(startIndex, endIndex + 2); // Include "/>" in the substring

      String var_to_work_with_and_trim = vars_to_try[count_keys];
      var_to_work_with_and_trim.replace("<S&=", "");
      var_to_work_with_and_trim.replace("/>", "");
      var_to_work_with_and_trim.trim();
            
      bool var_replaced = false;

      for (const auto& pair : view_vars) {
        if (pair.first == var_to_work_with_and_trim) {
          response_compiled.replace(vars_to_try[count_keys], pair.second);
          var_replaced = true;
          break;
        }
      }

      if (!var_replaced) {
        response_compiled.replace(vars_to_try[count_keys], "");
      }

      count_keys++;
    } else {
      break;
    }
  }
}


void SpartanAbstractControllerClass::internal_set_view_var(const String& key, const String& value) {
  if (view_vars.size() < MAX_VIEW_VARS) {
    view_vars.push_back(std::make_pair(key, value));
  }
}















/* #include "buffer_renders.h"

class SpartanAbstractControllerClass {
  private:
    String uri, http_verb, params_array[32], params_content_array[32], keys_view_var[128], values_view_var[128];
    String cookies, accept, host, user_agent;
    String response_compiled;
    int counter_array_views;

		void prepare_resources(String, String, String[32], String[32]);
    void copy_array_to_another(String*, String*, int);
    String params(String);
    String headers(String);
    void render_plain(String);
    void post_render();
    void internal_set_view_var(String, String);

  public:
	
	  SpartanAbstractControllerClass(String class_uri, String class_method, String class_params_array[32], String class_params_content_array[32]) {
      prepare_resources (class_uri, class_method, class_params_array, class_params_content_array);
    }
    void load_headers(String, String, String, String);

  	String perform_request();
    String generateContent(String);
    String getContentType(String);
    void pre_render(String);
    void pre_render_layout(String);
    void set_view_var(String, String);
    void set_view_var(String, int);
    void set_view_var(String, float);
    void set_view_var(String, const char*);
    void run_application();

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

void SpartanAbstractControllerClass::pre_render_layout(String layout){
  #include "buffer_layouts.h"
}

void SpartanAbstractControllerClass::pre_render(String content){
  response_compiled.replace("<S&= render_absolute_view />", content);
}

void SpartanAbstractControllerClass::post_render() {
  const int MAX_VARS = 128;
  String vars_to_try[MAX_VARS];
  int count_keys = 0;
  
  while (response_compiled.indexOf("<S&=") != -1) {
    int startIndex = response_compiled.indexOf("<S&=");
    int endIndex = response_compiled.indexOf("/>", startIndex); // Search from startIndex
    if (endIndex != -1) {
      vars_to_try[count_keys] = response_compiled.substring(startIndex, endIndex + 2); // Include "/>" in the substring

      String var_to_work_with_and_trim = vars_to_try[count_keys];
      var_to_work_with_and_trim.replace("<S&=", "");
      var_to_work_with_and_trim.replace("/>", "");
      var_to_work_with_and_trim.trim();
            
      Serial.print("Replacing view-var: "); 
      Serial.print(vars_to_try[count_keys]); 
      Serial.print(" --> "); 

      bool var_replaced = false;
      for (int i = 0; i < MAX_VARS - 1; i++) {
        if (keys_view_var[i] == var_to_work_with_and_trim) {
          Serial.println(values_view_var[i]); 
          response_compiled.replace(vars_to_try[count_keys], values_view_var[i]);
          var_replaced = true;
          break;
        }
      }

      if (!var_replaced) {
        Serial.println("."); 
        response_compiled.replace(vars_to_try[count_keys], "");
      }

      count_keys++;
    } else {
      break;
    }
  }
}

void SpartanAbstractControllerClass::internal_set_view_var(String key, String value){
  if( counter_array_views < 127 ) {
    keys_view_var[counter_array_views] = key;
    values_view_var[counter_array_views] = value;
    counter_array_views++;
  }
}

void SpartanAbstractControllerClass::run_application(){
  #include "../../jobs/controllers/application.cpp"
  Logger.println("Loaded Application.cpp");
}

void SpartanAbstractControllerClass::set_view_var(String key, String value){
  internal_set_view_var(key, value);
}

void SpartanAbstractControllerClass::set_view_var(String key, int value){
  internal_set_view_var(key, String(value));
}

void SpartanAbstractControllerClass::set_view_var(String key, float value){
  internal_set_view_var(key, String(value));
}

void SpartanAbstractControllerClass::set_view_var(String key, const char* value){
  internal_set_view_var(key, String(value));
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
*/