#include <allegro.h>
#include <iostream>

#include "variables.h"
#include "funciones_globales.h"
#include "mapa.h"


int main()
{
    iniciar_allegro();

    Mapa oMapa; //objeto de la clase mapa


    while(!key[KEY_ESC]){
        oMapa.planoMapa();
        oMapa.imprimirMapa();
    }
}
END_OF_MAIN();
