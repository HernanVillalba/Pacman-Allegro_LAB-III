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


void main()
{

    iniciar_allegro();

    Mapa oMapa;
    Pacman oPacman;
    Fantasma oGhost1(TAM*12,TAM*10,0);
    Fantasma oGhost2(TAM*13,TAM*10,1);
    Fantasma oGhost3(TAM*14,TAM*10,2);
    Fantasma oGhost4(TAM*15,TAM*10,3);
    Fantasma oGhost5(TAM*16,TAM*10,4);
    pantalla_inicial();

    int ghost_x,ghost_y;

    while(!game_over){
//        if(!primera_vez){
//            //para pausar la pantalla al comienzo
//            pantalla_princio(&primera_vez,oMapa,oPacman);
//        }

        //para la colision entre pac y ghost;
        pac_x = oPacman.getPosXPac();
        pac_y = oPacman.getPosYPac();
        //en x
        vec_ghost_x[0] = oGhost1.get_ghost_x();
        vec_ghost_x[1] = oGhost2.get_ghost_x();
        vec_ghost_x[2] = oGhost3.get_ghost_x();
        vec_ghost_x[3] = oGhost4.get_ghost_x();
        vec_ghost_x[4] = oGhost5.get_ghost_x();
        //en y
        vec_ghost_y[0] = oGhost1.get_ghost_y();
        vec_ghost_y[1] = oGhost2.get_ghost_y();
        vec_ghost_y[2] = oGhost3.get_ghost_y();
        vec_ghost_y[3] = oGhost4.get_ghost_y();
        vec_ghost_y[4] = oGhost5.get_ghost_y();


        dibujar_vidas_pacman(oPacman.getVidas());
        dibujar_puntaje(puntaje);

//        se_presiono_una_tecla(oMapa);
        oPacman.mover_pacman();

//        if(oPacman.comidaGrande()){
//        oGhost1.cambiarEstado();
//        oGhost2.cambiarEstado();
//        oGhost3.cambiarEstado();
//        oGhost4.cambiarEstado();
//        oGhost5.cambiarEstado();
//        }

        oGhost1.moverFantasma();
        oGhost2.moverFantasma();
        oGhost3.moverFantasma();
        oGhost4.moverFantasma();
        oGhost5.moverFantasma();

//      imprime el pacman con la boca abierta
        clear(buffer);
        oPacman.Comer();
        oPacman.imprimirPacmanComiendo();
        if(oGhost1.getEstado() || !oGhost1.getEstado()){
            //dibuja los fantasmas depende del estado, o sea, si son comestibles o no;
            //lo sin importar el estado porque aún no están los diseños;
            oGhost1.dibujarFantasma();
            oGhost2.dibujarFantasma();
            oGhost3.dibujarFantasma();
            oGhost4.dibujarFantasma();
            oGhost5.dibujarFantasma();
        }

        oMapa.imprimirMapa();

        rest(125);


        //imprime el pacman con la boca cerrada
        clear(pacman);
        oPacman.imprimirPacmanQuieto();
        oMapa.imprimirMapa();
        rest(125);
        oMapa.imprimirMapa();

        if(pacman_colision_ghost(pac_x, pac_y, vec_ghost_x, vec_ghost_y)){
                //hay que optimizarlo ya que tarda en procesar la muerte
            oPacman.restarVida();
            oPacman.posicionInicial();
            oGhost1.posicionInicialGhost();
            oGhost2.posicionInicialGhost();
            oGhost3.posicionInicialGhost();
            oGhost4.posicionInicialGhost();
            oGhost5.posicionInicialGhost();
        }

        if(!oPacman.hayComida() || key[KEY_ESC] || oPacman.getVidas()== -1){ //si no hay comida... termina el juego
            game_over = true;
        }
    }
    if(game_over){
        allegro_message("LOSER! :)");
    }
destruir();
}
END_OF_MAIN();
