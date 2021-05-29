#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 10

/* Enunciat:
    Defineix un vector de 10 caselles i demana números a l’usuari fins que el vector estigui ple.
    Introduirem el nou números dins del vector, sempre i quan, aquest no estigui ja introduït prèviament.
    Al finalitzar caldrà mostrar el vector amb els 10 números diferents.
*/

void scanV(int v[],int qttE);

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 06. (VectorSenseRepetits) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    program();
    return 0;
}

// Inici del programa
void program(){
    int v[MAXVECTOR];

    marcaV(v,MAXVECTOR); // Marco el vector per seguretat
    scanV(v,MAXVECTOR);
    imprimirV(v,MAXVECTOR);
    resetPrograma();
}

void scanV(int v[],int qttE){
    int i1,i2,numUsu;
    bool trobat = false;

    for(i1=0;i1<qttE;i1++){
        // reset de variables
        trobat = false;
        i2 = 0;

        numUsu=demanarEntreMinMax(0,100);
        // Cerca el numero. Si el troba interrumpeix el bucle.
        while(i2<qttE && trobat == false){
            if(v[i2]==numUsu){


                trobat = true;
            }
            ++i2;
        }
        // Si no el troba el guarda al vector
        if (trobat == false){
            v[i1]=numUsu;
        }
    }
}
