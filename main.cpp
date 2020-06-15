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
    Pacman oPacman(3);

    Fantasma oFantasma1(TAM*12,TAM*10,0);
    Fantasma oFantasma2(TAM*13,TAM*10,1);
    Fantasma oFantasma3(TAM*14,TAM*10,2);
    Fantasma oFantasma4(TAM*15,TAM*10,3);
    Fantasma oFantasma5(TAM*16,TAM*10,4);
    pantalla_inicial();
//    vidas = oPacman.getVidas();

    while(!key[KEY_ESC] && !game_over){

        dibujar_vidas_pacman(vidas);
        dibujar_puntaje(puntaje);

        anteriorpx=px;
        anteriorpy=py;

        se_presiono_una_tecla();
        mover_pacman(oMapa);
        if(oMapa.comidaGrande()){
        oFantasma1.cambiarEstado();
        oFantasma2.cambiarEstado();
        oFantasma3.cambiarEstado();
        oFantasma4.cambiarEstado();
        oFantasma5.cambiarEstado();
        }

        oFantasma1.moverFantasma();
        oFantasma2.moverFantasma();
        oFantasma3.moverFantasma();
        oFantasma4.moverFantasma();
        oFantasma5.moverFantasma();

        oMapa.portalMapa();
//      imprime el pacman con la boca abierta
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
      //  oPacman.restarVida();
//        dibujar_vidas_pacman();

        if(!oMapa.hayComida() || vidas == -1){ //si no hay comida... termina el juego
            game_over = true;

        }
    }
destruir();
}
END_OF_MAIN();
