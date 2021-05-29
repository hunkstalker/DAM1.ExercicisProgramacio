#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Dossier 2020-21-ME-UF1. Tema 3. Exercici 08

/*(QuantitatDigits)
 Fer una funció que li passem un nombre positiu i ens retorni la quantitat de dígits que té.
*/

// Prototipos
void resetPrograma(void);
void pregUsu(char []);
void quantitatDigits(int);
int retornValorNum(void);


// Variables globales.
char qstPhrase[50];
int espera=10;

int num;


int main()
{
    SetConsoleTitle("Dossier Tema 3.0 Exercici 08. (QuantitatDigits) Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    setColor(6); pregUsu(strcpy(qstPhrase,"\n >> Dossier Tema 3.0 Exercici 08. (QuantitatDigits) Denis Anfruns.\n"));

    setColor(7); pregUsu(strcpy(qstPhrase,"\n >> Introdueix un nombre: "));
    num=retornValorNum();

    while (!(num >= 0)){
        setColor(RED); pregUsu(strcpy(qstPhrase," >> Error "));
        setColor(7); pregUsu(strcpy(qstPhrase,"\n >> Introdueix un nombre: "));
        num=retornValorNum();
    }

    quantitatDigits(num);

    resetPrograma();
    return 0;
}

// Procedimiento de preguntas al usuario.
void pregUsu(char phrase[])
{
    int pos=0;
    while (phrase[pos] != '\0')
    {
        msleep(espera);
        printf("%c",phrase[pos]);
        pos++;
    }
}

void quantitatDigits(num){
    int count=0;
    while (num>0)
    {
        count++;
        /// setColor(7); pregUsu(strcpy(qstPhrase,"\n >> Num: "));
        /// printf("%d",num);
        num=num/10;
    }
    setColor(6); pregUsu(strcpy(qstPhrase,"\n >> El numero te "));
    printf("%d",count);
    pregUsu(strcpy(qstPhrase," digits."));
}

int retornValorNum()
{
    int num=0;
    scanf("%d",&num);

    return num;
}

// Función reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=2; // I'ts a final countdown!

    // RESET.

    fflush(stdin);
    setColor(7); pregUsu(strcpy(qstPhrase,"\n\n >> Ara vols ["));
    setColor(RED); pregUsu(strcpy(qstPhrase,"R"));
    setColor(7); pregUsu(strcpy(qstPhrase,"]einiciar el programa o vols ["));
    setColor(RED); pregUsu(strcpy(qstPhrase,"S"));
    setColor(7); pregUsu(strcpy(qstPhrase,"]ortir? "));
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
        espera=0;
        setColor(6);
        pregUsu(strcpy(qstPhrase,"\n Dossier Tema 3.0 Exercici 08. (QuantitatDigits).\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers."));
        setColor(15);

        // Cuenta atrás.
        espera=10;
        pregUsu(strcpy(qstPhrase,"\n\n Tancant programa..."));
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--){
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(500);
        exit(0);
    }
}
