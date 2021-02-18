#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 30
#define FICADENA '\0'
int longitud(char paraula[],int qttC);
bool esLletra(char c);
int main()
{
    char frase[MAXCADENA]="Hola que tal";
    invertirParaulaPerParaula(frase,MAXCADENA);
    return 0;
}
void invertirParaulaPerParaula(char frase[],int qttC)
{
    int i=0,contParaules=0;
    char paraula[MAXCADENA];

    while (frase[i]!=FICADENA && i<qttC)
    {
        passaNoLletres(frase,&i, qttC);

        /// if (frase[i]!=FICADENA
        if (esLletra(frase[i]))
        {
            copiaParaules(frase,&i, qttC,paraula);
            if (contParaules>0) printf("\n");
            printf("%s",paraula);

            invertir(paraula,MAXCADENA);
            printf("\t%s",paraula);
            contParaules++;
        }
    }
    return contParaules;
}

void copiaParaules(char frase[],int *i, int qttC,char paraula[])
{
    int j=0;
    while (esLletra(frase[*i]) && *i<qttC && frase[*i]!=FICADENA)
    {
        paraula[j]=frase[*i];
        j++;
        (*i)++;   /// *i=*i+1;
    }
    paraula[j]=FICADENA;
}

void passaNoLletres(char frase[],int *i, int qttC)
{
    while (!esLletra(frase[*i]) && *i<qttC && frase[*i]!=FICADENA)
        (*i)++;   /// *i=*i+1;

}

void invertir(char paraula[],int qttC)
{
    int i=0,j=longitud(paraula,qttC)-1;
    char aux;
    while (i<j)
    {
        aux=paraula[i];
        paraula[i]=paraula[j];
        paraula[j]=aux;
        i++;
        j--;
    }

}

int longitud(char paraula[],int qttC)
{
    int i=0;
    while (i<qttC && paraula[i]!=FICADENA) i++;
    return i;
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
