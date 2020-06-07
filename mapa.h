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
        "XC   C CXC          CXC C   CX",
        "X XXX X X XXXXXXXXXX X X XXX X",
        "X XC CX X XC      CX X XC CX X",
        "X X XXX X X XXXXXX X X XXX X X",
        "XC   C C C C      C C C C C CX",
        "X XXX X XXXXXXXXXXXXXX X XXX X",
        "X XXX XC  CXXXXXXXXC  CX XXX X",
        "X XXX XXXXC        CXXXX XXX X",
        "PC   C  CX XXXNNXXX XC  C   CP",
        "X XXXXXX X XXFFFFXX X XXXXXX X",
        "XC    CX X XXFFFFXX X XC    CX",
        "X XXXX X X XXXXXXXX X X XXXX X",
        "XC C CCXC C        C CXCC   CX",
        "XXX X XX XXXXXXXXXXXX XX X XXX",
        "XC CXC  C C        C C  CXC CX",
        "X XXX XXXX XXXXXXXX XXXX XXX X",
        "X XXX XXXXC        CXXXX XXX X",
        "XC   C    CXXXXXXXXC    C   CX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};
    public:
        void planoMapa();
        void imprimirMapa();
        bool bordeMapa();
        void portalMapa();
};

void Mapa::planoMapa(){
    //aca dibujo los limites del mapa, en este caso son las 'X' de la matriz
    for(int fil=0; fil<MAXFILAS; fil++){
        for(int col=0; col<MAXCOL; col++){
            if(mapa[fil][col] == 'X'){
                draw_sprite(buffer, bloque, col*TAM, fil*TAM);
            }
            if(mapa[fil][col] == ' ' || mapa[fil][col] == 'C'){
                draw_sprite(buffer, comida, col*TAM, fil*TAM);
            }if ((py/TAM == fil) && (px/TAM == col)) {mapa[fil][col] = 'K';}
        }
    }
}

void Mapa::imprimirMapa(){
    //
    blit(buffer,screen,0,0,0,0,1200,640);
}

bool Mapa::bordeMapa(){
    switch(dir)
{
    case 0:if ((mapa[py/TAM][(px+TAM)/TAM]!='X') && (mapa[py/TAM][(px+TAM)/TAM]!='N'))
            return true; else return false;break;
    case 1:if ((mapa[(py-TAM)/TAM][px/TAM]!='X') && (mapa[(py-TAM)/TAM][px/TAM]!='N'))
            return true; else return false;break;
    case 2:if ((mapa[py/TAM][(px-TAM)/TAM]!='X') && (mapa[py/TAM][(px-TAM)/TAM]!='N'))
            return true; else return false;break;
    case 3:if ((mapa[(py+TAM)/TAM][px/TAM]!='X') && (mapa[(py+TAM)/TAM][px/TAM]!='N'))
            return true; else return false;break;
    default :return true; break;
        }
}
void Mapa::portalMapa(){

if (px<0)px=930;
        else if (px>930) px=0;
}


#endif // MAPA_H_INCLUDED
