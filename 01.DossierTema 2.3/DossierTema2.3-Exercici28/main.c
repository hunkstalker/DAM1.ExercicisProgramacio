#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

/* Dossier UF1. Tema 2.3, Exercici 28

(N_Suma_de_Numeros)
Fer un algoritme que demani un n�mero natural (n) a l'usuari.
Aquest algoritme ha d'indicar si la suma d'una s�rie de com a molt deu n�meros demanats
tamb� a l'usuari, �s m�s gran que el primer n�mero natural (n) demanat.
*/

void repeat(){
    cls();
    main();
}

// BLOC PROGRAMA
int main()
{
    int numInici=0, numUsu=0, suma=0, cont=0;
    char option='X';

    SetConsoleTitle("Dossier UF1. Tema 2.3, Exercici 28");

    setColor(WHITE);
    printf("\n>> Introdueix un nombre natural Inicial: ");
    scanf("%d",&numInici);
    for (cont=0;cont<10;cont++){
        printf(">> Introdueix un nombre natural: ");
        scanf("%d",&numUsu);
        suma=suma+numUsu;
        while (suma>numInici){
            printf("\n>> La suma es mes gran que el numero introduit inicialment.\n");
    // BLOC PROGRAMA

            // SORTIDA & Compr errores
            while (!(option=='R' || option=='r' || option=='S' || option=='s')){
                fflush(stdin);
                printf(">> Vols ["); setColor(12); printf("R"); setColor(WHITE); printf("]epetir l'exercici o vols ["); setColor(12); printf("S"); setColor(WHITE); printf("]ortir? ");
                scanf("%c",&option);
                fflush(stdin);
            }
            if (option=='R' || option=='r') repeat(); // Llama al reinicio del programa.
            else {
                setColor(14);
                printf("\nDossier UF1. Tema 2.3, Exercici 28, 2020 Denis Anfruns. EDUCEM, Granollers.");
                setColor(WHITE);
                getchar();
                // Llama a la salida del programa.
                exit(0);
            }
        }
    }
    printf("\n>> La suma dels numeros introduits no es mes gran que el numero introduit inicialment.\n");

    // SORTIDA & Compr errores
    while (!(option=='R' || option=='r' || option=='S' || option=='s')){
        fflush(stdin);
        printf(">> Vols ["); setColor(12); printf("R"); setColor(WHITE); printf("]epetir l'exercici o vols ["); setColor(12); printf("S"); setColor(WHITE); printf("]ortir? ");
        scanf("%c",&option);
        fflush(stdin);
    }
    if (option=='R' || option=='r') repeat(); // Llama al reinicio del programa.
    else {
        setColor(6);
        printf("\nDossier UF1. Tema 2.3, Exercici 28, Curs 2020/2021 Denis Anfruns. EDUCEM, Granollers.\n>> Prem Intro per sortir...");
        setColor(WHITE);
        getchar();
        // Llama a la salida del programa.
        exit(0);
    }
}

/* Exemple
N�mero: 15
S�rie de n�meros que introduiex l�usuari: 2, 8, 5, 1
Resultat: La suma �s m�s gran  // fixa�t que ja no cal demanar els deu n�meros  a  l�usuari

N�mero: 150
S�rie de n�meros que introduiex l�usuari: 2, 8, 5, 1, 3, 5, 6, 7, 1, 2
Resultat: La suma dels n�meros introdu�ts no �s m�s gran que el n�mero
*/
