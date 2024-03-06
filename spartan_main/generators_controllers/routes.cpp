/*
    THIS PART IS COMPLETED SELF_GENERATED, DO NOT MANUALLY CHANGE
*/

//*%..IDENTIFIER $GET /admin/login/session_new$
if (uri == "/admin/login/session_new" && http_verb == "GET"){
  pre_render_layout("admin.html");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_views_admin_login_GET_session_new_html);
  #include "../../jobs/controllers/admin/login/GET_session_new_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/login/session_new$
if (uri == "/admin/login/session_new" && http_verb == "POST"){
  pre_render_layout("");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_views_admin_login_POST_session_new_js);
  #include "../../jobs/controllers/admin/login/POST_session_new_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /admin/dashboard$
if (uri == "/admin/dashboard" && http_verb == "GET"){
  pre_render_layout("admin.html");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_views_admin_dashboard_GET_board_html);
  #include "../../jobs/controllers/admin/dashboard/GET_board_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /default/test$
if (uri == "/default/test" && http_verb == "GET"){
  pre_render_layout("application.html");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_views_default_test_GET_default_test_html);
  #include "../../jobs/controllers/default_test/GET_default_test_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /test.html$
if (uri == "/test.html" && http_verb == "GET"){
  pre_render_layout("");
  run_application();
  pre_render(var_home_docmac_Develop_spartan_industrial_2_special_compilers____jobs_public_assets__test_html);
  
  post_render();
} else
    
//{++ AUTO GENERATED PART, DO NOT CHANGE! ++}

{
  render_plain("WELCOME TO SPARTA!");
}
