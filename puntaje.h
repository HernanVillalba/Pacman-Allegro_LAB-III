#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED

class Puntuacion{
    private:
        const char *ARCHIVO_PUNTAJE;
        char nombre[4];
        int score;
    public:
        Puntuacion(){
            ARCHIVO_PUNTAJE = "maxscores.dat";
        }
        bool guardarEnArchivo(){
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
        bool leerDeArchivo(int pos){
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

};

#endif // PUNTAJE_H_INCLUDED
