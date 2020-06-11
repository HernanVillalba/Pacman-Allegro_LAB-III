#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

class Mapa{
    private:
        /*X = ladrillos
        P = porta
        C = esquinas
        F = donde aparecen los fantasmas
        N = espacios entre los bloques
        */
        char mapa[MAXFILAS][MAXCOL] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "X       X            X       X",
        "X XXX X X XXXXXXXXXX X X XXX X",
        "X X   X X X        X X X   X X",
        "X X XXX X X XXXXXX X X XXX X X",
        "X                            X",
        "XXXXX X XXXXXXXXXXXXXX X XXXXX",
        "XNNNX X    XXXXXXXX    X XNNNX",
        "XXXXX XXXX          XXXX XXXXX",
        "P        X XXXNNXXX X        P",
        "XXXXX XX X XFFFFFFX X XX XXXXX",
        "XNNNX XX X XFFFFFFX X XX XNNNX",
        "XXXXX XX X XXXXXXXX X XX XXXXX",
        "X     XX              XX     X",
        "X XXX XX XXXXXXXXXXXX XX XXX X",
        "X XNX                    XNX X",
        "X XNX XXXX XXXXXXXX XXXX XNX X",
        "X XXX XXXX          XXXX XXX X",
        "X          XXXXXXXX          X",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};
    public:
        void planoMapa();
        void imprimirMapa();
        bool bordeMapa1();
        bool bordeMapa2();
        void portalMapa();
        bool hayComida();
};

void Mapa::planoMapa(){
    //aca dibujo los limites del mapa, en este caso son las 'X' de la matriz
    for(int fil=0; fil<MAXFILAS; fil++){
        for(int col=0; col<MAXCOL; col++){
            if(mapa[fil][col] == 'X'){
                //dibuja los bloques del mapa;
                draw_sprite(buffer, bloque, col*TAM, fil*TAM);
            }
            if(mapa[fil][col] == ' '){
                //dibuja la comida
                draw_sprite(buffer, comida, col*TAM, fil*TAM);
            }
            if ((py/TAM == fil) && (px/TAM == col) && (mapa[fil][col] != 'P')){
                //el "!= 'P' es para que no ponga un punto en esa posición y no borre los portales al pasar por ahi el pacman
                //si las coordenadas del pacman coincide donde está la comida, pongo un punto para que las borre;
                mapa[fil][col] = '.';
            }
            if(mapa[fil][col] == 'P'){
                //dibuja los portales
                if(fil==9 && col ==0)draw_sprite(buffer,portal_IZQ,col*TAM,fil*TAM);
                if(fil==9 && col ==29)draw_sprite(buffer,portal_DER,col*TAM,fil*TAM);
            }
        }
    }
}

void Mapa::imprimirMapa(){
    //
    blit(buffer,screen,0,0,0,0,1200,640);
}

bool Mapa::bordeMapa1(){
    switch(dir){
    case 0:
        if ((mapa[py/TAM][(px+TAM)/TAM]!='X') && (mapa[py/TAM][(px+TAM)/TAM]!='N'))return true;
            else return false; break;
    case 1:
        if ((mapa[(py-TAM)/TAM][px/TAM]!='X') && (mapa[(py-TAM)/TAM][px/TAM]!='N'))return true;
            else return false; break;
    case 2:
        if ((mapa[py/TAM][(px-TAM)/TAM]!='X') && (mapa[py/TAM][(px-TAM)/TAM]!='N'))return true;
            else return false; break;
    case 3:
        if ((mapa[(py+TAM)/TAM][px/TAM]!='X') && (mapa[(py+TAM)/TAM][px/TAM]!='N'))return true;
            else return false; break;
    default: return true; break;
        }
}


void Mapa::portalMapa(){
    if (px<0)px=930;
    else if (px>930) px=0;
}

bool Mapa::hayComida(){
    for(int fil=0; fil<MAXFILAS; fil++){
        for(int col=0; col<MAXCOL; col++){
            if(mapa[fil][col] == ' '){
                return true;
            }
        }
    }
    return false;
}

#endif // MAPA_H_INCLUDED
