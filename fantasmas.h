#ifndef FANTASMAS_H_INCLUDED
#define FANTASMAS_H_INCLUDED

class Fantasma{
private:
    int fdir;
    int fx,fy;
    int colorfant;
    int primerfy,primerfx;
    bool estadoFantas;
    char mapa[MAXFILAS][MAXCOL] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XJ   J JXJ         JXJ J   JX",
        "X XXX X X XXXXXXXXX X X XXX X",
        "X XJ JX X XJ     JX X XJ JX X",
        "X X XXX X X XXXXX X X XXX X X",
        "XJ J J J J J     J J J J J JX",
        "XXXXX X XXXXXXXXXXXXX X XXXXX",
        "XNNNX XJ  JXXXXXXXJ  JX XNNNX",
        "XXXXX XXXXJ   J   JXXXX XXXXX",
        "P    J  JX XXXNXXX XJ  J    P",
        "XXXXX XX X XhhYHHX X XX XXXXX",
        "XNNNX XX X XhhYHHX X XX XNNNX",
        "XXXXX XX X XXXXXXX X XX XXXXX",
        "XJ   JXXJ J       J JXXJ   JX",
        "X XXX XX XXXXXXXXXXX XX XXX X",
        "X XNXJ  J J       J J  JXNX X",
        "X XNX XXXX XXXXXXX XXXX XNX X",
        "X XXX XXXXJ       JXXXX XXX X",
        "XJ   J    JXXXXXXXJ    J   JX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};
public:
    Fantasma(int x, int y, int col); //construimos el fantasma
    void dibujarFantasma();
    bool bordeMapa2();
    void moverFantasma();
    bool caminoFantasma();
    bool salidaFantasma();
    void centroFantasma();
    void choqueFantasma();
    void cambiarEstado();
};

Fantasma::Fantasma(int x, int y, int col){
    fx=x;
    fy=y;
    primerfy=y;
    primerfx=x;
    colorfant=col;
    fdir=rand()%4;
    estadoFantas=1;
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
        if (mapa[fy/TAM][(fx+TAM)/TAM]!='X')return true;
            else return false; break;
    case 1:
        if (mapa[(fy-TAM)/TAM][fx/TAM]!='X')return true;
            else return false; break;
    case 2:
        if (mapa[fy/TAM][(fx-TAM)/TAM]!='X')return true;
            else return false; break;
    case 3:
        if ((mapa[(fy+TAM)/TAM][fx/TAM]!='X') && (mapa[(fy+TAM)/TAM][fx/TAM]!='N'))return true;
            else return false; break;
    default: return true; break;
        }
}
bool Fantasma::salidaFantasma(){
    if (mapa[fy/TAM][fx/TAM]=='Y')return true;
    else return false;
}
void Fantasma::centroFantasma(){
    if (mapa[fy/TAM][fx/TAM]=='H')
        fdir=2;
    else if(mapa[fy/TAM][fx/TAM]=='h')
            fdir=0;
}

void Fantasma::cambiarEstado(){
    //vuelve a los fantasmas comestibles
estadoFantas=0;
}
bool Fantasma::caminoFantasma(){
    //Los fantas leen los bifurcaciones
    if (mapa[fy/TAM][fx/TAM]=='J')return true;
            else return false; ;
}
void Fantasma::moverFantasma(){
    //Los fantasmas se mueven
    choqueFantasma();
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
 void Fantasma::choqueFantasma(){
    //Choque fantasma, tanto muerte del pac, como del fantasma
    if ((py==fy && px==fx )||(fx==anteriorpx && fy==anteriorpy)){
    if (estadoFantas){
    clear(pacman);
    clear(buffer);
    blit(buffer,screen,0,0,0,0,1200,640);
    px=TAM*14;
    py=TAM*17;}
    else {
    clear(buffer);
    fy=primerfy;
    fx=primerfx;}
    }


 }
#endif // FANTASMAS_H_INCLUDED
