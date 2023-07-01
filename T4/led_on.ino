void led_on(){
  
  switch (stateLED_on){
    
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

    ///////////////////////
    // E1 - LED ON //
    ///////////////////////

    case 1:
      digitalWrite(LED_on, HIGH);     // El pin del LED_on en ON hasta que algo haga que el sistema se apague
      
    break;

}