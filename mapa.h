#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

class Mapa{
    protected:
        /*X = ladrillos
        P = porta
        C = comida GRANDE
        F = donde aparecen los fantasmas
        N = espacios entre los bloques
        */
    char mapaP[MAXFILAS][MAXCOL] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XC      X           X      CX",
        "X XXX X X XXXXXXXXX X X XXX X",
        "X X   X X X       X X X   X X",
        "X X XXX X X XXXXX X X XXX X X",
        "X                           X",
        "XXXXX X XXXXXXXXXXXXX X XXXXX",
        "XNNNX X    XXXXXXX    X XNNNX",
        "XXXXX XXXX.........XXXX XXXXX",
        "P....    X.XXXNXXX.X    ....P",
        "XXXXX XX X.XFFFFFX.X XX XXXXX",
        "XXXXX XX X.XFFFFFX.X XX XXXXX",
        "X     XX X.XXXXXXX.X XX     X",
        "X XXX XX ........... XX XXX X",
        "X   X XX XXXXXXXXXXX XX X   X",
        "XXX X                   X XXX",
        "X   X XXXX XXXXXXX XXXX X   X",
        "X XXX XXXX    .    XXXX XXX X",
        "XC         XXXXXXX         CX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",};

    char mapaF[MAXFILAS][MAXCOL] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "XJ   J JXJ         JXJ J   JX",
        "X XXX X X XXXXXXXXX X X XXX X",
        "X XJ JX X XJ     JX X XJ JX X",
        "X X XXX X X XXXXX X X XXX X X",
        "XJ J J   J J     J J   J J JX",
        "XXXXX X XXXXXXXXXXXXX X XXXXX",
        "XNNNX XJ  JXXXXXXXJ  JX XNNNX",
        "XXXXX XXXXJ   J   JXXXX XXXXX",
        "P    J  JX XXXNXXX XJ  J    P",
        "XXXXX XX X XhhYHHX X XX XXXXX",
        "XXXXX XX X XNNNNNX X XX XXXXX",
        "XJ   JXX X XXXXXXX X XXJ   JX",
        "X XXX XXJ J       J JXX XX  X",
        "XJ JX XX XXXXXXXXXXX XX XJ JX",
        "XXX XJ  J J       J J  JX XXX",
        "XJ JX XXXX XXXXXXX XXXX XJ JX",
        "X XXX XXXXJ   .   JXXXX XXX X",
        "XJ   J    JXXXXXXXJ    J   JX",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};
    public:
        void planoMapa();
        void imprimirMapa();
        bool bordeMapa1 (int,int,int);
        bool bordeMapa2();
        bool hayComida();
        bool comidaGrande(int,int);

        //estos get son para devolver la posición del pacman + 1;
//        char getbordeIzq(int,int);
//        char getbordeDer(int,int);
//        char getbordeArri(int,int);
//        char getbordeAba(int,int);
};

//char Mapa::getbordeIzq(int px, int py){
//    return mapaP[py/TAM][(px/TAM)-1];
//}
//
//char Mapa::getbordeDer(int px, int py){
//    return mapaP[py/TAM][(px/TAM)+1];
//}
//
//char Mapa::getbordeArri(int px, int py){
//    return mapaP[(py/TAM)-1][px/TAM];
//}
//
//char Mapa::getbordeAba(int px, int py){
//    return mapaP[(py/TAM)+1][px/TAM];
//}

void Mapa::planoMapa(){
    //aca dibujo los limites del mapa, en este caso son las 'X' de la matriz
    for(int fil=0; fil<MAXFILAS; fil++){
        for(int col=0; col<MAXCOL; col++){
            if(mapaP[fil][col] == 'X'){
                //dibuja los bloques del mapa;
                draw_sprite(buffer, bloque, col*TAM, fil*TAM);
            }
            if(mapaP[fil][col] == ' '){
                //dibuja la comida
                draw_sprite(buffer, comida, col*TAM, fil*TAM);

            }
            if(mapaP[fil][col] == 'C'){
                draw_sprite(buffer,comida_grande,col*TAM,fil*TAM);
            }
//            if ((posicion_pacman_y / TAM == fil) && (posicion_pacman_x/TAM == col) && (mapaP[fil][col] != 'P')
//                && ((mapaP[fil][col] == ' ') ||(mapaP[posicion_pacman_y/TAM][posicion_pacman_x/TAM] == 'C'))){
//                el "!= 'P' es para que no ponga un punto en esa posición y no borre los portales al pasar por ahi el pacman
//                si las coordenadas del pacman coincide donde está la comida, pongo un punto para que las borre;
//                if(mapaP[fil][col] == 'C'){
//                    play_sample(big_food,70,100,1000,0);
//                }
//                else if(mapaP[fil][col] == ' ') play_sample(bolitas,70,70,1000,0);
//                else{}
//
//
//                mapaP[fil][col] = '.'; puntaje++;
//            }
            if(mapaP[fil][col] == 'P'){
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


bool Mapa::bordeMapa1(int aux, int posicion_pacman_y, int posicion_pacman_x){
    switch(aux){
    case 0:
        if ((mapaP[posicion_pacman_y / TAM][(posicion_pacman_x+TAM) / TAM]!='X') &&
            (mapaP[posicion_pacman_y / TAM][(posicion_pacman_x+TAM) / TAM]!='N'))return true;
            else return false; break;
    case 1:
        if ((mapaP[(posicion_pacman_y - TAM) / TAM][posicion_pacman_x/TAM]!='X') &&
            (mapaP[(posicion_pacman_y - TAM) / TAM][posicion_pacman_x/TAM]!='N'))return true;
            else return false; break;
    case 2:
        if ((mapaP[posicion_pacman_y / TAM][(posicion_pacman_x-TAM) / TAM]!='X') &&
            (mapaP[posicion_pacman_y / TAM][(posicion_pacman_x-TAM) / TAM]!='N'))return true;
            else return false; break;
    case 3:
        if ((mapaP[(posicion_pacman_y + TAM) / TAM][posicion_pacman_x/TAM]!='X') &&
            (mapaP[(posicion_pacman_y + TAM) / TAM][posicion_pacman_x/TAM]!='N'))return true;
            else return false; break;
    default: return true; break;
        }
}




#endif // MAPA_H_INCLUDED
