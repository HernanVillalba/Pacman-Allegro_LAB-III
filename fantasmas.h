#ifndef FANTASMAS_H_INCLUDED
#define FANTASMAS_H_INCLUDED

class Fantasma{
private:
    int fdir;
    int fx,fy;
    int colorfant;
    char mapa[MAXFILAS][MAXCOL] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XJ   J JXJ          JXJ J   JX",
        "X XXX X X XXXXXXXXXX X X XXX X",
        "X XJ JX X XJ      JX X XJ JX X",
        "X X XXX X X XXXXXX X X XXX X X",
        "XJ J J J J J      J J J J J JX",
        "XXXXX X XXXXXXXXXXXXXX X XXXXX",
        "XNNNX XJ  JXXXXXXXXJ  JX XNNNX",
        "XXXXX XXXXJ        JXXXX XXXXX",
        "P    J  JX XXXNNXXX XJ  J    P",
        "XXXXX XX X XFFFFFFX X XX XXXXX",
        "XNNNX XX X XFFFFFFX X XX XNNNX",
        "XXXXX XX X XXXXXXXX X XX XXXXX",
        "XJ   JXXJ J        J JXXJ   JX",
        "X XXX XX XXXXXXXXXXXX XX XXX X",
        "X XNXJ  J J        J J  JXNX X",
        "X XNX XXXX XXXXXXXX XXXX XNX X",
        "X XXX XXXXJ        JXXXX XXX X",
        "XJ   J    JXXXXXXXXJ    J   JX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};
public:
    Fantasma(int x, int y); //construimos el fantasma
    void dibujarFantasma();
    bool bordeMapa2();
    void moverFantasma();
    bool caminoFantasma();
};

Fantasma::Fantasma(int x, int y){
    fx=x;
    fy=y;
    colorfant=rand()%5;
    fdir=rand()%4;

}
void Fantasma::dibujarFantasma(){

blit(fantBMP,fantas,colorfant*TAM,0,0,0,32,32);
draw_sprite(buffer,fantas,fx,fy);
}

bool Fantasma::bordeMapa2(){
    switch(fdir){
    case 0:
        if ((mapa[fy/TAM][(fx+TAM)/TAM]!='X') && (mapa[fy/TAM][(fx+TAM)/TAM]!='N'))return true;
            else return false; break;
    case 1:
        if ((mapa[(fy-TAM)/TAM][fx/TAM]!='X') && (mapa[(fy-TAM)/TAM][fx/TAM]!='N'))return true;
            else return false; break;
    case 2:
        if ((mapa[fy/TAM][(fx-TAM)/TAM]!='X') && (mapa[fy/TAM][(fx-TAM)/TAM]!='N'))return true;
            else return false; break;
    case 3:
        if ((mapa[(fy+TAM)/TAM][fx/TAM]!='X') && (mapa[(fy+TAM)/TAM][fx/TAM]!='N'))return true;
            else return false; break;
    default: return true; break;
        }
}

bool Fantasma::caminoFantasma(){
    if (mapa[fy/TAM][fx/TAM]=='J')return true;
            else return false; ;
}
void Fantasma::moverFantasma(){

    if(fdir == 0 && bordeMapa2())       fx += TAM;
    else if(fdir == 1 && bordeMapa2())  fy -= TAM;
    else if(fdir == 2 && bordeMapa2())  fx -= TAM;
    else if(fdir == 3 && bordeMapa2())  fy += TAM;
    if (caminoFantasma()) fdir=rand()%4;
    if (fx<0)fx=930;
    else if (fx>930) fx=0;
 }
#endif // FANTASMAS_H_INCLUDED
