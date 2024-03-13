    
  String id_system = params("id_system");
  #ifdef SPARTAN_CONFIG_USE_ENABLE_PORT
    if(digitalRead(POWER_PORT_PIN)){
      pinMode(POWER_PORT_PIN, OUTPUT);
      digitalWrite(POWER_PORT_PIN, LOW);
    } else {
      pinMode(POWER_PORT_PIN, OUTPUT);
      digitalWrite(POWER_PORT_PIN, HIGH);
    };
    Logger.println("Set: Power Port");
  #endif

  render_plain("setTimeout(() => {window.location.reload();}, 50);");