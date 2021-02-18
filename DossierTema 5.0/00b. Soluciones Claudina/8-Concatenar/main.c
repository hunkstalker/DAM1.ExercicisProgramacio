#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 30
#define FICADENA '\0'
bool iguals(char frase1[],char frase2[],int qttC);
bool igualsG(char frase1[],char frase2[],int qttC);

int longitud(char paraula[],int qttc);
bool esLletra(char c);
int main()
{
    char frase1[MAXCADENA]="Hola";
    char frase2[MAXCADENA]="adeu";
    concatenar(frase1," ",MAXCADENA);
    concatenar(frase1,frase2,MAXCADENA);
    printf("\nLa cadena final es %s",frase1);
}
void concatenar(char frase1[],char frase2[],int qttc)
{
    int l1=longitud(frase1,qttc),l2=longitud(frase2,qttc);

    if ((l1+l2+1)<=qttc)
    {
        copiar(frase1,frase2,l1,l2,qttc);
    }
}
void copiar(char frase1[],char frase2[],int l1,int l2,int qttC)
{
    int i;
    for (i=0;i<=l2;i++)
    {
        frase1[l1+i]=frase2[i];
    }
}
int longitud(char paraula[],int qttC)
{
    int i=0;
    while (i<qttC && paraula[i]!=FICADENA) i++;
    return i;
}
