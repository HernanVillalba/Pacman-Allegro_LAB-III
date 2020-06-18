#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

class Mapa{
    private:
        /*X = ladrillos
        P = porta
        C = comida GRANDE
        F = donde aparecen los fantasmas
        N = espacios entre los bloques
        */
        char mapa[MAXFILAS][MAXCOL] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XC      X           X      CX",
        "X XXX X X XXXXXXXXX X X XXX X",
        "X X   X X X       X X X   X X",
        "X X XXX X X XXXXX X X XXX X X",
        "X                           X",
        "XXXXX X XXXXXXXXXXXXX X XXXXX",
        "XNNNX X    XXXXXXX    X XNNNX",
        "XXXXX XXXX.........XXXX XXXXX",
        "P        X.XXXNXXX.X        P",
        "XXXXX XX X.XFFFFFX.X XX XXXXX",
        "XNNNX XX X.XFFFFFX.X XX XNNNX",
        "XXXXX XX X.XXXXXXX.X XX XXXXX",
        "X     XX ........... XX     X",
        "X XXX XX XXXXXXXXXXX XX XXX X",
        "X XNX                   XNX X",
        "X XNX XXXX XXXXXXX XXXX XNX X",
        "X XXX XXXX    .    XXXX XXX X",
        "XC         XXXXXXX         CX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",};
    public:
        void planoMapa();
        void imprimirMapa();
        bool bordeMapa1();
        bool bordeMapa2();
        void portalMapa();
        bool hayComida();
        bool comidaGrande();
        char getbordeIzq(int,int);
        char getbordeDer(int,int);
        char getbordeArri(int,int);
        char getbordeAba(int,int);
};

char Mapa::getbordeIzq(int px, int py){
    return mapa[py/TAM][(px/TAM)-1];
}

char Mapa::getbordeDer(int px, int py){
    return mapa[py/TAM][(px/TAM)+1];
}

char Mapa::getbordeArri(int px, int py){
    return mapa[(py/TAM)-1][px/TAM];
}

char Mapa::getbordeAba(int px, int py){
    return mapa[(py/TAM)+1][px];
}

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
            if(mapa[fil][col] == 'C'){
                draw_sprite(buffer,comida_grande,col*TAM,fil*TAM);
            }
            if ((posicion_pacman_y / TAM == fil) && (posicion_pacman_x/TAM == col) && (mapa[fil][col] != 'P')
                && ((mapa[fil][col] == ' ') ||(mapa[posicion_pacman_y/TAM][posicion_pacman_x/TAM] == 'C'))){
                //el "!= 'P' es para que no ponga un punto en esa posición y no borre los portales al pasar por ahi el pacman
                //si las coordenadas del pacman coincide donde está la comida, pongo un punto para que las borre;
                if(mapa[fil][col] == 'C'){
                    play_sample(big_food,150,100,1000,0);
                }
                else play_sample(bolitas,150,70,1000,0);

                mapa[fil][col] = '.'; puntaje++;
            }
            if(mapa[fil][col] == 'P'){
                //dibuja los portales
                if(fil==9 && col ==0)draw_sprite(buffer,portal_IZQ,col*TAM,fil*TAM);
                if(fil==9 && col ==28)draw_sprite(buffer,portal_DER,col*TAM,fil*TAM);
            }
        }
    }
}

void Mapa::imprimirMapa(){
    //
    blit(buffer,screen,0,0,0,0,960,640);
}

bool Mapa::comidaGrande(){
if(mapa[posicion_pacman_y / TAM][posicion_pacman_x/TAM] == 'C') {puntaje+=24;return true;}
else return false;

}

bool Mapa::bordeMapa1(){
    switch(dir){
    case 0:
        if ((mapa[posicion_pacman_y / TAM][(posicion_pacman_x+TAM) / TAM]!='X') &&
            (mapa[posicion_pacman_y / TAM][(posicion_pacman_x+TAM) / TAM]!='N'))return true;
            else return false; break;
    case 1:
        if ((mapa[(posicion_pacman_y - TAM) / TAM][posicion_pacman_x/TAM]!='X') &&
            (mapa[(posicion_pacman_y - TAM) / TAM][posicion_pacman_x/TAM]!='N'))return true;
            else return false; break;
    case 2:
        if ((mapa[posicion_pacman_y / TAM][(posicion_pacman_x-TAM) / TAM]!='X') &&
            (mapa[posicion_pacman_y / TAM][(posicion_pacman_x-TAM) / TAM]!='N'))return true;
            else return false; break;
    case 3:
        if ((mapa[(posicion_pacman_y + TAM) / TAM][posicion_pacman_x/TAM]!='X') &&
            (mapa[(posicion_pacman_y + TAM) / TAM][posicion_pacman_x/TAM]!='N'))return true;
            else return false; break;
    default: return true; break;
        }
}


void Mapa::portalMapa(){
    if (posicion_pacman_x<0)posicion_pacman_x=898;
    else if (posicion_pacman_x>=898) posicion_pacman_x=0;
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
