#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.3 Exercici 10

(MitjaAritmetica)
Calcula la mitjana aritmètica de n valors introduïts per l’usuari.
Finalitzarem d’introduir nombres quan l’usuari introdueixi un -1. Considerarem que tots els números introduïts són enters.
*/

int main()
{
    float num, acum, cont=0;

    printf(">> Introdueix un nombre: ");
    scanf("%f",&num);

    while (num<-1){

        if (num!=-1){
            cont++;
            acum=acum+num;
            printf(">> Introdueix un altre nombre: ");
            scanf("%f",&num);
}
    }
    }

    printf("\n-- %.2f\n",(float)acum);
    printf("\n-- Mitja aritmetica de %0.f numeros introduits: %.2f\n", cont, (float)acum/cont);
    printf("\n>> Sortint del programa...\n");
    return 0;
}

// Exemple:
// Nombres introduits per l’usuari: 1 5 7 4 2 4 5 8 4 6 -1
// Resultat: Mitja aritmetica del (10) numeros itnroduits: 4.6
