const char security_page_html[] PROGMEM =
R"=====(  
<div class="main-content">
  <h1>Security</h1>

  <div class="mini-card sub-card" style="width: 86%;">
    <h2>SET System Password</h2>
    <br>
    <form id="form_user_passwd" action="/set_system_password" method="POST">
      <label for="password">System Password: </label>
      <input type="password" id="password" name="password" required>
      <br><br>
      
      <input type="submit" value="Submit" class="button">
    </form>
  </div>

</div>
)====="
;

    