#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>

// Explicació 07 Funcions i Procediments.

// Prototipos.
void resetPrograma(void);

float demanarNumeroFloat(void);
char demanarOperador(void);

float suma(float,float);
float resta(float,float);
float multi(float,float);
float divisio(float,float);

void pantalla(float,float,char,float);


// INICI PROGRAMA
int main(){

    SetConsoleTitle("Exercici: Calculadora. Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    // Variables locales main.
    float num1,num2;
    float res;
    char op='x';

    // Preguntes al usuario.
    printf("\n>> Introdueix el primer numero: ");
    num1=demanarNumeroFloat();
    printf(">> Introdueix el segon numero: ");
    num2=demanarNumeroFloat();
    printf(">> Introdueix l'operador: ");
    op=demanarOperador();


    switch (op){
        case'+': res=suma(num1,num2);break;
        case'-': res=resta(num1,num2);break;
        case'*': res=multi(num1,num2);break;
        case'x': res=multi(num1,num2);break;
        case'X': res=multi(num1,num2);break;
        case'/': res=divisio(num1,num2);break;
    }
    pantalla(num1,num2,op,res);
    return 0;
}

// función que lee números.
float demanarNumeroFloat(void){
    float num;
    fflush(stdin);
    scanf("%f",&num);
    fflush(stdin);
    return (num);
}

// función que devuelve un operador válido.
char demanarOperador(void){
    char op;
    fflush(stdin);
    scanf("%c",&op);
    fflush(stdin);
    while (op!='+' && op!='-' && op!='*' && op!='/' && op!='x' && op!='X'){
        fflush(stdin);
        printf("Introdueix un operador valid (+,-,*,/): ");
        scanf("%c",&op);
        fflush(stdin);
    }
    return (op);
}

// Bloque de cálculos
float suma(float a,float b){
    return (a+b);
}

float resta(float a,float b){
    return (a-b);
}

float multi(float a,float b){
    return (a*b);
}

// Hacer un paso por referencia.
float divisio(float a,float b){
    float res;
    while (b==0){
        printf("\n>> No es pot dividir per cero.");
        printf("\n>> Introdueix el segon numero: ");
        b=demanarNumeroFloat();
    }
    return (a/b);
}

// Print resultado.
void pantalla(float num1, float num2, char op, float res)
{
    if (op=='*') op='x';
    fflush(stdin);
    printf("\n>> %.f%c%.f=%.2f", num1, op, num2, res);
    resetPrograma();
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
        printf("\n DAM1 M3/UF1.Programació Estructurada. Funcions y Procediments: Exercici Calculadora.\n Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
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
