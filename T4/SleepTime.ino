#include <LowPower.h>

void SleepTime() {
  for (int i = 0; i < 7; i++) {
    LowPower.idle(SLEEP_8S); // Se utiliza el valor máximo predefinido de 8 segundos
  }
  LowPower.idle(SLEEP_4S); // Se utiliza el valor de 4 segundos para completar el minuto
}
