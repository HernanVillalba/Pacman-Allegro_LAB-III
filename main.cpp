#include <allegro.h>
#include <conio.h>
#include<stdlib.h>

#include "variables.h"
#include "funciones_globales.h"
#include "mapa.h"
#include "pacman.h"
#include "fantasmas.h"

void main()
{
    iniciar_allegro();

    Mapa oMapa; //objeto de la clase mapa
    Pacman oPacman;
    Fantasma oFantasma1(TAM*5,TAM*10);
    Fantasma oFAntasma2(TAM*9,TAM*15);
    Fantasma oFAntasma3(TAM*6,TAM*15);
    Fantasma oFAntasma4(TAM*15,TAM*15);

    pantalla_inicial();
    while(!key[KEY_ESC] && !game_over){

        se_presiono_una_tecla();
        mover_pacman(oMapa);
        oMapa.portalMapa();
        //imprime el pacman con la boca abierta
        clear(buffer);
        oMapa.planoMapa();
        oPacman.imprimirPacmanComiendo();
        oFantasma1.dibujarFantasma();
        oFAntasma2.dibujarFantasma();
        oFAntasma3.dibujarFantasma();
        oFAntasma4.dibujarFantasma();

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
