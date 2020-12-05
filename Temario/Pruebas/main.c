#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

// Prototipos
void resetPrograma(void);
void qstUser(char phrase[]);

// Variables globales.
char qstPhrase[50];
int espera=10;

int main()
{
    SetConsoleTitle("Pruebas. Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL));

    int num;
    char value;
    bool comprDigit=false, comprValue=false;

    while (!(comprDigit && comprValue)){
    // Bloque preguntas al usuario.
    strcpy(qstPhrase,"\n >> Introduce un número entre 0 y 10: ");
    qstUser(qstPhrase);
    fflush(stdin); scanf("%c",&value); fflush(stdin);
    comprDigit=false; comprValue=false;
        if (isdigit(value) == 0){
            setColor(RED); printf(" >> ¡Error! Has introducido una letra. "); setColor(WHITE);
            comprDigit=true;
        }

        if (comprDigit==false){
            setColor(RED); printf(" >> Error"); setColor(WHITE);
            comprValue=true;
        }
    }

    setColor(WHITE); printf("\n >> El número es... %c", value);
    // Llamada al cierre/repetición del programa.
    resetPrograma();
    return 0;
}

// Procedimiento de preguntas al usuario.
void qstUser(char phrase[])
{
    int num=0;
    int pos=0;
    while (phrase[pos] != '\0')
    {
        msleep(espera);
        printf("%c",phrase[pos]);
        pos++;
    }
}

// Procedimiento reset programa.
void resetPrograma()
{
    void pregUsuFi(char phrase[]);
    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=2; // I'ts a final countdown!

    // RESET.
    setColor(15); strcpy(qstPhrase,"\n >> ¿Quieres ["); pregUsuFi(qstPhrase);
    setColor(12); strcpy(qstPhrase,"R"); pregUsuFi(qstPhrase);
    setColor(15); strcpy(qstPhrase,"]einiciar el programa o quieres ["); pregUsuFi(qstPhrase);
    setColor(12); strcpy(qstPhrase,"S"); pregUsuFi(qstPhrase);
    setColor(15); strcpy(qstPhrase,"]alir? "); pregUsuFi(qstPhrase);
    fflush(stdin);
    scanf("%c",&optionPr);
    fflush(stdin);

    // Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s'))
    {
        espera=10;
		setColor(15); printf(" >> ¿Quieres [");
		setColor(12); printf("R");
		setColor(15); printf("]einiciar el programa o quieres [");
		setColor(12); printf("S");
		setColor(15); printf("]alir? ");
		fflush(stdin);
		scanf("%c",&optionPr);
		fflush(stdin);
    }
    if (optionPr=='R' || optionPr=='r')
    {
        cls();
        main();
    } else {
        espera=0;
        setColor(6); strcpy(qstPhrase,"\n    Denis Anfruns, probando, probando..."); pregUsuFi(qstPhrase);
        setColor(15);

        // Cuenta atrás.
        espera=25;
        msleep(250); strcpy(qstPhrase,"\n\n >> Cerrando aplicación... "); pregUsuFi(qstPhrase);
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--)
        {
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(1000);
        exit(0);
    }
}

// Procedimiento preguntas reset.
void pregUsuFi(char phrase[])
{
    int pos=0;
    while (phrase[pos] != '\0')
    {
        msleep(espera);
        printf("%c",phrase[pos]);
        pos++;
    }
}

// Notas.
// system("pause");
