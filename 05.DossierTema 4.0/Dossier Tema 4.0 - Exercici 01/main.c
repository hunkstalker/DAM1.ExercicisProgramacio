#include <ANFRUNSDENIS.h>
#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <time.h>
#include <stdbool.h>

#define MAXVECTOR 6

void imprVector(int v[],int qttE);
void sumaAnt(int v[],int qttE);
void intercambio(int v[]);
int contPares(int v[],int qttE);
int sumaVector(int v[],int qttE);
int sumaPares(int v[],int qttE);

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 01. (Vectors) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    /// Inicio del ejercicio
    int v[MAXVECTOR];

    // Exrercici 1.1
    v[0]=4;
    v[1]=3;
    v[2]=5;
    v[3]=6;
    v[4]=2;
    v[5]=10;

    // Exercici 1.2
    printf("\n >> Ejercicio 1.2 (Imprimir):");
    imprVector(v,MAXVECTOR);
    // Exercici 1.3
    printf("\n >> Ejercicio 1.3 (Contar los pares): Hay %d números pares.", contPares(v,MAXVECTOR));
    // Exercici 1.4
    printf("\n >> Ejercicio 1.4 (sumar Vectores): La suma es %d.", sumaVector(v,MAXVECTOR));
    // Exercici 1.5
    printf("\n >> Ejercicio 1.5 (Sumar los pares): La suma de los pares es %d.", sumaPares(v,MAXVECTOR));
    // Exercici 1.6
    sumaAnt(v,MAXVECTOR);
    imprVector(v,MAXVECTOR);
    // Exercici 1.7
    intercambio(v);
    imprVector(v,MAXVECTOR);

    resetPrograma();
    return 0;
}

void imprVector(int v[],int qttE) {
    int i;
    printf("\n");
    for (i=0; i<qttE; i++) {
        printf(" >> v[%d]=%d\n", i,v[i]);
    }
}

// Exercici 1.3
int contPares(int v[],int qttE) {
    int i, cont=0;
    for (i=0; i<qttE; ++i) {
        if (v[i]%2==0) ++cont;
    }
    return cont;
}

// Exercici 1.4
int sumaVector(int v[],int qttE) {
    int i, suma=0;
    for (i=0; i<qttE; ++i) {
        suma=suma+v[i];
    }
    return suma;
}

// Exercici 1.5
int sumaPares(int v[],int qttE) {
    int i, cont=0, suma=0;
    for (i=0; i<qttE; ++i) {
        if (v[i]%2==0) {
            suma=suma+v[i];
            ++cont;
        }
    }
    return suma;
}

// Exercici 1.6
void sumaAnt(int v[],int qttE) {
    int i, ant=0;
    printf("\n\n >> Ejercicio 1.6 (sumaAnt):");
    for (i=0; i<qttE; ++i) {
        v[i]=v[i]+ant;
        ant=v[i];
    }
}

// Exercici 1.7
void intercambio(int v[]) {
    // Intercambiar el valor de la primera casilla con la última.
    printf("\n >> Ejercicio 1.7 (intercambio):");
    int aux;
    aux=v[0];
    v[0]=v[5];
    v[5]=aux;
}




