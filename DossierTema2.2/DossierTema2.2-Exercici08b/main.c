#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 8b

(Dies del mes)
Fer un algoritme que donat un nombre natural de l’u al dotze, que representa el mes,
indiqui si el mes corresponent té 28 (no es té en compte si és any de traspàs), 30 o 31 dies.
*/

int main()
{
    int numMes=30, dies;

    printf(">> Introdueix el nombre de mes: ");
    scanf("%d",&numMes);
    dies=30;

    if (numMes>=1 && numMes<=12){
        if (numMes==2){
            dies=28;
        } else if (numMes==1 || numMes==3 || numMes==5 || numMes==7 || numMes==8 || numMes==10 || numMes==12){
            dies=31;
        }
        printf("\n-- Mes: %d ; Resultat %d dies\n", numMes, dies);
    }
    return 0;
}

// Per exemple: mes: 10 ; Resultat 31 dies
