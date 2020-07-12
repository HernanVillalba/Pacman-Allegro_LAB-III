#ifndef FANTASMAS_H_INCLUDED
#define FANTASMAS_H_INCLUDED
#include "mapa.h"
#include "pacman.h"

class Fantasma:public Mapa{
private:
    int fdir;
    int fx,fy;
    int colorfant;
    int primerfy,primerfx;
    bool estadoFantas;
public:
    Fantasma();
    Fantasma(int x, int y, int col); //construimos el fantasma
    void dibujarFantasma();
    bool bordeMapa2();
    void moverFantasma();
    bool caminoFantasma();
    bool salidaFantasma();
    void centroFantasma();
    bool choqueFantasma(Pacman);
    void cambiarEstado(){estadoFantas=0;}
    void volverFantasma();
    bool getEstado();
    int get_ghost_x(){return fx;}
    int get_ghost_y(){return fy;}
    void posicionInicialGhost();
    void setEstado(){estadoFantas=true;}
};

Fantasma::Fantasma(){

}

Fantasma::Fantasma(int x, int y, int col){
    fx=x;
    fy=y;
    primerfy=y;
    primerfx=x;
    colorfant=col;
    fdir=rand()%4;
    estadoFantas=1;
}

void Fantasma::posicionInicialGhost(){
    fx = primerfx;
    fy = primerfy;
    estadoFantas=true;
}

void Fantasma::dibujarFantasma(){
    //Impresion de los fantasmas
blit(fantBMP,fantas,colorfant*TAM,0,0,0,32,32);
draw_sprite(buffer,fantas,fx,fy);
}

bool Fantasma::bordeMapa2(){
    //Los fantasmas leen los bordes
    switch(fdir){
    case 0:
        if (mapaF[fy/TAM][(fx+TAM)/TAM]!='X')return true;
            else return false; break;
    case 1:
        if (mapaF[(fy-TAM)/TAM][fx/TAM]!='X')return true;
            else return false; break;
    case 2:
        if (mapaF[fy/TAM][(fx-TAM)/TAM]!='X')return true;
            else return false; break;
    case 3:
        if ((mapaF[(fy+TAM)/TAM][fx/TAM]!='X') && (mapaF[(fy+TAM)/TAM][fx/TAM]!='N'))return true;
            else return false; break;
    default: return true; break;
        }
}
bool Fantasma::salidaFantasma(){
    if (mapaF[fy/TAM][fx/TAM]=='Y')return true;
    else return false;
}
void Fantasma::centroFantasma(){
    if (mapaF[fy/TAM][fx/TAM]=='H') fdir=2;
    else if(mapaF[fy/TAM][fx/TAM]=='h') fdir=0;
}


bool Fantasma::caminoFantasma(){
    //Los fantas leen los bifurcaciones
    if (mapaF[fy/TAM][fx/TAM]=='J')return true;
            else return false;
}
void Fantasma::moverFantasma(){
    //Los fantasmas se mueven
    Fantasma::centroFantasma();
    if     (fdir == 0 && bordeMapa2())  fx += TAM;
    else if(fdir == 1 && bordeMapa2())  fy -= TAM;
    else if(fdir == 2 && bordeMapa2())  fx -= TAM;
    else if(fdir == 3 && bordeMapa2())  fy += TAM;
    if (caminoFantasma()) fdir=rand()%4;
    if (salidaFantasma()) fdir=1;
    //Los fantis atraviesan el portal
    if      (fx<0)fx=898;
    else if (fx>898) fx=0;
 }

bool Fantasma::choqueFantasma(Pacman p){
    //Choque fantasma, tanto muerte del pac, como del fantasma
    if ((p.getPosYPac() == fy && p.getPosXPac()==fx) || (p.getAnty() == fy && p.getAntx()==fx)){
        if (estadoFantas){
            clear(pacman);
            clear(buffer);
            blit(buffer,screen,0,0,0,0,960,640);
            p.posicionInicial();
            p.restarVida();
            if (puntaje<100) puntaje=0;
            else puntaje-=100;
            return true;
        }
        else{
            clear(buffer);
            fy=primerfy;
            fx=primerfx;
            puntaje+=50;
            estadoFantas=1;
            return false;
        }
    }
}
 bool Fantasma::getEstado(){
    if(estadoFantas) return true;
    else return false;
}
#endif // FANTASMAS_H_INCLUDED
