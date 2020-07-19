#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED


class Puntuacion{
    private:
        int nombre[4];
        int punt;
    public:
        Puntuacion(int);
        Puntuacion();
        bool guardarEnArchivo(int*, int);
        bool leerDeArchivo(int);
        bool leerDeArchivo();
        bool crearPuntaje();
        void cargarPuntaje(int,int*);
        void spritear(int*, int c[][4]);
        int getName(){return *nombre;}
        int getScore(){return punt;}
        int setScore();
        void ordenarScores();
        void maxPunt(int);
        void ordenaryGuardar();
};

bool Puntuacion::guardarEnArchivo(int *v, int x){
 //guarda el max score en disco;
            bool escribio; //si escribio correctamente, devuelve true;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"rb+");
            if(p == NULL){
                allegro_message("No se pudo abrir el archivo MAX SCORE para guardar la puntuación.");
                exit(1);
                return false;
            }
            fseek(p,x*sizeof(Puntuacion),SEEK_SET);
            escribio = fwrite(&v[x],sizeof(Puntuacion),1,p);
            fclose(p);
            return escribio;
            ////////////////////////////////FALTA AGREGAR UN IF QUE PREGUNTE SI ES MAX SCORE PARA GUARDARLO O NO;
        }

 bool Puntuacion::leerDeArchivo(){
            //trae la info contenida en el archivo y la carga en el objeto;
            bool leyo;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"rb");
            if(p == NULL){
                allegro_message("No se pudo abir el archivo de MAX SCORE para leerlo.");
                exit(1);
                return false;
            }
            for(int x=0;x<4;x++){
            fseek(p,x *sizeof(Puntuacion),0);
            if(fread(this,sizeof(Puntuacion),1,p)==1){
                    vec_punt[x]=punt;
                    for (int y=0;y<4;y++){
                        mat_nom[x][y]=nombre[y];
                    }}
            fclose(p);
            return true;
        }
 }

Puntuacion::Puntuacion(int p){
    punt=p;
    for(int x=0;x<4;x++){
        nombre[x]='s';
    }
}
Puntuacion::Puntuacion(){
    punt=1600;
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
void Puntuacion::cargarPuntaje(int p, int*n){
        punt=p;
        for(int x=0;x<4;x++){
        nombre[x]=n[x];
    }
}

void Puntuacion::spritear(int *v, int c[][4]){
    clear(buffer);

    while (!key[KEY_ESC]){
    for(int x=0;x<4;x++){
    punt=v[x];
    int nunidad,ndecena,ncentena,nmilesima;
        //decomponemos el num
        if (punt>=9999) punt=9999;
        nmilesima=punt/1000;
        punt=punt%1000;
        ncentena=punt/100;
        punt=punt%100;
        ndecena=punt/10;
        punt=punt%10;
        nunidad=punt/1;

        //usamos la descomposicion para buscar el num
        blit(numeros,unidad,nunidad*TAM,0,0,0,TAM,TAM);
        blit(numeros,decena,ndecena*TAM,0,0,0,TAM,TAM);
        blit(numeros,centena,ncentena*TAM,0,0,0,TAM,TAM);
        blit(numeros,milesima,nmilesima*TAM,0,0,0,TAM,TAM);

        blit(letras,let1,9*TAM,0,0,0,TAM,TAM);
        blit(letras,let2,1*TAM,0,0,0,TAM,TAM);
        blit(letras,let3,7*TAM,0,0,0,TAM,TAM);
        blit(letras,let4,3*TAM,0,0,0,TAM,TAM);


        //imprimimos el num descompuesto
        draw_sprite(scores,let1,4*TAM,TAM*(x+1)*4);
        draw_sprite(scores,let2,5*TAM,TAM*(x+1)*4);
        draw_sprite(scores,let3,6*TAM,TAM*(x+1)*4);
        draw_sprite(scores,let4,7*TAM,TAM*(x+1)*4);

        draw_sprite(scores,milesima,22*TAM,TAM*(x+1)*4);
        draw_sprite(scores,centena,23*TAM,TAM*(x+1)*4);
        draw_sprite(scores,decena,24*TAM,TAM*(x+1)*4);
        draw_sprite(scores,unidad,25*TAM,TAM*(x+1)*4);
        blit(scores,buffer,0,0,0,0,1200,640);
        blit(buffer,screen,0,0,0,0,1200,640);
}
}
}

void Puntuacion::ordenarScores(){

    int aux;

   for(int x=0;x<4;x++){
    for(int y=0;y<3;y++){
        if(vec_punt[y]<vec_punt[y+1]){
            aux=vec_punt[y];
            vec_punt[y]=vec_punt[y+1];
            vec_punt[y+1]=aux;
        }
    }
   }
    spritear(vec_punt,mat_nom);
}

void Puntuacion::maxPunt(int puntero){
int nunidad,ndecena,ncentena,nmilesima;
        //decomponemos el num
        if (puntero>=9999) puntero=9999;
        nmilesima=puntero/1000;
        puntero=puntero%1000;
        ncentena=puntero/100;
        puntero=puntero%100;
        ndecena=puntero/10;
        puntero=puntero%10;
        nunidad=puntero/1;

        //usamos la descomposicion para buscar el num
        blit(numeros,unidad,nunidad*TAM,0,0,0,TAM,TAM);
        blit(numeros,decena,ndecena*TAM,0,0,0,TAM,TAM);
        blit(numeros,centena,ncentena*TAM,0,0,0,TAM,TAM);
        blit(numeros,milesima,nmilesima*TAM,0,0,0,TAM,TAM);

        //imprimimos el num descompuesto

        draw_sprite(buffer,maxscore,30*TAM,1*TAM);
        draw_sprite(buffer,milesima,31*TAM,3*TAM);
        draw_sprite(buffer,centena,32*TAM,3*TAM);
        draw_sprite(buffer,decena,33*TAM,3*TAM);
        draw_sprite(buffer,unidad,34*TAM,3*TAM);
        blit(buffer,screen,0,0,0,0,1200,640);

}








#endif // PUNTAJE_H_INCLUDED
