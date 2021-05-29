#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 6

/* Enunciat:
    A partir d�un vector de 6 caselles, demanar a l�usuari un nombre compr�s entre
    0 i 6 i omplir tantes caselles com aquest n�mero indiqui. El valor de les
    caselles seran valors aleatoris compresos entre 0 i 10.  Es demana fer un
    programa que calculi el valor promig dels n�meros aleatoris generats.
*/

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 02. (Promig) Denis Anfruns.");

    // Tildes y s�mbolos alien�genas.
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

    marcaVector(v,MAXVECTOR);

    numUsu=demanarEntreMinMax(0,6);
    randomIn(v,numUsu,10);
    imprimirVector(v,MAXVECTOR);
    printf("\n >> El promig es %.1f",avgVector(v,numUsu));

    resetPrograma();
}
