#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Dossier 2020-21-ME-UF1. Tema 3.1 Exercici 01

/*(IntercanviVariables)
Crea un procediment que intercanviï el valor de dues variables que passarem
com a paràmetres i que prèviament haurem introduït per teclat. S’han d’intercanviar
els valors entre les variables i no mostrar les variables al revés)

void intercanviVariables (int *num1, int *num2)
*/

// prototipos
void resetPrograma(void);

void intercanviVariables (int *, int *);
int demanarValors (int *, int *);

int main()
{
    SetConsoleTitle("Dossier Tema 3.1 Exercici 1. (IntercanviVariables)  Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int num1, num2, cont=1;

    num1=demanarValors(&num1,&cont);
    num2=demanarValors(&num2,&cont);
    intercanviVariables (&num1, &num2);
    printf("\n >> El valor 1 ara es: %d y el 2: %d\n", num1, num2);

    resetPrograma();
    return 0;
}

int demanarValors (int *num, int *cnt){
    {
        printf("\n >> Introdueix un valor %d: ", *cnt);
        scanf("%d", &(*num));
        (*cnt)++;
    }
    return *num;
}

void intercanviVariables (int *num1, int *num2){
    int aux;
    aux=(*num1);
    (*num1)=(*num2);
    (*num2)=(aux);
}

// Función reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=1; // I'ts a final countdown!
    int i=0;

    // RESET.
    setColor(15);
    fflush(stdin);
    printf("\n\n >> Ara vols ["); setColor(12); printf("R"); setColor(15); printf("]einiciar el sistema o vols ["); setColor(12); printf("S"); setColor(15); printf("]ortir? ");
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
        printf("\n Dossier Tema 3.1 Exercici 1. (IntercanviVariables)\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
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
