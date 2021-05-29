#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 6

/* Enunciat:
    A partir de l’exercici anterior, el programa ens ha d’indicar quin és el valor màxim dels dels números aleatoris generats.
*/

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 03. (Maxim) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    program();
    return 0;
}

/// Inicio del programa
void program(){
    int v[MAXVECTOR]={};
    int numUsu;

    marcaV(v,MAXVECTOR);

    numUsu=demanarEntreMinMax(0,6);
    randomIn(v,numUsu,10);
    imprimirV(v,MAXVECTOR);
    printf("\nEl promig es %.1f\n",avgV(v,numUsu));
    printf("\nEl numero màxim %d",maxNumV(v,MAXVECTOR));

    resetPrograma();
}
