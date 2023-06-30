
void level_status(){ // maquina para definir en que estado esta el nivel, configurar flags dependiendo de las mediciones
  
    switch (stateLevel){
    
        /////////////////////////////
        // E0 - NO HAY INFORMACION //
        ////////////////////////////
        
        case 0:
            flagLevel0 = 1;
            flagLevel1 = 0;
            flagLevel2 = 0;
            flagLevel3 = 0;
            flagLevel4 = 0;

            if ( flagCheckStatus ){
                level = getLevel();             // Realizar mediciones (aqui estoy media perdida si esperar o no la orden o darle no mas y como funcionaria esa flag)
            }
            if ( level > 1000 ){
                flagLevel1 = 1;
                flagLevel0 = 0;
            }
            else if ( level>800 && level<1000 ){
                flagLevel2 = 1;
                flagLevel0 = 0;
            }
            else if ( level>600 && level<800 ){
                flagLevel3 = 1;
                flagLevel0 = 0;
            }
            else if ( level<600 ){
                flagLevel4 = 1;
                flagLevel0 = 0;
            }
        break;

        ////////////////////////
        // E1 - ESTADO IDEAL //
        ///////////////////////

        case 1:
            
        break;

        ////////////////////////
        // E2 - ESTADO SEGURO //
        ///////////////////////

        case 2:

        break;    
        
        
        ///////////////////////////
        // E3 - ESTADO NO SEGURO //
        ///////////////////////////

        case 3:

        break;

        ////////////////////////7
        // E4 - ESTADO CRITICO //
        /////////////////////////

        case 4:

        break;

        default:
            stateLevel = 0;
  }
}
