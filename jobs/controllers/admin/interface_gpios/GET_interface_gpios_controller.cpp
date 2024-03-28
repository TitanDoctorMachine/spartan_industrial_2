
	String gpio_ports;

	for (const auto& element : gpio_map) {
   	gpio_ports += R"=====(<h2 class='grid-32'><span class='button' )=====";
		gpio_ports += R"=====(onclick="call_fast_ajax('/admin/interface_gpios', ')=====";
		gpio_ports += String(element.first);
		gpio_ports += R"=====(','gpio');" id=')=====";
		gpio_ports += String(element.first);
		gpio_ports += "'><b class='big'>";
		if(digitalRead(element.first)){
			gpio_ports += "✓";
		} else {
			gpio_ports += "✗";
		};
		gpio_ports += "</b>" + element.second + "</span></h2>";
	};

  set_view_var("gpios_ports_compiled", gpio_ports);


