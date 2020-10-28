#include <stdio.h>
#include <stdlib.h>

/* Exercici Extra 1

CONTADOR CON DECENAS Y UNIDADES (FOR & WHILE)
*/

// Definicio de les variables globals.
int d,u;
int opcio;

int sortir();

int main()
{
    // Definicio de funcions.
    int forFunction(int d, int u);
    int whileFunction(int d, int u);

    // Declaracio de les variables.
    d=0, u=0, opcio=0;

    // Selector d'exercicis.
    printf(">> Quina funcio vols fer, 'for'[1] o 'while'[2]?\n");
    scanf("%d",&opcio);
    // Control d'errors.
    while (opcio!=1 && opcio!=2){
        printf(">> ¡Te he dicho 1 o 2 carajo! Prueba otra vez...\n");
        scanf("%d",&opcio);
    }

    // Selector perque l'usuari decideixi.
    if (opcio==1){
        printf(">> Pulsa una tecla qualsevol per iniciar el 'for'.\n");
        fflush(stdin);
        getchar();
        forFunction(d,u);
    } else {
        printf(">> Pulsa una tecla qualsevol per iniciar el 'while'.\n");
        fflush(stdin);
        getchar();
        whileFunction(d,u);
    }
    return 0;
}

// Funcio per l'exercici fet amb 'for'.
int forFunction(var1,var2){
    opcio=0;
    for (d=0;d<=9;d++){
        for (u=0;u<=9;u++){
        printf("%d%d\n",d,u);
        }
    }
    printf("\n>> Aquesta ha sigut una funcio amb 'for'.\n");
    sortir();
    return 0;
}

// Funcio per l'exercici fet amb 'while'.
int whileFunction(var1,var2){
    opcio=0;
    while (var1<=9){
        var2=0;
        while (var2<=9){
            printf("%d%d\n",var1,var2);
            var2++;
        }
        var1++;
    }
    printf("\n>> Aquesta ha sigut una funcio amb 'while'.\n");
    sortir();
    return 0;
}

int sortir(){
    // Funcio per repetir el programa o sortir.
    printf("\n>> Introdueix [1] per tornar a comencar o qualsevol altre num/caracter per sortir.\n");
    scanf("%d",&opcio);
    if (opcio==1) main();
    return 0;
}
