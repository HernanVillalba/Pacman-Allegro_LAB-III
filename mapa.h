#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

class Mapa{
    private:
        /*X = ladrillos
        P = porta
        C = esquinas
        F = donde aparecen los fantasmas
        */
        char mapa[MAXFILAS][MAXCOL] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XC   C    CXC    CXC    C   CX",
        "X XXX XXXX X XXXX X XXXX XXX X",
        "X XXX XXXX X      X XXXX XXX X",
        "XC   C    C C    C C    C   CX",
        "X XXX XX XXXXXXXXXXXX XX XXX X",
        "XC   CXXC   CXXXXC   CXXC   CX",
        "X XXX XXXXXX XXXX XXXXXX XXX X",
        "X XXX XXC            CXX XXX X",
        "P    CXX XXXXXNNXXXXX XXC    P",
        "X XXX XX XFFFFFFFFFFX XX XXX X",
        "X XXX XX XFFFFFFFFFFX XX XXX X",
        "X XXX XX XXXXXXXXXXXX XX XXX X",
        "XC   CXXC            CXXC   CX",
        "X XXX XX XXXXXXXXXXXX XX XXX X",
        "X XXXC  C C        C C  CXXX X",
        "X XXX XXXX XXXXXXXX XXXX XXX X",
        "X XXX XXXXC        CXXXX XXX X",
        "XC   C    CXXXXXXXXC    C   CX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};
    public:
        void planoMapa();
        void imprimirMapa();
};

void Mapa::planoMapa(){
    //aca dibujo los limites del mapa, en este caso son las 'X' de la matriz
    for(int fil=0; fil<MAXFILAS; fil++){
        for(int col=0; col<MAXCOL; col++){
            if(mapa[fil][col] == 'X'){
                draw_sprite(buffer, bloque, col*32, fil*32);
            }
            if(mapa[fil][col] == ' ' || mapa[fil][col] == 'C'){
                draw_sprite(buffer, comida, col*32, fil*32);
            }
        }
    }
}

void Mapa::imprimirMapa(){
    //
    blit(buffer,screen,0,0,0,0,1200,640);
}
#endif // MAPA_H_INCLUDED
