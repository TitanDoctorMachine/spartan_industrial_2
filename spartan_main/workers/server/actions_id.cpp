   if (job_id.startsWith("AUTO")) {

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

  } else

  // ... WELL i THINK THAT IS INVERSED KKKKKK
  if (job_id == "POWER_SUPPLIER_UP"){
    SpartanInterfaceIo.set_power_port(true);
	} else
	
	if (job_id == "POWER_SUPPLIER_DOWN"){
    SpartanInterfaceIo.set_power_port(false);
	} else
  
  if (job_id == "POWER_PORT_UP"){
    SpartanInterfaceIo.set_external_power_supply(true);
	} else
	
	if (job_id == "POWER_PORT_DOWN"){
    SpartanInterfaceIo.set_external_power_supply(false);
	} else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	// if (job_id == ""){	
	// } else
	{
		return "FAIL";
	};
