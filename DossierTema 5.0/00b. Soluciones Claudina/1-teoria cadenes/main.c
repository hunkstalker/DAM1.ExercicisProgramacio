#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXCADENA 10
#define FICADENA '\0'
void pintaCodisAscii();
void introdueixCadena(char cadena[MAXCADENA]);
int longitudCadena(char cadena[MAXCADENA],int qttC);
void pintaCadena(char cadena[MAXCADENA],int qttC);
char convertirCaracterMajuscula(char c);
bool esLletra(char c);
bool esVocal(char c);
int main()
{
    char cadena[MAXCADENA]="Hola.";

    ///pintaCodisAscii();

    ///introdueixCadena(cadena);

    //pintaCadena(cadena,MAXCADENA);
    //printf("\nLa longitud de la cadena es %d",longitudCadena(cadena,MAXCADENA)); ///3

    //passaMajuscula(cadena,MAXCADENA);
    //pintaCadena(cadena,MAXCADENA);

    //controlarCadaCaracter(cadena,MAXCADENA);
    controlarSiEsUnaVocal(cadena,MAXCADENA);
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

void passaMajuscula(char cadena[MAXCADENA],int qttC)
{
    int i=0;
    while (i<qttC && cadena[i]!=FICADENA)
    {
        cadena[i]=convertirCaracterMajuscula(cadena[i]);
        i++;
    }
}
char convertirCaracterMajuscula(char c)
{
    if (c>='a' && c<='z') c=c-32;
    return c;
}
void controlarCadaCaracter(char cadena[],int total)
{
    int i=0;

    while (cadena[i]!=FICADENA && i<total)
    {
        printf("\n%c es %d",cadena[i],esLletra(cadena[i]));
        i++;
    }
}
bool esLletra(char c)
{
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";
    int i=0;
    bool trobat=false;

    while (lletres[i]!=FICADENA && !trobat)
    {
        if (lletres[i]==c) trobat=true;
        else i++;
    }
    return trobat;
}
void controlarSiEsUnaVocal(char cadena[],int total)
{
    int i=0;

    while (cadena[i]!=FICADENA && i<total)
    {
        printf("\n%c es %d",cadena[i],esVocal(cadena[i]));
        i++;
    }
}
bool esVocal(char c)
{
    char vocals[] = "AEIOUÀÁÈÉÍÏÒÓÚÜaeiouàáèéíïòóúü";
    int i=0;
    bool trobat=false;

    while (vocals[i]!=FICADENA && !trobat)
    {
        if (vocals[i]==c) trobat=true;
        else i++;
    }
    return trobat;

}
