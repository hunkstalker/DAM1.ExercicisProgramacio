#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Dossier 2020-21-ME-UF1. Tema 3. Exercici 01

/*(M�xim)
Fer una funci� que passant-li dos nombres, ens retorni el m�xim dels dos nombres.
En el cas que els dos nombres siguin iguals, la funci� ha de retornar qualsevol dels dos nombres

int maxim(int num1, int num2);
Exemple: num1=1, num2=5
Resultat: 5
*/

// prototipos
void resetPrograma(void);

int demanarNumInt(void);
int maxim(int,int);

int main()
{
    SetConsoleTitle("Dossier Tema3. Exercici01. (M�xim) Denis Anfruns.");

    // Tildes y s�mbolos alien�genas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int num1, num2, numMax;

    printf("\n>> Introdueix un primer nombre: ");
    num1=demanarNumInt();
    printf(">> Introdueix un segon nombre: ");
    num2=demanarNumInt();

    numMax=maxim(num1,num2);
    printf(">> El numero m�xim es %d", numMax);
    resetPrograma();
    return 0;
}

int maxim(a,b){
    if (a>b)b=a;
    return b;
}

int demanarNumInt(){
    int res;
    scanf("%d",&res);
    return a;
}

// Funci�n reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetici�n del programa.
    int finalCountdown=1; // I'ts a final countdown!
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
        printf("\n Dossier Tema3. Exercici01. (M�xim).\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
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
        msleep(500);
        exit(0);
    }
}
