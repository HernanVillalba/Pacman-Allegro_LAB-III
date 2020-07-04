#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

//constantes
const int MAXFILAS = 20;
const int MAXCOL = 30;
const int TAM = 32;

// imagenes
BITMAP *buffer;
BITMAP *bloque;
BITMAP *comida;
BITMAP *pacBMP;
BITMAP *pacman;
BITMAP *portal_IZQ;
BITMAP *portal_DER;
BITMAP *inicio; //pantalla de inicio
BITMAP *cursor; // cursor
BITMAP *fantBMP;
BITMAP *fantas;
BITMAP *comida_grande;
BITMAP *muerte;
BITMAP *vidas_pacmanBMP;
BITMAP *vidas_pacman;
BITMAP *letras_vidas;
BITMAP *numeros;
BITMAP *unidad;
BITMAP *decena;
BITMAP *centena;
BITMAP *milesima;
BITMAP *score;
BITMAP *maxscore;
//menu slegir skin
BITMAP *cursor_elegir_skin;
BITMAP *fondo_elegir_skin;
BITMAP *fondo_elegir_skin1;
BITMAP *fondo_elegir_skin2;
BITMAP *fondo_elegir_skin3;

//sonidos
MIDI *sountrack_stage_1;
SAMPLE *big_food;
SAMPLE *bolitas;
SAMPLE *portal_sountrack;
const char *RUTA_sountrack_stage_1; //para poner la ruta de musica del juego


int puntaje=0;
int puntajemax;
int anterior_dir_Pacman;

#endif // VARIABLES_H_INCLUDED
