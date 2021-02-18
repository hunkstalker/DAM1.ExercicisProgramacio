#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 30
#define FICADENA '\0'

bool esLletra(char caracter);

int main()
{

    char frase[MAXCADENA]={"  Bon dia   Eduard  "};

    printf("\nLa cadena te %d paraules.",comptaParaules(frase,MAXCADENA));


    return 0;
}


///Funció que compta les paraules de un vector diferenciants els que no són lletres de les lletres

int comptaParaules(char frase[],int qttMax){

    int i=0,qttParaules=0;

    while(frase[i]!=FICADENA && i<qttMax){

        passaNoLletres(frase,&i,qttMax);

        //Només entrarà en cas que frase[i] sigui una lletra, si el vector està buit no sumarà res

        if(esLletra(frase[i])){

            qttParaules++;

            passaLletres(frase,&i,qttMax);

        }

    }

    return qttParaules;
}

///Funció que col·loca posició passat els valors que no són lletres

void passaNoLletres(char frase[],int *i,int qttMax){

    while(!esLletra(frase[*i]) && *i<qttMax && frase[*i]!=FICADENA){(*i)++;}
}

///Funció que col·loca posició passat els valors que no són lletres

void passaLletres(char frase[],int *i,int qttMax){

    while(esLletra(frase[*i]) && *i<qttMax && frase[*i]!=FICADENA){(*i)++;}
}

///Controla si el caràcter passat és lletra o no
bool esLletra(char caracter){
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";
    bool lletra=false;
    int i=0;

        while (lletres[i]!=FICADENA && !lletra)
    {
        if (lletres[i]==caracter) lletra=true;
        else i++;
    }

    return lletra;
}
