/*
    THIS PART IS COMPLETED SELF_GENERATED, DO NOT MANUALLY CHANGE
*/

//*%..IDENTIFIER $GET /admin/$
if (uri == "/admin/" && http_verb == "GET"){
  pre_render_layout("");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_admin_login_redirect_html);
  
  post_render();
} else
    
//*%..IDENTIFIER $GET /admin/login_session_new$
if (uri == "/admin/login_session_new" && http_verb == "GET"){
  pre_render_layout("admin.html");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_admin_login_GET_session_new_html);
  #include "../../jobs/controllers/admin/login/GET_session_new_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/login_session_new$
if (uri == "/admin/login_session_new" && http_verb == "POST"){
  pre_render_layout("");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_admin_login_POST_session_new_js);
  #include "../../jobs/controllers/admin/login/POST_session_new_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /admin/dashboard$
if (uri == "/admin/dashboard" && http_verb == "GET"){
  pre_render_layout("admin.html");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_admin_dashboard_GET_board_html);
  #include "../../jobs/controllers/admin/dashboard/GET_board_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /admin/connections$
if (uri == "/admin/connections" && http_verb == "GET"){
  pre_render_layout("admin.html");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_admin_connections_GET_connections_html);
  #include "../../jobs/controllers/admin/connections/GET_connections_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/set_hotspot_params$
if (uri == "/admin/set_hotspot_params" && http_verb == "POST"){
  
  run_application();
  
  #include "../../jobs/controllers/admin/connections/POST_set_hotspot_params_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/set_network_params$
if (uri == "/admin/set_network_params" && http_verb == "POST"){
  
  run_application();
  
  #include "../../jobs/controllers/admin/connections/POST_set_network_params_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /admin/security$
if (uri == "/admin/security" && http_verb == "GET"){
  pre_render_layout("admin.html");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_admin_security_GET_security_html);
  #include "../../jobs/controllers/admin/security/GET_security_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/security$
if (uri == "/admin/security" && http_verb == "POST"){
  
  run_application();
  
  #include "../../jobs/controllers/admin/security/POST_security_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /admin/interface_gpios$
if (uri == "/admin/interface_gpios" && http_verb == "GET"){
  pre_render_layout("admin.html");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_admin_interface_gpios_GET_interface_gpios_html);
  #include "../../jobs/controllers/admin/interface_gpios/GET_interface_gpios_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/interface_gpios$
if (uri == "/admin/interface_gpios" && http_verb == "POST"){
  
  run_application();
  
  #include "../../jobs/controllers/admin/interface_gpios/POST_interface_gpios_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /admin/set_interface_ios$
if (uri == "/admin/set_interface_ios" && http_verb == "GET"){
  pre_render_layout("admin.html");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_admin_interface_shift_ios_GET_interface_shift_ios_html);
  #include "../../jobs/controllers/admin/interface_shift_ios/GET_interface_shift_ios_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/set_interface_ios$
if (uri == "/admin/set_interface_ios" && http_verb == "POST"){
  
  run_application();
  
  #include "../../jobs/controllers/admin/interface_shift_ios/POST_interface_shift_ios_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/set_interface_power_port$
if (uri == "/admin/set_interface_power_port" && http_verb == "POST"){
  
  run_application();
  
  #include "../../jobs/controllers/admin/interface_shift_ios/POST_interface_power_port_enable_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $POST /admin/set_interface_ext_power_supply$
if (uri == "/admin/set_interface_ext_power_supply" && http_verb == "POST"){
  
  run_application();
  
  #include "../../jobs/controllers/admin/interface_shift_ios/POST_interface_ext_power_supply_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /$
if (uri == "/" && http_verb == "GET"){
  pre_render_layout("application.html");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_views_GET_default_landing_page_html);
  #include "../../jobs/controllers/GET_default_landing_page_controller.cpp"
  post_render();
} else
    
//*%..IDENTIFIER $GET /do_not_use_firefox.html$
if (uri == "/do_not_use_firefox.html" && http_verb == "GET"){
  pre_render_layout("");
  run_application();
  pre_render(var_home_docmac_Arduino_spartan_industrial_2_special_compilers____jobs_public_assets__do_not_use_firefox_html);
  
  post_render();
} else
    
//{++ AUTO GENERATED PART, DO NOT CHANGE! ++}

{
  render_plain("WELCOME TO SPARTA!");
}
