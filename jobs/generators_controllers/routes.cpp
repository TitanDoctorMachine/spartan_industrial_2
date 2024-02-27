/*
  THIS PART IS COMPLETED SELF_GENERATED, DO NOT MANUALLY CHANGE
*/

//*%..IDENTIFIER $GET /default_test$
if (uri == "/default/test" && http_verb == "GET"){
  pre_render(R"=====(<***!SPARTAN_GENERATOR_TAG_GET_default_test_controller.html***>)=====");
  #include "../controllers/default_test/GET_default_test_controller.cpp"
} else

//*%..IDENTIFIER $POST /default_test$
if (uri == "/default/test" && http_verb == "POST"){
  #include "../controllers/default_test/POST_default_test_controller.cpp"
} else 

//{++ AUTO GENERATED PART, DO NOT CHANGE! ++}

{
  /*if (http_verb == "GET"){
    handleFileRead(uri);
    render_plain("");
  } else {*/
    render_plain("WELCOME TO SPARTA!");
  //};
}