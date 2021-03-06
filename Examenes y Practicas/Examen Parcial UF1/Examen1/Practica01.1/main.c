#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // permite el uso de booleanos
#include <time.h>       // seed para el rand()
#include <rlutil.h>     // colorines
#include <windows.h>    // m�sica

// Exercici Pr�ctica #1.

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
    SetConsoleTitle("DAM1 M3/UF1.Programacio Estructurada. Denis Anfruns. 2020/2021");

    // Seed del srand() basado en tiempo para obtener un n�mero aleatorio distinto cada vez.
    srand(time(NULL));

    // Tildes y s�mbolos alien�genas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    // Valores que se le piden al usuario.
    int cotMin=0, cotMax=0, cotInicial=0;

    // Cotizaci�n aleatoria (subida/bajada).
    int randCot=0, numRandom=2;

    // Valores de la tabla. Dias y valores de cotizaci�n.
    int dia=1, cotAct=0, cotAnt=0, cotAnt2=0;  // Valores de control de Cotizaci�n.
    int falloCont=0; // Contadores.
    float avgCot=0;

    // Valores del recuento/resumen final.
    int diaMax=0, cotDiaMax=0, diaMin=0, cotDiaMin=0;

    // Llamada a al m�todo music().
    if (musicPlay){
        music();
    }

    // INICIO DEL PROGRAMA
    setColor(6);
    printf("\n Benvingut al SISTEMA GESTOR DE COTITZACIONS A BORSA 1.1.0\n");
    printf(" Realitzat per: Denis Anfruns Mill�n\n\n");
    setColor(15);
    yDirPlus+=5;

    // BLOQUE DE PREGUNTAS AL USUARIO.
    printf(">> Introdueix la cotitzaci� m�nima (0..10): "); setColor(2);
    scanf("%d",&cotMin); setColor(15);
    yDirPlus++;
    while (cotMin<0 || cotMin>10){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotitzaci� m�nima (0..10): "); setColor(2);
        scanf("%d",&cotMin); setColor(15);
        yDirPlus+=2;
    }
    printf(">> Introdueix la cotitzaci� m�xima (30..40): "); setColor(2);
    scanf("%d",&cotMax); setColor(15);
    yDirPlus++;
    while (cotMax<30 || cotMax>40){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotitzaci� m�xima (30..40): "); setColor(2);
        scanf("%d",&cotMax); setColor(15);
        yDirPlus+=2;
    }
    printf(">> Introdueix la cotitzaci� inicial (%d..%d): ", cotMin, cotMax); setColor(2);
    scanf("%d",&cotInicial); setColor(15);
    yDirPlus++;
    while (cotInicial<cotMin || cotInicial>cotMax){
        setColor(4); printf(">> VALOR INCORRECTE"); setColor(15); printf("\n>> Introdueix de nou la cotitzaci� inicial (%d..%d): ", cotMin, cotMax); setColor(2);
        scanf("%d",&cotInicial); setColor(15);
        yDirPlus+=2;
    }
    // FIN BLOQUE PREGUNTAS USUARIO
    // Falla con la entrada de alg�n caracter como la 'a' porque scanf() toma el valor num�rico ANSII de los car�cteres/s�mbolos (adem�s del tema del buffer),
    // estoy investigando como controlar la introducci�n de car�cteres, espacios y el Intro como no v�lidos con un string y getchar() recorriendo el buffer y buscando lo que quiero restringir.
    // Aunque imagino que antes de encontrar la soluci�n daremos el salto a otros lenguajes donde ser� m�s f�cil controlar todo eso
    // ando cerca ya de poderlo controlar, puedo controlarlo todo pero me falta poder acotar el rango num�rico a introducir por el usuario.

    // BLOQUE DE TABLA.
    // dia 1
    cotAct=cotInicial;
    printf("\n dia %2d: %3d\n", dia, cotAct); // Coloco el %3d porque con n�meros negativos se descuadra todo.

    // Contador d�as
    dia++;
    yDirPlus++;
    // Bloque recuentos resumen final.
    cotDiaMax=cotInicial;
    diaMax=dia;
    cotDiaMin=cotInicial;
    diaMin=dia;

    // Intercambio de valores.
    cotAnt=cotAct;

    // C�lculo de variaci�n cotizaci�n.
    randCot=rand()%(numRandom*2+1)-numRandom;
    cotAct+=randCot;

    // Suma para c�lculo de la media.
    avgCot+=cotInicial;
    avgCot+=cotAct;

    // dia 2
    msleep(15);
    printf(" dia %2d: %3d %3d\n", dia, cotAct, cotAnt);

    // Contador d�as
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
        // randCot=rand()%numRandom-2; // En este caso s�lo sirve para un n�mero est�tico prefijado %5=0,4(-2)=-2,2
        randCot=rand()%(numRandom*2+1)-numRandom; // En este caso cambiar variable al rango que quieras que suba/baje: Ej. num=2 (num*2=4+1)%5=(0,4)-num = -2,2
        cotAct+=randCot;

        // Suma para c�lculo de la media.
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

        // Contador de d�as.
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

    // Ajuste posici�n.
    xDir=1; yDir+=2;
    gotoxy(xDir,yDir);
    printf(">> Cotitzaci� M�nima: "); setColor(2); printf("%d ", cotMin); setColor(15); printf("Cotitzaci� M�xima: "); setColor(2); printf("%d ", cotMax); setColor(15); printf("Cotitzaci� Inicial: "); setColor(2); printf("%d ", cotInicial); setColor(15);
    dia--;

    printf("\n\n>> El valor promig de les cotitzacions ha sigut de: ");

    if ((avgCot/dia)<cotMin){
        setColor(4); printf("%.2f",avgCot/dia); setColor(15);
    } else if ((avgCot/dia)>cotMax){
        setColor(3); printf("%.2f",avgCot/dia); setColor(15);
    } else {
        setColor(15); printf("%.2f",avgCot/dia); setColor(15);
    }

    printf("\n>> El dia que s'ha obtingut la darrera m�xima cotitzaci� ha sigut: %d i amb un valor m�xim de: ",diaMax); setColor(3); printf("%d", cotDiaMax); setColor(15);
    printf("\n>> El dia que s'ha obtingut la darrera m�nima cotitzaci� ha sigut: %d i amb un valor m�nim de: ",diaMin); setColor(RED); printf("%d", cotDiaMin); setColor(15);
    resetPrograma();
    return 0;
}

// M�todo/procedimiento cierre/reset programa.
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
        gotoxy(xDir,yDir+10);
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
