#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Dossier 2020-21-ME-UF1. Tema 3. Exercici 03

/*(NotaNumericaaLLetres2)
Fer un programa que, a partir d’una funció demani a l’usuari una nota compresa entre 0 i 10.
Posteriorment aquesta nota, i a través del procediment que s’ha creat a l’exercici número 2, cal transformar-la en lletres.

Funció: int demanarNota()  // cal controlar que el número sigui correcte
Procediment: void notaEnLletres(int nota)

*/

// prototipos
void resetPrograma(void);
void imprimirNota(int);
int demanarNota(int);


int main()
{
    SetConsoleTitle("Dossier Tema3. Exercici 03. (NotaNumericaaLLetres2) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    // Variables.
    int numNota=0;

    demanarNota(numNota);
    resetPrograma();
    return 0;
}

int demanarNota(num){
    printf("\n>> Introdueix la nota (valors de 0 a 10): ");
    scanf("%d",&num);
    while (num<0 || num>10){
        setColor(RED); printf(">> Valor erroni!"); setColor(15); printf("\n>> Tens que introduir un valor de 0 a 10): ");
        scanf("%d",&num);
    }
    setColor(6);
    imprimirNota(num);
    setColor(15);
    return num;
}

void imprimirNota(num){
    if (num>=0 && num<=4) printf("\n>> La teva nota es de %d y es un Insuficient D:", num);
    if (num>=5 && num<=6) printf("\n>> La teva nota es de %d y es un Suficient :)", num);
    if (num>=7 && num<=8) printf("\n>> La teva nota es de %d y es un Notable :D", num);
    if (num>=9 && num==10) printf("\n>> La teva nota es de %d y es un Excel·lent ~(^-^)~", num);
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
        printf("\n Dossier Tema3. Exercici 03. (NotaNumericaaLLetres2).\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
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
