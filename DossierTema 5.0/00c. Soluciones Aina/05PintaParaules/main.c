#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCADENA 30
#define FICADENA '\0'
void passaLletres(char frase[],int *i, int qttC);
void pintaParaules(char frase[],int qttC);
void passaNoLletres(char frase[],int *i, int qttC);
bool esLletra(char caracter);

int main()
{
    char frase[MAXCADENA]=" hola bon dia   ";
    pintaParaules(frase,MAXCADENA);
    return 0;
}
void pintaParaules(char frase[],int qttC)
{
    int i=0,contParaules=0;

    while (frase[i]!=FICADENA && i<qttC)
    {
        passaNoLletres(frase,&i, qttC);

        /// if (frase[i]!=FICADENA
        if (esLletra(frase[i]))
        {
            if (contParaules>0) printf("\n");
            pintaLletres(frase,&i, qttC);
            contParaules++;
        }
    }
    return contParaules;
}

///Funció que col·loca posició passat els valors que no són lletres

void passaNoLletres(char frase[],int *i,int qttMax){

    while(!esLletra(frase[*i]) && *i<qttMax && frase[*i]!=FICADENA){(*i)++;}
}

///Controla si el caràcter passat és lletra o no
bool esLletra(char caracter){
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";
    bool lletra=false;
    int i=0;

        while (lletres[i]!=FICADENA && !lletra)
    {
        if (lletres[i]==caracter) lletra=true;
        else i++;
    }

    return lletra;
}

///Pinta les lletres
void pintaLletres(char frase[],int *i, int qttC)
{
    while (esLletra(frase[*i]) && *i<qttC && frase[*i]!=FICADENA)
    {
        printf("%c",frase[*i]);
        (*i)++;   /// *i=*i+1;
    }
}
