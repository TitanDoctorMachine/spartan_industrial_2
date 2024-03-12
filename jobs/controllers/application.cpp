  /*
    Spartan Industrial 02 development - application controller
    This page runs before the page pre-render, normally the point
    of preloading the layout
  */

  /*
    The next goal is to put keys like <S&= some_name_of_var />
    and automatically search in memory for some var with this 
    name and changing the value;

    remembering:
      - method to set type render
    
  */

  if (String(uri).startsWith("/do_not_use_firefox.html") == false && headers("User-Agent").indexOf("Firefox") != -1) {
    render_plain(R"(<html><head><meta charset="utf-8"/>
			<meta http-equiv="refresh" content="0; URL='/do_not_use_firefox.html'"/> 
		</head></html>)");
  }

  if (String(uri).startsWith("/admin") == true && String(uri).startsWith("/admin/login") == false){
    if (headers("Cookie").indexOf("session_token=" + SpartanInterfaceFile.read_value("session_token_system")) == -1) {
      add_header("Location","/admin/login/session_new");
      render_plain(R"(<html><head><meta charset="utf-8"/>
				<meta http-equiv="refresh" content="0; URL='/admin/login_session_new'"/> 
			</head></html>)");
    }
  }

  render_partial("layouts/assets/_application.css", "render_application_css");
  render_partial("layouts/assets/_application.js", "render_application_js");
