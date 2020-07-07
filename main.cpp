#include <allegro.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdio>

#include "variables.h"
#include "funciones_globales.h"
#include "mapa.h"
#include "pacman.h"
#include "fantasmas.h"
#include "puntaje.h"
#include "jugar.h"


void main()
{

    iniciar_allegro();
    bool continuar=false;
    int opc;
    while (!continuar){
    opc = pantalla_inicial();
        switch (opc){
            case 1:jugar();break;
        case 2:/*puntaje()*/break;
    case 3:menu_idioma(); break;
    case 0:break;
    }
    clear(screen);
    }

destruir();
}
END_OF_MAIN();
