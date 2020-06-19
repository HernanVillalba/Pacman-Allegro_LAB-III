#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

//constantes
const int MAXFILAS = 20;
const int MAXCOL = 30;
const int TAM = 32;
bool game_over = false;

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

//sonidos
MIDI *sountrack_stage_1;
SAMPLE *big_food;
SAMPLE *bolitas;
SAMPLE *portal_sountrack;

//posiciones iniciales del pacman y las que controlan X e Y del mismo
int posicion_pacman_x, posicion_pacman_y;
int dir=4;
int cx=TAM*10, cy=TAM*8; //Ubicacion del cursor
int anteriorpx, anteriorpy;
int vidas;
int puntaje=0;
int puntajemax;
int anterior_dir_Pacman;

#endif // VARIABLES_H_INCLUDED
