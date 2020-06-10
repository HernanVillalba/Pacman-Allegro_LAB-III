#ifndef FANTASMAS_H_INCLUDED
#define FANTASMAS_H_INCLUDED

class Fantasma{
private:
    int fdir;
    int fx,fy;
    int colorfant;
public:
    Fantasma(int x, int y); //construimos el fantasma
    void dibujarFantasma();
    void moverFantasma();


};

Fantasma::Fantasma(int x, int y){
    fx=x;
    fy=y;
    fdir=rand()%4;
    colorfant=rand()%5;

}
void Fantasma::dibujarFantasma(){

blit(fantBMP,fantas,colorfant*TAM,0,0,0,32,32);
draw_sprite(buffer,fantas,fx,fy);
}

#endif // FANTASMAS_H_INCLUDED
