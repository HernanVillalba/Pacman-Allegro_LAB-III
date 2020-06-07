#ifndef FUNCIONES_GLOBALES_H_INCLUDED
#define FUNCIONES_GLOBALES_H_INCLUDED

void iniciar_allegro(){
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,640,0,0);
    buffer = create_bitmap(1200,640);

    //cargar la imagen del bloque en el BITMAP 'bloque'
    bloque = load_bitmap("images/mapa/mapa_bloque.bmp",NULL);
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
