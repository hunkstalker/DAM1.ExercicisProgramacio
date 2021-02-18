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


///Funci� que compta les paraules de un vector diferenciants els que no s�n lletres de les lletres

int comptaParaules(char frase[],int qttMax){

    int i=0,qttParaules=0;

    while(frase[i]!=FICADENA && i<qttMax){

        passaNoLletres(frase,&i,qttMax);

        //Nom�s entrar� en cas que frase[i] sigui una lletra, si el vector est� buit no sumar� res

        if(esLletra(frase[i])){

            qttParaules++;

            passaLletres(frase,&i,qttMax);

        }

    }

    return qttParaules;
}

///Funci� que col�loca posici� passat els valors que no s�n lletres

void passaNoLletres(char frase[],int *i,int qttMax){

    while(!esLletra(frase[*i]) && *i<qttMax && frase[*i]!=FICADENA){(*i)++;}
}

///Funci� que col�loca posici� passat els valors que no s�n lletres

void passaLletres(char frase[],int *i,int qttMax){

    while(esLletra(frase[*i]) && *i<qttMax && frase[*i]!=FICADENA){(*i)++;}
}

///Controla si el car�cter passat �s lletra o no
bool esLletra(char caracter){
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ������������abcdefghijklmnopqrstuvwxyz������������";
    bool lletra=false;
    int i=0;

        while (lletres[i]!=FICADENA && !lletra)
    {
        if (lletres[i]==caracter) lletra=true;
        else i++;
    }

    return lletra;
}
