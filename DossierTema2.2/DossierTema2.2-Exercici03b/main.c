#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 3

(Abs)
Fer un algoritme que mostri el valor absolut d’un número enter entrat per l’usuari.
El valor absolut d’un número és el mateix número amb signe positiu
*/

int main()
{
    int num1=0;

    printf(">> Introdueix un nombre: ");
    scanf("%d",&num1);
    if (num1<0)
    {
        num1=num1*(-1);
    }
    printf("\n-- El valor absolut es: %d\n", num1);
    return 0;
}

//Exemple: num=-10
//Resultat: El valor absolut del número és 10
//Exemple: num=10
//Resultat: El valor absolut del número és 10
