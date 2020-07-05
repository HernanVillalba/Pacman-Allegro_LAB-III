#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED
#include "mapa.h"
class Pacman:public Mapa{
    protected:
        int pos_x;
        int pos_y;
        int anterior_px;
        int anterior_py;
        int vidas;
        int dir;

    public:
        Pacman();
        void imprimirPacmanComiendo();
        void imprimirPacmanQuieto();
        int getVidas();
        void restarVida();
        int getPosXPac();
        int getPosYPac();
        void moverPacman();
        int getDir(){return dir;}
        void Comer();
        bool comidaGrande();
        bool hayComida();
        void posicionInicial();
        void DibujarMuerte(Mapa);
};

Pacman::Pacman(){
    vidas = 3;
    pos_x = TAM*14;
    pos_y = TAM*17;

    dir   = 2;
}

void Pacman::DibujarMuerte(Mapa oMapa){
    clear(screen);
    play_sample(dead_sound,255,100,1000,0);
    int i;
    for(i=0;i<7; i++){
        clear(pacman);
        clear(buffer);
        clear(screen);
//        oMapa.planoMapa();
        oMapa.imprimirMapa();
        blit(pac_dead_BMP,pacman,i*TAM,0,0,0,TAM,TAM);
        draw_sprite(buffer,pacman,pos_x,pos_y);
        oMapa.planoMapa();
        oMapa.imprimirMapa();
        rest(125+i*100);
    }
}

void Pacman::posicionInicial(){
    pos_x = TAM*14;
    pos_y = TAM*17;
}

int Pacman::getPosXPac(){
    return pos_x;
}

int Pacman::getPosYPac(){
    return pos_y;
}

void Pacman::imprimirPacmanComiendo(){
    blit(pacBMP,pacman,dir*TAM,0,0,0,TAM,TAM);
    draw_sprite(buffer,pacman,pos_x,pos_y);
}

void Pacman::imprimirPacmanQuieto(){
    blit(pacBMP,pacman,4*TAM,0,0,0,TAM,TAM);
    draw_sprite(buffer,pacman,pos_x,pos_y);
}

int Pacman::getVidas(){
    return vidas;
}

void Pacman::restarVida(){
    vidas--;
}

void Pacman::moverPacman(){

    anterior_px=pos_x;
    anterior_py=pos_y;

    if((key[KEY_RIGHT] || key[KEY_D]) && mapaP[pos_y/TAM][(pos_x/TAM)+1] != 'X') dir = 0; //DER vale 0
    if((key[KEY_UP]    || key[KEY_W]) && mapaP[(pos_y/TAM)-1][pos_x/TAM] != 'X') dir = 1; //ARRIB vale 1
    if((key[KEY_LEFT]  || key[KEY_A]) && mapaP[pos_y/TAM][(pos_x/TAM)-1] != 'X') dir = 2; //IZQ vale 2
    if((key[KEY_DOWN]  || key[KEY_S]) && mapaP[(pos_y/TAM)+1][pos_x/TAM] != 'X') dir = 3; //ABAJ vale 3

    if(dir == 0 && Mapa::bordeMapa1(dir,pos_y,pos_x)) pos_x += TAM;
    else if(dir == 1 && Mapa::bordeMapa1(dir,pos_y,pos_x)) pos_y -= TAM;
    else if(dir == 2 && Mapa::bordeMapa1(dir,pos_y,pos_x)) pos_x -= TAM;
    else if(dir == 3 && Mapa::bordeMapa1(dir,pos_y,pos_x)) pos_y += TAM;

    //movimiento en los portales
    if (pos_x<0){
        pos_x=898;
        play_sample(portal_sountrack,150,70,1500,0);
    }
    else if (pos_x>=928){
        pos_x=0;
        play_sample(portal_sountrack,150,70,1000,0);
    }

}

bool Pacman::comidaGrande(){
    if(mapaP[pos_y / TAM][pos_x/TAM] == 'C') {puntaje+=24;return true;}
    else return false;
    }

void Pacman::Comer(){
        Mapa::planoMapa();
        for(int fil=0; fil<MAXFILAS; fil++){
            for(int col=0; col<MAXCOL; col++){
                if ((pos_y / TAM == fil) && (pos_x/TAM == col) && (mapaP[fil][col] != 'P')
                    && ((mapaP[fil][col] == ' ') ||(mapaP[pos_y/TAM][pos_x/TAM] == 'C'))){
//                el "!= 'P' es para que no ponga un punto en esa posición y no borre los portales al pasar por ahi el pacman
//                si las coordenadas del pacman coincide donde está la comida, pongo un punto para que las borre;
                        if(mapaP[fil][col] == 'C'){
                            play_sample(big_food,60,100,1000,0);
                        }
                        else if(mapaP[fil][col] == ' ') play_sample(bolitas,100,70,1000,0);
                        mapaP[fil][col] = '.'; puntaje++;
                }
            }//for chico
        }//for grande
}//funcion

bool Pacman::hayComida(){
    for(int fil=0; fil<MAXFILAS; fil++){
        for(int col=0; col<MAXCOL; col++){
            if((mapaP[fil][col] == ' ') || (mapaP[fil][col] == 'C' )){
                return true;
            }
        }
    }
    return false;
}
#endif // PACMAN_H_INCLUDED
