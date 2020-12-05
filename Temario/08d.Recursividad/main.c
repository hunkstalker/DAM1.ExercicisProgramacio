#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

/* Enunciat.

*/

// prototipos
void resetPrograma(void);

int factorial(int numero) {
    if (numero > 1) return (numero*factorial(numero-1));
    else return(1);
}

int main() {
    SetConsoleTitle("Dossier Tema3. Exercici01. (Màxim) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int n;
    printf("Introduce el número: ");
    scanf("%d",&n);
    printf("El factorial es %d", factorial(n));

    resetPrograma();
    return 0;
}

// Función reset programa.
void resetPrograma() {

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=1; // I'ts a final countdown!
    int i=0;

    // RESET.
    fflush(stdin);
    setColor(15);
    printf("\n\n >> Ara vols [");
    setColor(12);
    printf("R");
    setColor(15);
    printf("]einiciar el sistema o vols [");
    setColor(12);
    printf("S");
    setColor(15);
    printf("]ortir? ");
    scanf("%c",&optionPr);
    fflush(stdin);

    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')) {
        printf(" >> Vols [");
        setColor(12);
        printf("R");
        setColor(15);
        printf("]einiciar el sistema o vols [");
        setColor(12);
        printf("S");
        setColor(15);
        printf("]ortir? ");
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
