void led_transA(){

    switch (stateLED_transA) {
    
      ///////////////////
      // E0 - NO ERROR //
      ///////////////////
      
      case 0:
        digitalWrite(LED_TRSA, LOW);     // El pin del LED_transA en OFF

        if ( flagErrorTransA ) {         // Se detectan errores de medicion de sensor de corriente A
          stateLED_transA = 1;           // pasa al estado 1
        }
        else {                           // Si no, 
          stateLED_transA = 0;           // se mantiene en estado 0
        }
      break;

      /////////////////////////////////
      // E1 - ERROR MEDICION TRANS A //
      /////////////////////////////////

      case 1:
        digitalWrite(LED_TRSA, HIGH);        // El pin del LED_transA en ON

        if ( !flagErrorTransA ){             // Se soluciona el error de medicion de sensor de corriente A
          stateLED_transA = 0;               // pasa al estado 0
        }
        else {                               // Si no,
          stateLED_transA = 1;               // se mantiene en estado 1
        }
      break;

      default:
        stateLED_transA = 0;                // Se pasa al estado 0
      break;
  
    }
}
