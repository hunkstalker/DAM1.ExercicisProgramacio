#include "ANFRUNSDENIS.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVECTOR 56

/* Enunciat:
    Utilitzant un vector de 56 caselles genera les 28 fitxes del dominó aleatòriament, tenint en compte que cada dues
    caselles forma una fitxa. El procediment serà:
*/

void generarFitxes(int v1[MAXVECTOR],int *i,int *j);
void comprovarFitxes(int v1[MAXVECTOR],int qttE,int i,int j,bool *encontrado,int *posicion1,int *posicion2);
void guardarFitxes(int v1[MAXVECTOR],int *i, int *j,int *pos1,int *pos2);
void imprimirFitxes(int v1[MAXVECTOR],int qttE);

int main() {
    SetConsoleTitle("Dossier Tema 4.0 Exercici 00. () Denis Anfruns.");

    //tildes
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    //números aleatorios.
    srand(time(NULL));

    start();
    return 0;
}

void start() {
    int fitxesDomino[MAXVECTOR];
    int num1,num2,pos1=0,pos2=1;
    bool trobat=false;

    marcaV(fitxesDomino,MAXVECTOR);
    // Se tendría que meter esto en un bucle.
    while(fitxesDomino[MAXVECTOR]!='\0')
    {
        generarFitxes(fitxesDomino,&num1,&num2);
        comprovarFitxes(fitxesDomino,MAXVECTOR,num1,num2,&trobat,&pos1,&pos2);
        if(fitxesDomino[0]!=-1 || trobat==false) guardarFitxes(fitxesDomino,&pos1,&pos2,&num1,&num2);
    }
    imprimirFitxes(fitxesDomino,MAXVECTOR);
    resetPrograma();
}

void generarFitxes(int v1[MAXVECTOR],int *i,int *j) {
    (*i)=rand()%6;
    (*j)=rand()%6;
}

void comprovarFitxes(int v1[MAXVECTOR],int qttE,int i,int j,bool *trobat,int *pos1,int *pos2) {
    *trobat=false;
    //controlo el inicio del vector, si es -1 es que no hay todavía ninguna ficha así que se guarda directamente.
    if(v1[0]!=-1) {
        //recorremos todo el vector y pararemos si encontramos una marca (-1).
        while(*pos2<qttE && v1[*pos1]!=-1 || v1[MAXVECTOR]!='\0' || *trobat==true) {
            if((v1[*pos1]==i && v1[*pos2]==j) || (v1[*pos1]==j && v1[*pos2]==i)) (*trobat)=true;                                                                                ///miramos si el primer valor se encuentra.
            else
            {
                *pos1+=2;
                *pos2+=2;
            }
            if(v1[0]==-1 || *trobat==false)
            {
                v1[*pos1]=i;
                v1[*pos2]=j;
            }
        }
    }
}

void imprimirFitxes(int v1[MAXVECTOR],int qttE) {
    int i=0,j=1;
    printf("\n\n");
    for(; j<qttE; i=i+2,j=j+2) printf(" (%d:%d)\n",v1[i],v1[j]);
}

void guardarFitxes(int v1[MAXVECTOR],int *pos1,int *pos2,int *i, int *j){
    v1[*pos1]=*i;
    v1[*pos2]=*j;
}
