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
    Fantasma oFantasma2(TAM*9,TAM*15);
    Fantasma oFantasma3(TAM*6,TAM*15);
    Fantasma oFantasma4(TAM*15,TAM*15);
    Fantasma oFantasma5(TAM*20,TAM*15);
    pantalla_inicial();
    while(!key[KEY_ESC] && !game_over){

        se_presiono_una_tecla();
        mover_pacman(oMapa);
        oFantasma1.moverFantasma();
        oFantasma2.moverFantasma();
        oFantasma3.moverFantasma();
        oFantasma4.moverFantasma();
        oFantasma5.moverFantasma();

        oMapa.portalMapa();
        //imprime el pacman con la boca abierta
        clear(buffer);
        oMapa.planoMapa();
        oPacman.imprimirPacmanComiendo();
        oFantasma1.dibujarFantasma();
        oFantasma2.dibujarFantasma();
        oFantasma3.dibujarFantasma();
        oFantasma4.dibujarFantasma();
        oFantasma5.dibujarFantasma();
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
destruir();
}
END_OF_MAIN();
