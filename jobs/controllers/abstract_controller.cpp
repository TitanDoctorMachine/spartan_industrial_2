class SpartanAbstractControllerClass {
  private:
    String uri, http_verb, params_array[32], params_content_array[32], header_array[32], header_content_array[32];

		void prepare_resources(String, String, String[32], String[32], String[32], String[32]);
    void copy_array_to_another(String*, String*, int);
    String params(String);
    String headers(String);

  public:
	
	  SpartanAbstractControllerClass(String class_uri, String class_method, String class_params_array[32], String class_params_content_array[32], String class_header_array[32], String class_header_content_array[32]) {
      prepare_resources (class_uri, class_method, class_params_array, class_params_content_array, class_header_array, class_header_content_array);
    }

  	String perform_request();

};

String SpartanAbstractControllerClass::perform_request () {

  Logger.println("REQUEST PARSER - URI: " + uri);
  Logger.println("REQUEST PARSER - VERB: " + http_verb);
  Logger.println("REQUEST PARSER - Accept: " + headers("Accept"));
  Logger.println("REQUEST PARSER - Accept-Encoding: " + headers("Accept-Encoding"));
  Logger.println("REQUEST PARSER - Cookie: " + headers("Cookie"));
  Logger.println("REQUEST PARSER - Host: " + headers("Host"));
  Logger.println("REQUEST PARSER - User-Agent: " + headers("User-Agent"));

  Logger.println(params("key"));

  return "WELCOME TO SPARTA!";
};

void SpartanAbstractControllerClass::prepare_resources (String class_uri, String class_method, String class_params_array[32], String class_params_content_array[32], String class_header_array[32], String class_header_content_array[32]) {
  uri = class_uri;
  http_verb = class_method;
  
  copy_array_to_another(class_params_array, params_array, sizeof(class_params_array));
  copy_array_to_another(class_params_content_array, params_content_array, sizeof(class_params_content_array)); 
  
  copy_array_to_another(class_header_array, header_array, sizeof(class_header_array)); 
  copy_array_to_another(class_header_content_array, header_content_array, sizeof(class_header_content_array)); 
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
  for (int i = 0; i < sizeof(header_array); i++) {
    if (strcmp(key.c_str(), header_array[i].c_str())){
      return header_content_array[i];
    }
  }
  return "";
};

void SpartanAbstractControllerClass::copy_array_to_another(String* src, String* dst, int len) {
  for (int i = 0; i < len; i++) {
    dst[i] = src[i];
  }
}