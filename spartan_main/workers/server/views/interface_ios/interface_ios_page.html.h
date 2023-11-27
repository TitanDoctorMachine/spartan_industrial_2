const char interface_ios_page_html[] PROGMEM =
R"=====(  
<div class="main-content">
  <h1>Interface IO</h1>

  <div class="mini-card sub-card" style="width: 34%;">
    <h1><span class="button"><b class="big">✓</b></span> Power Port</h1>
    <br><br>

  </div>

  <div class="mini-card sub-card" style="width: 40,%;">
    <h1><span class="button"><b class="big">✓</b></span> External Power Supply</h1>
    <br><br>
  </div>

  <div class="mini-card sub-card" style="width: 89%;">
    <h1>Shift Register Ports</h1>
    <br>
    <*SP_shift_ports_tag*>
  </div>
  
  <div class="mini-card sub-card" style="width: 89%;">
    <h1>GPIO Ports</h1>
    <br>
	  <*SP_D_ports_tag*>
  </div>

</div>
)====="
;

    