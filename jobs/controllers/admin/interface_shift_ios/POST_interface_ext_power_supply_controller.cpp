
  String id_system = params("id_system");

  #ifdef SPARTAN_CONFIG_USE_POWER_PORT
    if(digitalRead(ENABLE_PORT_PIN)){
      pinMode(ENABLE_PORT_PIN, OUTPUT);
      digitalWrite(ENABLE_PORT_PIN, LOW);
    } else {
      pinMode(ENABLE_PORT_PIN, OUTPUT);
      digitalWrite(ENABLE_PORT_PIN, HIGH);
    };
    Logger.println("Set: External Power Supply");
  #endif
  
  render_plain("setTimeout(() => {window.location.reload();}, 50);");