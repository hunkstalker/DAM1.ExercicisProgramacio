#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

//#define MAXVECTOR 6
#define MAXCADENA 50
#define FICADENA '\0'

/* Enunciat:
    Donada una frase, compta quantes paraules cont�
*/

int main() {
    SetConsoleTitle("Dossier Tema 5.0 Exercici 03. (Quantitat Paraules) Denis Anfruns.");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //n�meros aleatorios.
    //srand(time(NULL));

    start();
    return 0;
}

void start() {
    char frase[MAXCADENA]="    BON   DIA   EDUARD  ";
    printf("La cadena te %d paraules",comptaParaules(frase,MAXCADENA));

    resetPrograma();
}
