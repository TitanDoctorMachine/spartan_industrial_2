/*
  THIS PART IS COMPLETED SELF_GENERATED, DO NOT MANUALLY CHANGE
*/

//*%..IDENTIFIER $GET /default_test$
if (uri == "/default/test" && http_verb == "GET"){
  #include "../controllers/default_test/GET_default_test_controller.cpp"
} else 

//*%..IDENTIFIER $POST /default_test$
if (uri == "/default/test" && http_verb == "POST"){
  #include "../controllers/default_test/POST_default_test_controller.cpp"
} else 

//{++ AUTO GENERATED PART, DO NOT CHANGE! ++}

{
  render_plain("WELCOME TO SPARTA!");
}