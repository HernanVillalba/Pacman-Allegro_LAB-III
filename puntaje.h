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
        void spritear(int*);
        int getName(){return *nombre;}
        int getScore(){return punt;}
        int setScore();
        void ordenarScores();
        void maxPunt();
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

 bool Puntuacion::leerDeArchivo(int pos){
            //trae la info contenida en el archivo y la carga en el objeto;
            bool leyo;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"rb");
            if(p == NULL){
                allegro_message("No se pudo abir el archivo de MAX SCORE para leerlo.");
                exit(1);
                return false;
            }
            fseek(p,pos *sizeof(Puntuacion),0);
            leyo= fread(this,sizeof(Puntuacion),1,p);
            fclose(p);
            return leyo;
        }


Puntuacion::Puntuacion(int p){
    punt=p;
    for(int x=0;x<4;x++){
        nombre[x]='s';
    }
}
Puntuacion::Puntuacion(){
    punt=150;
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

void Puntuacion::spritear(int *v){
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

        //imprimimos el num descompuesto
        draw_sprite(buffer,milesima,22*TAM,TAM*(x+1)*4);
        draw_sprite(buffer,centena,23*TAM,TAM*(x+1)*4);
        draw_sprite(buffer,decena,24*TAM,TAM*(x+1)*4);
        draw_sprite(buffer,unidad,25*TAM,TAM*(x+1)*4);
        blit(buffer,screen,0,0,0,0,1200,640);
}
}
}

void Puntuacion::ordenarScores(){

    int v[4]={0}, aux, nm[4][4], auxn, x,y;
    for(x=0;x<4;x++){
   if(leerDeArchivo(x)){
    v[x]=punt;
   }}
   for(x=0;x<4;x++){
    for(y=0;y<3;y++){
        if(v[y]<v[y+1]){
            aux=v[y];
            v[y]=v[y+1];
            v[y+1]=aux;
        }
    }
   }

    spritear(v);
}

void Puntuacion::maxPunt(){
    leerDeArchivo(3);
int nunidad,ndecena,ncentena,nmilesima;
        //decomponemos el num
        if (this->punt>=9999) this->punt=9999;
        nmilesima=this->punt/1000;
        this->punt=this->punt%1000;
        ncentena=this->punt/100;
        this->punt=this->punt%100;
        ndecena=this->punt/10;
        this->punt=this->punt%10;
        nunidad=this->punt/1;

        //usamos la descomposicion para buscar el num
        blit(numeros,unidad,nunidad*TAM,0,0,0,TAM,TAM);
        blit(numeros,decena,ndecena*TAM,0,0,0,TAM,TAM);
        blit(numeros,centena,ncentena*TAM,0,0,0,TAM,TAM);
        blit(numeros,milesima,nmilesima*TAM,0,0,0,TAM,TAM);

        //imprimimos el num descompuesto
        draw_sprite(buffer,score,30*TAM,2*TAM);
        draw_sprite(buffer,milesima,31*TAM,3*TAM);
        draw_sprite(buffer,centena,32*TAM,3*TAM);
        draw_sprite(buffer,decena,33*TAM,3*TAM);
        draw_sprite(buffer,unidad,34*TAM,3*TAM);
        blit(buffer,screen,0,0,0,0,1200,640);

}

void Puntuacion::ordenaryGuardar(){

    int v[4]={0}, aux, nm[4][4], auxn, x,y;
    for(x=0;x<4;x++){
   if(leerDeArchivo(x)){
    v[x]=punt;
   }}
   for(x=0;x<4;x++){
    for(y=0;y<3;y++){
        if(v[y]<v[y+1]){
            aux=v[y];
            v[y]=v[y+1];
            v[y+1]=aux;
        } //if
    } //for y
   } // for x
   for (x=0;x<4;x++){
        guardarEnArchivo(v,x);

}
}








#endif // PUNTAJE_H_INCLUDED
