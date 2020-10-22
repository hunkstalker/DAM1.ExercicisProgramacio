#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 8

(Dies del mes)
Fer un algoritme que donat un nombre natural de l’u al dotze, que representa el mes,
indiqui si el mes corresponent té 28 (no es té en compte si és any de traspàs), 30 o 31 dies.
*/

int main()
{
    int numMes=0;

    printf(">> Introdueix el nombre de mes: ");
    scanf("%d",&numMes);

    switch (numMes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: printf("\n-- Mes: %d ; Resultat 31 dies.\n",numMes);
            break;
        case 4:
        case 6:
        case 9:
        case 11: printf("\n-- Mes: %d ; Resultat 30 dies.\n",numMes);
            break;
        case 2: printf("\n-- Mes: %d ; Resultat 28 dies.\n",numMes);
            break;
    }
return 0;
}

// Per exemple: mes: 10 ; Resultat 31 dies
