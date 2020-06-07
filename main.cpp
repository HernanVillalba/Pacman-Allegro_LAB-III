#include <allegro.h>
#include <conio.h>

#include "variables.h"
#include "funciones_globales.h"
#include "mapa.h"
#include "pacman.h"

void main()
{
    iniciar_allegro();

    Mapa oMapa; //objeto de la clase mapa
    Pacman oPacman;

    while(!key[KEY_ESC]){
        if(key[KEY_RIGHT]) dir = 0; //IZQ vale 0
        else if(key[KEY_UP]) dir = 1; //ARRIB vale 1
        else if(key[KEY_LEFT]) dir = 2; //DER vale 2
        else if(key[KEY_DOWN]) dir = 3; //ABAJ vale 3

        if(dir == 0 && oMapa.bordeMapa()) px += TAM;
        if(dir == 1 && oMapa.bordeMapa()) py -= TAM;
        if(dir == 2 && oMapa.bordeMapa()) px -= TAM;
        if(dir == 3 && oMapa.bordeMapa()) py += TAM;

        //imprime el pacman con la boca abierta
        clear(buffer);
        oMapa.planoMapa();
        oPacman.imprimirPacmanComiendo();
        oMapa.imprimirMapa();
        rest(110);

        //imprime el pacman con la boca cerrada
        clear(pacman);
        oPacman.imprimirPacmanQuieto();
        oMapa.imprimirMapa();
        rest(110);

    }
}
END_OF_MAIN();
