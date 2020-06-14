#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

class Pacman{
    private:
        //int vidas;

    public:
        Pacman(int );
        void imprimirPacmanComiendo();
        void imprimirPacmanQuieto();
       // int getVidas();
      //  void restarVida();
};

Pacman::Pacman(int aux){
    vidas = aux;
}

void Pacman::imprimirPacmanComiendo(){
    blit(pacBMP,pacman,dir*TAM,0,0,0,TAM,TAM);
    draw_sprite(buffer,pacman,px,py);
}
void Pacman::imprimirPacmanQuieto(){
    blit(pacBMP,pacman,4*TAM,0,0,0,TAM,TAM);
    draw_sprite(buffer,pacman,px,py);
}

//int Pacman::getVidas(){
//    return vidas;
//}
//void Pacman::restarVida(){
//    vidas--;
//}
#endif // PACMAN_H_INCLUDED
