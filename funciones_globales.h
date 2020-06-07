#ifndef FUNCIONES_GLOBALES_H_INCLUDED
#define FUNCIONES_GLOBALES_H_INCLUDED

void iniciar_allegro(){
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
}

int se_preciono_una_tecla(){
    //devuelve el valor de la tecla que se precionó;

    if(key[KEY_RIGHT]) return 0; //IZQ vale 0
    else if(key[KEY_UP]) return 1; //ARRIB vale 1
    else if(key[KEY_LEFT]) return 2; //DER vale 2
    else if(key[KEY_DOWN]) return 3; //ABAJ vale 3

    return -1; //si es otra tecla que no sea una flecha, devuelve -1;
}

int inicia_audio(int izquierda, int derecha){
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

	set_volume(izquierda, derecha);
    return 0;
}

#endif // FUNCIONES_GLOBALES_H_INCLUDED
