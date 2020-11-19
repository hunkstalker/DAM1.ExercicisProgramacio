#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Examen 1.1 DAM1. Denis Anfruns.

// prototipos
void resetPrograma(void);

int main()
{

    system("MODE CON: COLS=100");
    SetConsoleTitle("Examen 1.1 DAM1. Denis Anfruns.");

    // Gotoxy
    int xDir=1, yDir=5;
    int tirada=0, casillaAct=1, casilla=0,dado=0, casillaCero=0;

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    setColor(6);
    // Comienza el juego.
    printf("\n Examen DAM1 1.1 2020/21 Denis Anfruns\n");
    printf("\n Iniciem el joc:\n");
    setColor(15);
    printf(" Tirada[%02d]:%02d",tirada, casillaAct);
    while (casillaAct<54){
        dado=rand()%6+1;
        if (dado==6) casillaCero++;
        else casillaCero=0;
        gotoxy(xDir,yDir);
        yDir++;
        msleep(50);
        printf(" Tirada[%02d]:%02d+%02d=%02d",tirada, casillaAct, dado, casillaAct+dado);
        tirada++;
        casillaAct+=dado;
        if (casillaCero==2){
            casillaAct=1;
            setColor(RED); printf("\ Has tret 2 vegadoes 6, retornes al inici."); setColor(15);
        }
        if (casillaAct==7){
            casillaAct=17;
            printf("-->%d",casillaAct);
        }
        if (casillaAct==30){
            casillaAct=36;
            printf("-->%d",casillaAct);
        }
        if (casillaAct==44){
            casillaAct=22;
            printf("-->%d",casillaAct);
        }
        if (casillaAct==49){
            casillaAct=46;
            printf("-->%d",casillaAct);
        }
    }
    printf("\n Tirada[%d]:%d+%d=%d",tirada, casillaAct, dado, casillaAct+dado);
    gotoxy(xDir,tirada+4);
    setColor(6);
    printf("\n S'han produit %d tirades.", tirada-=1);
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
