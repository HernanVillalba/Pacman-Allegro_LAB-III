#include <allegro.h>
#include <conio.h>
#include <stdlib.h>

#include "variables.h"
#include "funciones_globales.h"
#include "mapa.h"
#include "pacman.h"
#include "fantasmas.h"


void main()
{
    int opc;
    bool continuar=true;
    iniciar_allegro();
    opc=pantalla_inicial();
    while(continuar)
    switch (opc){
    case 1: {jugar();}break;
//    case 2: menu_puntaje();break;
//    case 3: menu_idioma(); break;
    case 0: continuar=false;}

    destruir();
}
END_OF_MAIN();
