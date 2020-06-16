#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED


const int MAXFILAS = 20;
const int MAXCOL = 30;
const int TAM = 32;
bool game_over = false;

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
BITMAP *vidass;
BITMAP *numeros;
BITMAP *unidad;
BITMAP *decena;
BITMAP *centena;
BITMAP *milesima;
BITMAP *score;
BITMAP *maxscore;

//coordenadas,

//posiciones iniciales del pacman y las que controlan X e Y del mismo
int dir=4;
int px=TAM*14, py=TAM*17;
int cx=TAM*10, cy=TAM*8; //Ubicacion del cursor
int anteriorpx, anteriorpy;
int vidas=3;
int puntaje=0;
int puntajemax;
//FUNCIONES
int inicia_audio(int izquierda, int derecha);


#endif // VARIABLES_H_INCLUDED
