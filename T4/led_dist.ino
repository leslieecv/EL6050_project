// maquina que modifica el estado del led dist segun el nivel del estanque
void led_dist(){

    switch (stateLED_dist){
    
      ////////////////////////
      // E0 - EVALUAR NIVEL //
      ///////////////////////
      
      case 0:

        digitalWrite(LED_dist, LOW);    // El pin del LED_dist en OFF

        if ( flagLevel1 ){              // Si el nivel es ideal - más de 72 hrs de autonomia
          stateLED_dist = 1;            // pasa al estado 1
        }
        else if ( flagLevel2 ){         // Si el nivel es seguro - entre 60 y 72 hrs de autonomia
          stateLED_dist = 2;            // pasa al estado 2
        }
        else if ( flagLevel3 ){         // Si el nivel no es seguro - entre 48 y 60 hrs de autonomia
          stateLED_dist = 3;            // pasa al estado 3
        }
        else if ( flagLevel4 ){         // Si el nivel es crítico - menos de 48 hrs de autonomia
          stateLED_dist = 4;            // pasa al estado 4
        }
        else {                          // Si no, 
          stateLED_dist = 0;            // se mantiene en estado 0
        }
      break;

      //////////////////////////
      // E1 - NIVEL 1 - LED ON//
      //////////////////////////

      case 1:
        digitalWrite(LED_dist, HIGH);       // Se enciende el LED

        if (flagCheckSensors){              // Se deben medir el nivel
          stateLED_dist = 0;                // pasa al estado 1
        }
        else {                              // Si no,
          stateLED_dist = 1;                // se mantiene en estado 1
        }
      break;

      ////////////////////////////
      // E2 - NIVEL 2 - LED 1Hz //
      ////////////////////////////


      case 2:
        digitalWrite(LED_dist, HIGH);                                 // Se enciende el LED_dist
        if (flagCheckSensors){                                        // Se deben medir el nivel
          stateLED_dist = 0;                                          // pasa al estado 0
        }
        else if ( !flagCheckSensors && (countLED_dist > millis1) ){   //
          stateLED_dist = 2;                                          //
        }
        else if( !flagCheckSensors && (countLED_dist > millis200) ){  //
          stateLED_dist = 0;                                          //   
        }
        else{                                                         //
          stateLED_dist = 1;                                          //
        }

      break;

      ////////////////////////////
      // E3 - NIVEL 3 - LED 2Hz //
      ////////////////////////////

      case 3:
        digitalWrite(LED_dist, HIGH);                                 // Se enciende el LED_dist
        if (flagCheckSensors){                                        // Se deben medir el nivel
          stateLED_dist = 0;                                          // pasa al estado 0
        }
        else if ( !flagCheckSensors && (countLED_dist > millis1) ){   //
          stateLED_dist = 2;                                          //
        }
        else if( !flagCheckSensors && (countLED_dist > millis200) ){  //
          stateLED_dist = 0;                                          //   
        }
        else{                                                         //
          stateLED_dist = 1;                                          //
        }

      break;
      
      ////////////////////////////
      // E4 - NIVEL 4 - LED 3Hz //
      ////////////////////////////


      case 4:
        digitalWrite(LED_dist, HIGH);                                 //
        if (flagCheckSensors){                                        // Se deben medir el nivel
          stateLED_dist = 0;                                          // pasa al estado 0
        }
        else if ( !flagCheckSensors && (countLED_dist > millis1) ){   //
          stateLED_dist = 2;                                          //
        }
        else if( !flagCheckSensors && (countLED_dist > millis200) ){  //
          stateLED_dist = 0;                                          //   
        }
        else{                                                         //
          stateLED_dist = 1;                                          //
        }

      break;


      ////////////////////////
      // E5 - RESET COUNTER //
      ////////////////////////

      case 5:
        digitalWrite(LED_dist, LOW);  //
        countLed0 = 0;            //
        
        stateLED_dist = 0;            //
      break;

      default:
      break;
  
    }
}