#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED
using namespace std;
class Puntuacion{
    private:
        char nombre[4];
        int score;
    public:
        Puntuacion();
        bool guardarEnArchivo();
        bool leerDeArchivo(int);
        bool crearPuntaje();
        void cargarPuntaje(int,char*);
        void spritear();
        char *getName(){return nombre;}
        int getScore(){return score;}
};
bool Puntuacion::guardarEnArchivo(){
 //guarda el max score en disco;
            bool escribio; //si escribio correctamente, devuelve true;
            Puntuacion oPuntuacion;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"rb");
            if(p == NULL){
                allegro_message("No se pudo abrir el archivo MAX SCORE para guardar la puntuación.");
                exit(1);
                return false;
            }
            escribio = fwrite(this,sizeof(Puntuacion),1,p);
            fclose(p);
            return escribio;
            ////////////////////////////////FALTA AGREGAR UN IF QUE PREGUNTE SI ES MAX SCORE PARA GUARDARLO O NO;
        }

 bool Puntuacion::leerDeArchivo(int pos){
            //trae la info contenida en el archivo y la carga en el objeto;
            bool leyo;
            Puntuacion oPuntuacion;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"rb");
            if(p == NULL){
                allegro_message("No se pudo abir el archivo de MAX SCORE para leerlo.");
                exit(1);
                return false;
            }
            fseek(p,pos *sizeof(Puntuacion),0);
            leyo = fread(this,sizeof(Puntuacion),1,p);
            fclose(p);
            return leyo;
        }
Puntuacion::Puntuacion(){
    score=2200;
    for(int x=0;x<4;x++){
        nombre[x]='s';
    }


}


bool Puntuacion::crearPuntaje(){
            bool escribio; //si escribio correctamente, devuelve true;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"ab");
            if(p == NULL){
                allegro_message("No se pudo abrir el archivo MAX SCORE para guardar la puntuación.");
                exit(1);
                return false;
            }
            escribio = fwrite(this,sizeof(Puntuacion),1,p);
            fclose(p);
            return escribio;
}
void Puntuacion::cargarPuntaje(int p, char*n){
        score=p;
        for(int x=0;x<4;x++){
        nombre[x]=n[x];
    }
}

void Puntuacion::spritear(){
    clear(buffer);
    while (!key[KEY_ESC]){
    for(int x=0;x<4;x++){
    int nunidad,ndecena,ncentena,nmilesima;
        //decomponemos el num
        if (score>=9999) score=9999;
        nmilesima=score/1000;
        score=score%1000;
        ncentena=score/100;
        score=score%100;
        ndecena=score/10;
        score=score%10;
        nunidad=score/1;

        //usamos la descomposicion para buscar el num
        blit(numeros,unidad,nunidad*TAM,0,0,0,TAM,TAM);
        blit(numeros,decena,ndecena*TAM,0,0,0,TAM,TAM);
        blit(numeros,centena,ncentena*TAM,0,0,0,TAM,TAM);
        blit(numeros,milesima,nmilesima*TAM,0,0,0,TAM,TAM);

        //imprimimos el num descompuesto
        draw_sprite(buffer,milesima,22*TAM,TAM*(x+1)*4);
        draw_sprite(buffer,centena,23*TAM,TAM*(x+1)*4);
        draw_sprite(buffer,decena,24*TAM,TAM*(x+1)*4);
        draw_sprite(buffer,unidad,25*TAM,TAM*(x+1)*4);
        blit(buffer,screen,0,0,0,0,1200,640);



}

    }
}


#endif // PUNTAJE_H_INCLUDED
