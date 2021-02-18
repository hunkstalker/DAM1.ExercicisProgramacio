#include <stdio.h>
#include <stdlib.h>

#define MAXCADENA 20
#define FICADENA '\0'

int main()
{

    char cadena[MAXCADENA]="Hola como estas";

    printf("%s",cadena);

    invertirCadena(cadena,MAXCADENA);

    printf("\n");

    printf("%s",cadena);

    return 0;
}

void invertirCadena(char cadena[],int qttMax){

    int i,j;
    int posMarca;
    char aux;

    posMarca=trobaFiCadena(cadena,qttMax);
    j=posMarca-1;

    for(i=0;i<j;i++){

        aux=cadena[i];
        cadena[i]=cadena[j];
        cadena[j]=aux;
        j--;
    }
}

int trobaFiCadena(char cadena[],int qttMax){

    int i=0;

    while(cadena[i]!=FICADENA && i<qttMax){
        i++;
    }

    return i;
}
