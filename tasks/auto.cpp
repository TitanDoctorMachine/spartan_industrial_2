#ifdef SPARTAN_CONFIG_USE_SHIFT_PORTS

  //AUTO-Port_1-TRUE

  String substring = job_id.substring(4);
  String tokens[10];
  int tokenIndex = 0;
  char charArray[substring.length() + 1];

  substring.toCharArray(charArray, sizeof(charArray));
  char *token = strtok(charArray, "-");

  while (token != NULL && tokenIndex < 10) {
    tokens[tokenIndex] = String(token);
    tokenIndex++;
    token = strtok(NULL, "-");
  }

  for (int i = 0; i < size_of_mapped_commands; i++) {
        
    if (strcmp(system_shift_register[i].c_str(), tokens[0].c_str()) == 0) {
  
      Logger.println(tokens[0]);
      Logger.println(tokens[1]);
      Logger.println(system_shift_register[i]);
    
      if (tokens[1] == "TRUE"){
        SpartanInterfaceShiftRegister.set_port(i, true);
      } else {
        SpartanInterfaceShiftRegister.set_port(i, false);
      }
    }
  }
#endif