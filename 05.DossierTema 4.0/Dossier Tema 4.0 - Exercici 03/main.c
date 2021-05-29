#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 6

/* Enunciat:
    A partir de l�exercici anterior, el programa ens ha d�indicar quin �s el valor m�xim dels dels n�meros aleatoris generats.
*/

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 03. (Maxim) Denis Anfruns.");

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

    marcaV(v,MAXVECTOR);

    numUsu=demanarEntreMinMax(0,6);
    randomIn(v,numUsu,10);
    imprimirV(v,MAXVECTOR);
    printf("\nEl promig es %.1f\n",avgV(v,numUsu));
    printf("\nEl numero m�xim %d",maxNumV(v,MAXVECTOR));

    resetPrograma();
}
