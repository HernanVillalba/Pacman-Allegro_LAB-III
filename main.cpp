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
    Fantasma oFantasma1(TAM*12,TAM*10,0);
    Fantasma oFantasma2(TAM*13,TAM*10,1);
    Fantasma oFantasma3(TAM*14,TAM*10,2);
    Fantasma oFantasma4(TAM*15,TAM*10,3);
    Fantasma oFantasma5(TAM*16,TAM*10,4);

//    posicion_pacman_x = oPacman.getPosXPac();
//    posicion_pacman_y = oPacman.getPosYPac();
    bool primera_vez = false;




    pantalla_inicial();
    pantalla_elegir_skin();

    play_midi(sountrack_stage_1,1);

    bool game_over = false;
    while(!game_over){

        if(!primera_vez){
            //para pausar la pantalla al comienzo
            pantalla_princio(&primera_vez,oMapa,oPacman);
        }
        dibujar_vidas_pacman(oPacman.getVidas());
        dibujar_puntaje(puntaje);

//        se_presiono_una_tecla(oMapa);
        oPacman.mover_pacman();

        if(oPacman.comidaGrande()){
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

//      imprime el pacman con la boca abierta
        clear(buffer);
        oPacman.Comer();
        oPacman.imprimirPacmanComiendo();
        oFantasma1.dibujarFantasma();
        oFantasma2.dibujarFantasma();
        oFantasma3.dibujarFantasma();
        oFantasma4.dibujarFantasma();
        oFantasma5.dibujarFantasma();

        oMapa.imprimirMapa();

        rest(125);


        //imprime el pacman con la boca cerrada
        clear(pacman);
        oPacman.imprimirPacmanQuieto();
        oMapa.imprimirMapa();
        rest(125);
        oMapa.imprimirMapa();
//        oPacman.restarVida();

        if(!oPacman.hayComida() || key[KEY_ESC] || oPacman.getVidas()== -1){ //si no hay comida... termina el juego
            game_over = true;
        }
    }
destruir();
}
END_OF_MAIN();
