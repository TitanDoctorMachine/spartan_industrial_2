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
      - fix params breaking
      - add render headers


  */

  render_partial("layouts/assets/_application.css", "render_application_css");
  render_partial("layouts/assets/_application.js", "render_application_js");


