#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED


class Puntuacion{
    private:
        int nombre[4]={0};
        int punt;
    public:
        Puntuacion();
        bool guardarEnArchivo();
        bool leerDeArchivo(int);
        bool leerDeArchivo();
        bool crearPuntaje();
        void cargarPuntaje(int,int*);
        void spritear();
        int getName(){return *nombre;}
        int getScore(){return punt;}
        int setScore();
        void ordenarScores();
        void maxPunt(int);
        void ordenaryGuardar();
        void ordenarNombres(int);
        int copiarNombre(int);
        void cargarNewscore(int);
        void solordenarScores();
};

bool Puntuacion::guardarEnArchivo(){
 //guarda el max score en disco;
            bool escribio; //si escribio correctamente, devuelve true;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"rb+");
            if(p == NULL){
                allegro_message("No se pudo abrir el archivo MAX SCORE para guardar la puntuación.");
                return false;
            }
            Puntuacion * v;
            v=(Puntuacion *) malloc(4 * sizeof(Puntuacion));
                if(v==NULL) { free(v); return false;}
            for(int y=0;y<4;y++){
                for(int x=0;x<4;x++){
                    v[y].nombre[x]=mat_nom[y][x];} // for matriz
                        v[y].punt=vec_punt[y];} // for vector
            fseek(p,0,SEEK_SET);
            escribio = fwrite(&v[0],sizeof(Puntuacion),4,p);
            fclose(p);
            return escribio;
        }


 bool Puntuacion::leerDeArchivo(){
            //trae la info contenida en el archivo y la carga en el objeto;
            bool leyo;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"rb");
            if(p == NULL){
                allegro_message("No se pudo abir el archivo de MAX SCORE para leerlo.");
                return false;
            }
            int x=0;
            fseek(p,0,SEEK_SET);

            while(fread(this,sizeof(Puntuacion),1,p)==1){
                    vec_punt[x]=this->punt;
                    for (int y=0;y<4;y++){
                        mat_nom[x][y]=this->nombre[y];
                }
                x++;
            }

        fclose(p);
        return true;
 }

Puntuacion::Puntuacion(){
    punt=0;
    nombre[0]=0;
    nombre[1]=0;
    nombre[2]=0;
    nombre[3]=0;
}

bool Puntuacion::crearPuntaje(){
            bool escribio; //si escribio correctamente, devuelve true;
            FILE *p = fopen(ARCHIVO_PUNTAJE,"ab");
            if(p == NULL){
                allegro_message("No se pudo abrir el archivo MAX SCORE para guardar la puntuación.");
                return false;
            }
            escribio = fwrite(this,sizeof(Puntuacion),1,p);
            fclose(p);
            return escribio;
}


void Puntuacion::spritear(){
    clear(buffer);

    while (!key[KEY_ESC]){
    for(int x=0;x<4;x++){
    punt=vec_punt[x];

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

        blit(letras,let1,mat_nom[x][0]*TAM,0,0,0,TAM,TAM);
        blit(letras,let2,mat_nom[x][1]*TAM,0,0,0,TAM,TAM);
        blit(letras,let3,mat_nom[x][2]*TAM,0,0,0,TAM,TAM);
        blit(letras,let4,mat_nom[x][3]*TAM,0,0,0,TAM,TAM);


        //imprimimos el num descompuesto
        draw_sprite(scores,let1,4*TAM,TAM*(x+1)*4);
        draw_sprite(scores,let2,5*TAM,TAM*(x+1)*4);
        draw_sprite(scores,let3,6*TAM,TAM*(x+1)*4);
        draw_sprite(scores,let4,7*TAM,TAM*(x+1)*4);

        draw_sprite(scores,milesima,29*TAM,TAM*(x+1)*4);
        draw_sprite(scores,centena,30*TAM,TAM*(x+1)*4);
        draw_sprite(scores,decena,31*TAM,TAM*(x+1)*4);
        draw_sprite(scores,unidad,32*TAM,TAM*(x+1)*4);
        blit(numeros,unidad,(x+1)*TAM,0,0,0,TAM,TAM);

        draw_sprite(scores,unidad,1*TAM,TAM*(x+1)*4);
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
            ordenarNombres(y);
        }
    }
   }
   spritear();
}

void Puntuacion::solordenarScores(){

    int aux;

   for(int x=0;x<4;x++){
    for(int y=0;y<3;y++){
        if(vec_punt[y]<vec_punt[y+1]){
            aux=vec_punt[y];
            vec_punt[y]=vec_punt[y+1];
            vec_punt[y+1]=aux;
            ordenarNombres(y);
        }
    }
   }
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

void Puntuacion::ordenarNombres(int t){
        int aux[4];
    for (int x=0;x<4;x++){
            if(mat_nom[t][x]>26) mat_nom[t][x]=26;
            if(mat_nom[t][x]<0) mat_nom[t][x]=0;
        aux[x]=mat_nom[t][x];
        mat_nom[t][x]=mat_nom[t+1][x];
        mat_nom[t+1][x]=aux[x];
    }
}

void Puntuacion::cargarNewscore(int p){
    bool continuar=true;
    punt=p;

         int nunidad,ndecena,ncentena,nmilesima;
        //decomponemos el num
        if (p>=9999) p=9999;
        nmilesima=p/1000;
        p=p%1000;
        ncentena=p/100;
        p=p%100;
        ndecena=p/10;
        p=p%10;
        nunidad=p/1;
    for (int x=0;x<4;x++){
    while(!key[KEY_ENTER]){
        //usamos la descomposicion para buscar el num
        blit(numeros,unidad,nunidad*TAM,0,0,0,TAM,TAM);
        blit(numeros,decena,ndecena*TAM,0,0,0,TAM,TAM);
        blit(numeros,centena,ncentena*TAM,0,0,0,TAM,TAM);
        blit(numeros,milesima,nmilesima*TAM,0,0,0,TAM,TAM);
        blit(letras,let1,nombre[0]*TAM,0,0,0,TAM,TAM);
        blit(letras,let2,nombre[1]*TAM,0,0,0,TAM,TAM);
        blit(letras,let3,nombre[2]*TAM,0,0,0,TAM,TAM);
        blit(letras,let4,nombre[3]*TAM,0,0,0,TAM,TAM);

        draw_sprite(buffer,newscores,0,0);
        draw_sprite(buffer,milesima,20*TAM,10*TAM);
        draw_sprite(buffer,centena,21*TAM,10*TAM);
        draw_sprite(buffer,decena,22*TAM,10*TAM);
        draw_sprite(buffer,unidad,23*TAM,10*TAM);
        draw_sprite(buffer,let1,10*TAM,TAM*10);
        draw_sprite(buffer,let2,11*TAM,TAM*10);
        draw_sprite(buffer,let3,12*TAM,TAM*10);
        draw_sprite(buffer,let4,13*TAM,TAM*10);

        blit(buffer,screen,0,0,0,0,1200,640);

        if(key[KEY_UP] || key[KEY_W]) {clear(buffer);if(nombre[x]<=25){nombre[x]++;rest(50);}}
        if(key[KEY_DOWN] || key[KEY_S]) {clear(buffer);if(nombre[x]>=0){nombre[x]--;rest(50);}}
        }
        rest(1000);
    }
    vec_punt[3]=punt;
        for (int y=0;y<4;y++){
            mat_nom[3][y]=nombre[y];
                }
    guardarEnArchivo();
}






#endif // PUNTAJE_H_INCLUDED
