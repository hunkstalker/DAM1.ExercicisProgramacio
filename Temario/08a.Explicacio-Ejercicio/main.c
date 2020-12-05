#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Dossier 2020-21-ME-UF1. Tema 3. Exercici 01

// prototipos
void resetPrograma(void);
void coord(int *, int *);
void rectangle(int,int,int,int);

int main()
{
    SetConsoleTitle("Exercici (Rectangle) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int xIni, yIni, xFin, yFin;

    printf("Introdueix coordenadas inicials: ");
    coord(&xIni,&yIni);
    printf("Introdueix coordenadas finals: ");
    coord(&xFin,&yFin);
    rectangle(xIni,yIni,xFin,yFin);


    resetPrograma();
    return 0;
}

void coord(int *xCoord, int *yCoord){
    scanf("%d %d",&*xCoord,&*yCoord);
}

void rectangle(xIni,yIni,xFin,yFin){
    setColor(RED);
    setBackgroundColor(RED);
    char car= 'X';
    int aux=xIni;

    for (;yIni<yFin;yIni++){
        for (;xIni<yFin;xIni++) {
            gotoxy(xIni,yIni);
            printf("%c",car);
        }
        xIni=aux;
    }
    setColor(WHITE);
    setBackgroundColor(0);
}

// Función reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=1; // I'ts a final countdown!
    int i=0;

    // RESET.
    setColor(15);
    fflush(stdin);
    printf("\n\n>> Ara vols ["); setColor(12); printf("R"); setColor(15); printf("]einiciar el sistema o vols ["); setColor(12); printf("S"); setColor(15); printf("]ortir? ");
    scanf("%c",&optionPr);
    fflush(stdin);

    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')){
		printf(">> Vols ["); setColor(12); printf("R"); setColor(15); printf("]einiciar el sistema o vols ["); setColor(12); printf("S"); setColor(15); printf("]ortir? ");
		scanf("%c",&optionPr);
		fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r'){
        cls();
        main();
    } else {
        setColor(6);
        printf("\n Exercici (Rectangle)\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        setColor(15);

        // Cuenta atrás.
        printf("\n\n El programa es tancara en: ");
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--){
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        for (i=0;i<=27;i++){
            msleep(10);
            printf("\b \b");
        }
        msleep(500);
        exit(0);
    }
}
