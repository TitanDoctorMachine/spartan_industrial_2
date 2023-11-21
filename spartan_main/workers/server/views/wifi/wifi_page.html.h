const char wifi_page_html_html[] PROGMEM =
R"=====(  
<div class="main-content">
  <h1>Connections</h1>

  <div class="mini-card sub-card" style="width: 40%;">
    <h2>Wifi Connection</h2>
    Wifi Status: <b><*SP_wifi_connection_tag*></b><br>
    InternalIP: <b><*SP_wifi_connection_ip_tag*></b><br>
    Wifi Name: <b><*SP_wifi_connection_name_tag*></b>
  </div>

  <div class="mini-card sub-card" style="width: 40%;">
    <h2>Wifi Hotspot</h2>
    Wifi Status: <b><*SP_wifi_hotspot_tag*></b><br>
    InternalIP: <b><*SP_wifi_hotspot_ip_tag*></b><br>
    Wifi Name: <b><*SP_wifi_hotspot_name_tag*></b>
  </div>

  <div class="mini-card sub-card" style="width: 86%;">
    <h2>SET Wifi Connection</h2>
    <br>
    <form id="form_network" action="/set_network_params" method="POST">
      <label for="wifi_name">Wifi Name: </label>
      <input type="wifi_name" id="wifi_name" name="wifi_name" required value="<*SP_wifi_connection_name_tag*>">
      <br><br>
      <label for="wifi_pass">Wifi Password: </label>
      <input type="wifi_pass" id="wifi_pass" name="wifi_pass" required>
      <br><br>
      
      <input type="submit" value="Submit" class="button">
    </form>
  </div>

  <div class="mini-card sub-card" style="width: 86%;">
    <h2>SET Wifi Hotspot</h2>
    <br>
    <form id="form_hotspot" action="/set_hotspot_params" method="POST">
      <label for="wifi_name">Wifi Name: </label>
      <input type="wifi_name" id="wifi_name" name="wifi_name" required value="<*SP_wifi_hotspot_name_tag*>">
      <br><br>
      <label for="wifi_pass">Wifi Password: </label>
      <input type="wifi_pass" id="wifi_pass" name="wifi_pass" required>
      <br><br>
      
      <input type="submit" value="Submit" class="button">
    </form>
  </div>

</div>
)====="
;

    