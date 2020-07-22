#ifndef FUNCIONES_GLOBALES_H_INCLUDED
#define FUNCIONES_GLOBALES_H_INCLUDED
#include "mapa.h"
#include "fantasmas.h"
#include "pacman.h"
#include "puntaje.h"

//protoripos
void iniciar_sonido();
void pantalla_elegir_skin();
void iniciar_sonido();
void iniciar_allegro();
void jugar();
int pantalla_inicial();
int inicia_audio(int izquierda, int derecha);
void destruir();
void dibujar_vidas_pacman(int vid);
void dibujar_puntaje(int puntaje);
void menu_idioma();
void mostrar_japo();
void iniciar_vectriz();


//funciones
void iniciar_allegro(){
    //inicia allegro junto con sus imagenes
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,640,0,0);
    buffer = create_bitmap(1200,640);
    install_mouse(); //para usar el mouse con allegro;


    inicio = load_bitmap("images/menu/inicio/inicio.bmp",NULL);
    elegir_inicio1 = load_bitmap("images/menu/inicio/inicio_1.bmp",NULL);
    elegir_inicio2 = load_bitmap("images/menu/inicio/inicio_2.bmp",NULL);
    elegir_inicio3 = load_bitmap("images/menu/inicio/inicio_3.bmp",NULL);
    elegir_inicio4 = load_bitmap("images/menu/inicio/inicio_4.bmp",NULL);

    vidas_pacmanBMP = load_bitmap("images/pacman/pacman_vidas.bmp",NULL);
    vidas_pacman = create_bitmap(TAM*3,TAM);
    letras_vidas=load_bitmap("images/menu/vidas.bmp",NULL);
    numeros=load_bitmap("images/menu/puntaje/numeros.bmp",NULL);
    score=load_bitmap("images/menu/puntaje/puntaje.bmp",NULL);
    maxscore=load_bitmap("images/menu/puntaje/maxpuntaje.bmp",NULL);
    unidad=create_bitmap(TAM,TAM);
    decena=create_bitmap(TAM,TAM);
    centena=create_bitmap(TAM,TAM);
    milesima=create_bitmap(TAM,TAM);
    letras=load_bitmap("images/menu/puntaje/letras.bmp",NULL);
    let1=create_bitmap(TAM,TAM);
    let2=create_bitmap(TAM,TAM);
    let3=create_bitmap(TAM,TAM);
    let4=create_bitmap(TAM,TAM);
    scores = load_bitmap("images/menu/puntaje/tabla_puntajes.bmp",NULL);

    //cargar imagenes -menu elegir skin-;
    cursor_elegir_skin = load_bitmap("images/menu/elegir_skin/cursor_skin.bmp",NULL);
    fondo_elegir_skin = load_bitmap("images/menu/elegir_skin/fondo.bmp",NULL);
    fondo_elegir_skin1 = load_bitmap("images/menu/elegir_skin/fondo_skin1.bmp",NULL);
    fondo_elegir_skin2 = load_bitmap("images/menu/elegir_skin/fondo_skin2.bmp",NULL);
    fondo_elegir_skin3 = load_bitmap("images/menu/elegir_skin/fondo_skin3.bmp",NULL);

    idioma = load_bitmap("images/menu/idioma/idioma.bmp",NULL);
    elegir_idioma1 = load_bitmap("images/menu/idioma/idioma_1.bmp",NULL);
    elegir_idioma2 = load_bitmap("images/menu/idioma/idioma_2.bmp",NULL);
    elegir_idioma3 = load_bitmap("images/menu/idioma/idioma_3.bmp",NULL);
    elegir_idioma4 = load_bitmap("images/menu/idioma/idioma_4.bmp",NULL);
    japo = load_bitmap("images/menu/idioma/japones.bmp",NULL);
    escape= load_bitmap("images/mapa/escape.bmp",NULL);
    dead_ghost = load_wav("sounds/Pacman/dead_ghost.wav");
    win = load_wav("sounds/Map/win.wav");
    newscores=load_bitmap("images/menu/puntaje/puntajenuevo.bmp",NULL);

    iniciar_vectriz();
    //carga de los sonidos
    iniciar_sonido();
//    sountrack_stage_1 = load_midi("sounds/Map/sountrack_game-stage_01.mid");

}

//pone el bitmap en el inicio
int pantalla_inicial(){
   bool salir = false;
    clear(buffer);
    while(!salir){
        blit(inicio,buffer,0,0,0,0,1200,640);

        if((mouse_x>388 && mouse_x<595) && (mouse_y>255 && mouse_y<287)){
            blit(elegir_inicio1,buffer,0,0,0,0,1200,640);
            if(mouse_b & 1){
                pantalla_elegir_skin();
                return 1;
            }
        }
        if((mouse_x>388 && mouse_x<710) && (mouse_y>353 && mouse_y<384)){
            blit(elegir_inicio2,buffer,0,0,0,0,1200,640);
            if(mouse_b & 1){
                return 2;
            }
        }
        if((mouse_x>388 && mouse_x<630) && (mouse_y>455 && mouse_y<481)){
            blit(elegir_inicio3,buffer,0,0,0,0,1200,640);
            if(mouse_b & 1){ return 3;
            }
        }
        if((mouse_x>388 && mouse_x<544) && (mouse_y>552 && mouse_y<572)){
            blit(elegir_inicio4,buffer,0,0,0,0,1200,640);
            if(mouse_b & 1){ exit(0);}
        }

        masked_blit(cursor_elegir_skin,buffer,0,0,mouse_x,mouse_y,45,48);
        blit(buffer,screen,0,0,0,0,1200,640);
    }
}

void destruir(){
    destroy_bitmap(buffer);
    destroy_bitmap(pacBMP);
    destroy_bitmap(pacman);
    destroy_bitmap(fantas);
    destroy_bitmap(fantBMP);
    destroy_bitmap(bloque);
    destroy_bitmap(comida);
    destroy_bitmap(portal_IZQ);
    destroy_bitmap(portal_DER);
    destroy_bitmap(inicio);
    destroy_bitmap(vidas_pacman);
    destroy_bitmap(vidas_pacmanBMP);
    destroy_bitmap(numeros);
    destroy_bitmap(unidad);
    destroy_bitmap(decena);
    destroy_bitmap(centena);
    destroy_bitmap(milesima);
    destroy_bitmap(score);
    destroy_bitmap(letras_vidas);
    destroy_bitmap(elegir_idioma1);
    destroy_bitmap(elegir_idioma2);
    destroy_bitmap(elegir_idioma3);
    destroy_bitmap(elegir_idioma4);
    destroy_bitmap(japo);

}

void dibujar_vidas_pacman(int vid){
        blit(vidas_pacmanBMP,vidas_pacman,vid*TAM,0,0,0,TAM*3,TAM);
        draw_sprite(buffer,letras_vidas,30*TAM,14*TAM);
        draw_sprite(buffer,vidas_pacman,30*TAM,15*TAM);
//        blit(buffer,screen,0,0,0,0,1200,640);
}

void dibujar_puntaje(int puntaje){
int nunidad,ndecena,ncentena,nmilesima;
        //decomponemos el num
        if (puntaje>=9999) puntaje=9999;
        nmilesima=puntaje/1000;
        puntaje=puntaje%1000;
        ncentena=puntaje/100;
        puntaje=puntaje%100;
        ndecena=puntaje/10;
        puntaje=puntaje%10;
        nunidad=puntaje/1;

        //usamos la descomposicion para buscar el num
        blit(numeros,unidad,nunidad*TAM,0,0,0,TAM,TAM);
        blit(numeros,decena,ndecena*TAM,0,0,0,TAM,TAM);
        blit(numeros,centena,ncentena*TAM,0,0,0,TAM,TAM);
        blit(numeros,milesima,nmilesima*TAM,0,0,0,TAM,TAM);

        //imprimimos el num descompuesto
        draw_sprite(buffer,score,30*TAM,4*TAM);
        draw_sprite(buffer,milesima,31*TAM,5*TAM);
        draw_sprite(buffer,centena,32*TAM,5*TAM);
        draw_sprite(buffer,decena,33*TAM,5*TAM);
        draw_sprite(buffer,unidad,34*TAM,5*TAM);
        blit(buffer,screen,0,0,0,0,1200,640);
}

void pantalla_princio(bool *primera_vez,Mapa oMapa,Pacman oPacman){
    *primera_vez = true;
    clear(buffer);
    oMapa.planoMapa();
    oMapa.imprimirMapa();
    draw_sprite(screen,ready,11*TAM,6*TAM);
    rest(5000);
}

void iniciar_sonido(){
     if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       system("pause");
       return;
    }
    set_volume(500, 500);
}

void pantalla_elegir_skin(){
    bool salir = false;
    clear(buffer);
    while(!salir){
        blit(fondo_elegir_skin,buffer,0,0,0,0,960,640);
        ready = load_bitmap("images/menu/ready.bmp",NULL);

        if((mouse_x>90 && mouse_x<280) && (mouse_y>320 && mouse_y<549)){

            blit(fondo_elegir_skin1,buffer,0,0,0,0,960,640);
            if(mouse_b & 1){
                //sounds
                RUTA_sountrack_stage_1 = "sounds/Map/sountrack_game-stage_01.mid";
                sountrack_stage_1 = load_midi(RUTA_sountrack_stage_1);
                big_food = load_wav("sounds/pacman/bigfood_sound_pacman.wav");
                bolitas = load_wav("sounds/pacman/food_pacman.wav");
                portal_sountrack = load_wav ("sounds/Map/portal_sound_pacman.wav");
                dead_sound = load_wav("sounds/Pacman/dead_sound_pacbolico.wav");

                //imagenes
                pacBMP = load_bitmap("images/pacman/pacman.bmp",NULL);
                pacman = create_bitmap(TAM,TAM);
                comida = load_bitmap("images/mapa/mapa_comida.bmp",NULL);
                comida_grande = load_bitmap("images/mapa/mapa_comida_grande.bmp",NULL);
                fantBMP = load_bitmap("images/pacman/fantas.bmp",NULL);
                fantas = create_bitmap(TAM,TAM);
                bloque = load_bitmap("images/mapa/mapa_bloque.bmp",NULL);
                portal_IZQ = load_bitmap("images/mapa/mapa_portal_izq.bmp",NULL);
                portal_DER = load_bitmap("images/mapa/mapa_portal_der.bmp",NULL);
                pac_dead_BMP = load_bitmap ("images/pacman/muerte_pac.bmp",NULL);

                salir = true;
            }
        }

        if((mouse_x>388 && mouse_x<570) && (mouse_y>319 && mouse_y<542)){
            blit(fondo_elegir_skin2,buffer,0,0,0,0,960,640);
            if(mouse_b & 1){
                //sounds
                RUTA_sountrack_stage_1 = "sounds/Map/sountrack_pacrome.mid";
                sountrack_stage_1 = load_midi(RUTA_sountrack_stage_1);
//                play_midi(sountrack_stage_1,1);
                big_food = load_wav("sounds/pacman/bigfood_sound_pacrome.wav");
                bolitas = load_wav("sounds/pacman/food_pacrome.wav");
                portal_sountrack = load_wav ("sounds/Map/portal_sound_pacrome.wav");
                dead_sound = load_wav("sounds/Pacman/dead_sound_pacrome.wav");

                pacBMP = load_bitmap("images/pacman/pachrome.bmp",NULL);
                pacman = create_bitmap(TAM,TAM);
                comida = load_bitmap("images/mapa/mapa_crhomida.bmp",NULL);
                comida_grande = load_bitmap("images/mapa/mapa_crhomida_grande.bmp",NULL);
                fantBMP = load_bitmap("images/pacman/fantas_crome.bmp",NULL);
                fantas = create_bitmap(TAM,TAM);
                bloque = load_bitmap("images/mapa/mapa_blocrome.bmp",NULL);
                portal_IZQ = load_bitmap("images/mapa/mapa_portal_izq.bmp",NULL);
                portal_DER = load_bitmap("images/mapa/mapa_portal_der.bmp",NULL);
                pac_dead_BMP = load_bitmap ("images/pacman/muerte_pacrome.bmp",NULL);
                salir = true;
            }
        }

        if((mouse_x>660 && mouse_x<860) && (mouse_y>320 && mouse_y<556)){
                //SKIN DIABOLICA
            blit(fondo_elegir_skin3,buffer,0,0,0,0,960,640);
            if(mouse_b & 1){
                //sounds
                big_food = load_wav("sounds/pacman/bigfood_sound_pacbolico.wav");
                bolitas = load_wav("sounds/pacman/food_pacbolico.wav");
                portal_sountrack = load_wav ("sounds/Map/portal_sound_pacbolico.wav");
                dead_sound = load_wav("sounds/Pacman/dead_sound_pacbolico.wav");
                RUTA_sountrack_stage_1 = "sounds/Map/sountrack_game-stage_01_diabolico.mid";
                sountrack_stage_1 = load_midi(RUTA_sountrack_stage_1);
//                play_midi(sountrack_stage_1,300);

                //images
                pacBMP = load_bitmap("images/pacman/pacdiabolico.bmp",NULL);
                pacman = create_bitmap(TAM,TAM);
                comida = load_bitmap("images/mapa/mapa_diabomida.bmp",NULL);
                comida_grande = load_bitmap("images/mapa/mapa_diabomida_grande.bmp",NULL);
                fantBMP = load_bitmap("images/pacman/fantas_diabolico.bmp",NULL);
                fantas = create_bitmap(TAM,TAM);
                bloque = load_bitmap("images/mapa/mapa_blocbolico.bmp",NULL);
                portal_IZQ = load_bitmap("images/mapa/mapa_portbolico_izq.bmp",NULL);
                portal_DER = load_bitmap("images/mapa/mapa_portbolico_der.bmp",NULL);
                pac_dead_BMP = load_bitmap ("images/pacman/muerte_pacbolico.bmp",NULL);
                salir = true;
            }
        }

        masked_blit(cursor_elegir_skin,buffer,0,0,mouse_x,mouse_y,45,48);
        blit(buffer,screen,0,0,0,0,960,640);
    }
}

void obtener_posicio_personajes(Pacman oPacman, Fantasma oGhost1,Fantasma oGhost2,Fantasma oGhost3,Fantasma oGhost4,Fantasma oGhost5){
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
}

bool pacman_colision_ghost(int pac_x, int pac_y, int antx, int anty, int *vec_ghost_x, int *vec_ghost_y){
        if(
        ((pac_x == vec_ghost_x[0])&&(pac_y == vec_ghost_y[0])) ||
        ((pac_x == vec_ghost_x[1])&&(pac_y == vec_ghost_y[1])) ||
        ((pac_x == vec_ghost_x[2])&&(pac_y == vec_ghost_y[2])) ||
        ((pac_x == vec_ghost_x[3])&&(pac_y == vec_ghost_y[3])) ||
        ((pac_x == vec_ghost_x[4])&&(pac_y == vec_ghost_y[4]))
           )
        {return true;}

        else return false;
}

void menu_idioma(){
   bool salir = false;
    clear(buffer);
    rest(100);
    while(!salir){
        blit(idioma,buffer,0,0,0,0,1200,640);

        if((mouse_x>388 && mouse_x<645) && (mouse_y>255 && mouse_y<287)){
            blit(elegir_idioma1,buffer,0,0,0,0,1200,640);
            if(mouse_b & 1){
                idioma = load_bitmap("images/menu/idioma/idioma.bmp",NULL);
                elegir_idioma1 = load_bitmap("images/menu/idioma/idioma_1.bmp",NULL);
                elegir_idioma2 = load_bitmap("images/menu/idioma/idioma_2.bmp",NULL);
                elegir_idioma3 = load_bitmap("images/menu/idioma/idioma_3.bmp",NULL);
                elegir_idioma4 = load_bitmap("images/menu/idioma/idioma_4.bmp",NULL);
                inicio = load_bitmap("images/menu/inicio/inicio.bmp",NULL);
                elegir_inicio1 = load_bitmap("images/menu/inicio/inicio_1.bmp",NULL);
                elegir_inicio2 = load_bitmap("images/menu/inicio/inicio_2.bmp",NULL);
                elegir_inicio3 = load_bitmap("images/menu/inicio/inicio_3.bmp",NULL);
                elegir_inicio4 = load_bitmap("images/menu/inicio/inicio_4.bmp",NULL);
                scores = load_bitmap("images/menu/puntaje/tabla_puntajes.bmp",NULL);


            }
        }
        if((mouse_x>388 && mouse_x<650) && (mouse_y>353 && mouse_y<384)){
            blit(elegir_idioma2,buffer,0,0,0,0,1200,640);
            if(mouse_b & 1){
                idioma = load_bitmap("images/menu/languaje/language.bmp",NULL);
                elegir_idioma1 = load_bitmap("images/menu/languaje/language_1.bmp",NULL);
                elegir_idioma2 = load_bitmap("images/menu/languaje/language_2.bmp",NULL);
                elegir_idioma3 = load_bitmap("images/menu/languaje/language_3.bmp",NULL);
                elegir_idioma4 = load_bitmap("images/menu/languaje/language_4.bmp",NULL);
                inicio = load_bitmap("images/menu/start/start.bmp",NULL);
                elegir_inicio1 = load_bitmap("images/menu/start/start_1.bmp",NULL);
                elegir_inicio2 = load_bitmap("images/menu/start/start_2.bmp",NULL);
                elegir_inicio3 = load_bitmap("images/menu/start/start_3.bmp",NULL);
                elegir_inicio4 = load_bitmap("images/menu/start/start_4.bmp",NULL);
                scores = load_bitmap("images/menu/puntaje/table_scores.bmp",NULL);

            }
        }
        if((mouse_x>388 && mouse_x<630) && (mouse_y>455 && mouse_y<481)){
            blit(elegir_idioma3,buffer,0,0,0,0,1200,640);
            if(mouse_b & 1){ mostrar_japo();

}
        }
        if((mouse_x>388 && mouse_x<544) && (mouse_y>552 && mouse_y<572)){
            blit(elegir_idioma4,buffer,0,0,0,0,1200,640);
            if(mouse_b & 1) {salir=true; rest(500);}
        }

        masked_blit(cursor_elegir_skin,buffer,0,0,mouse_x,mouse_y,45,48);
        blit(buffer,screen,0,0,0,0,1200,640);
    }
}

void mostrar_japo(){
    while (!key[KEY_ESC]){
    blit(japo,buffer,0,0,0,0,1200,640);
    masked_blit(cursor_elegir_skin,buffer,0,0,mouse_x,mouse_y,45,48);
    blit(buffer,screen,0,0,0,0,1200,640);
    }

    }

void mostrar_puntaje(){
Puntuacion oPuntuacion;
//oPuntuacion.crearPuntaje();
oPuntuacion.leerDeArchivo();
oPuntuacion.ordenarScores();

}

bool buscar_newscore(int p){

    for (int x=0;x<4;x++){
       if(p>vec_punt[x]) {vec_punt[3]=p;return true;}
        }
    return false;

}

void iniciar_vectriz(){
    for (int x=0;x<4;x++){
        for(int y=0;y<4;y++){
            mat_nom[x][y]=0;
        }
        vec_punt[x]=0;
    }


}



#endif // FUNCIONES_GLOBALES_H_INCLUDED
