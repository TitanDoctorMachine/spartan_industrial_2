const char pre_load_screen[] PROGMEM =
R"=====(
  <html lang="en"><head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Spartan Slave 2.0</title>
      
  <head>
    <*SP_css_tag*>
    <*SP_js_tag*>
  </head>
  <body>

    <*SP_sidebar_tag*>
    
    <*SP_content_tag*>

    <div id="notification" class="notify_modal">
      <div class="notify_modal-content mini-card sub-card">
        <span onclick="close_notification()" style="cursor: pointer; float: right;">&times;</span>
        <p id="message_for_message_modal"></p>
      </div>
    </div>

    </body>
  </html>
)====="
;