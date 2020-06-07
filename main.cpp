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

    while(!key[KEY_ESC] && !game_over){

        se_presiono_una_tecla();
        mover_pacman(oMapa);
        oMapa.portalMapa();

        //imprime el pacman con la boca abierta
        clear(buffer);
        oMapa.planoMapa();
        oPacman.imprimirPacmanComiendo();
        oMapa.imprimirMapa();
        rest(115);

        //imprime el pacman con la boca cerrada
        clear(pacman);
        oPacman.imprimirPacmanQuieto();
        oMapa.imprimirMapa();
        rest(115);
        oMapa.imprimirMapa();

        if(!oMapa.hayComida()){ //si no hay comida... termina el juego
            game_over = true;
        }
    }
}
END_OF_MAIN();
