#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rlutil.h>
#include <windows.h>

// Exercici Pr�ctica #1.

int musicPlay=1;

// M�todo para reproducir m�sica.
void music(){
    PlaySound(TEXT("artblock"), NULL, SND_LOOP | SND_ASYNC);
}

// INICI PROGRAMA
int main(){


    // Ejecuta la m�sica 1 vez.
    if (musicPlay==1){
        music();
        musicPlay=0;
    }

    system("MODE CON: COLS=100");
    SetConsoleTitle("DAM1 M3/UF1.Programacio Estructurada. Denis Anfruns. 2020/2021");

    srand(time(NULL));

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


    // Valores que se le piden al usuario.
    int cotMin=0, cotMax=0, cotInicial=0;

    // Cotizaci�n aleatoria (subida/bajada).
    int randCot=0, numRandom=2;

    // Valores de la tabla. Dias y valores de cotizaci�n.
    int dia=1, cotAux=0, cotAux2=0, cotDiaActual=0, cotDiaAnterior=0, cotDiaAnAnterior=0; // Valores de control de Cotizaci�n.
    int xDir=0, yDir=0, yDirPlus=0; // Valores de gotoxy().
    int falloCont=0; // Contadores.
    float avgCot=0;

    // Valores del recuento/resumen final.
    int diaMax=0, cotRecMax=0, diaMin=0, cotRecMin=0;

    // Variable para controlar la salida/repetici�n del programa.
    char optionPr='X';
    // Variable contador final.
    int finalCountdown=5;

    setColor(6);
    printf("\n Benvingut al SISTEMA GESTOR DE COTITZACIONS A BORSA 1.0c\n");
    printf(" Realitzat per: Denis Anfruns Mill�n\n\n");
    setColor(15);
    yDirPlus=yDirPlus+5;

    // BLOQUE DE PREGUNTAS AL USUARIO.
    printf(">> Introdueix la cotitzaci� m�nima (0..10): "); setColor(2);;
    scanf("%d",&cotMin);
    fflush(stdin);
    setColor(15);
    yDirPlus++;
    resetColor(); // Chapuza, pero veremos si arregla el bug misterioso del color.
    while (cotMin<0 || cotMin>10){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotitzaci� m�nima (0..10): "); setColor(2);
        scanf("%d",&cotMin);
        fflush(stdin);
        setColor(15);
        yDirPlus=yDirPlus+2;
    }
    printf(">> Introdueix la cotitzaci� m�xima (30..40): "); setColor(2);
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

    // BLOQUE DE TABLA.
    // dia 1
    cotDiaActual=cotInicial;
    cotAux=cotDiaActual;
    printf("\n dia %2d: %3d\n", dia, cotDiaActual);
    dia++;

    // Bloque recuentos resumen final.
    avgCot=cotInicial;
    cotRecMax=cotInicial;
    diaMax=dia;
    cotRecMin=cotInicial;
    diaMin=dia;

    while ((dia<=60) && (!(falloCont==3))){

        // NUM RANDOM
        // C�lculo aleatorio de subida/bajada cotizaci�n.
        // En este caso cambiar variable por 5. %5=4 rangos: (0-2 = -2) a (4-2 = 2)
        // randCot=rand()%numRandom-2;
        // En este caso cambiar variable al rango que quieras que suba/baje: Ej. num=2 (num*2=4)-2 = -2 a 2 (best option).
        randCot=rand()%(numRandom*2+1)-numRandom;

        // Contador bancarrota.
        if (cotDiaActual<cotMin){
            falloCont++;
        } else if (cotDiaActual>=cotMin) falloCont=0;

        // C�lculo de variaci�n cotizaci�n.
        cotDiaActual=cotDiaActual+randCot;

        // Intercambio de valores entre d�as.
        cotAux2=cotDiaAnterior;
        cotDiaAnterior=cotAux;
        cotDiaAnAnterior=cotAux2;

        // Suma para c�lculo de la media.
        avgCot=avgCot+cotDiaActual;

        // dia 2
        if (dia<=2){
            if (cotDiaActual<cotMin) setColor(RED);
            if (cotDiaActual>cotMax) setColor(3);

            msleep(15);
            printf(" dia %2d: %3d %3d\n", dia, cotDiaActual, cotDiaAnterior);
            yDirPlus++;
            setColor(15);
            cotAux=cotDiaActual;

            // Bloque resumen final. Esto lo har�a en una funci�n.
            if (cotDiaActual>=cotRecMax){
                cotRecMax=cotDiaActual;
                diaMax=dia;
            } else if (cotDiaActual<=cotRecMin){
                cotRecMin=cotDiaActual;
                diaMin=dia;
            }
        }

        // Primer bloque de d�as (1er mes, 3 a 30).
        if ((dia>=3 && dia<=30) && (!(falloCont==3))){
            if (cotDiaActual<cotMin) setColor(RED);
            if (cotDiaActual>cotMax) setColor(3);
            msleep(15);
            printf(" dia %2d: %3d %3d %3d\n", dia, cotDiaActual, cotDiaAnterior, cotDiaAnAnterior);
            yDirPlus++;
            setColor(15);
            cotAux=cotDiaActual;

            // Bloque resumen final. Esto lo har�a en una funci�n.
            if (cotDiaActual>=cotRecMax){
                cotRecMax=cotDiaActual;
                diaMax=dia;
            } else if (cotDiaActual<=cotRecMin){
                cotRecMin=cotDiaActual;
                diaMin=dia;
            }
        }

        // Segundo bloque de d�as (2do mes, 31 a 60).
        if ((dia>=31 && dia<=60) && (!(falloCont==3))){
            if (dia==31) yDir=yDirPlus-29;
            xDir=32; yDir++;
            gotoxy(xDir,yDir);
            if (cotDiaActual<cotMin) setColor(RED);
            if (cotDiaActual>cotMax) setColor(3);
            msleep(15);
            printf(" dia %2d: %3d %3d %3d\n", dia, cotDiaActual, cotDiaAnterior, cotDiaAnAnterior);
            setColor(15);
            cotAux=cotDiaActual;

            // Bloque resumen final. Esto lo har�a en una funci�n.
            if (cotRecMax<=cotDiaActual){
                cotRecMax=cotDiaActual;
                diaMax=dia;
            } else if (cotRecMin>=cotDiaActual){
                cotRecMin=cotDiaActual;
                diaMin=dia;
            }
        }
    // Contador de d�as.
    dia++;
    }
    // FIN BLOQUE TABLA

    // SALIDA DEL PROGRAMA
    if (falloCont==3){
        yDir=4+yDirPlus; xDir=1;
        gotoxy(xDir,yDir);
        printf(" L'EMPRESA A CAIGUT EN BANCARROTA\n\n");
        yDirPlus=yDirPlus+2;
    }

    yDir=4+yDirPlus; xDir=1;
    gotoxy(xDir,yDir);
    printf(">> Cotitzaci� M�nima: "); setColor(2); printf("%d ", cotMin); setColor(15); printf("Cotitzaci� M�xima: "); setColor(2); printf("%d ", cotMax); setColor(15); printf("Cotitzaci� Inicial: "); setColor(2); printf("%d ", cotInicial); setColor(15);
    printf("\n\n>> El valor promig de les cotitzacions ha sigut de: "); setColor(2); printf("%.2f",avgCot=(avgCot/dia)); setColor(15);

    printf("\n>> El dia que s'ha obtingut la darrera m�xima cotitzaci� ha sigut: %d i amb un valor m�xim de: ",diaMax); setColor(3); printf("%d", cotRecMax); setColor(15);
    printf("\n>> El dia que s'ha obtingut la darrera m�nima cotitzaci� ha sigut: %d i amb un valor m�nim de: ",diaMin); setColor(RED); printf("%d", cotRecMin); setColor(15);

    // RESET
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
        int borrado;
        for (borrado=0;borrado<=27;borrado++){
            msleep(10);
            printf("\b \b");
        }
        gotoxy(xDir,yDirPlus+14);
        printf("\n\n Prem Intro per sortir...");
        getchar();
        exit(0);
    }
    return 0;
}
