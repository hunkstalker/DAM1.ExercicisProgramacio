#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <RiazaClaudina.h>
#define MAXCADENA 30
#define FICADENA '\0'
void separaVocalsConsonants(char frase[],char vocals[],
                            char consonants[],int total);
int main()
{
    char frase[MAXCADENA]=" cal treballar molt.";
    char vocals[MAXCADENA];
    char consonants[MAXCADENA];

    separaVocalsConsonants(frase,vocals,consonants,MAXCADENA);
    pinta(vocals,MAXCADENA);
    pinta(consonants,MAXCADENA);

    return 0;
}
void separaVocalsConsonants(char frase[],char vocals[],
                            char consonants[],int total);
