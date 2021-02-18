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
    char frase[MAXCADENA]="      ";
    printf("\nLa cadena te %d paraules",comptaParaules(frase,MAXCADENA));
    return 0;
}
int comptaParaules(char frase[],int qttC)
{
    int i=0,contParaules=0;

    while (frase[i]!=FICADENA && i<qttC)
    {
        passaNoLletres(frase,&i, qttC);

        /// if (frase[i]!=FICADENA
        if (esLletra(frase[i]))
        {
            contParaules++;
            passaLletres(frase,&i, qttC);
        }
    }
    return contParaules;
}
void passaNoLletres(char frase[],int *i, int qttC)
{
    while (!esLletra(frase[*i]) && *i<qttC && frase[*i]!=FICADENA)
        (*i)++;   /// *i=*i+1;

}
void passaLletres(char frase[],int *i, int qttC)
{
    while (esLletra(frase[*i]) && *i<qttC && frase[*i]!=FICADENA)
        (*i)++;   /// *i=*i+1;

}

