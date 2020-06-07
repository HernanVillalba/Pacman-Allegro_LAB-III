#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

class Mapa{
    private:
        char mapa[MAXFILAS][MAXCOL] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "X          X      X          X",
        "X XXX XXXX X XXXX X XXXX XXX X",
        "X XXX XXXX X      X XXXX XXX X",
        "X                            X",
        "X XXX XX XXXXXXXXXXXX XX XXX X",
        "X     XX     XXXX     XX     X",
        "X XXX XXXXXX XXXX XXXXXX XXX X",
        "X XXX XX              XX XXX X",
        "      XX XXXXX  XXXXX XX      ",
        "X XXX XX X          X XX XXX X",
        "X XXX XX X          X XX XXX X",
        "X XXX XX XXXXXXXXXXXX XX XXX X",
        "X     XX              XX     X",
        "X XXX XX XXXXXXXXXXXX XX XXX X",
        "X XXX                    XXX X",
        "X XXX XXXX XXXXXXXX XXXX XXX X",
        "X XXX XXXX          XXXX XXX X",
        "X          XXXXXXXX          X",
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
        }
    }
}

void Mapa::imprimirMapa(){
    //
    blit(buffer,screen,0,0,0,0,1200,640);
}
#endif // MAPA_H_INCLUDED
