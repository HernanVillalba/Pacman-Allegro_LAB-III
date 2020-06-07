#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED


const int MAXFILAS = 20;
const int MAXCOL = 31;
const int TAM = 32;
bool game_over = false;

BITMAP *buffer;
BITMAP *bloque;
BITMAP *comida;
BITMAP *pacBMP;
BITMAP *pacman;
BITMAP *portal_IZQ;
BITMAP *portal_DER;

//posiciones iniciales del pacman y las que controlan X e Y del mismo
int dir=4;
int px=TAM*15, py = TAM*17;


//FUNCIONES
int inicia_audio(int izquierda, int derecha);


#endif // VARIABLES_H_INCLUDED
