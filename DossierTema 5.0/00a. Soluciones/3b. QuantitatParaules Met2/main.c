#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

//#define MAXVECTOR 6
#define MAXCADENA 50

/* Enunciat:
    Compta paraules amb la variable d'estat dins/fora.
*/

int main() {
    SetConsoleTitle("Dossier Tema 5.0 Exercici 03. (Quantitat Paraules) Denis Anfruns.");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //números aleatorios.
    //srand(time(NULL));

    start();
    return 0;
}

void start() {
    char frase[MAXCADENA]="    Buenos días  ";
    printf("La cadena te %d paraules",comptaParaulesDins(frase,MAXCADENA));

    resetPrograma();
}

int comptaParaulesDins(char frase[],int qttC) {
    int i=0,contP=0;
    bool dins=false;

    while(i<qttC && frase[i]!=FICADENA) {
            // Incremento en una palabra cuando entremos a la palabra
            if(esLletra(frase[i]) && dins==false) {
                dins=true;
                ++contP;
            } else if (!esLletra(frase[i]) && dins==true) dins=false;
            ++i;
    }
    return contP;
}
