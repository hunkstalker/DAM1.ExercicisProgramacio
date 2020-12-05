#include <stdio.h>
#include <stdlib.h>
#include <rlutil.h>
#include <stdbool.h>

/// Ejemplo paso de valor por referencia de memoria.

// prototipos
void resetPrograma(void);

float divisio (float ,float ,bool *);

int main()
{
    SetConsoleTitle("Ejemplo paso de valor por referencia de memoria. Denis Anfruns.");

    // Tildes y símbolos alienígenas.
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    float num1=10,num2=2,res;
    bool error=false;

    res=divisio(num1,num2,&error);
    if (error) printf(" >> No es pot dividir entre 0.");
    else printf("\n >> La divisio es: %f", res);

    resetPrograma();
    return 0;
}

float divisio (float num1, float num2,bool *error){
    float r;
    if (num2==0) (*error)=true;
    else r=num1/num2;
    return r;
}


// Función reset programa.
void resetPrograma(){

    char optionPr='X'; // Variable para controlar la salida/repetición del programa.
    int finalCountdown=3; // I'ts a final countdown!
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
        printf("\n Ejemplo paso de valor por referencia de memoria. Curs.2020/2021. Denis Anfruns. EDUCEM, Granollers.");
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
