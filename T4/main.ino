#include <TFmini.h>


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

void pin_setup(){
    pinMode(LED_on, OUTPUT);
    pinMode(LED_red, OUTPUT);
    pinMode(LED_dist, OUTPUT);
    pinMode(LED_trsa, OUTPUT);
    pinMode(LED_trsb, OUTPUT);
    pinMode(LED_trsc, OUTPUT);
}

void setup(){

    pin_setup();

}

void loop() {


} 