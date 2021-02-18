#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 6

/* Enunciat:
    Definir un vector de n caselles. Posteriorment, l’usuari introduirà nombres
    i aquests s’introduiran ordenadament dins del vector. Finalitza el programa
    quan tot el vector estigui ple. En cada passada mostrarem el vector amb els seus valors
*/

void guardarV(int v[],int qttE);
void ordenarV(int v[],int qttE,int numUsu,bool *majorTrobat);

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 08. (InserirOrdenadament) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    start();
    return 0;
}

// Inici del programa
void start() {
    int v[MAXVECTOR]= {0,};

    marcaV(v,MAXVECTOR);
    guardarV(v,MAXVECTOR);
    imprimirV(v,MAXVECTOR);

    resetPrograma();
}

void guardarV(int v[],int qttE) {
    int i,numUsu;
    bool majorTrobat = false;

    numUsu=demanarEntreMinMax(0,6); //inicio, pido número, el primero siempre se va
    v[0]=numUsu;                    //a introducir en la primera posición y lo guardo.

    for(i=1; i<=qttE-1; ++i) {
        imprimirV(v,MAXVECTOR);
        printf("\n\n");

        numUsu=demanarEntreMinMax(0,6);             //pido siguiente número.
        ordenarV(v,MAXVECTOR,numUsu,&majorTrobat);  //reviso si tengo que ordenarlo

        if (!majorTrobat) v[i]=numUsu;  //en el caso de haber encontrado un número mayor
        majorTrobat=false;              //no lo guardará en la posición original ya que
    }                                   //se gaurdó con anterioridad en la función "ordenarV".
}

void ordenarV(int v[],int qttE,int num,bool *majorTrobat){
    int j,k,aux;
    for(j=0; j<qttE; j++) {
        if(num<v[j]) {
            for(k=qttE-1; k>=0; k--) {
                if(v[k]==-1 || num<v[k]) {
                    aux=v[k];
                    v[k+1]=aux;
                    v[k]=-1;
                }
            }
            v[j]=num;
            j=qttE;
            *majorTrobat=true;
        }
    }
}

