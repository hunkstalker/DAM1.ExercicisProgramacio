#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 10
#define FICADENA '\0'

bool esLletra(char caracter);
bool esVocal(char caracter);

///Exercici que retorna si un caracter es una lletra o no

int main()
{
    char cadena[MAXCADENA]="Hola.";

    controlarCadaCaracter(cadena,MAXCADENA);
    printf("\n");
    controlarCadaVocal(cadena,MAXCADENA);

    return 0;
}

///Primer es controlen els caràcters i dins del while la funcio de si és lletra
void controlarCadaCaracter(char cadena[MAXCADENA], int total){

    int i=0;

    while(cadena[i]!=FICADENA && i<total){

            printf("\n%c es %d",cadena[i],esLletra(cadena[i]));
            i++;
    }

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


///Primer es controlen els caràcters i dins del while la funcio de si és vocal
void controlarCadaVocal(char cadena[MAXCADENA], int total){

    int i=0;

    while(cadena[i]!=FICADENA && i<total){

            printf("\n%c es %d",cadena[i],esVocal(cadena[i]));
            i++;
    }

}

///Controla si el caràcter passat és vocal o no
bool esVocal(char caracter){
    char vocals[] = "AEIOUÀÁÈÉÍÏÒÓÚÜaeiouàáèéíïòóúü";
    bool lletra=false;
    int i=0;

        while (vocals[i]!=FICADENA && !lletra)
    {
        if (vocals[i]==caracter) lletra=true;
        else i++;
    }

    return lletra;
}

