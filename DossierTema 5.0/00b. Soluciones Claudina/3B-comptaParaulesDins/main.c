#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <RiazaClaudina.h>
#define FICADENA '\0'
#define MAXCADENA 30

///compta paraules amb la variable d'estat dins fora
int main()
{
    char frase[MAXCADENA]="Bon Nadal";
    printf("La cadena te %d paraules",comptaParaulesDins(frase,MAXCADENA));
    return 0;
}
int comptaParaulesDins(char frase[],int qttC)
{
    int i=0,contP=0;
    bool dins=false;

    ///" Bon Nadal  "
    while (i<qttC && frase[i]!=FICADENA)
    {
        /// incremento en una paraula quan entrem a la paraula
        if (esLletra(frase[i]) && dins==false)
        {
            dins=true;
            contP++;
        }
        else if (!esLletra(frase[i]) && dins==true) dins=false;
        i++;
    }
    return contP;
}






