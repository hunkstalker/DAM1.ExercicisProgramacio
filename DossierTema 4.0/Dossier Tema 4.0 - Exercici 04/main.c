#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 10

/* Enunciat:
    A partir d�un vector de 10 caselles, demanar a l�usuari un nombre compr�s entre 0 i 10
    i omplir tantes caselles com aquest n�mero indiqui.
    El valor de les caselles seran valors aleatoris compresos entre 1 i 100.
    Posteriorment demanar un  n�mero a l�usuari, compr�s entre 1 i 100 i cercar
    si aquest valor existeix dins del vector.
*/

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 04. (Cerca) Denis Anfruns.");

    // Tildes y s�mbolos alien�genas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    program();
    return 0;
}

/// Inicio del programa
void program(){
    int v[MAXVECTOR];
    int numUsuari, numCerca;

    marcaV(v,MAXVECTOR);
    printf("\nIntrodueix un numero compr�s enre 0 i 10: ");
    numUsuari=demanarNum();
    randomIn(v,numUsuari,100);
    imprimirV(v,MAXVECTOR);
    printf("\n\nIntrodueix el numero que vols trobar: ");
    numCerca=demanarNum();
    cerca(v,MAXVECTOR,numCerca);

    resetPrograma();
}
