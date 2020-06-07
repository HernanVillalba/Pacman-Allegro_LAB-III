#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED


const int MAXFILAS = 20;
const int MAXCOL = 31;
const int TAM = 32;

BITMAP *buffer;
BITMAP *bloque;
BITMAP *comida;
BITMAP *pacBMP;
BITMAP *pacman;

int dir=0;
int px=TAM*16, py = TAM*15;


//FUNCIONES
int inicia_audio(int izquierda, int derecha);


#endif // VARIABLES_H_INCLUDED
