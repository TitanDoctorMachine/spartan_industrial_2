/*
    THIS PART IS COMPLETED SELF_GENERATED, DO NOT MANUALLY CHANGE
*/

//*%..IDENTIFIER $GET /default/test$
if (uri == "/default/test" && http_verb == "GET"){
  pre_render_layout("application.html");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_views_default_test_GET_default_test_html);
  #include "../../jobs/controllers/default_test/GET_default_test_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /default/test$
if (uri == "/default/test" && http_verb == "POST"){
  
  run_application();
  
  #include "../../jobs/controllers/default_test/POST_default_test_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /application.css$
if (uri == "/application.css" && http_verb == "GET"){
  pre_render_layout("");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_public_assets__application_css);
  
  post_render();
} else
    
//*%..IDENTIFIER $GET /application.js$
if (uri == "/application.js" && http_verb == "GET"){
  pre_render_layout("");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_public_assets__application_js);
  
  post_render();
} else
    
//*%..IDENTIFIER $GET /html_test/test.html$
if (uri == "/html_test/test.html" && http_verb == "GET"){
  pre_render_layout("");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_public_assets__html_test_test_html);
  
  post_render();
} else
    
//{++ AUTO GENERATED PART, DO NOT CHANGE! ++}

{
  render_plain("WELCOME TO SPARTA!");
}
