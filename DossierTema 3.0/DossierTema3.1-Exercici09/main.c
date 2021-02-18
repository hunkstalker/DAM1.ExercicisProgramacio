#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
// #include <time.h>

/// Dossier 2020-21-ME-UF1. Tema 3.1 Exercici 09. 9. (MostraDigits)

/*
 Fer un procediment que li passem un nombre i ens mostri per pantalla els seus digits.
*/

/// Prototipos Procedimientos: 1ro los Void-Array. 2do Void-Void. 3ro Void-int/char.
void pregunta(char []);    // para imprimir texto
void resetPrograma(void);   // reset o cierre programa
/// Prototipos Funciones: 4to int/char-Void. 5to int/char-int/char.
int mostraDigits(int);     /// EXERCICI
int retornValor(void);      // para pedir valores

/// Variables globales.
char argumento[50];
int espera=10;

int main()
{
    SetConsoleTitle("Dossier Tema 3.0 Exercici 09. (MostraDigits)  Denis Anfruns.");

    /// Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int num;
    int result;

    setColor(6); pregunta(strcpy(argumento,"\n >> Dossier Tema 3.0 Exercici 09. (MostraDigits)  Denis Anfruns.\n"));

    setColor(7); pregunta(strcpy(argumento,"\n >> Introdueix un nombre: "));
    num=retornValorNum();

    while (!(num >= 0)){
        setColor(RED); pregunta(strcpy(argumento," >> Error "));
        setColor(7); pregunta(strcpy(argumento,"\n >> Introdueix un nombre: "));
        num=retornValorNum();
    }

    // quantitatDigits(num);
    result=mostraDigits(num);

    printf(" >> %d",result);

    resetPrograma();
    return 0;
}

/// Procedimiento de preguntas al usuario.
void pregunta(char phrase[])
{
    int pos=0;
    while (phrase[pos] != '\0')
    {
        msleep(espera);
        printf("%c",phrase[pos]);
        pos++;
    }
}

int mostraDigits(num){
    int reverse=0;
    while (num>0){
        reverse=reverse*10+(num%10);
        num=num/10;
    }
    return reverse;
}

int retornValorNum()
{
    int num;
    scanf("%d",&num);

    return num;
}

/// Función reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=2; // I'ts a final countdown!

    /// RESET.

    fflush(stdin);
    setColor(7); pregunta(strcpy(argumento,"\n\n >> Ara vols ["));
    setColor(RED); pregunta(strcpy(argumento,"R"));
    setColor(7); pregunta(strcpy(argumento,"]einiciar el programa o vols ["));
    setColor(RED); pregunta(strcpy(argumento,"S"));
    setColor(7); pregunta(strcpy(argumento,"]ortir? "));
    scanf("%c",&optionPr);
    fflush(stdin);

    /// Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')){
		printf(">> Vols ["); setColor(12); printf("R"); setColor(15); printf("]einiciar el sistema o vols ["); setColor(12); printf("S"); setColor(15); printf("]ortir? ");
		scanf("%c",&optionPr);
		fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r'){
        cls();
        main();
    } else {
        espera=0;
        setColor(6);
        pregunta(strcpy(argumento,"\n Dossier Tema 3.0 Exercici 09. (MostraDigits) .\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers."));
        setColor(15);

        /// Cuenta atrás.
        espera=10;
        pregunta(strcpy(argumento,"\n\n Tancant programa..."));
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--){
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(500);
        exit(0);
    }
}
