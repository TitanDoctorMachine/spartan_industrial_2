const char interface_ios_page_html[] PROGMEM =
R"=====(  
<div class="main-content">
  <h1>Interface IO</h1>

  <div class="mini-card sub-card" style="width: 34%;">
    <h1><span class="button" onclick="call_fast_ajax('/set_interface_ios', '0', 'power_port')"><b class="big"><*SP_power_port_tag*></b></span> Power Port</h1>
    <br><br>

  </div>

  <div class="mini-card sub-card" style="width: 40,%;">
    <h1><span class="button" onclick="call_fast_ajax('/set_interface_ios', '0', 'ext_power_supply')"><b class="big"><*SP_ext_supply_port_tag*></b></span> External Power Supply</h1>
    <br><br>
  </div>
  
  <*SP_shift_ports_tag*>

</div>

)====="
;