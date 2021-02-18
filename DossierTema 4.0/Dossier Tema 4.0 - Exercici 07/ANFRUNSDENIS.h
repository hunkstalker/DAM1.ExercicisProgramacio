#ifndef ANFRUNSDENIS_H_INCLUDED
#define ANFRUNSDENIS_H_INCLUDED

// Sé que no está bien incluir todas las librerías siempre pero por si acaso para el examen tengo una plantilla preparada con todas ellas.
#include <rlutil.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int demanarNumero();
int demanarEntreMinMax(int minim,int maxim);
int posicioVector(int num[], int qttE, int numUsuario);
void imprimirNumVectoryPos(int num[], int cont[], int qttE);

// Estos dos prototipos son para poder reiniciar el programa.
void program();
void resetPrograma();

int demanarNumero(){
    int n;
    scanf("%d",&n);
    return n;
}

int demanarEntreMinMax(int minim,int maxim){
    int n;
    do {
        printf(" >> Introduce un número entre %d y %d: ", minim, maxim);
        setColor(2);
        scanf("%d",&n);
        setColor(7);
    } while (n<minim || n>maxim);

    return n;
}

int posicioVector(int num[], int qttE, int numUsuario) {
    int i=0;
    int pos=-1;

    while (i<qttE && pos==-1){
        if (num[i]==numUsuario){
            pos=i;
        } else
            i++;
    }
    return pos;
}

void imprimirNumVectoryPos(int num[], int cont[], int qttE){
    int i=0;
    if (qttE==0){
        printf("\n >> No se ha introducido ningún valor válido.");
    }else{
        for (;i<qttE;i++){
            printf("\n >> El número %d se ha introducido %d veces.",num[i],cont[i]);
        }
    }
}

/// Reset del programa.
void resetPrograma(){

    char optionPr='X';      // Variable para controlar la salida/repetición del programa.
    int finalCountdown=1;   // I'ts a final countdown!

    // RESET.
    fflush(stdin);
    setColor(7); printf("\n\n >> Ara vols [");
    setColor(12); printf("R");
    setColor(7); printf("]einiciar el sistema o vols [");
    setColor(12); printf("S");
    setColor(7); printf("]ortir? ");
    scanf("%c",&optionPr);
    fflush(stdin);

    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')) {
        setColor(RED); printf(" >> ¡Error!");
        setColor(7); printf(" Vols [");
        setColor(12); printf("R");
        setColor(7); printf("]einiciar el sistema o vols [");
        setColor(12); printf("S");
        setColor(7); printf("]ortir? ");
        scanf("%c",&optionPr);
        fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r') {
        cls();
        program();
    } else {
        setColor(6);
        printf("\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        setColor(7);

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
