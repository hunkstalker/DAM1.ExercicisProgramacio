#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// #include <time.h>
#include <rlutil.h>
#include <stdbool.h>

// char name[15];

// prototipos
void resetPrograma(void);

void pr(int ,int ,int );
void heart(void);

int wait=0;
bool heartTrue;

int main(){
    int i;

    // srand(time(NULL));
    // printf("\n >> Pon tu palabra: ");
    // scanf("%s",&name);

    setBackgroundColor(RED);
    heart();
    for(i=0; i<12; i++)
    {
        msleep(150);
        setBackgroundColor(rand()%12);
        heart();
    }

    resetPrograma();
    return 0;
}

void pr(int start, int stop, int y){
    int x;
    for(x=start; x<=stop; x++)
    {
        gotoxy(x,y);
        printf(" ");
    }
    if (heartTrue) msleep(wait);
    else msleep(100);
}

void heart(){
    pr(20,21,17);
    pr(19,22,16);
    pr(18,23,15);
    pr(17,24,14);
    pr(16,25,13);
    pr(16,25,12);
    pr(16,25,11);
    pr(17,24,10);

    pr(18,19,9);
    pr(22,23,9);

//    pr(40,41,7);
//    pr(31,39,6);
//    pr(41,49,6);
//    pr(33,37,5);
//    pr(43,47,5);
    heartTrue=true;
}

// Función reset programa.
void resetPrograma()
{
    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=3; // I'ts a final countdown!

    // RESET.
    gotoxy(2,20);
    resetColor();
    setBackgroundColor(BLACK);
    setColor(15); printf("\n >> Ara vols [");
    setColor(12); printf("R");
    setColor(15); printf("]einiciar el sistema o vols [");
    setColor(12); printf("S");
    setColor(15); printf("]ortir? ");
    scanf("%c",&optionPr); fflush(stdin);

    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s'))
    {
        setColor(15); printf(" >> Vols [");
        setColor(12); printf("R");
        setColor(15); printf("]einiciar el sistema o vols [");
        setColor(12); printf("S");
        setColor(15); printf("]ortir? ");
        scanf("%c",&optionPr); fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r')
    {
        cls();
        main();
    }
    else
    {
        setColor(6); printf("\n Dossier Tema3. Exercici01. (Màxim).\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");

        // Cuenta atrás.
        setColor(15); printf("\n\n El programa es tancara en: ");
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--)
        {
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(500);
        exit(0);
    }
}
