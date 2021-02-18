#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

//#define MAXVECTOR 6
#define MAXCADENA 50
#define FICADENA '\0'

/* Enunciat:

*/

bool compararParaules(char frase1[],char frase2[],int qttC);

int main() {
    SetConsoleTitle("Dossier Tema 5.0 Exercici 07. (Iguals) Denis Anfruns.");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //números aleatorios.
    //srand(time(NULL));

    start();
    return 0;
}

void start() {
    char frase1[MAXCADENA]="Hola";
    char frase2[MAXCADENA]="Hola";

    printf("\n Les frases son %d",compararParaules(frase1,frase2,MAXCADENA));

    resetPrograma();
}

bool compararParaules(char frase1[],char frase2[],int qttC) {
    int i=0;
    bool iguals;

    while(i<qttC && frase1[i]!=FICADENA && frase2[i]!=FICADENA && frase1[i]==frase2[i]) ++i;
    if(frase1[i]==FICADENA && frase2[i]==FICADENA) iguals=true;
    else iguals=false;
    return iguals;
}

//Versión Gerard
//bool compararParaules(char frase1[],char frase2[],int qttC) {
//    int i=0;
//    bool iguals=true;
//
//    while(i<qttC && iguals && (frase1[i]!=FICADENA || frase2[i]!=FICADENA)) ++i;
//    if(frase[i]==FICADENA && frase2[i]==FICADENA) iguals=false;
//    else iguals=false;
//    return iguals;
//}
