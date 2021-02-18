#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Examen 1.2 DAM1. Denis Anfruns.

// prototipos
void resetPrograma(void);

int main()
{
    int numMax=0,numMin=0,numAux=0,numRand=0,numCorrecte=0,count=0,yDirDiff=0;
    // Gotoxy
    int xDir=1, yDir=8;

    system("MODE CON: COLS=100");
    SetConsoleTitle("Examen 1.2 DAM1. Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    setColor(6);
    printf("\n Examen 1.2 DAM1 2020/21 Denis Anfruns\n");

    setColor(15);
    printf("\n>> Introdueix un primer valor inicial entre 1 y 20: "); setColor(2);
    scanf("%d",&numMax);
    while (numMax<1 || numMax>20){
        setColor(RED); printf(">> Valor incorrcte, ha de ser entre 1 y 20.\n"); setColor(15); printf(">> Introdueix un altre primer valor inicial: "); setColor(2);
        scanf("%d",&numMax);
        yDirDiff+=2;
    }
    setColor(15);
    printf("\n>> Introdueix un segon valor inicial entre 1 y 20: "); setColor(2);
    scanf("%d",&numMin);
    setColor(15);
    while (numMin<1 || numMin>20){
        setColor(RED); printf(">> Valor incorrcte, ha de ser entre 1 y 20.\n"); setColor(15); printf(">> Introdueix un altre segon valor inicial: "); setColor(2);
        scanf("%d",&numMin);
        yDirDiff+=2;
    }
    setColor(15);
    while (numMax==numMin){
        setColor(RED); printf(">> Valor incorrcte, son el mateix.\n"); setColor(15); printf(">> Introdueix un altre segon valor inicial: "); setColor(2);
        scanf("%d",&numMin);
        yDirDiff+=2;
    }
    if (numMax<numMin){
        numAux=numMin;
        numMin=numMax;
        numMax=numAux;
    }
    gotoxy(xDir,yDir+yDirDiff);
    printf(">> El valor màxim es %d y el mínim %d.", numMax, numMin);
    yDir++;
    numCorrecte=numMax;
    gotoxy(xDir,yDir+yDirDiff);
    printf("\n CREANT L'ESCALA\n");
    yDir+=3;
    gotoxy(xDir,yDir+yDirDiff);
    while (numCorrecte>=numMin){
        msleep(25);
        numRand=rand()%(numMax-numMin+1)+numMin;
        count++;
        if (numRand==numCorrecte){
            setColor(1);
            printf("%d",numRand);setColor(15); printf(",",numRand);
            numCorrecte--;
        } else {
            setColor(RED);
            printf("%d",numRand); setColor(15); printf(",",numRand);
        }
    }
    printf("\b \b. FI");
    setColor(6);
    printf("\n\n>> S'han generat %d numeros.", count);
    setColor(15);
    resetPrograma();
    return 0;
}



// Función reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=3; // I'ts a final countdown!
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
        printf("\n Examen DAM1. Denis Anfruns. EDUCEM, Granollers. 2020/21");
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
