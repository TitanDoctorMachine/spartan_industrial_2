const char login_page_html[] PROGMEM =
R"=====(  
<div class="main-content center">

   <div class="mini-card sub-card" style="width: 40%; margin-top: 100; margin-left: 50%;">
    <h2>LOGIN</h2>
    <br>
    <form id="form_login" action="/login" method="POST">
      <label for="password">Password: </label>
      <input type="password" id="password" name="password" required>
      <br><br>
      
      <input type="submit" value="Submit" class="button">
    </form>
  </div>

</div>
)====="
;

    