#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 100

/* Enunciat:
    Definir un vector de 100 caselles. Posteriorment, es demanarà números a l’usuari
    mentre que aquest no introdueixi un -1. Els números vàlids estaran compresos entre
    el 0 i el 99. Al finalitzar el programa, ens ha d’indicar quantes vegades s’han
    introduït cadascun dels números vàlids.
*/

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 07. (ComptaQuantesVegades) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    program();
    return 0;
}

/// Inicio del programa
void program(){
    int cont[MAXVECTOR]={};
    int cicle=0;
    int numUsuario;

    marcaVector(cont,MAXVECTOR);

    printf("\n");
    numUsuario=demanarEntreMinMax(-1,99);

    while (numUsuario!=-1){
        cicle++;
        contador(cont,numUsuario);
        numUsuario=demanarEntreMinMax(-1,99);
    }
    imprimirVector(cont,MAXVECTOR);

    resetPrograma();
}
