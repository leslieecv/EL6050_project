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
int TRS_A = 36;                     ///< pin de hardware del transductor B
int TRS_A = 37;                     ///< pin de hardware del transductor C

int LRW_TX = 0;                     ///< pin de hardware del transmisor LoRaWAN
int LRW_RX = 1;                     ///< pin de hardware del receptor LoRaWAN

string msg[23];                     // Mensaje a enviar mediante LoRaWAN

// Definición de los estados
enum Estados { //Se define una enumeración para los estados
  Energia,
  Lidar,
  Guardar1,
  Trans,
  Guardar2,
  Lora,
  Guardar3,
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
  estadoActual = Energia;
  pin_setup();
}

void loop() {
  // Lógica de los estados
  switch (estadoActual) {
    case Energia:
      ///////////////////////
      // E1 - ESTADO ENERGIA //
      ///////////////////////
      // Código para el estado Energia
      // ...
      // Cambio de estado
      estadoActual = Lidar;
      break;

    case Lidar:
      //////////////////////
      // E2 - ESTADO LIDAR //
      //////////////////////
      // Código para el estado Lidar
      // ...
      // Cambio de estado
      estadoActual = Guardar1;
      break;

    case Guardar1:
      ////////////////////////////
      // E3 - ESTADO GUARDAR 1 ///
      ////////////////////////////
      // Código para el estado Guardar1
      // ...
      // Cambio de estado
      estadoActual = Trans;
      break;

    case Trans:
      ///////////////////////
      // E4 - ESTADO TRANS //
      ///////////////////////
      // Código para el estado Trans
      // ...
      // Cambio de estado
      estadoActual = Guardar2;
      break;

    case Guardar2:
      ///////////////////////////
      // E5 - ESTADO GUARDAR 2 //
      ///////////////////////////
      // Código para el estado Guardar2
      // ...
      // Cambio de estado
      estadoActual = Lora;
      break;

    case Lora:
      //////////////////////
      // E6 - ESTADO LORA //
      //////////////////////
      // Código para el estado Lora
      // ...
      // Cambio de estado
      estadoActual = Guardar3;
      break;

    case Guardar3:
      ///////////////////////////
      // E7 - ESTADO GUARDAR 3 //
      ///////////////////////////
      // Código para el estado Guardar3
      // ...
      // Cambio de estado
      estadoActual = Energia;
      break;

    case Error:
      ///////////////////////
      // E8 - ESTADO ERROR //
      ///////////////////////
      // Código para el estado Error
      // ...
      // Posible manejo del error
      estadoActual = Energia;
      break;
  }
}
