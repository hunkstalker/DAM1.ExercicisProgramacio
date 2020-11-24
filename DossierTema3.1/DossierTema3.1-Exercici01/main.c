#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Dossier 2020-21-ME-UF1. Tema 3. Exercici 01

/*(Máxim)
Fer una funció que passant-li dos nombres, ens retorni el màxim dels dos nombres.
En el cas que els dos nombres siguin iguals, la funció ha de retornar qualsevol dels dos nombres

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
    SetConsoleTitle("Dossier Tema3. Exercici01. (Màxim) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int num1, num2, numMax;

    printf("\n>> Introdueix un primer nombre: ");
    num1=demanarNumInt();
    printf(">> Introdueix un segon nombre: ");
    num2=demanarNumInt();

    numMax=maxim(num1,num2);
    printf(">> El numero màxim es %d", numMax);
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

// Función reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
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
        printf("\n Dossier Tema3. Exercici01. (Màxim).\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
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
