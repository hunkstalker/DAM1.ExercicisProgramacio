#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <stdbool.h>

// Dossier 2020-21-ME-UF1. Tema 3.0 Exercici 16 (Rectangle_Dreta_Esquerra_Centrat)

/*
 Fer un programa que demani a l'usuari un nombre natural entre 1 i 10  i un caràcter que pot ser 'C', 'E' o 'D'.
 El programa ha de dibuixar llavors un triangle depenent de la lletra proporcionada i amb l'alçada que digui el número.
 Les lletres signifiquen si el triangle ha d'estar Centrat, a l'Esquerra o a la Dreta.  El programa finalitarà quan
 l’usuari hagi fet les tres opcions.
*/

// prototipos
void resetPrograma(void);

int demanarNumero(int,int);
char demanarTriangle();
void triangleEsquerra(int);
void triangleCentrat(int);
void triangleDreta(int);

int main() {
    SetConsoleTitle("Dossier Tema 3.0 Exercici 16. (Rectangle_Dreta_Esquerra_Centrat) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int min=1, max=10, num=0;
    char car;
    bool boolEsq=false, boolCent=false, boolDret=false;

    while (!(boolEsq==true && boolCent==true && boolDret==true)) {
        if (boolEsq==true || boolCent==true || boolDret==true) {
            system("pause");
            system("cls");
        }
        printf("\n >> Esquerra: %d | Centre: %d | Dreta: %d", boolEsq, boolCent, boolDret);
        num=demanarNumero(min,max);
        car=demanarTriangle();
        if (car=='E' || car=='e') {
            boolEsq=true;
            triangleEsquerra(num);
        } else if (car=='C' || car=='c') {
            boolCent=true;
            triangleCentrat(num);
        } else {
            boolDret=true;
            triangleDreta(num);
        }
    }

    setColor(GREEN);
    printf("FINISH!!");
    setColor(7);
    resetPrograma();
    return 0;
}

int demanarNumero(min,max) {
    int num=0;
    do {
        printf("\n\n >> Introdueix un número entre %d y %d: ", min, max);
        scanf("%d",&num);
    } while (num<min || num>max);
    return num;
}

char demanarTriangle() {
    char car;
    do {
        printf(" >> Introdueix un caracter [E]squerra, [C]entre o [D]reta: ");
        fflush(stdin);
        scanf("%c",&car);
        fflush(stdin);
    } while (!(car=='E' || car=='e' || car=='C' || car=='c'|| car=='D' || car=='d'));
    return car;
}

void triangleEsquerra(num) {
    printf(" >> Esquerra\n");
    int col=1, filas=1;
    int i=1;
    int xDir=2, yDir=7;

    for (; filas<=num; filas++) {
        yDir++;
        xDir=2;
        for (; i<=col; i++) {
            gotoxy(xDir,yDir);
            printf("x");
            xDir++;
        }
        i=1;
        col++;
    }
    xDir=2;
    yDir+=2;
    gotoxy(xDir,yDir);
}

void triangleCentrat(num) {
    printf(" >> Centrat\n");
    int col=1, filas=1;
    int i=1;
    int xDir=num+2, yDir=7;

    for (; filas<=num; filas++) {
        yDir++;
        xDir=num+2;
        for (; i<=col; i++) {
            gotoxy(xDir,yDir);
            printf("x");
            xDir--;
        }
        i=1;
        col++;
    }
    col=1, filas=1;
    i=1;
    yDir=7;

    for (; filas<=num; filas++) {
        yDir++;
        xDir=num+2;
        for (; i<=col; i++) {
            gotoxy(xDir,yDir);
            printf("x");
            xDir++;
        }
        i=1;
        col++;
    }
    xDir=2;
    yDir+=2;
    gotoxy(xDir,yDir);
}

void triangleDreta(num) {
    printf(" >> Dreta\n");
    int col=1, filas=1;
    int i=1;
    int xDir=num+1, yDir=7;

    for (; filas<=num; filas++) {
        yDir++;
        xDir=num+1;
        for (; i<=col; i++) {
            gotoxy(xDir,yDir);
            printf("x");
            xDir--;
        }
        i=1;
        col++;
    }
    xDir=2;
    yDir+=2;
    gotoxy(xDir,yDir);
}

// Función reset programa.
void resetPrograma() {

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=1; // I'ts a final countdown!

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
        printf(">> Vols [");
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
        printf("\n Dossier Tema 3.0 Exercici 16. (Rectangle_Dreta_Esquerra_Centrat).\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
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
