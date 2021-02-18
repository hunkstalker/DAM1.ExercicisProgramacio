#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXCADENA 10
#define FICADENA '\0'
void pintaCodisAscii();
void introdueixCadena(char cadena[MAXCADENA]);
int longitudCadena(char cadena[MAXCADENA],int qttC);
void pintaCadena(char cadena[MAXCADENA],int qttC);
int main()
{
    char cadena[MAXCADENA]="hola";
    //pintaCodisAscii();
    //introdueixCadena(cadena);
    pintaCadena(cadena,MAXCADENA);
    printf("\nLa longitud de la cadena es %d",longitudCadena(cadena,MAXCADENA)); ///3

    passaMajuscula(cadena,MAXCADENA);
    printf("\n");
    pintaCadena(cadena,MAXCADENA);
    return 0;
}
void pintaCodisAscii()
{
    /// des del 0 fins al 255
    int i;
    for (i=0;i<=255;i++)
    {
        printf("[%d]:%c\t",i,i);
    }
}
void introdueixCadena(char cadena[MAXCADENA])
{
    cadena[0]='a';
    cadena[1]='b';
    cadena[2]='\0';
    cadena[3]='c';
    cadena[4]='\0';
}
void pintaCadena(char cadena[MAXCADENA],int qttC)
{
    int i=0;
    while (i<qttC && cadena[i]!=FICADENA)
    {
        printf("%c",cadena[i]);
        i++;
    }
}

int longitudCadena(char cadena[MAXCADENA],int qttC)
{
    int i=0;
    while (i<qttC && cadena[i]!=FICADENA) i++;
    return i;
}


void passaMajuscula(char cadena[MAXCADENA],int qttC){

    int i=0;

    while(i<qttC && cadena[i]!=FICADENA){

        if(cadena[i]>=97){cadena[i]=cadena[i]-32;}

        i++;
    }

}
