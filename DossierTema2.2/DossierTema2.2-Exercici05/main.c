#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Dossier UF1. Tema 2.2, Exercici 5

(Equació_segon_grau)
Fer un algoritme que calculi el resultat d’una equació de segon grau.
L’usuari ha d’introduir els valors per a a, b i c. S’ha de fer servir la
fórmula de resolució de les equacions de segon grau:
*/

int main()
{
    float num1, num2, num3=0;
    float numAux=0;

    printf(">> Introdueix el 1r nombre: ");
    scanf("%f",&num1);
    printf(">> Introdueix el 2n nombre: ");
    scanf("%f",&num2);
    printf(">> Introdueix el 3r nombre: ");
    scanf("%f",&num3);

    numAux=num2*num2-(4*num1*num3);

    if (numAux==0){
        printf("\n-- Solucio 1: %.2f",-num2/(2*num1));
    } else if (numAux>0){
        printf("\n-- Solucio 1: %.2f\n",(-num2+sqrt(numAux))/(2*num1));
        printf("-- Solucio 2: %.2f\n",(-num2-sqrt(numAux))/(2*num1));
    } else {
        printf("\n-- Solucio 1: %.2f+%.2f i\n",-num2/(2*num1),(sqrt(-numAux))/(2*num1));
        printf("-- Solucio 2: %.2f-%.2f i\n",-num2/(2*num1),(sqrt(-numAux))/(2*num1));
    }
    return 0;
}
