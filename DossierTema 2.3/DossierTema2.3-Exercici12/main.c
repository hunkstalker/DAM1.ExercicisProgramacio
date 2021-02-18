#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.3 Exercici 12

(Factorial)
Calcula el factorial del número natural introduit per teclat.
*/

int main()
{
    float fact=1;
    float n,cont;

    printf(">> Introdueix un nombre: ");
    scanf("%f",&n);

    for (cont=2;cont<=n;cont++)
    {
        fact=fact*cont;
    }
    printf("El factorial de %0.f es %0.f\n", n, fact);
    getch();
    return 0;
}

// Exemple:
// Número:6
// Resultat: 720


//    TABULADOR
//    int cont=0;
//
//    for (;cont<=100; cont++){
//        printf("\n%d\t",cont);
//    }
//    printf("\n");
