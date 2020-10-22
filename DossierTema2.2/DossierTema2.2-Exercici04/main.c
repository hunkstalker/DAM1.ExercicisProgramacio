#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 4

(Nat_Senar)
Fer un algoritme que donat un nombre natural, indiqui si és o no un nombre natural senar.
*/

int main()
{
    int num1=0;

    printf(">> Introdueix un nombre: ");
    scanf("%d",&num1);
    if (num1%2==0){
        printf("\n-- El numero %d es parell.\n",num1);
    } else {
        printf("\n-- El numero %d es senar.\n",num1);
    }

    return 0;
}

// Exemple: num=1201
// Resultat: El número 1201 és senar
