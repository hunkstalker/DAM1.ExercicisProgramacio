#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 13

(CreixentDecreixent)
Donats tres nombre a,b i c, determina si la seqüència és creixent, decreixent o cap d’elles.
Es determina que una seqüència és creixent si el valor actual és igual o superior al valor anterior.
Una seqüència on els tres nombres tenen el mateix valor, la considerarem seqüència creixent
*/

int main()
{
    int num1, num2, num3=0;
    printf(">> Introdueix el primer nombre\n");
    scanf("%d",&num1);
    printf(">> Introdueix el segon nombre\n");
    scanf("%d",&num2);
    printf(">> Introdueix el tercer nombre\n");
    scanf("%d",&num3);

    if (num1<=num2 && num2<=num3){
        printf("\n-- Creix.\n");
    } else if (num1>=num2 && num2>=num3){
        printf("\n-- Decreix.\n");
    } else {
        printf("\n-- Nothing.\n");
    }

    return 0;
}

/* Per exemple:
si a=4, b=4 i c=11, es mostrarà el missatge “seqüència creixent”
Si a=6, b=-6 i c=11 es mostrarà el missatge “no és ni creixent ni decreixent”
Si a=6, b=6 i c=6 es mostrarà el missatge “seqüència creixent”
Si a=6, b=6 i c=-7 es mostrarà el missatge “seqüència decreixent”
*/
