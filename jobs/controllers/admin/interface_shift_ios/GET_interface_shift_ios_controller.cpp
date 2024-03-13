	/*For god's sake, this part is complicated...*/

	String shift_ports;

	#ifdef SPARTAN_CONFIG_USE_ENABLE_PORT
		if(digitalRead(ENABLE_PORT_PIN)){
		  set_view_var("ext_supply_port_tag", "✓");
		} else {
		  set_view_var("ext_supply_port_tag", "✗");
		};
	#endif
	#ifndef SPARTAN_CONFIG_USE_ENABLE_PORT
	  set_view_var("ext_supply_port_tag", "¤");
	#endif

	#ifdef SPARTAN_CONFIG_USE_POWER_PORT
		if(!digitalRead(POWER_PORT_PIN)){
		  set_view_var("power_port_tag", "✓");
		} else {
		  set_view_var("power_port_tag", "✗");
		};
	#endif
	#ifndef SPARTAN_CONFIG_USE_POWER_PORT
	  set_view_var("power_port_tag", "¤");
	#endif
	
	#ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS
		shift_ports += R"=====(<div class="mini-card sub-card" style="width: 89%;"><h1>Shift Register Ports</h1><br>)=====";
		for (const auto& element : system_shift_register) {
			
			if (element.second == ""){
				continue;
			}

			shift_ports += R"=====(<h2 class='grid-32'><span class='button' )=====";
			shift_ports += R"=====(onclick="call_fast_ajax('/admin/set_interface_ios', ')=====";
			shift_ports += String(element.first);
			shift_ports += R"=====(','shift_port');" id=')=====";
			shift_ports += String(element.first);
			shift_ports += "'><b class='big'>";
			
			if(DATA_PORT[element.first]){
				shift_ports += "✓";
			} else {
				shift_ports += "✗";
			};
			shift_ports += "</b>" + element.second + "</span></h2>";
		
		};
		shift_ports += "</div>";

	  set_view_var("shift_ports_tag", shift_ports);
	#endif
	#ifndef SPARTAN_CONFIG_USE_SHIFT_PORTS
	  set_view_var("shift_ports_tag", "");
	#endif