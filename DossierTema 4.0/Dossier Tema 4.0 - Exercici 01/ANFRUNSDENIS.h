#ifndef ANFRUNSDENIS_H_INCLUDED
#define ANFRUNSDENIS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int demanarNumero();
int demanarNumeroCompresEntreDosValors(int minim,int maxim);
int demanarNumeroControlPerUnLimit(int minim);

void resetPrograma();

int demanarNumero(){
    int num;
    scanf("%d",&num);
    return num;
}

int demanarNumeroCompresEntreDosValors(int minim,int maxim){
    int num;
    scanf("%d",&num);
    while(n<minim || n>maxim){
        printf(" >> Els valors han d'estar compresos entre %d-%d: ",minim,maxim);
        scanf("%d",&num);
    }
    return num;
}

int demanarNumeroControlPerUnLimit(int minim){
    int num;
    scanf("%d",&num);
    while(n<minim){
        printf(" >> Els valors han d'estar compresos entre %d-%d: ",minim,maxim);
        scanf("%d",&num);
    }
    return num;
}

void resetPrograma(){

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

#endif // ANFRUNSDENIS_H_INCLUDED
