#include <stdio.h>
#include <stdlib.h>
#include <RiazaClaudina.h>
#define MAXCADENA 30
#define FICADENA '\0'
void passaLletres(char frase[],int *i, int qttC);
int comptaParaules(char frase[],int qttC);
void passaNoLletres(char frase[],int *i, int qttC);
int main()
{
    char frase[MAXCADENA]=" hola  iker ";
    separaParaules(frase,MAXCADENA);
    return 0;
}
void separaParaules(char frase[],int qttC)
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
            printf("  %d",calculaLongitud(paraula,MAXCADENA));
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

