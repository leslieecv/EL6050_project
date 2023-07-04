#include <LoRaWAN.h>

void Lora(int Nivel, byte tranA, byte tranB, byte tranC) {

  byte nivelBytes[sizeof(Nivel)];                      // Construir el mensaje a enviar
  memcpy(nivelBytes, &Nivel, sizeof(Nivel));           // Convertir el valor de Nivel a un array de bytes
  LoRaWAN.sendData(nivelBytes, sizeof(nivelBytes));    // Enviar el mensaje por LoRaWAN
  
  while (!LoRaWAN.isSent()) { // Esperar confirmación de envío
    // ...
  }
}
