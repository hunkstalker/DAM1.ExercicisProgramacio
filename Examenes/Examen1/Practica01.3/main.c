#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // permite el uso de booleanos
#include <time.h>       // seed para el rand()
#include <rlutil.h>     // colorines
#include <windows.h>    // música


// float caudalRand();

// INICI PROGRAMA
int main(void){

    system("MODE CON: COLS=100");
    SetConsoleTitle("Práctica 1 Exercici 3. Embassament.");
    srand(time(NULL));
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    float caudal=750, caudalAnt=0, riu1=100, riu2=100;
    float percent=0, total;
    int hora=0, azar;
    // Gotoxy
    int xDir=2, yDir=10;

    // INICIO PROGRAMA
    setColor(6);
    printf("\n BENVINGUTS AL SISTEMA DE CONTROL DE L'EMBASSAMENT DE VALLFORNERS versió Beta");
    printf("\n DENIS ANFRUNS\n");
    setColor(15);

    printf("\n>> Introdueix el cabal inicial de l'embassament (0-1500): %.2f",caudal);
    // scanf("%d",&caudal);
    printf("\n>> Introdueix la capacitat inicial del riu 1 (0-400): %.2f",riu1);
    // scanf("%d",&riu_1);
    printf("\n>> Introdueix la capacitat inicial del riu 2 (0-400): %.2f",riu2);
    // scanf("%d",&riu_2);

    printf("\n\n Hora\tEstat\t\tPercent\t\tRiu1\tRiu2\tTotal\tCompt1\tCompt2\n");

    caudalAnt+=(riu1+riu2);
    while (hora<=60){

        // Total de los ríos.
        total=(riu1+riu2);
        // Porcentaje lleno del embalse.
        percent=(caudal/1500)*100;
        gotoxy(xDir,yDir++);
        printf("%d\t%.2f\t\t%.2f\t\t%2.f\t%2.f\t%.2f",hora, caudal, percent, riu1, riu2, total);
        msleep(100);
        hora++;

        azar=rand()%2;
        if (azar==0) caudal+=rand()%11*caudalAnt/100;
        else caudal-=rand()%11*caudalAnt/100;
    }
    getchar();
    return 0;
}

//float caudalRand(){
//    int azar;
//    float caudal, caudalAnt;
//    // Caudal aleatorio
//    azar=rand()%2;
//        if (azar==0) caudal=caudalAnt+rand()%11*caudalAnt/100;
//        else caudal=caudalAnt-rand()%11*caudalAnt/100;
//    return caudal;
//}

