#include <EEPROM.h>

void error(){
  EEPROM.begin();   // Inicializar la comunicación con la memoria EEPROM
  int pointer = 0;
  byte readValue = EEPROM.read(0);
  while (readValue == 255) {
    pointer = ponter + 1;
    readValue = EEPROM.read(pointer);
  EEPROM.write(pointer, error_type);
  EEPROM.write(pointer+1, time_value);
  }
}
  
