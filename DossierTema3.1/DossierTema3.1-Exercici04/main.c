#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <time.h> // Apunte para que no se me vuelva a olvidar.

/// Dossier 2020-21-ME-UF1. Tema 3. Exercici 04

/*(NotaNumericaaLLetres5)
    Realitzar l’exercici número 3 (demanar nota i visualitzar nota en lletres), però amb 5 alumnes. Ha de mostrar:
        Alumne 1 ha tret Insuficient
        Alumne 2 ha tret Excel·lent
        …
        Alumne 5 ha tret Notable
*/

/// Prototipos Procedimientos: 1ro los Void-Array. 2do Void-Void. 3ro Void-int/char.
void preguntaArray(char []);
void resetPrograma(void);
void notaNumericaLLetres(void); // raíz del programa
///void timer(void); // experimento
void imprimirNota(int);
// Prototipos Funciones: 4to int/char-Void. 5to int/char-int/char.
int preguntaNota(void);
int retornValorNum(void);
// Nota personal. Los Métodos son Funciones y Procedimientos dentro de clases (en C "no hay" clases).

/// Variables globales.
char qstPhrase[50];
int espera=10;

/// Main relegado sólo a lo necesario para el encabezado del programa
int main()
{
    SetConsoleTitle("Dossier Tema3. Exercici 04. (NotaNumericaaLLetres5) Denis Anfruns.");

    /// Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    srand(time(NULL)); //Apunte para que no se me vuelva a olvidar.

    setColor(6); preguntaArray(strcpy(qstPhrase,"\n >> Dossier Tema3. Exercici 04. (NotaNumericaaLLetres5) Denis Anfruns."));
//    timer(); // Experimento
//    Curiosidad: Comprobando si usando de seed el tiempo y pidiendo 2 números aleatorios seguidos si la CPU es suficientemente rápida como para generar el mismo número.
//    int rnd1,rnd2;
//    rnd1=rand()%10; rnd2=rand()%10;
//    printf(" >> %d,%d",rnd1,rnd2);

    /// Inicia el programa
    notaNumericaLLetres();
    /// Resetea o finaliza el programa
    resetPrograma();
    return 0;
}

/// Procedimiento raíz
void notaNumericaLLetres(){
    /// Variables
    int numNota;

    int i=1;
    for(;i<=5;i++){
        // se pregunta la nota
        numNota=preguntaNota();
        // se menciona el alumno usando el bucle
        setColor(6); preguntaArray(strcpy(qstPhrase," >> Alumne "));
        printf("%d ",i);
        // se imprime la nota
        imprimirNota(numNota);
        setColor(15);
    }
}

/// Función para registrar la nota que el usuario introduce
int preguntaNota(){
    int num;
    setColor(7); preguntaArray(strcpy(qstPhrase,"\n >> Introdueix la nota (valors de 0 a 10): "));
    num=retornValorNum();
    while (num<0 || num>10){
        setColor(RED); preguntaArray(strcpy(qstPhrase," ¡¡Valor erroni!!"));
        setColor(7); preguntaArray(strcpy(qstPhrase,"\n >> Tens que introduir un valor de 0 a 10): "));
        num=retornValorNum();
    }
    return num;
}

/// Procedimiento para imprimir las notas en texto
void imprimirNota(num){
    if (num>=0 && num<=4) preguntaArray(strcpy(qstPhrase,"ha tret un Insuficient D:"));
    else if (num<=6) preguntaArray(strcpy(qstPhrase,"ha tret un Suficient :)"));
    else if (num<=8) preguntaArray(strcpy(qstPhrase,"ha tret un Notable :D"));
    else preguntaArray(strcpy(qstPhrase,"ha tret un Excel·lent ~(^-^)~"));
}

/// Procedimiento del recorrido del string
void preguntaArray(char phrase[])
{
    int pos=0;
    while (phrase[pos] != '\0')
    {
        msleep(espera);
        printf("%c",phrase[pos]);
        pos++;
    }
}

/// Función para escanear valor.
int retornValorNum()
{
    int num=0;
    scanf("%d",&num);
    return num;
}

/// Función reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=2; // I'ts a final countdown!

    fflush(stdin); // porsiaca que no me joda los strings por haber algo en el buffer.
    setColor(7); preguntaArray(strcpy(qstPhrase,"\n\n >> Ara vols ["));
    setColor(RED); preguntaArray(strcpy(qstPhrase,"R"));
    setColor(7); preguntaArray(strcpy(qstPhrase,"]einiciar el programa o vols ["));
    setColor(RED); preguntaArray(strcpy(qstPhrase,"S"));
    setColor(7); preguntaArray(strcpy(qstPhrase,"]ortir? "));
    scanf("%c",&optionPr);
    fflush(stdin); // limpiando el buffer de scanf.

    /// Compr. errores
    while (!(optionPr=='R' || optionPr=='r' || optionPr=='S' || optionPr=='s')){
		printf(">> Vols ["); setColor(12); printf("R"); setColor(15); printf("]einiciar el sistema o vols ["); setColor(12); printf("S"); setColor(15); printf("]ortir? ");
		scanf("%c",&optionPr);
		fflush(stdin); // limpiando el buffer de scanf.
    }
    if (optionPr=='R' || optionPr=='r'){
        cls();
        main();
    } else {
        espera=0;
        setColor(6); preguntaArray(strcpy(qstPhrase,"\n Dossier Tema3. Exercici08. (QuantitatDigits).\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers."));

        /// Cuenta atrás.
        espera=10;
        setColor(7); preguntaArray(strcpy(qstPhrase,"\n\n Tancant programa..."));
        printf("%d",finalCountdown);
        for (finalCountdown=finalCountdown-1; finalCountdown>=0; finalCountdown--){
            msleep(1000);
            printf("\b%d",finalCountdown);
        }
        msleep(500);
        exit(0);
    }
}

void timer(){
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "\n >> %Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);
}
