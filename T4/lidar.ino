#include "TFMini.h"

TFMini lidar1;
TFMini lidar2;

uint16_t dist1 = 0;
uint16_t dist2 = 0;

bool stateLidar = 0;

void getLevel(){
    switch (stateLidar){

        ////////////////////
        // E0 - ESPERANDO //
        ////////////////////
        case 0: 
            errorCount = 0;                         
            if ( flagCheckStatus ){                 // Si se recibe la orden de medir
                stateLidar = 1;                     // se pasa al estado 1
            }
        break;

        ///////////////////////////
        // E1 - MIDIENDO LIDAR 1 //
        ///////////////////////////
        case 1: 
            lidar1.externalTrigger();               // Se solicita la medicion del LiDAR1
            dist1 = lidar1.getDistance();           // y se recibe la distancia en cm 

            if ( dist1 = -1 ){                      // Si se detecta una medición erronea
                stateLidar = 1;                     // se mantiene el estado
                errorCount ++;                      // y se suma 1 al contador de errores
            }
            else if ( errorCount >=3 ){              // Si se realizan más de 3 mediciones errones seguidas
                stateLidar = 3;                     // se pasa al estado 3
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
            lidar2.externalTrigger();               // Se solicita la medicion del LiDAR1
            dist2 = lidar2.getDistance();           // y se recibe la distancia en cm 

            if ( dist2 = -1 ){                      // Si se detecta una medición erronea
                stateLidar = 2;                     // se mantiene el estado
                errorCount ++;                      // y se suma 1 al contador de errores
            }
            else if ( errorCount >=3 ){              // Si se realizan más de 3 mediciones errones seguidas
                stateLidar = 3;                     // se pasa al estado 3
            }
            else {
                stateLidar = 0;                     // Se vuelve al estado 0
                errorCount = 0;                     // Contador de errores a 0
            }
        break;
        /////////////////////////////
        // E3 - 3 ERRORES SEGUIDOS //
        /////////////////////////////
        case 3: 
            

        default:
            break;
    } 
}