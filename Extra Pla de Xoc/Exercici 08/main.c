#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 20
#define MAXCADENA 50

/* Enunciat:
    Jugarem amb un dau i un vector de 20 caselles. Tira el dau i omple el
    vector amb el n�mero que ha sortit tantes caselles com el n�mero ho indiqui.
    Si ens excedim de les caselles s�atura el programa, i els darrers n�meros no s�n introdu�ts.
*/

int main() {
    SetConsoleTitle("Pla de Xoc Exercici 08. Denis Anfruns.");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //n�meros aleatorios.
    srand(time(NULL));

    start();
    return 0;
}

void start() {


    resetPrograma();
}

