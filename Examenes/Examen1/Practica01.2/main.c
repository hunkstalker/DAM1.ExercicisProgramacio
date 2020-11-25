#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // permite el uso de booleanos
#include <time.h>       // seed para el rand()
#include <rlutil.h>     // colorines
#include <windows.h>    // m�sica

// Exercici Pr�ctica #2.

// Prototipos.
void music(void);
void resetPrograma(void);
// NOTA. No uso m�s procedimentos porque dijisteis que no quer�ais. Los uso para pijadas m�as que quer�a meter nada m�s.

// Variables globales.
int xDir=1, yDir=1, yDirPlus=0; // Valores de gotoxy().
bool musicPlay=true; // Variable para reproducir m�sica.

// INICI PROGRAMA
int main(){

    system("MODE CON: COLS=100");
    SetConsoleTitle("DAM1 M3/UF1.Programacio Estructurada. Denis Anfruns. 2020/2021 Exercici 2.");

    srand(time(NULL));

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


    // Valores que se le piden al usuario.
    int cotMin=0, cotMax=0, cotInicial=0;

    // Cotizaci�n aleatoria (subida/bajada).
    int randCot=0, numRandom=2;

    // Valores de la tabla. Dias y valores de cotizaci�n.
    int dia=1, i=0;
    int xDir=1, yDir=0, yDirPlus=0; // Valores de gotoxy().
    int falloCont=0; // Contadores.

    // Ejecuta la m�sica 1 vez.
    if (musicPlay){
        music();
        musicPlay=false;
    }

    setColor(6);
    printf("\n Benvingut al SISTEMA GESTOR DE COTITZACIONS A BORSA v1.1\n");
    printf(" Realitzat per: Denis Anfruns Mill�n\n");
    setColor(15);
    yDirPlus=yDirPlus+3;

    // BLOQUE DE PREGUNTAS AL USUARIO.
    printf("\n>> Introdueix la cotitzaci� m�xima (30..40): "); setColor(2);
    scanf("%d",&cotMax);
    fflush(stdin);
    setColor(15);
    yDirPlus++;
    while (cotMax<30 || cotMax>40){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotitzaci� m�xima (30..40): "); setColor(2);
        scanf("%d",&cotMax);
        fflush(stdin);
        setColor(15);
        yDirPlus=yDirPlus+2;
    }
    printf(">> Introdueix la cotitzaci� m�nima (0..10): "); setColor(2);;
    scanf("%d",&cotMin);
    fflush(stdin);
    setColor(15);
    yDirPlus=yDirPlus+2;
    resetColor(); // Chapuza, pero veremos si arregla el bug misterioso del color.
    while (cotMin<0 || cotMin>10){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotitzaci� m�nima (0..10): "); setColor(2);
        scanf("%d",&cotMin);
        fflush(stdin);
        setColor(15);
        yDirPlus=yDirPlus+2;
    }
    printf(">> Introdueix la cotitzaci� inicial (%d..%d): ", cotMin, cotMax); setColor(2);
    scanf("%d",&cotInicial);
    fflush(stdin);
    setColor(15);
    yDirPlus++;
    while (cotInicial<cotMin || cotInicial>cotMax){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotitzaci� inicial (%d..%d): ", cotMin, cotMax); setColor(2);
        scanf("%d",&cotInicial);
        fflush(stdin);
        setColor(15);
        yDirPlus=yDirPlus+2;
    }
    // FIN BLOQUE PREGUNTAS USUARIO

    // 1er INICIO BLOQUE DEL GR�FICO
    yDir=yDir+yDirPlus+1;
    for (i=40;i>=0;i--){
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
    // 1er FIN BLOQUE DEL GR�FICO

    gotoxy(xDir=5,yDir=42+yDirPlus); // reset posici�n
    gotoxy(xDir,yDir=yDir-cotInicial); // posici�n inicial de Cotizaci�n

    msleep(250);
    // 2do INICIO BLOQUE DEL GR�FICO
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
        // C�lculo aleatorio de subida/bajada cotizaci�n.
        // En este caso cambiar variable por 5. %5=4 rangos: (0-2 = -2) a (4-2 = 2)
        // randCot=rand()%numRandom-2;
        // En este caso cambiar variable al rango que quieras que suba/baje: Ej. num=2 (num*2=4)-2 = -2 a 2 (best option).
        randCot=rand()%(numRandom*2+1)-numRandom;

        // C�lculo variaci�n cotizaci�n
        yDir=yDir-(randCot);

        // Avance de gr�fico
        xDir++;
        dia++;
        gotoxy(xDir,yDir);
    }
    xDir=1; yDir=43+yDirPlus;
    gotoxy(xDir,yDir);
    resetPrograma();
    // 2do FIN BLOQUE DEL GR�FICO

    // SALIDA DEL PROGRAMA
    if (falloCont==3){
        xDir=1; yDir=43+yDirPlus;
        gotoxy(xDir,yDir);
        printf(" L'EMPRESA A CAIGUT EN BANCARROTA\n\n");
        yDirPlus=yDirPlus+2;
        resetPrograma();
    }
    return 0;
}

// M�todo/Procedimiento reset/cierre programa.
void resetPrograma(){

    int i=0; // Contador para el borrador final. Podr�a activar en settings>compiler el -std=c99 y...
             // declarar la variable directo en el 'for' pero por si acaso te da problemas lo hago as�.
    char optionPr='X'; // Variable para controlar la salida/repetici�n del programa.
    int finalCountdown=3; // I'ts a final countdown!

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
        printf("\n DAM1 M3/UF1.Programaci� Estructurada. Pr�ctica de Programaci�. Exercici 1\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        printf("\n M�SICA 'artblock' DE https://opengameart.org/content/artblock");
        setColor(15);

        // Cuenta atr�s.
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
        gotoxy(xDir,yDir+=(55+yDirPlus));
        printf("\n\n Prem Intro per sortir...");
        getchar();
        exit(0);
    }
}

// M�todo/procedimiento para reproducir tema musical.
void music(){
    PlaySound(TEXT("artblock"), NULL, SND_LOOP | SND_ASYNC);
    musicPlay=false;
}

