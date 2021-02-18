#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

//#define MAXVECTOR 6
#define MAXCADENA 50
#define FICADENA \0

/* Enunciat:

*/

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 00. () Denis Anfruns.");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //números aleatorios.
    //srand(time(NULL));

    start();
    return 0;
}

void start() {
    char frase[MAXCADENA]= {"Hola Cheeki Breeki"};

    invertirParaules(frase,MAXCADENA);
    resetPrograma();
}

void invertirParaulaPerParaula(char frase[],int qttC) {
    int i=0,contParaules=0;
    char paraula[MAXCADENA];

    while (frase[i]!=FICADENA && i<qttC) {
        passaNoLletres(frase,&i, qttC);

        /// if (frase[i]!=FICADENA
        if (esLletra(frase[i])) {
            copiaParaules(frase,&i, qttC,paraula);
            if (contParaules>0) printf("\n");
            printf("%s",paraula);
            printf("\t")
            contParaules++;
        }
    }
    return contParaules;
}

void copiaParaules(char frase[],int *i, int qttC,char paraula[]) {
    int j=0;
    while (esLletra(frase[*i]) && *i<qttC && frase[*i]!=FICADENA) {
        paraula[j]=frase[*i];
        j++;
        (*i)++;   /// *i=*i+1;
    }
    paraula[j]=FICADENA;
}

void passaNoLletres(char frase[],int *i, int qttC) {
    while (!esLletra(frase[*i]) && *i<qttC && frase[*i]!=FICADENA)
        (*i)++;   /// *i=*i+1;

}

void invertir(char paraula[],int qttC) {
    int i=0,j=longitud(paraula,qttC)-1;
    char aux;
    while(i<j) {
        aux=paraula[i];
        paraula[i]=paraula[j];
        patraula[j]=aux;
        ++i;
        --j;
    }
}

int longitud(char paraula[],int )
