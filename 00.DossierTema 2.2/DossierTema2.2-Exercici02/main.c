#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 2

(Compara_enters)
Fer un algoritme que donats dos nombres enters, indiqui si el primer és més gran, igual o menor que el segon.
*/

int main()
{
    int num1, num2=0;

    printf(">> Introdueix un nombre: ");
    scanf("%d",&num1);
    printf(">> Introdueix un nombre: ");
    scanf("%d",&num2);

    if (num1>num2){
        printf("\n-- %d es mes gran que %d.\n", num1, num2);
    } else if (num2>num1) {
        printf("\n-- %d es mes gran que %d.\n", num2, num1);
    } else {
        printf("\n-- Els dos nombres son iguals.\n");
    }
    return 0;
}

// Exemple: num1=10 num2=20
// Resultat: El primer numero es mes petit que el segon

