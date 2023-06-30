bool flagLevel1 = 0;
bool flagLevel2 = 0;
bool flagLevel3 = 0;
bool flagLevel4 = 0;

void level_status(){ // maquina para definir en que estado esta el nivel, configurar flags dependiendo de las mediciones
  
  switch (level_status){
    
    //////////////////
    // E0 - LED OFF //
    //////////////////
    
    case 0:

      digitalWrite(LED_on, LOW);      // El pin del LED_on en OFF

      if ( flagStart ){               // Si se inicializan correctamente todos los sistemas
        stateLED_on = 1;              // pasa al estado 1
      }
      else{                           // Si no, 
        stateLED_on = 0;              // se mantiene en estado 0
      }
    break;
  }
}
