
void level_status(){
  
    switch (stateLevel){
    
        /////////////////////////////
        // E0 - ESPERANDO MEDICION //
        /////////////////////////////
        
        case 0:
            flagLevel0 = 1;                     // 
            flagLevel1 = 0;
            flagLevel2 = 0;
            flagLevel3 = 0;
            flagLevel4 = 0;

            if ( flagCheckStatus ){             // Si se activa la flag para medir nivel
                level = getLevel();             // se realizan mediciones
            }
            if ( level > 14 ){                  // Si el estanque tiene más de 14m de petróleo
                flagLevel1 = 1;                 // se activa la flag de nivel 1
                flagLevel0 = 0;                 // se desactiva la flag de nivel 0
                stateLevel = 1;                 // y se pasa al estado 1
            }
            else if ( level>12 && level<14 ){   // Si el estanque tiene más de 12m de petróleo
                flagLevel2 = 1;                 // se activa la flag de nivel 2
                flagLevel0 = 0;                 // se desactiva la flag de nivel 0
                stateLevel = 2;                 // y se pasa al estado 2
            }
            else if ( level>8 && level<10 ){    // Si el estanque tiene más de 10m de petróleo
                flagLevel3 = 1;                 // se activa la flag de nivel 3
                flagLevel0 = 0;                 // se desactiva la flag de nivel 0
                stateLevel = 3;                 // y se pasa al estado 3
            }
            else if ( level<8 ){                // Si el estanque tiene menos de 8m de petróleo
                flagLevel4 = 1;                 // se activa la flag de nivel 4
                flagLevel0 = 0;                 // se desactiva la flag de nivel 0
                stateLevel = 4;                 // y se pasa al estado 4
            }
        break;

        ////////////////////////
        // E1 - ESTADO IDEAL //
        ///////////////////////

        case 1:
            if ( flagCheckStatus ){             // Si se activa la flag para medir nivel
                level = getLevel();             // se realizan mediciones
            }  
        break;

        ////////////////////////
        // E2 - ESTADO SEGURO //
        ///////////////////////

        case 2:
            if ( flagCheckStatus ){             // Si se activa la flag para medir nivel
                level = getLevel();             // se realizan mediciones
            }    
        break;    
        
        
        ///////////////////////////
        // E3 - ESTADO NO SEGURO //
        ///////////////////////////

        case 3:
             if ( flagCheckStatus ){            // Si se activa la flag para medir nivel
                level = getLevel();             // se realizan mediciones
            }   
                                                // Agregar mensaje de urgencia con detalle
        break;

        ////////////////////////7
        // E4 - ESTADO CRITICO //
        /////////////////////////

        case 4:
            if ( flagCheckStatus ){             // Si se activa la flag para medir nivel
                level = getLevel();             // se realizan mediciones
            }
                                                // Activar flag de mensaje urgente
                                                // Agregar mensaje de urgencia con detalle
                
        break;

        default:
            stateLevel = 0;
  }
}
