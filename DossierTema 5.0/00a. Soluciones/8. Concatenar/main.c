#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

//#define MAXVECTOR 6
#define MAXCADENA 50
#define FICADENA \0

/* Enunciat:

*/

int main() {
    SetConsoleTitle("Dossier Tema 5.0 Exercici 08. (Concatenar) Denis Anfruns.");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //números aleatorios.
    //srand(time(NULL));

    start();
    return 0;
}

void start() {
    char frase1[MAXCADENA]="nanonano";
    char frase2[MAXCADENA]="brikibriki";
    concatenar(frase1,frase2,MAXCADENA);
    printf("\n La cadena final es %s",frase1);

    resetPrograma();
}

void concatenar(char frase1[],char frase2[],int qttC){
    int l1=longitud(frase1,qttc),l2=longitud(frase2,qttC);

    if((l1+l2+1)<=qttC) {
        copiar(frase1,frase2,l1,l2,qttC);
    }
}

void copiar(char frase1[],char frase2[],int l1,int l2,int qttC){
    int i;
    for(i=0;i<=l2;)
}


