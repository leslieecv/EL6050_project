
void led_dist(){

    switch (stateLED_dist){
    
      ///////////////////
      // E0 - NO ERROR //
      ///////////////////
      
      case 0:
        digitalWrite(LED_dist, LOW);    // El pin del LED_dist en OFF

        if ( flagErrorLidar ) {         // Se detectan errores de medicion de LiDAR
          stateLED_dist = 1;            // pasa al estado 1
        }
        else {                          // Si no, 
          stateLED_dist = 0;            // se mantiene en estado 0
        }
      break;

      /////////////////////
      // E1 - LIDAR ERROR//
      /////////////////////

      case 1:
        digitalWrite(LED_dist, HIGH);       // El pin del LED_dist en ON

        if ( !flagErrorLidar ){             // Se soluciona el error de medicion de LiDAR
          stateLED_dist = 0;                // pasa al estado 0
        }
        else {                              // Si no,
          stateLED_dist = 1;                // se mantiene en estado 1
        }
      break;

      default:
        stateLED_dist = 0;
      break;
  
    }
}