int stateTrans = 0;                 // Estado de los sensores de corriente

uint8_t tranA = 0;                 // Valor que mide el sensor de corriente A
uint8_t tranB = 0;                 // Valor que mide el sensor de corriente B
uint8_t tranC = 0;                 // Valor que mide el sensor de corriente C

byte error_type = 3;                // Código del error de los sensores de corriente en caso de que fallen
int errorCount = 0;                 // Contador de errores

void getCurrent(){
    switch (stateTrans){

        ////////////////////
        // E0 - ESPERANDO //
        ////////////////////

        case 0: 
            tranA = 0;                              // Resetear medicion sensor de corriente A
            tranB = 0;                              // Resetear medicion sensor de corriente B
            tranC = 0;                              // Resetear medicion sensor de corriente C
            errorCount = 0;                         // Se reinicia el contador de errores
            if ( flagCheckStatus ){                 // Si se recibe la orden de medir
                stateLidar = 1;                     // se pasa al estado 1
            }
            else {                                  // Si no,
                stateLidar = 0;                     // se mantiene en estado 0
            }
        break;

        ////////////////////////////
        // E1 - MIDIENDO SENSORES //
        ////////////////////////////

        case 1: 
            tranA = analogRead(TRS_A);              // Se mide el sensor de corriente A
            tranB = analogRead(TRS_B);              // Se mide el sensor de corriente B
            tranC = analogRead(TRS_C);              // Se mide el sensor de corriente C

            if ( errorCount > 5 ){                  // Si se realizan más de 5 mediciones erroneas seguidas
                stateTrans = 4;                     // se pasa al estado 5
            }
            else if ( tranA > 1000 || tranB > 1000 || tranC > 1000) {   // Si se detecta una medición erronea
                stateTrans = 1;                                         // se mantiene el estado
                errorCount ++;                                          // y se suma 1 al contador de errores
            }
            else {
                stateTrans = 2;                     // Se pasa al estado 2
                errorCount = 0;                     // Contador de errores a 0
            }
        break;

        /////////////////////////
        // E2 - CALCULO SIMPLE //
        /////////////////////////

        case 2: 
                                                    // Se realiza un ajuste entre la lectura analoga y corriente en la red
            stateTrans = 3;                         // Se pasa a estado 4
        break;

        ////////////////////////////
        // E3 - ACTUALIZAR ESTADO //
        ////////////////////////////

        case 3:
            flagErrorTrans = 0;                 // Se desactiva la flag de error en los sensores de corriente
            flagCheckTrans = 1;                 // Se activa la flag de revision de estado de los LiDAR
            led_trans();                        // Se actualiza el estado del LED_trans
                                                // Se agregan los datos al mensaje a enviar por LoRaWAN
            stateTrans = 0;                     // Se pasa al estado 0
        break;

        /////////////////////////////
        // E4 - 5 ERRORES SEGUIDOS //
        /////////////////////////////

        case 4: 
            flagErrorTrans = 1;                     // Se activa la flag de error en los LiDAR
            led_trans();                            // Se actualiza el estado del LED_trans
            error(error_type)                       // Se guarda el error para futura revisión
            stateTrans = 0;                         // Se pasa al estado 0
        break;

        default:
            stateTrans = 0;                         // Se define en estado 0
        break;
    } 
}