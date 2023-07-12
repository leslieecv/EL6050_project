#include <TFmini.h>
#include <EEPROM.h>
#include <LowPower.h>
#include <avr/io.h>


int LED_on = 42;                    ///< pin de hardware de LED de encendido
int LED_red = 43;                   ///< pin de hardware de LED de red
int LED_dist = 44;                  ///< pin de hardware de LED del estado de la distancia
int LED_trsa = 45;                  ///< pin de hardware de LED del estado del transductor A
int LED_trsb = 46;                  ///< pin de hardware de LED del estado del transductor B
int LED_trsc = 47;                  ///< pin de hardware de LED del estado del transductor c

int LIDAR1_TX = 19;                 ///< pin de hardware del transmisor del LiDAR 1
int LIDAR1_RX = 18;                 ///< pin de hardware del receptor del LiDAR 1
int LIDAR2_TX = 17;                 ///< pin de hardware del transmisor del LiDAR 2
int LIDAR2_RX = 16;                 ///< pin de hardware del receptor del LiDAR 2

int TRS_A = 35;                     ///< pin de hardware del transductor A
int TRS_B = 36;                     ///< pin de hardware del transductor B
int TRS_C = 37;                     ///< pin de hardware del transductor C

int LRW_TX = 0;                     ///< pin de hardware del transmisor LoRaWAN
int LRW_RX = 1;                     ///< pin de hardware del receptor LoRaWAN

string msg[23];                     // Mensaje a enviar mediante LoRaWAN

byte error_type = 0;

// Definición de los estados
enum Estados { //Se define una enumeración para los estados
  Iniciar,
  Lidar,
  Trans,
  Lora,
  SleepTime,
  Error
};

// Variable para almacenar el estado actual
Estados estadoActual;

void pin_setup(){
    pinMode(LED_on, OUTPUT);
    pinMode(LED_red, OUTPUT);
    pinMode(LED_dist, OUTPUT);
    pinMode(LED_trsa, OUTPUT);
    pinMode(LED_trsb, OUTPUT);
    pinMode(LED_trsc, OUTPUT);
}

void setup() {
  // Inicialización del programa
  estadoActual = Iniciar;
  pin_setup();
}

void loop() {
  // Lógica de los estados
  switch (estadoActual) {
    case Iniciar:
      /////////////////////////
      // E1 - ESTADO INICIAR //
      /////////////////////////

      led_on();
      estadoActual = Lidar;
      break;

    case Lidar:
      ///////////////////////
      // E2 - ESTADO LIDAR //
      ///////////////////////

      getLevel();
      estadoActual = Trans;
      break;


    case Trans:
      ///////////////////////
      // E3 - ESTADO TRANS //
      ///////////////////////

      getCurrent();
      estadoActual = Lora;
      break;

    case Lora:
      //////////////////////
      // E4 - ESTADO LORA //
      //////////////////////

    
      estadoActual = SleepTime;
      break;


    case SleepTime:
      ///////////////////////
      // E5 - ESTADO Time  //
      ///////////////////////
      
      SleepTime()
      estadoActual = Lidar;
      break;
  }
}
