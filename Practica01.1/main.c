#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <rlutil.h>
#include <windows.h> // música

// Exercici Práctica #1.
// NOTA!. Tener activado en Settings>Compiler en Compiler Flags la opción -std=C99 para poder iniclializar directamente una variable dentro de un 'for'.

bool musicPlay=true;

// Método/procedimiento para reproducir tema musical.
void music(){
    PlaySound(TEXT("artblock"), NULL, SND_LOOP | SND_ASYNC);
    musicPlay=false;
}

// INICI PROGRAMA
int main(){

    // Llamada a al método music().
    if (musicPlay){
        music();
    }

    system("MODE CON: COLS=100");
    SetConsoleTitle("DAM1 M3/UF1.Programacio Estructurada. Denis Anfruns. 2020/2021");

    // Seed del srand() basado en tiempo para obtener un número aleatorio distinto cada vez.
    srand(time(NULL));

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    // Valores que se le piden al usuario.
    int cotMin=0, cotMax=0, cotInicial=0;

    // Cotización aleatoria (subida/bajada).
    int randCot=0, numRandom=2;

    // Valores de la tabla. Dias y valores de cotización.
    int dia=1, cotAct=0, cotAnt=0, cotAnt2=0;  // Valores de control de Cotización.
    int xDir=1, yDir=1, yDirPlus=0; // Valores de gotoxy().
    int falloCont=0; // Contadores.
    float avgCot=0;

    // Valores del recuento/resumen final.
    int diaMax=0, cotDiaMax=0, diaMin=0, cotDiaMin=0;

    // Variable contador final.
    int finalCountdown=3;

    // INICIO DEL PROGRAMA
    setColor(6);
    printf("\n Benvingut al SISTEMA GESTOR DE COTITZACIONS A BORSA 1.1.0\n");
    printf(" Realitzat per: Denis Anfruns Millán\n\n");
    setColor(15);
    yDirPlus+=5;

    // BLOQUE DE PREGUNTAS AL USUARIO.
    printf(">> Introdueix la cotització mínima (0..10): "); setColor(2);;
    scanf("%d",&cotMin); setColor(15);
    yDirPlus++;
    while (cotMin<0 || cotMin>10){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotització mínima (0..10): "); setColor(2);
        scanf("%d",&cotMin); setColor(15);
        yDirPlus+=2;
    }
    printf(">> Introdueix la cotització màxima (30..40): "); setColor(2);
    scanf("%d",&cotMax); setColor(15);
    yDirPlus++;
    while (cotMax<30 || cotMax>40){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotització màxima (30..40): "); setColor(2);
        scanf("%d",&cotMax); setColor(15);
        yDirPlus+=2;
    }
    printf(">> Introdueix la cotització inicial (%d..%d): ", cotMin, cotMax); setColor(2);
    scanf("%d",&cotInicial); setColor(15);
    yDirPlus++;
    while (cotInicial<cotMin || cotInicial>cotMax){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotització inicial (%d..%d): ", cotMin, cotMax); setColor(2);
        scanf("%d",&cotInicial); setColor(15);
        yDirPlus+=2;
    }
    // FIN BLOQUE PREGUNTAS USUARIO
    // Falla con la entrada de algún caracter como la 'a' porque scanf() toma el valor numérico ANSII de los carácteres/símbolos (además del tema del buffer),
    // estoy investigando como controlar la introducción de carácteres, espacios y el Intro como no válidos con un string y getchar() recorriendo el buffer y buscando lo que quiero restringir.
    // Aunque imagino que antes de encontrar la solución daremos el salto a otros lenguajes donde será más fácil controlar todo eso
    // ando cerca ya de poderlo controlar, puedo controlarlo todo pero me falta poder acotar el rango numérico a introducir por el usuario.


    // BLOQUE DE TABLA.
    // dia 1
    cotAct=cotInicial;
    printf("\n dia %2d: %3d\n", dia, cotAct); // Coloco el %3d porque con números negativos se descuadra todo.

    // Contador días
    dia++;
    yDirPlus++;
    // Bloque recuentos resumen final.
    cotDiaMax=cotInicial;
    diaMax=dia;
    cotDiaMin=cotInicial;
    diaMin=dia;

    // Intercambio de valores.
    cotAnt=cotAct;

    // Cálculo de variación cotización.
    randCot=rand()%(numRandom*2+1)-numRandom;
    cotAct+=randCot;

    // Suma para cálculo de la media.
    avgCot+=cotInicial;
    avgCot+=cotAct;

    // dia 2
    msleep(15);
    printf(" dia %2d: %3d %3d\n", dia, cotAct, cotAnt);

    // Contador días
    dia++;
    // Bloque recuentos resumen final.
    cotDiaMax=cotInicial;
    diaMax=dia;
    cotDiaMin=cotInicial;
    diaMin=dia;

    yDir+=yDirPlus;
    while ((dia<=60) && (falloCont<3)){

        // Intercambio de valores.
        cotAnt2=cotAnt;
        cotAnt=cotAct;

        // ALEATORIO (2 sistemas).
        // randCot=rand()%numRandom-2; // En este caso sólo sirve para un número estático prefijado %5=0,4(-2)=-2,2
        randCot=rand()%(numRandom*2+1)-numRandom; // En este caso cambiar variable al rango que quieras que suba/baje: Ej. num=2 (num*2=4+1)%5=(0,4)-num = -2,2
        cotAct+=randCot;

        // Suma para cálculo de la media.
        avgCot+=cotAct;

        if (cotAct<cotMin) setColor(RED);
        else if (cotAct>cotMax) setColor(3);
        else setColor(15);

        // Bloque de mensajes.
        if (dia==31){
            xDir=32;
            yDir=yDirPlus-1;
        }
        yDir++;
        gotoxy(xDir,yDir);
        msleep(15);
        printf(" dia %2d: %3d %3d %3d", dia, cotAct, cotAnt, cotAnt2); setColor(15);

        // Bloque resumen final.
        if (cotAct>=cotDiaMax){
            cotDiaMax=cotAct;
            diaMax=dia;
        } else if (cotAct<=cotDiaMin) {
            cotDiaMin=cotAct;
            diaMin=dia;
        }

        // Contador bancarrota.
        if (cotAct<cotMin) falloCont++;
        else falloCont=0;

        // Contador de días.
        dia++;
    }
    // FIN BLOQUE TABLA

    // SALIDA DEL PROGRAMA
    if (falloCont==3){
        xDir=1; yDir+=2;
        gotoxy(xDir,yDir);
        setColor(4);
        printf(" L'EMPRESA A CAIGUT EN BANCARROTA\n\n");
        setColor(15);
        yDirPlus+=2;
    }

    // Ajuste posición.
    xDir=1; yDir+=2;
    gotoxy(xDir,yDir);
    printf(">> Cotització Mínima: "); setColor(2); printf("%d ", cotMin); setColor(15); printf("Cotització Màxima: "); setColor(2); printf("%d ", cotMax); setColor(15); printf("Cotització Inicial: "); setColor(2); printf("%d ", cotInicial); setColor(15);
    dia--;

    printf("\n\n>> El valor promig de les cotitzacions ha sigut de: ");

    if ((avgCot/dia)<cotMin){
        setColor(4); printf("%.2f",avgCot/dia); setColor(15);
    } else if ((avgCot/dia)>cotMax){
        setColor(3); printf("%.2f",avgCot/dia); setColor(15);
    } else {
        setColor(15); printf("%.2f",avgCot/dia); setColor(15);
    }

    printf("\n>> El dia que s'ha obtingut la darrera màxima cotització ha sigut: %d i amb un valor màxim de: ",diaMax); setColor(3); printf("%d", cotDiaMax); setColor(15);
    printf("\n>> El dia que s'ha obtingut la darrera mínima cotització ha sigut: %d i amb un valor mínim de: ",diaMin); setColor(RED); printf("%d", cotDiaMin); setColor(15);








    // RESET. Que lo suyo sería crear una clase a parte, supongo.
    char optionPr='X'; // Variable para controlar la salida/repetición del programa.

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
        printf("\n DAM1 M3/UF1.Programació Estructurada. Práctica de Programació. Exercici 1\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
        printf("\n MÚSICA 'artblock' DE https://opengameart.org/content/artblock");
        setColor(15);

        // Cuenta atrás.
        printf("\n\n El programa es tancara en: ");
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--){
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        for (int borrado=0;borrado<=27;borrado++){
            msleep(10);
            printf("\b \b");
        }
        gotoxy(xDir,yDir+10);
        printf("\n\n Prem Intro per sortir...");
        getchar();
        exit(0);
    }
    return 0;
}
