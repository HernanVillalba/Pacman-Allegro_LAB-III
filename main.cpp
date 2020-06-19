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

    iniciar_allegro();
    Mapa oMapa;
    Pacman oPacman;
    vidas = oPacman.getVidas();
    posicion_pacman_x = oPacman.getPosXPac();
    posicion_pacman_y = oPacman.getPosYPac();
    bool primera_vez = false;

    Fantasma oFantasma1(TAM*12,TAM*10,0);
    Fantasma oFantasma2(TAM*13,TAM*10,1);
    Fantasma oFantasma3(TAM*14,TAM*10,2);
    Fantasma oFantasma4(TAM*15,TAM*10,3);
    Fantasma oFantasma5(TAM*16,TAM*10,4);
//    Fantasma oFantasma6(TAM*12,TAM*11,1);
    pantalla_inicial();

    play_midi(sountrack_stage_1,1);
    while(!key[KEY_ESC] && !game_over){
        if(!primera_vez){
            //para pausar la pantalla al comienzo
            pantalla_princio(&primera_vez,oMapa,oPacman);
        }
        dibujar_vidas_pacman(vidas);
        dibujar_puntaje(puntaje);

        anteriorpx = posicion_pacman_x;
        anteriorpy = posicion_pacman_y;

        se_presiono_una_tecla(oMapa);
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
//        oFantasma6.moverFantasma();

//      imprime el pacman con la boca abierta
        clear(buffer);
        oMapa.planoMapa();
        oPacman.imprimirPacmanComiendo();
        oFantasma1.dibujarFantasma();
        oFantasma2.dibujarFantasma();
        oFantasma3.dibujarFantasma();
        oFantasma4.dibujarFantasma();
        oFantasma5.dibujarFantasma();
//        oFantasma6.dibujarFantasma();
        oMapa.imprimirMapa();

        rest(125);


        //imprime el pacman con la boca cerrada
        clear(pacman);
        oPacman.imprimirPacmanQuieto();
        oMapa.imprimirMapa();
        rest(125);
        oMapa.imprimirMapa();
      //  oPacman.restarVida();
//        dibujar_vidas_pacman();

        if(!oMapa.hayComida() || vidas == 0){ //si no hay comida... termina el juego
            game_over = true;
        }
    }
destruir();
}
END_OF_MAIN();
