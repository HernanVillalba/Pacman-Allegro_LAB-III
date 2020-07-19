#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

////////////////////////// DECLARACIONES VARIABLES

//terminar juego o iniciarlo

//constantes mapa
const int MAXFILAS = 20;
const int MAXCOL = 30;
const int TAM = 32; //en pixeles
const char *ARCHIVO_PUNTAJE = "maxscores.dat";

// imagenes
BITMAP *buffer;
BITMAP *bloque;
BITMAP *comida;
BITMAP *escape;
BITMAP *pacBMP;
BITMAP *pacman;
BITMAP *portal_IZQ;
BITMAP *portal_DER;
BITMAP *inicio; //pantalla de inicio
BITMAP *elegir_inicio1;
BITMAP *elegir_inicio2;
BITMAP *elegir_inicio3;
BITMAP *elegir_inicio4;

BITMAP *fantBMP;
BITMAP *fantas;
BITMAP *comida_grande;
BITMAP *muerte;
BITMAP *vidas_pacmanBMP;
BITMAP *vidas_pacman;
BITMAP *letras_vidas;
//puntaje
BITMAP *numeros;
BITMAP *unidad;
BITMAP *decena;
BITMAP *centena;
BITMAP *milesima;
BITMAP *score;
BITMAP *maxscore;
BITMAP *letras;
BITMAP *let1;
BITMAP *let2;
BITMAP *let3;
BITMAP *let4;

BITMAP *pac_dead_BMP;
BITMAP *ready;
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
SAMPLE *dead_sound;
SAMPLE *dead_ghost;
SAMPLE *win;
const char *RUTA_sountrack_stage_1; //para poner la ruta de musica del juego

//elegir idioma
BITMAP *idioma;
BITMAP *elegir_idioma1;
BITMAP *elegir_idioma2;
BITMAP *elegir_idioma3;
BITMAP *elegir_idioma4;
BITMAP *japo;
BITMAP *scores;

//pacman
int pac_x, pac_y;
int vec_ghost_x[5],vec_ghost_y[5];
int vec_punt[4];
int puntaje;
int mat_nom[4][4]={0};



#endif // VARIABLES_H_INCLUDED
