#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 10

(Restaurant)
Un restaurant cobra els menús dels dies laborables a 10 € i dels festius a 14 €.
Fer un algoritme que demani a l’usuari un número de l’1 al 7 que indica el dia de la setmana,
i la quantitat d’euros que ha pagat el client. Llavors l’algoritme ha de donar error si el client
ha pagat menys del que correspon segons el dia, o bé el canvi que se li ha de tornar, si ha pagat més.
*/


int main()
{
    int dia=0;
    float import=0;

    printf(">> Introdueix un dia de 1a setmana (nombre del 1 al 7): ");
    scanf("%d",&dia);
    while (!(dia>=1 && dia<=7)){
        printf(">> Error. No has introduit un dia correcte.\n>> Introdueix un dia de 1a setmana (nombre del 1 al 7): ");
        scanf("%d",&dia);
    }
    printf(">> Introdueix l'import: ");
    scanf("%f",&import);
    while (import<0){
        printf(">> Error. No te sentit, la quantitat de diners ha de ser superior a 0.\n>> Introdueix l'import: ");
        scanf("%f",&import);
    }

    if (dia>=1 && dia<=5){
        if (import>=10){
            printf("\n-- Import a retornar: %.2f euros.\n", import-10);
        } else {
            printf("\n-- Import insuficient, falten %.2f euros.\n", fabs(import-10));
        }
    } else if (import>=14){
            printf("\n-- Import a retornar: %.2f euros.\n", import-14);
        } else {
            printf("\n-- Import insuficient, falten %.2f euros.\n", fabs(import-14));
        }
    return 0;
}

// Per exemple: numero dia=5; import=20,
// Mostrarà per pantalla: import a retornar 10 €
