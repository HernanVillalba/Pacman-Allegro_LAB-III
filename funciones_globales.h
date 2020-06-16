#ifndef FUNCIONES_GLOBALES_H_INCLUDED
#define FUNCIONES_GLOBALES_H_INCLUDED
#include "mapa.h"
#include "fantasmas.h"

void iniciar_allegro(){
    //inicia allegro junto con sus imagenes
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,640,0,0);
    buffer = create_bitmap(1200,640);

    //cargar la imagen
    bloque = load_bitmap("images/mapa/mapa_bloque.bmp",NULL);
    comida = load_bitmap("images/mapa/mapa_comida.bmp",NULL);
    pacBMP = load_bitmap("images/pacman/pacman.bmp",NULL);
    pacman = create_bitmap(TAM,TAM);
    portal_IZQ = load_bitmap("images/mapa/mapa_portal_izq.bmp",NULL);
    portal_DER = load_bitmap("images/mapa/mapa_portal_der.bmp",NULL);
    inicio = load_bitmap("images/menu/inicio.bmp",NULL);
    cursor = load_bitmap("images/menu/cursor.bmp",NULL);
    fantBMP = load_bitmap("images/pacman/fantas.bmp",NULL);
    fantas = create_bitmap(TAM,TAM);
    comida_grande = load_bitmap("images/mapa/mapa_comida_grande.bmp",NULL);
    vidas_pacmanBMP = load_bitmap("images/pacman/pacman_vidas.bmp",NULL);
    vidas_pacman = create_bitmap(TAM*3,TAM);
    vidass=load_bitmap("images/menu/vidas.bmp",NULL);
    numeros=load_bitmap("images/menu/numeros.bmp",NULL);
    score=load_bitmap("images/menu/puntaje.bmp",NULL);
    maxscore=load_bitmap("images/menu/maxpuntaje.bmp",NULL);
    unidad=create_bitmap(TAM,TAM);
    decena=create_bitmap(TAM,TAM);
    centena=create_bitmap(TAM,TAM);
    milesima=create_bitmap(TAM,TAM);
    puntajemax=100;
}
//pone el bitmap en el inicio
void poner_inicio(){
    blit(buffer,screen,0,0,0,0,1200,640);
    blit(inicio,buffer,0,0,0,0,960,640);

   }

void mover_cursor(){
    //movimiento del cursor
    if (key[KEY_UP] && cy>256)  {cy-=TAM*3;}
    else if (key[KEY_DOWN] && cy<544)  {cy+=TAM*3;}
    rest(100);
    clear_keybuf();
}
//impresion de la pantalla y funcionalidad
void pantalla_inicial(){
    bool continuar=true;
    while (continuar){
        poner_inicio();
        draw_sprite (buffer,cursor,cx,cy);
        mover_cursor();
        //pantalla();
        if (key[KEY_ENTER] && cy==256) continuar= false;
    }
}

void se_presiono_una_tecla(){
    // detecta la tecla que se precinó para asignarle el numero correspondiente a la dirección
    if(key[KEY_RIGHT] || key[KEY_D]) dir = 0; //DER vale 0
    else if(key[KEY_UP] || key[KEY_W]) dir = 1; //ARRIB vale 1
    else if(key[KEY_LEFT] || key[KEY_A]) dir = 2; //IZQ vale 2
    else if(key[KEY_DOWN] || key[KEY_S]) dir = 3; //ABAJ vale 3
}

int inicia_audio(int izquierda, int derecha){
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

	set_volume(izquierda, derecha);
    return 0;
}

void mover_pacman(Mapa oMapa){
    if(dir == 0 && oMapa.bordeMapa1()) px += TAM;
    if(dir == 1 && oMapa.bordeMapa1()) py -= TAM;
    if(dir == 2 && oMapa.bordeMapa1()) px -= TAM;
    if(dir == 3 && oMapa.bordeMapa1()) py += TAM;
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
    destroy_bitmap(cursor);
    destroy_bitmap(vidas_pacman);
    destroy_bitmap(vidas_pacmanBMP);
    destroy_bitmap(numeros);
    destroy_bitmap(unidad);
    destroy_bitmap(decena);
    destroy_bitmap(centena);
    destroy_bitmap(milesima);
    destroy_bitmap(score);
}

void dibujar_vidas_pacman(int vid){

    //    if(vid == 3){

        blit(vidas_pacmanBMP,vidas_pacman,vid*TAM,0,0,0,TAM*3,TAM);
        draw_sprite(buffer,vidass,30*TAM,14*TAM);
        draw_sprite(buffer,vidas_pacman,960,15*TAM);
        blit(buffer,screen,0,0,0,0,1200,640);
//    }
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

#endif // FUNCIONES_GLOBALES_H_INCLUDED
