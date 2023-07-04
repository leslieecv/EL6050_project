#include "TFMini.h"                 // Libreria para los LiDAR TF Mini

TFMini lidar1;                      // Inicializacion de LiDAR 1
TFMini lidar2;                      // Inicializacion del LiDAR 2

uint16_t dist1 = 0;                 // Distancia que mide el LiDAR 1
uint16_t dist2 = 0;                 // Distancia que mide el LiDAR 2

int stateLidar = 0;                 // Estado del LiDAR

int sensorLevel = 15;               // Altura en metros a la que están los sensores respecto a la base del estanque

void getLevel(){
    switch (stateLidar){

        ////////////////////
        // E0 - ESPERANDO //
        ////////////////////

        dist1 = 0;                                  // Se reinicia el valor de dist1
        dist2 = 0;                                  // Se reinicia el valor de dist2
        case 0: 
            errorCount = 0;                         
            if ( flagCheckStatus ){                 // Si se recibe la orden de medir
                stateLidar = 1;                     // se pasa al estado 1
            }
            else {                                  // Si no,
                stateLidar = 0;                     // se mantiene en estado 0
            }
        break;

        ///////////////////////////
        // E1 - MIDIENDO LIDAR 1 //
        ///////////////////////////

        case 1: 
            lidar1.externalTrigger();               // Se solicita la medicion del LiDAR1,
            dist1 = lidar1.getDistance();           // se recibe la distancia en cm 
            dist1 = dist1* 0.01;                    // y se transforma a metros

            if ( errorCount > 5 ){                  // Si se realizan más de 5 mediciones erroneas seguidas
                stateLidar = 5;                     // se pasa al estado 5
            }
            else if ( dist1 = -1 ){                 // Si se detecta una medición erronea
                stateLidar = 1;                     // se mantiene el estado
                errorCount ++;                      // y se suma 1 al contador de errores
            }
            else {
                stateLidar = 2;                     // Se pasa al estado 2
                errorCount = 0;                     // Contador de errores a 0
            }
        break;

        ///////////////////////////
        // E2 - MIDIENDO LIDAR 2 //
        ///////////////////////////

        case 2: 
            lidar2.externalTrigger();               // Se solicita la medicion del LiDAR1,
            dist2 = lidar2.getDistance();           // se recibe la distancia en cm
            dist2 = dist2 * 0.01;                   // y se transforma a metros

            if ( errorCount > 5 ){                  // Si se realizan más de 5 mediciones erroneas seguidas
                stateLidar = 5;                     // se pasa al estado 5
            }

            else if ( dist2 = -1 ){                 // Si se detecta una medición erronea,
                stateLidar = 2;                     // se mantiene el estado
                errorCount ++;                      // y se suma 1 al contador de errores
            }
            else {
                stateLidar = 3;                     // Se pasa al estado 3
                errorCount = 0;                     // Contador de errores a 0
            }
        break;

        /////////////////////////
        // E3 - CALCULO SIMPLE //
        /////////////////////////

        case 3: 
            dist = (dist1 + dist2) / 2;             // Se actualiza el nivel del estanque
            level = dist - sensorLevel;              // Se cambia la referencia de altura a la base
            stateLidar = 4;                         // Se pasa a estado 4
        break;

        ////////////////////////////
        // E4 - ACTUALIZAR ESTADO //
        ////////////////////////////

        case 4:
            flagErrorLidar = 0;                 // Se desactiva la flag de error en los LiDAR 
            led_dist();                         // Se actualiza el estado del LED_dist
            msg += 'diesel';                    // Se agregan datos al mensaje
            msg += level;                       // Se agrega nivel de estanque medido al mensaje
            
            stateLidar = 0;
        break;

        /////////////////////////////
        // E5 - 5 ERRORES SEGUIDOS //
        /////////////////////////////

        case 5: 
            flagErrorLidar = 1;                     // Se activa la flag de error en los LiDAR
            led_dist();                             // Se actualiza el estado del LED_dist
            msg += 'ErrorLidar:';                   // Agregar texto de error al mensaje a enviar
            msg += dist1;
            msg += dist2;
        break;

        default:
            stateLidar = 0;
        break;
    } 
}