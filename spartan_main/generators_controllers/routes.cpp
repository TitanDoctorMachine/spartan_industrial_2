/*
    THIS PART IS COMPLETED SELF_GENERATED, DO NOT MANUALLY CHANGE
*/

//*%..IDENTIFIER $GET /default/test$
if (uri == "/default/test" && http_verb == "GET"){
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_default_test_GET_default_test_html);
  #include "../../jobs/controllers/default_test/GET_default_test_controller.cpp"
} else
    
//*%..IDENTIFIER $POST /default/test$
if (uri == "/default/test" && http_verb == "POST"){
  
  #include "../../jobs/controllers/default_test/POST_default_test_controller.cpp"
} else
    
//{++ AUTO GENERATED PART, DO NOT CHANGE! ++}

{
  render_plain("WELCOME TO SPARTA!");
}
