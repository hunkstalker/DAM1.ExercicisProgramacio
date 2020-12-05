#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <stdbool.h>

// Dossier 2020-21-ME-UF1. Tema 3.0 Exercici 15. (DiesMesAnyQuantitatDies)

/*
 Donada una data determinada per un dia, un mes i un any en format numèric,
 i una quantitat de dies que ens proporciona l'usuari. Es demana, a partir del
 darrer dia del mes en curs, escriure els n dies que es demanen. S’haurà de tenir
 en compte els anys de trapàs.
*/

// prototipos
void resetPrograma(void);

void sortida(int dia,int mes,int any, int numDies);
int demanar(int min,int max);
int quantitatDiesMes(int mes,int any);
int demanaQuantitatDies(void);

int main() {
    SetConsoleTitle("Dossier Tema 3.0 Exercici 15. (DiesMesAnyQuantitatDies) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int any,mes,dia,numDies;

    printf("\n >> Introdueix un any: ");
    any=demanar(0,2050);
    printf(" >> Introdueix un mes: ");
    mes=demanar(1,12);
    dia=quantitatDiesMes(mes,any);
    numDies=demanaQuantitatDies();

    sortida(dia,mes,any,numDies);

    resetPrograma();
    return 0;
}

void sortida(int dia,int mes,int any, int numDies) {
    int num=1, diasMes, count=1;

    printf("\n >> Sortida:\n");

    while (count<=numDies) {
        while(mes<=12 && count<=numDies) {
            if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) {
                diasMes=31;
            } else if (mes==2) {
                if ((any%4==0) && (any%100!=0 || any%400==0)) {
                    diasMes=29;
                } else {
                    diasMes=28;
                }
            } else diasMes=30;

            do {
                printf(" >> %4d %02d/%02d/%04d\n",num,dia,mes,any);
                dia++;
                num++;
                count++;
            } while (dia<=diasMes && count<=numDies);
            dia=1;
            mes++;
        }
        mes=1;
        any++;
    }
}

int demanar(int min,int max) {
    int num;

    do {
        scanf("%d",&num);
    } while (num<min || num>max);
    return num;
}

int quantitatDiesMes(int mes,int any) {
    int diasMes, dia;

    do {
        printf(" >> Introdueix el dia: ");
        scanf("%d",&dia);
        if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) {
            diasMes=31;
        } else if (mes==2) {
            if ((any%4==0) && (any%100!=0 || any%400==0)) {
                diasMes=29;
            } else {
                diasMes=28;
            }
        } else diasMes=30;
    } while (dia<1 || dia>diasMes);
    return dia;
}

int demanaQuantitatDies() {
    int numDias;

    do {
        printf(" >> Introdueix quantitat de dies entre 1 y 2000: ");
        scanf("%d",&numDias);
    } while (numDias<1 || numDias>2000);
    return numDias;
}


// Función reset programa.
void resetPrograma() {

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=1; // I'ts a final countdown!
    int i=0;

    // RESET.
    setColor(15); printf("\n >> Ara vols [");
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
        printf("\n Dossier Tema 3.0 Exercici 15. (DiesMesAnyQuantitatDies).\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        setColor(15);

        // Cuenta atrás.
        printf("\n\n El programa es tancara en: ");
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--) {
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        for (i=0; i<=27; i++) {
            msleep(10);
            printf("\b \b");
        }
        msleep(500);
        exit(0);
    }
}
