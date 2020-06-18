#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

class Pacman{
    private:
        int vidas;
        int pos_x;
        int pos_y;

    public:
        Pacman();
        void imprimirPacmanComiendo();
        void imprimirPacmanQuieto();
        int getVidas();
        void restarVida();
        int getPosXPac();
        int getPosYPac();
};

Pacman::Pacman(){
    vidas = 3;
    pos_x = TAM*14;
    pos_y = TAM*17;
}

int Pacman::getPosXPac(){
    return pos_x;
}

int Pacman::getPosYPac(){
    return pos_y;
}

void Pacman::imprimirPacmanComiendo(){
    blit(pacBMP,pacman,dir*TAM,0,0,0,TAM,TAM);
    draw_sprite(buffer,pacman,posicion_pacman_x,posicion_pacman_y);
}
void Pacman::imprimirPacmanQuieto(){
    blit(pacBMP,pacman,4*TAM,0,0,0,TAM,TAM);
    draw_sprite(buffer,pacman,posicion_pacman_x,posicion_pacman_y);
}

int Pacman::getVidas(){
    return vidas;
}

void Pacman::restarVida(){
    vidas--;
}
#endif // PACMAN_H_INCLUDED
