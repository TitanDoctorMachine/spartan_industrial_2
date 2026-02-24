//GPIO-D1-TRUE

String substring = job_id.substring(4);
String tokens[10];
int tokenIndex = 0;

char charArray[substring.length() + 1];
substring.toCharArray(charArray, sizeof(charArray));

char *token = strtok(charArray, "-");

while (token != NULL && tokenIndex < 3) {
  tokens[tokenIndex] = String(token);
  tokenIndex++;
  token = strtok(NULL, "-");
}

if (tokenIndex >= 2) {

  String pinName = tokens[0];   // Ex: D4
  String state   = tokens[1];   // TRUE ou FALSE

  int gpioNumber = -1;

  // Procurar no mapa
  for (int i = 0; i < 16; i++) {
    if (gpio_map[i] == pinName) {
      gpioNumber = i;
      break;
    }
  }

  if (gpioNumber != -1) {

    Logger.println("GPIO encontrado:");
    Logger.println(pinName);
    Logger.println(gpioNumber);

    pinMode(gpioNumber, OUTPUT);

    if (state == "TRUE") {
      digitalWrite(gpioNumber, HIGH);
    } else {
      digitalWrite(gpioNumber, LOW);
    }

  } else {
    Logger.println("GPIO nao encontrado no mapa");
  }
}