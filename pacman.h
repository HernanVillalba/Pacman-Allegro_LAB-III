#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

class Pacman{
    private:
        int vidas;

    public:
        Pacman();
        void imprimirPacmanComiendo();
        void imprimirPacmanQuieto();

};

Pacman::Pacman(){
    vidas = 3;
}

void Pacman::imprimirPacmanComiendo(){
    blit(pacBMP,pacman,dir*TAM,0,0,0,TAM,TAM);
    draw_sprite(buffer,pacman,px,py);
}
void Pacman::imprimirPacmanQuieto(){
    blit(pacBMP,pacman,4*TAM,0,0,0,TAM,TAM);
    draw_sprite(buffer,pacman,px,py);
}

#endif // PACMAN_H_INCLUDED
