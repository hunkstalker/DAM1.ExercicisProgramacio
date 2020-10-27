#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 4

(Nat_Senar)
Fer un algoritme que donat un nombre natural, indiqui si és o no un nombre natural senar.
*/

int main()
{
    int num=0;

    printf(">> Introdueix un nombre: ");
    scanf("%d",&num);
    if (num%2==0){
        printf("\n-- El numero %d es parell.\n",num);
    } else {
        printf("\n-- El numero %d es senar.\n",num);
    }
    return 0;
}

// Exemple: num=1201
// Resultat: El número 1201 és senar
