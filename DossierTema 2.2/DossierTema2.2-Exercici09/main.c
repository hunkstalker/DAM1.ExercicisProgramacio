#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

/* Dossier UF1. Tema 2.2, Exercici 9

(Estacions)
Fer un algoritme que demani a l’usuari un mes i un dia, i mostri per pantalla l’estació de l’any corresponent.
*/

int main()
{
    int dia=0, mes=0;
    SetConsoleTitle("Dossier UF1. Tema 2.2, Exercici 9");

    while (!(mes>=1 && mes<=12)){
        printf(">> Introdueix un mes del any (valors del 1 al 12): ");
        scanf("%d",&mes);
    }
    if (mes==1 || (mes>=3 && mes<12)){
        while (!(dia>=1 && dia<=31)){
            printf(">> Introdueix un dia del mes (valors del 1 al 31): ");
            scanf("%d",&dia);
        }
        while (!(dia>=1 && dia<=28)){
        printf(">> Introdueix un dia del mes (valors del 1 al 31): ");
        scanf("%d",&dia);
        }
    }





    if (!(mes==2 && dia>=1 && dia<=28)) {
        printf("\n>> Error");
    }
//    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12 && (dia>=1 && dia<=31)) {
//        printf(">> Error");
//    }
//    if (mes==4 || mes==6 || mes==9 || mes==11 && (dia>=1 && dia<=30)) {
//        printf(">> Error");
//    }
    return 0;
}



//                printf("\n-- Error(!). Valors incorrectes torna a probar.\n>> Introdueix un mes del any (valors del 1 al 12): ");
//                scanf("%d",&mes);
//                printf(">> Introdueix un dia del mes (valors del 1 al 31): ");
//                scanf("%d",&dia);

//        if ((mes==9 && dia>21) || (mes==10 || mes==11) || (mes==12 && dia<=20)){
//            printf("\n-- Es tardor.\n");
//        } else if ((mes==12 && dia>=21) || (mes==1 || mes==2) || (mes==3 && dia<=20)){
//            printf("\n-- Es hivern.\n");
//        } else if ((mes==3 && dia>=21) || (mes==4 || mes==5) || (mes==6 && dia<=20)){
//            printf("\n-- Es primavera.\n");
//        } else {
//            printf("\n-- Es estiu.\n");
//        }

// Exemple
// Nota introduïda per l’usuari: 9
// Resultat: Excel·lent
// Nota introduïda per l’usuari: 15
// Resultat: No es una nota correcta
