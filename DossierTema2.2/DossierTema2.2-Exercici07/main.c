#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 7

(Num_Vocal)
Fer un algoritme que donada una lletra vocal (majúscula o minúscula) mostri quin nombre de lletra és.
*/

int main()
{
    char car='a';

    printf(">> Introdueix la nota: ");
    scanf("%c",&car);

    switch (car){
        case 'a':
        case 'A': printf("\n-- La vocal es el nombre: 1\n");
            break;
        case 'e':
        case 'E': printf("\n-- La vocal es el nombre: 2\n");
            break;
        case 'i':
        case 'I': printf("\n-- La vocal es el nombre: 3\n");
            break;
        case 'o':
        case 'O': printf("\n-- La vocal es el nombre: 4\n");
            break;
        case 'u':
        case 'U': printf("\n-- La vocal es el nombre: 5\n");
            break;
    }
    return 0;
}

// Per exemple, donada la ‘o’ (o la ‘O’), l’algoritme ha de mostrar un 4.
