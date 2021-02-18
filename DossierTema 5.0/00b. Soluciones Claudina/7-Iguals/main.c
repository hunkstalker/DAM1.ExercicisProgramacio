#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 30
#define FICADENA '\0'
bool iguals(char frase1[],char frase2[],int qttC);
bool igualsG(char frase1[],char frase2[],int qttC);

int longitud(char paraula[],int qttC);
bool esLletra(char c);
int main()
{
    char frase1[MAXCADENA]="Hola";
    char frase2[MAXCADENA]="Holaaaaaa";

    printf("\nLes frase son %d",iguals(frase1,frase2,MAXCADENA));
    printf("\nLes frase son %d",igualsG(frase1,frase2,MAXCADENA));
    return 0;
}


bool iguals(char frase1[],char frase2[],int qttC)
{
    int i=0;
    bool igualFrase;
    while (i<qttC && frase1[i]!=FICADENA && frase2[i]!=FICADENA && frase1[i]==frase2[i])
    {
        i++;
    }
    if (frase1[i]==FICADENA && frase2[i]==FICADENA) igualFrase=true;
    else igualFrase=false;
    return igualFrase;
}

bool igualsG(char frase1[],char frase2[],int qttC)
{
    int i=0;
    bool igualFrase=true;
    while (i<qttC && (frase1[i]!=FICADENA || frase2[i]!=FICADENA) && igualFrase)
    {
        if (frase1[i]!=frase2[i]) igualFrase=false;
        else i++;
    }
    return igualFrase;
}
