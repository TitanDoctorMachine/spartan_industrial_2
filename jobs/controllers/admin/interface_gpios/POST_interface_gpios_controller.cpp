  
  String id_system = params("id_system");

  if(digitalRead(id_system.toInt())){
    pinMode(id_system.toInt(), OUTPUT);
    digitalWrite(id_system.toInt(), LOW);
  } else {
    pinMode(id_system.toInt(), OUTPUT);
    digitalWrite(id_system.toInt(), HIGH);
  };
  Logger.println("Set: GPIO Port " + id_system);

	render_plain("setTimeout(() => {window.location.reload();}, 50);");