#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 13

(CreixentDecreixent)
Donats tres nombre a,b i c, determina si la seq��ncia �s creixent, decreixent o cap d�elles.
Es determina que una seq��ncia �s creixent si el valor actual �s igual o superior al valor anterior.
Una seq��ncia on els tres nombres tenen el mateix valor, la considerarem seq��ncia creixent
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
si a=4, b=4 i c=11, es mostrar� el missatge �seq��ncia creixent�
Si a=6, b=-6 i c=11 es mostrar� el missatge �no �s ni creixent ni decreixent�
Si a=6, b=6 i c=6 es mostrar� el missatge �seq��ncia creixent�
Si a=6, b=6 i c=-7 es mostrar� el missatge �seq��ncia decreixent�
*/
