#include <stdio.h>
#include <stdlib.h>

/* Dossier UF1. Tema 2.2, Exercici 6

(Notes)
Fer un algoritme que donada una nota numèrica (número natural), calculi la nota textual, segons la següent taula:
*/

int main()
{
    int nota=0;

    printf(">> Introdueix la nota: ");
    scanf("%d",&nota);
    printf("\n-- Nota introduida per l'usuari: %d\n", nota);

    while (!(nota>=1 && nota<=10)){
        printf("\n-- Error. Nota no valida.\n>> Introdueix un altre nombre: ");
        scanf("%d",&nota);
    }
    if (nota>=0 && nota<=10){
        switch (nota){
            case 1:
            case 2:
            case 3: printf("\n-- Resultat: Molt deficient.\n");
                break;
            case 4: printf("\n-- Resultat: Insuficient.\n");
                break;
            case 5: printf("\n-- Resultat: Suficient.\n");
                break;
            case 6: printf("\n-- Resultat: Be.\n");
                break;
            case 7:
            case 8: printf("\n-- Resultat: Notable.\n");
                break;
            case 9:
            case 10: printf("\n-- Resultat: Excel-lent.\n");
                break;
        }
    }
    return 0;
}

// Exemple
// Nota introduïda per l’usuari: 9
// Resultat: Excel·lent
// Nota introduïda per l’usuari: 15
// Resultat: No es una nota correcta
