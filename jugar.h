#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

void jugar(){

    bool game_over = false;
    bool primera_vez = false;

    Mapa oMapa;
    Pacman oPacman;
    Fantasma oGhost1(TAM*12,TAM*10,0);
    Fantasma oGhost2(TAM*13,TAM*10,1);
    Fantasma oGhost3(TAM*14,TAM*10,2);
    Fantasma oGhost4(TAM*15,TAM*10,3);
    Fantasma oGhost5(TAM*16,TAM*10,4);


    int ghost_x,ghost_y;

    while(!game_over){
        if(!primera_vez){
            //para pausar la pantalla al comienzo
            pantalla_princio(&primera_vez,oMapa,oPacman);
        }
        if(!oPacman.hayComida() || key[KEY_ESC] || oPacman.getVidas()== -1){ //si no hay comida... termina el juego
            game_over = true;
            break;
        }

        obtener_posicio_personajes(oPacman,oGhost1,oGhost2,oGhost3,oGhost4,oGhost5);

        if(pacman_colision_ghost(pac_x, pac_y, vec_ghost_x, vec_ghost_y)){
            stop_midi();
            oPacman.DibujarMuerte(oMapa);
            oPacman.restarVida();
            oPacman.posicionInicial();
            oGhost1.posicionInicialGhost();
            oGhost2.posicionInicialGhost();
            oGhost3.posicionInicialGhost();
            oGhost4.posicionInicialGhost();
            oGhost5.posicionInicialGhost();
            play_midi(sountrack_stage_1,300);
            //mensaje de ready ///////////////////
            draw_sprite(screen,ready,11*TAM,6*TAM);
            rest(5000);
        }

        dibujar_vidas_pacman(oPacman.getVidas());
        dibujar_puntaje(puntaje);

//        se_presiono_una_tecla(oMapa);
        oPacman.moverPacman();

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

    }
    stop_midi();
}



#endif // JUGAR_H_INCLUDED
