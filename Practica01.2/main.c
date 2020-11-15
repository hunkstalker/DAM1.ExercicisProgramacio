#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rlutil.h>
#include <stdbool.h>
#include <windows.h>

// Exercici Práctica #2.

bool musicPlay=true;

// Método para reproducir música.
void music(){
    PlaySound(TEXT("artblock"), NULL, SND_LOOP | SND_ASYNC);
}

// INICI PROGRAMA
int main(){


    // Ejecuta la música 1 vez.
    if (musicPlay){
        music();
        musicPlay=false;
    }

    system("MODE CON: COLS=100");
    SetConsoleTitle("DAM1 M3/UF1.Programacio Estructurada. Denis Anfruns. 2020/2021 Exercici 2.");

    srand(time(NULL));

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


    // Valores que se le piden al usuario.
    int cotMin=0, cotMax=0, cotInicial=0;

    // Cotización aleatoria (subida/bajada).
    int randCot=0, numRandom=2;

    // Valores de la tabla. Dias y valores de cotización.
    int dia=1;
    int xDir=1, yDir=0, yDirPlus=0; // Valores de gotoxy().
    int falloCont=0; // Contadores.

    // Variable para controlar la salida/repetición del programa.
    char optionPr='X';
    // Variable contador final.
    int finalCountdown=3;

    setColor(6);
    printf("\n Benvingut al SISTEMA GESTOR DE COTITZACIONS A BORSA v1.1\n");
    printf(" Realitzat per: Denis Anfruns Millán\n");
    setColor(15);
    yDirPlus=yDirPlus+3;

    // BLOQUE DE PREGUNTAS AL USUARIO.
    printf("\n>> Introdueix la cotització màxima (30..40): "); setColor(2);
    scanf("%d",&cotMax);
    fflush(stdin);
    setColor(15);
    yDirPlus++;
    while (cotMax<30 || cotMax>40){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotització màxima (30..40): "); setColor(2);
        scanf("%d",&cotMax);
        fflush(stdin);
        setColor(15);
        yDirPlus=yDirPlus+2;
    }
    printf(">> Introdueix la cotització mínima (0..10): "); setColor(2);;
    scanf("%d",&cotMin);
    fflush(stdin);
    setColor(15);
    yDirPlus=yDirPlus+2;
    resetColor(); // Chapuza, pero veremos si arregla el bug misterioso del color.
    while (cotMin<0 || cotMin>10){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotització mínima (0..10): "); setColor(2);
        scanf("%d",&cotMin);
        fflush(stdin);
        setColor(15);
        yDirPlus=yDirPlus+2;
    }
    printf(">> Introdueix la cotització inicial (%d..%d): ", cotMin, cotMax); setColor(2);
    scanf("%d",&cotInicial);
    fflush(stdin);
    setColor(15);
    yDirPlus++;
    while (cotInicial<cotMin || cotInicial>cotMax){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotització inicial (%d..%d): ", cotMin, cotMax); setColor(2);
        scanf("%d",&cotInicial);
        fflush(stdin);
        setColor(15);
        yDirPlus=yDirPlus+2;
    }
    // FIN BLOQUE PREGUNTAS USUARIO

    // 1er INICIO BLOQUE DEL GRÁFICO
    yDir=yDir+yDirPlus+1;
    for (int i=40;i>=0;i--){
        yDir++;
        gotoxy(xDir,yDir);
        msleep(15);
        printf(" %2d|",i);
    }
    gotoxy(xDir+4,yDir=yDir);
    msleep(15);
    printf("----|----|----|----|----|----|----|----|----|----|----|----|--------->\n");
    yDir++;
    printf("   01   05   10   15   20   25   30   35   40   45   50   55   60\n");
    setColor(3);
    gotoxy(xDir+4,yDir=yDir-(cotMax+1));
    msleep(250);
    printf("---------------------------------------------------------------------\n");
    setColor(4);
    gotoxy(xDir+4,yDir=yDir+(cotMax-cotMin));
    msleep(250);
    printf("---------------------------------------------------------------------\n");
    setColor(15);
    // 1er FIN BLOQUE DEL GRÁFICO

    gotoxy(xDir=5,yDir=42+yDirPlus); // reset posición
    gotoxy(xDir,yDir=yDir-cotInicial); // posición inicial de Cotización

    msleep(250);
    // 2do INICIO BLOQUE DEL GRÁFICO
    while ((dia<=60) && (!(falloCont==3))){

        msleep(15);
        if (yDir<=(2+yDirPlus)){
            yDir=(2+yDirPlus);
            gotoxy(xDir,yDir);
            setColor(2);
            printf("^");
        } else if (yDir<(42+yDirPlus)-cotMax){
            setColor(3);
            printf("*");
        } else if (yDir>((42+yDirPlus)-cotMin)){
            if (yDir>(42+yDirPlus)){
                yDir=(42+yDirPlus);
                gotoxy(xDir,yDir);
            }
            setColor(4);
            printf("*");
            falloCont++;
        } else {
            setColor(15);
            printf("*");
            falloCont=0;
        }

        // NUM RANDOM
        // Cálculo aleatorio de subida/bajada cotización.
        // En este caso cambiar variable por 5. %5=4 rangos: (0-2 = -2) a (4-2 = 2)
        // randCot=rand()%numRandom-2;
        // En este caso cambiar variable al rango que quieras que suba/baje: Ej. num=2 (num*2=4)-2 = -2 a 2 (best option).
        randCot=rand()%(numRandom*2+1)-numRandom;

        // Cálculo variación cotización
        yDir=yDir-(randCot);

        // Avance de gráfico
        xDir++;
        dia++;
        gotoxy(xDir,yDir);
    }
    // 2do FIN BLOQUE DEL GRÁFICO

    // SALIDA DEL PROGRAMA
    if (falloCont==3){
        xDir=1; yDir=45+yDirPlus;
        gotoxy(xDir,yDir);
        printf(" L'EMPRESA A CAIGUT EN BANCARROTA\n\n");
        yDirPlus=yDirPlus+2;
    }

    // RESET
    xDir=1; yDir=43+yDirPlus;
    gotoxy(xDir,yDir);
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
        yDirPlus++;
    }
    if (optionPr=='R' || optionPr=='r'){
        cls();
        main();
    } else {
        setColor(6);
        printf("\n DAM1 M3/UF1.Programació Estructurada. Práctica de Programació. Exercici 2\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        printf("\n MÚSICA 'artblock' DE https://opengameart.org/content/artblock");
        setColor(15);

        // Cuenta atrás.
        printf("\n\n El programa es tancara en: ");
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--){
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        int borrado;
        for (borrado=0;borrado<=27;borrado++){
            msleep(10);
            printf("\b \b");
        }
        gotoxy(xDir,yDirPlus+49);
        printf("\n\n Prem Intro per sortir...");
        getchar();
        exit(0);
    }
    return 0;
}

