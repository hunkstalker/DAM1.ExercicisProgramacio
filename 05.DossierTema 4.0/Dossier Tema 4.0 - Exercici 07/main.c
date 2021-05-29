#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 100

/* Enunciat:
    Definir un vector de 100 caselles. Posteriorment, es demanar� n�meros a l�usuari
    mentre que aquest no introdueixi un -1. Els n�meros v�lids estaran compresos entre
    el 0 i el 99. Al finalitzar el programa, ens ha d�indicar quantes vegades s�han
    introdu�t cadascun dels n�meros v�lids.
*/

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 07. (ComptaQuantesVegades) Denis Anfruns.");

    // Tildes y s�mbolos alien�genas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    program();

    return 0;
}

/// Inicio del programa
void program(){
    int num[MAXVECTOR]={}, cont[MAXVECTOR]={};
    int qttE=0;
    int numUsuario, pos;

    printf("\n");
    numUsuario=demanarEntreMinMax(-1,99);

    while (numUsuario != -1){
        pos=posicioVector(num,qttE,numUsuario);
        if (pos==-1){
            num[qttE]=numUsuario;
            cont[qttE]=1;
            ++qttE;
        } else {
            cont[pos]++;
        }
        numUsuario=demanarEntreMinMax(-1,99);
    }

    imprimirNumVectoryPos(num, cont, qttE);

    resetPrograma();
}
