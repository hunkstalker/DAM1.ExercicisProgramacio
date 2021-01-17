#include <stdio.h>
#include <stdlib.h>
#define MAXVECTOR 100

/* Enunciat.
Defineix un vector de 10 caselles i demana números a l’usuari fins que el vector estigui ple.
Introduirem el nou números dins del vector, sempre i quan, aquest no estigui ja introduït prèviament.
Al finalitzar caldrà mostrar el vector amb els 10 números diferents.
*/

// prototipos
void resetPrograma(void);



int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 06. (VectorSenseRepetits) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    /// Inicio del ejercicio
    int num[MAXVECTOR],cont[MAXVECTOR]={};
    int qttE=0;
    int valor;


    resetPrograma();
    return 0;
}

/// Reset programa.
void resetPrograma() {

    char optionPr='X';      // Variable para controlar la salida/repetición del programa.
    int finalCountdown=1;   // I'ts a final countdown!

    // RESET.
    fflush(stdin);
    setColor(15); printf("\n\n >> Ara vols [");
    setColor(12); printf("R");
    setColor(15); printf("]einiciar el sistema o vols [");
    setColor(12); printf("S");
    setColor(15); printf("]ortir? ");
    scanf("%c",&optionPr);
    fflush(stdin);

    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')) {
        setColor(RED); printf(" >> ¡Error!");
        setColor(15); printf(" Vols [");
        setColor(12); printf("R");
        setColor(15); printf("]einiciar el sistema o vols [");
        setColor(12); printf("S");
        setColor(15); printf("]ortir? ");
        scanf("%c",&optionPr);
        fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r') {
        cls();
        main();
    } else {
        setColor(6);
        printf("\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        setColor(15);

        // Cuenta atrás.
        printf("\n\n El programa es tancara en: ");
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--) {
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(500);
        exit(0);
    }
}
