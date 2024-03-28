  
  String id_system = params("id_system");

  #ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS
    if(DATA_PORT[id_system.toInt()]){
      SpartanInterfaceShiftRegister.set_port(id_system.toInt(), false);
    } else {
      SpartanInterfaceShiftRegister.set_port(id_system.toInt(), true);
    };
    Logger.println("Set: Shift Port " + id_system);
  #endif

  render_plain("setTimeout(() => {window.location.reload();}, 50);");