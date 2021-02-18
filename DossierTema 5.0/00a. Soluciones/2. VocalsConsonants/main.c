#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

//#define MAXVECTOR 6
#define MAXCADENA 50

/* Enunciat:
    Separar en vectores vocales y consonnates la frase "hola.pep"
*/

void separarVocalsConsonants(char cad[],char voc[],char cons[],int qttC,int *maxVocal,int *maxCons);

int main() {
    SetConsoleTitle("Vocales & Consonantes");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //números aleatorios.
    srand(time(NULL));

    start();
    return 0;
}

void start() {
    char frase[MAXCADENA]="hola.pep";
    char vocals[MAXCADENA], consonants[MAXCADENA];
    int maxVocal=0,maxCons=0;

    separarVocalsConsonants(frase,vocals,consonants,MAXCADENA,&maxVocal,&maxCons);
    pintaCadena(vocals,maxVocal);
    printf("\n");
    pintaCadena(consonants,maxCons);

    resetPrograma();
}

void separarVocalsConsonants(char cad[],char voc[],char cons[],int qttC,int *maxVocal,int *maxCons){
    int i=0;

    while (i<qttC && cad[i]!=FICADENA) {
        if(esVocal(cad[i])==1){
            voc[*maxVocal]=cad[i];
            (++*maxVocal);
        }else if(esLletra(cad[i])==1){
            cons[*maxCons]=cad[i];
            (++*maxCons);
        }
        i++;
    }
}
