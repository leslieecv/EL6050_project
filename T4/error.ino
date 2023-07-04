#include <EEPROM.h>
#include <avr/io.h>

void error(byte error_type, byte time_value) {      //
  EEPROM.begin();                                   // Inicializar la comunicación con la memoria EEPROM
  int pointer = 0;                                  // Se inicia pointer en cero, esta variable se usará para apuntar al espacio de memoria deseado
  byte readValue = EEPROM.read(pointer);                  // Se inicia la variable readValue igual al contenido del primer espacio de memoria
  while (readValue != 255) {                        // Siempre que readValue sea distinto de vacio
    pointer = pointer + 1;                          // Se aumenta en 1 el pointer
    readValue = EEPROM.read(pointer);               // Se actualiza el valor de readValue
  }                                                 // Cuando sale del ciclo significa que encontro el primer espacio de memoria libre (de 4096 direcciones)
  EEPROM.write(pointer, error_type);                // Escribe el tipo de error en el espacio vacio encontrado
  EEPROM.commit();                                  // Confirmar la escritura
  EEPROM.write(pointer + 1, time_value);            // Agrega la hora o fecha al siguiente espacio de memoria
  EEPROM.commit();                                  // Confirmar la escritura
  if (error_type == 4) {                            // Si el error es en el estado 4 (Lora) se reinicia el dispositivo
    asm volatile("jmp 0");                          // Reiniciar el dispositivo
  }
}
  
