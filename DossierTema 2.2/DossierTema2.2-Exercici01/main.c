#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 1

(Màxim)
Fer un algoritme que calculi el màxim de dos números enters entrats per l’usuari.
En cas que siguin el mateix nombre, mostrarà qualsevol dels dos nombres.
*/

int main()
{
    int num1, num2=0;

    printf(">> Introdueix un nombre: ");
    scanf("%d",&num1);
    printf(">> Introdueix un nombre: ");
    scanf("%d",&num2);
    if (num1>=num2){
        printf("\n-- El maxim dels dos nombres es: %d\n", num1);
    } else {
        printf("\n-- El maxim dels dos nombres es: %d\n", num2);
    }
    return 0;
}

// Exemple: num1=10 num2=20
// Resultat: El màxim dels dos nombres es 20
